# maxadjs_and_sentiment.py
import pandas as pd
import re
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from io import StringIO
from tqdm import tqdm
import string

# ---------- CONFIG ----------
INPUT_CSV = 'bias_clean.csv'         # change if needed
TEXT_COL = 'page_text'
LABEL_COL = 'bias'
OUTPUT_CSV = 'bias_maxadjs_sentiment.csv'
OUTPUT_FIG = 'boxplots_maxadjs_sentiment.png'
# thresholds for counting negative / highly positive sentences
NEG_SENT_THRESH = -0.4
POS_SENT_THRESH = 0.4
# -----------------------------

# ---------- try optional libs ----------
USE_SPACY = False
try:
    import spacy
    try:
        nlp = spacy.load('en_core_web_sm', disable=['ner'])
        USE_SPACY = True
        print("INFO: spaCy model loaded -> using spaCy for POS & sentence split.")
    except Exception:
        print("WARN: spaCy model 'en_core_web_sm' not available. Using heuristic fallback for adjectives/sentences.")
        USE_SPACY = False
except Exception:
    print("WARN: spaCy not installed. Using heuristic fallback for adjectives/sentences.")
    USE_SPACY = False

USE_VADER = False
try:
    from vaderSentiment.vaderSentiment import SentimentIntensityAnalyzer
    vader = SentimentIntensityAnalyzer()
    USE_VADER = True
    print("INFO: VADER available -> using it for sentence sentiment.")
except Exception:
    print("WARN: VADER not installed. Using small word-list fallback for sentiment.")
    USE_VADER = False

# ---------- helpers ----------
def robust_read_csv(path):
    encs = ['utf-8', 'utf-8-sig', 'latin1', 'cp1252']
    for e in encs:
        try:
            df = pd.read_csv(path, encoding=e)
            print(f"Loaded CSV with encoding: {e}")
            return df
        except Exception:
            pass
    print("All encodings failed; falling back to 'replace' decode.")
    with open(path, 'rb') as f:
        raw = f.read()
    decoded = raw.decode('utf-8', errors='replace')
    df = pd.read_csv(StringIO(decoded))
    print("Loaded CSV with fallback decode.")
    return df

def clean_text(t):
    if not isinstance(t, str):
        return ""
    t = re.sub(r'[\r\n\t]+', ' ', t)
    t = re.sub(r'\s+', ' ', t).strip()
    return t

# token regex for fallbacks
token_re = re.compile(r"[A-Za-z]+(?:'[A-Za-z]+)?")

# adjective heuristic (suffix-based) for fallback
ADJ_SUFFIXES = ('able','al','ful','ic','ive','ous','ish','less','ary','ant','ent','like','y','est','ier')
def count_adjs_in_sentence_heuristic(sent_text):
    toks = token_re.findall(sent_text.lower())
    cnt = 0
    for w in toks:
        for suf in ADJ_SUFFIXES:
            if w.endswith(suf) and len(w) > len(suf) + 1:
                cnt += 1
                break
    return cnt

# small fallback sentiment lexicon (if VADER not installed)
POS_WORDS = set([
    'good','great','excellent','positive','happy','fortunate','correct','superb','amazing','wonderful','best','love','favorable','beneficial'
])
NEG_WORDS = set([
    'bad','worse','worst','negative','sad','unfortunate','wrong','terrible','awful','hate','poor','harmful','angry','problem'
])

def sentence_sentiment_fallback(sent):
    """Return a rough normalized score in [-1,1] based on tiny lexicon counts."""
    if not sent:
        return 0.0
    words = [w.lower() for w in token_re.findall(sent)]
    if not words:
        return 0.0
    pos = sum(1 for w in words if w in POS_WORDS)
    neg = sum(1 for w in words if w in NEG_WORDS)
    return (pos - neg) / max(1, len(words))

# ---------- core computation ----------
def compute_max_adjs_and_sentiment(df, text_col=TEXT_COL):
    texts = df[text_col].fillna("").astype(str).apply(clean_text).tolist()

    max_adjs_list = []
    norm_sent_list = []
    neg_sent_count_list = []
    pos_sent_count_list = []

    if USE_SPACY:
        # spaCy path: reliable POS and sentence splitting
        for doc in tqdm(nlp.pipe(texts, batch_size=64), total=len(texts), desc='Parsing (spaCy)'):
            sent_adjs = []
            sent_scores = []
            for sent in doc.sents:
                # count adjectives in this sentence
                a_count = sum(1 for tok in sent if not tok.is_punct and tok.pos_ == 'ADJ')
                sent_adjs.append(a_count)
                # sentence sentiment
                s_text = sent.text
                if USE_VADER:
                    sc = vader.polarity_scores(s_text)['compound']
                else:
                    sc = sentence_sentiment_fallback(s_text)
                sent_scores.append(sc)
            # results for this article
            max_adjs = int(max(sent_adjs)) if sent_adjs else 0
            norm_sent = float(np.mean(sent_scores)) if sent_scores else 0.0
            neg_cnt = int(sum(1 for s in sent_scores if s <= NEG_SENT_THRESH))
            pos_cnt = int(sum(1 for s in sent_scores if s >= POS_SENT_THRESH))

            max_adjs_list.append(max_adjs)
            norm_sent_list.append(norm_sent)
            neg_sent_count_list.append(neg_cnt)
            pos_sent_count_list.append(pos_cnt)
    else:
        # heuristic path: regex sentence split + suffix adjective heuristic
        for t in tqdm(texts, total=len(texts), desc='Parsing (heuristic)'):
            sents = re.split(r'(?<=[\.\?\!])\s+', t) if t else []
            sent_adjs = []
            sent_scores = []
            for s in sents:
                s = s.strip()
                if not s:
                    continue
                a_count = count_adjs_in_sentence_heuristic(s)
                sent_adjs.append(a_count)
                if USE_VADER:
                    sc = vader.polarity_scores(s)['compound']
                else:
                    sc = sentence_sentiment_fallback(s)
                sent_scores.append(sc)
            max_adjs = int(max(sent_adjs)) if sent_adjs else 0
            norm_sent = float(np.mean(sent_scores)) if sent_scores else 0.0
            neg_cnt = int(sum(1 for s in sent_scores if s <= NEG_SENT_THRESH))
            pos_cnt = int(sum(1 for s in sent_scores if s >= POS_SENT_THRESH))

            max_adjs_list.append(max_adjs)
            norm_sent_list.append(norm_sent)
            neg_sent_count_list.append(neg_cnt)
            pos_sent_count_list.append(pos_cnt)

    # attach to DataFrame
    out = df.copy()
    out['max_adjs_per_sentence'] = max_adjs_list
    out['normalized_sentiment'] = norm_sent_list
    out['num_negative_sentences'] = neg_sent_count_list
    out['num_highly_positive_sentences'] = pos_sent_count_list
    return out

# ---------- plotting ----------
def plot_boxplots(df, label_col=LABEL_COL):
    sns.set(style='whitegrid')
    fig, axes = plt.subplots(1, 2, figsize=(14,6))
    sns.boxplot(x=label_col, y='max_adjs_per_sentence', data=df, ax=axes[0])
    axes[0].set_title('Max Adjectives per Sentence by Bias')
    axes[0].set_xlabel('Bias Label')
    axes[0].set_ylabel('Max adjectives in any sentence')

    sns.boxplot(x=label_col, y='normalized_sentiment', data=df, ax=axes[1])
    axes[1].set_title('Normalized Sentiment (mean sentence score) by Bias')
    axes[1].set_xlabel('Bias Label')
    axes[1].set_ylabel('Normalized sentiment (approx. -1..1)')

    plt.tight_layout()
    fig.savefig(OUTPUT_FIG, dpi=200)
    print("Saved boxplots to", OUTPUT_FIG)
    plt.show()

# ---------- main ----------
if __name__ == '__main__':
    df = robust_read_csv(INPUT_CSV)
    if TEXT_COL not in df.columns:
        raise RuntimeError(f"CSV must contain '{TEXT_COL}' column. Found: {df.columns.tolist()}")
    if LABEL_COL not in df.columns:
        raise RuntimeError(f"CSV must contain '{LABEL_COL}' column. Found: {df.columns.tolist()}")

    print("Computing max adjectives per sentence and normalized sentiment...")
    df_out = compute_max_adjs_and_sentiment(df, text_col=TEXT_COL)

    df_out.to_csv(OUTPUT_CSV, index=False)
    print("Saved output CSV:", OUTPUT_CSV)

    # quick preview
    print("\nGroup medians (preview):")
    print(df_out.groupby(LABEL_COL)[['max_adjs_per_sentence','normalized_sentiment',
                                     'num_negative_sentences','num_highly_positive_sentences']].median().round(4))
    # plot
    plot_boxplots(df_out, label_col=LABEL_COL)
    print("Done.")
