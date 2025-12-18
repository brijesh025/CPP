# metrics_boxplots.py
import pandas as pd
import re, string
import matplotlib.pyplot as plt
import seaborn as sns
import numpy as np
from io import StringIO
from tqdm import tqdm

# ---------- CONFIG ----------
INPUT_CSV = 'bias_clean.csv'
TEXT_COL = 'page_text'
LABEL_COL = 'bias'
OUTPUT_CSV = 'bias_metrics.csv'
OUTPUT_FIG = 'metrics_boxplots.png'
# ----------------------------

# ---------- Optional libs ----------
USE_SPACY = False
try:
    import spacy
    try:
        nlp = spacy.load('en_core_web_sm', disable=['ner'])
        USE_SPACY = True
        print("INFO: spaCy model loaded — using spaCy for adjective detection.")
    except Exception:
        print("WARN: spaCy model not found — using heuristic adjective detector.")
        USE_SPACY = False
except Exception:
    print("WARN: spaCy not installed — using heuristic adjective detector.")
    USE_SPACY = False

USE_TEXTSTAT = False
try:
    import textstat
    USE_TEXTSTAT = True
    print("INFO: textstat found — using it for Flesch score.")
except Exception:
    print("WARN: textstat not installed — using heuristic Flesch calculation.")
    USE_TEXTSTAT = False

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

# punctuation
EXTRA_PUNCT = {'—','–','…','“','”','‘','’'}
PUNCT_SET = set(string.punctuation) | EXTRA_PUNCT
def count_puncts(text):
    if not text:
        return 0
    return sum(1 for ch in text if ch in PUNCT_SET)

# token regex
token_re = re.compile(r"[A-Za-z]+(?:'[A-Za-z]+)?")

# adjective heuristic suffixes
ADJ_SUFFIXES = ('able','al','ful','ic','ive','ous','ish','less','ary','ant','ent','like','y','est','ier')

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

def count_adjs_spacy(doc):
    tokens = [t for t in doc if not t.is_punct and not t.is_space]
    num_adjs = sum(1 for t in tokens if t.pos_ == 'ADJ')
    num_words = len([t for t in doc if t.is_alpha])
    return num_adjs, num_words

# syllable heuristic and flesch
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
    total_syl = sum(syllable_count(w) for w in words)
    syl_per_word = total_syl / W
    words_per_sent = W / S
    flesch = 206.835 - 1.015 * words_per_sent - 84.6 * syl_per_word
    return flesch, W

# ---------- main compute ----------
def compute_metrics(df):
    texts = df[TEXT_COL].fillna("").astype(str).apply(clean_text).tolist()
    adjs = []
    adjs_per100 = []
    puncts = []
    puncts_per100 = []
    flesches = []

    if USE_SPACY:
        for doc in tqdm(nlp.pipe(texts, batch_size=64), total=len(texts), desc='Parsing (spaCy)'):
            t = doc.text
            a_count, nwords = count_adjs_spacy(doc)
            p_count = count_puncts(t)
            if USE_TEXTSTAT:
                try:
                    flesch_score = float(textstat.flesch_reading_ease(t))
                except Exception:
                    flesch_score, _ = flesch_heuristic(t)
            else:
                flesch_score, _ = flesch_heuristic(t)

            adjs.append(a_count)
            adjs_per100.append((a_count / nwords * 100.0) if nwords>0 else 0.0)
            puncts.append(p_count)
            puncts_per100.append((p_count / nwords * 100.0) if nwords>0 else 0.0)
            flesches.append(flesch_score)
    else:
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

            adjs.append(a_count)
            adjs_per100.append((a_count / nwords * 100.0) if nwords>0 else 0.0)
            puncts.append(p_count)
            puncts_per100.append((p_count / nwords * 100.0) if nwords>0 else 0.0)
            flesches.append(flesch_score)

    df2 = df.copy()
    df2['num_adjectives'] = adjs
    df2['adjs_per_100_words'] = adjs_per100
    df2['punct_total'] = puncts
    df2['punct_per_100_words'] = puncts_per100
    df2['flesch_reading_ease'] = flesches
    return df2

# ---------- plotting boxplots (three plots stacked horizontally) ----------
def plot_boxplots(df, label_col=LABEL_COL):
    sns.set(style='whitegrid')
    metrics = [
        ('adjs_per_100_words', 'Adjective density (per 100 words)'),
        ('punct_per_100_words', 'Punctuation density (per 100 words)'),
        ('flesch_reading_ease', 'Flesch Reading Ease (higher = easier)')
    ]
    labels = sorted(df[label_col].dropna().unique())
    fig, axes = plt.subplots(1, 3, figsize=(16,6))
    for ax, (col, title) in zip(axes, metrics):
        sns.boxplot(x=label_col, y=col, data=df, ax=ax)
        ax.set_title(title)
        ax.set_xlabel('Political Leaning')
        ax.set_ylabel('Value')
        # adjust y-grid and formatting similar to your example
        ax.yaxis.grid(True, linestyle='--', linewidth=0.4)
    plt.tight_layout()
    plt.savefig(OUTPUT_FIG, dpi=200)
    print("Saved boxplot figure to", OUTPUT_FIG)
    plt.show()

# ---------- run ----------
if __name__ == '__main__':
    df = robust_read_csv(INPUT_CSV)
    if TEXT_COL not in df.columns:
        raise RuntimeError(f"CSV must contain '{TEXT_COL}' column. Found: {df.columns.tolist()}")
    if LABEL_COL not in df.columns:
        raise RuntimeError(f"CSV must contain '{LABEL_COL}' column. Found: {df.columns.tolist()}")

    print("Computing metrics...")
    df_metrics = compute_metrics(df)
    df_metrics.to_csv(OUTPUT_CSV, index=False)
    print("Saved metrics CSV:", OUTPUT_CSV)

    print("\nGroup medians (preview):")
    print(df_metrics.groupby(LABEL_COL)[['adjs_per_100_words','punct_per_100_words','flesch_reading_ease']].median().round(3))

    plot_boxplots(df_metrics, label_col=LABEL_COL)
