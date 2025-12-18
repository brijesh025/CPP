# metrics_three_features.py
import pandas as pd
import re, string
import matplotlib.pyplot as plt
import seaborn as sns
import numpy as np
from tqdm import tqdm
from io import StringIO

# ---------- CONFIG ----------
INPUT_CSV = 'bias_clean.csv'   # change if your file name differs
TEXT_COL = 'page_text'
LABEL_COL = 'bias'
OUTPUT_CSV = 'bias_metrics.csv'
OUTPUT_FIG = 'metrics_avg_barplots.png'
# ----------------------------

# ---------- try optional libs ----------
USE_SPACY = False
try:
    import spacy
    try:
        nlp = spacy.load('en_core_web_sm', disable=['ner'])
        USE_SPACY = True
        print("INFO: spaCy model loaded — using spaCy for adjective detection.")
    except Exception:
        print("WARN: spaCy installed but en_core_web_sm not found; falling back to heuristic adjective detector.")
        USE_SPACY = False
except Exception:
    print("WARN: spaCy not installed; falling back to heuristic adjective detector.")
    USE_SPACY = False

USE_TEXTSTAT = False
try:
    import textstat
    USE_TEXTSTAT = True
    print("INFO: textstat available — using textstat for readability.")
except Exception:
    print("WARN: textstat not installed — using heuristic Flesch computation.")
    USE_TEXTSTAT = False

# ---------- helpers ----------
def robust_read_csv(path):
    encodings = ['utf-8', 'utf-8-sig', 'latin1', 'cp1252']
    for e in encodings:
        try:
            df = pd.read_csv(path, encoding=e)
            print(f"Loaded CSV with encoding: {e}")
            return df
        except Exception:
            pass
    # fallback: decode with replacement to avoid crash
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

# punctuation set (common)
EXTRA_PUNCT = {'—','–','…','“','”','‘','’'}
PUNCT_SET = set(string.punctuation) | EXTRA_PUNCT

def count_puncts(text):
    if not text:
        return 0
    return sum(1 for ch in text if ch in PUNCT_SET)

# --- adjective counting ---
ADJ_SUFFIXES = ('able','al','ful','ic','ive','ous','ish','less','ary','ant','ent','like','y','est','ier')
token_re = re.compile(r"[A-Za-z]+(?:'[A-Za-z]+)?")

def count_adjs_spacy(doc):
    tokens = [t for t in doc if not t.is_punct and not t.is_space]
    num_adjs = sum(1 for t in tokens if t.pos_ == 'ADJ')
    num_words = len([t for t in doc if t.is_alpha])
    return num_adjs, num_words

def count_adjs_heuristic(text):
    toks = token_re.findall(text.lower())
    num_words = len(toks)
    num_adjs = 0
    for w in toks:
        for suf in ADJ_SUFFIXES:
            if w.endswith(suf) and len(w) > len(suf) + 1:
                num_adjs += 1
                break
    return num_adjs, num_words

# ---------- readability fallback ----------
def syllable_count(word):
    w = re.sub(r'[^a-z]', '', word.lower())
    if not w:
        return 0
    if len(w) <= 3:
        return 1
    groups = re.findall(r'[aeiouy]+', w)
    count = len(groups)
    if w.endswith('e') and not (w.endswith('le') and len(w) > 2 and w[-3] not in 'aeiouy'):
        count -= 1
    if (w.endswith('es') or w.endswith('ed')) and len(groups) > 1:
        count -= 1
    return max(1, count)

def flesch_heuristic(text):
    words = token_re.findall(text)
    W = len(words)
    sents = re.split(r'(?<=[\.\?\!])\s+', text) if text else []
    S = len([s for s in sents if s.strip()])
    S = max(1, S)
    W = max(1, W)
    total_syll = sum(syllable_count(w) for w in words)
    syl_per_word = total_syll / W
    words_per_sent = W / S
    flesch = 206.835 - 1.015 * words_per_sent - 84.6 * syl_per_word
    return flesch, W

# ---------- main processing ----------
def compute_features(df, text_col=TEXT_COL):
    texts = df[text_col].fillna("").astype(str).apply(clean_text).tolist()
    # results lists
    num_adjs_list = []
    adjs_per_100_list = []
    punct_total_list = []
    punct_per_100_list = []
    flesch_list = []

    if USE_SPACY:
        # use spaCy pipe
        for doc in tqdm(nlp.pipe(texts, batch_size=64), total=len(texts), desc='Parsing (spaCy)'):
            t = doc.text
            a_count, nwords = count_adjs_spacy(doc)
            p_count = count_puncts(t)
            # readability
            if USE_TEXTSTAT:
                try:
                    flesch_score = float(textstat.flesch_reading_ease(t))
                except Exception:
                    flesch_score, _ = flesch_heuristic(t)
            else:
                flesch_score, _ = flesch_heuristic(t)

            num_adjs_list.append(a_count)
            adjs_per_100_list.append((a_count / nwords * 100.0) if nwords>0 else 0.0)
            punct_total_list.append(p_count)
            punct_per_100_list.append((p_count / nwords * 100.0) if nwords>0 else 0.0)
            flesch_list.append(flesch_score)
    else:
        # heuristic path (no heavy libs)
        for t in tqdm(texts, total=len(texts), desc='Parsing (heuristic)'):
            a_count, nwords = count_adjs_heuristic(t)
            p_count = count_puncts(t)
            if USE_TEXTSTAT:
                try:
                    flesch_score = float(textstat.flesch_reading_ease(t))
                except Exception:
                    flesch_score, _ = flesch_heuristic(t)
            else:
                flesch_score, _ = flesch_heuristic(t)

            num_adjs_list.append(a_count)
            adjs_per_100_list.append((a_count / nwords * 100.0) if nwords>0 else 0.0)
            punct_total_list.append(p_count)
            punct_per_100_list.append((p_count / nwords * 100.0) if nwords>0 else 0.0)
            flesch_list.append(flesch_score)

    df_features = df.copy()
    df_features['num_adjectives'] = num_adjs_list
    df_features['adjs_per_100_words'] = adjs_per_100_list
    df_features['punct_total'] = punct_total_list
    df_features['punct_per_100_words'] = punct_per_100_list
    df_features['flesch_reading_ease'] = flesch_list

    return df_features

# ---------- plotting (3 subplots: mean per bias) ----------
def plot_means(df, label_col=LABEL_COL):
    metrics = [
        ('adjs_per_100_words', 'Adjectives per 100 words'),
        ('punct_per_100_words', 'Punctuation per 100 words'),
        ('flesch_reading_ease', 'Flesch Reading Ease')
    ]
    labels = sorted(df[label_col].dropna().unique())
    fig, axes = plt.subplots(1, 3, figsize=(16,5))
    colors = ['#4c72b0','#55a868','#c44e52']  # color cycle
    for ax, (col, title) in zip(axes, metrics):
        means = df.groupby(label_col)[col].mean().reindex(labels)
        means = means.fillna(0)
        ax.bar(labels, means.values, color=[colors[i%len(colors)] for i in range(len(labels))])
        ax.set_title(title)
        ax.set_xlabel('Bias')
        ax.set_ylabel('Mean')
        for i, v in enumerate(means.values):
            ax.text(i, v + (0.01 * max(1.0, v)), f"{v:.2f}", ha='center', fontsize=9)
    plt.tight_layout()
    plt.savefig(OUTPUT_FIG, dpi=200)
    print("Saved plot to", OUTPUT_FIG)
    plt.show()

# ---------- run ----------
if __name__ == '__main__':
    df = robust_read_csv(INPUT_CSV)
    if TEXT_COL not in df.columns:
        raise RuntimeError(f"CSV must contain '{TEXT_COL}' column. Columns found: {df.columns.tolist()}")
    if LABEL_COL not in df.columns:
        raise RuntimeError(f"CSV must contain '{LABEL_COL}' column. Columns found: {df.columns.tolist()}")

    print("Computing features (adjective, punctuation, readability)...")
    df_features = compute_features(df, text_col=TEXT_COL)
    df_features.to_csv(OUTPUT_CSV, index=False)
    print("Saved features CSV:", OUTPUT_CSV)

    print("\nGroup means (preview):")
    preview = df_features.groupby(LABEL_COL)[['adjs_per_100_words','punct_per_100_words','flesch_reading_ease']].mean().round(4)
    print(preview)

    plot_means(df_features, label_col=LABEL_COL)
