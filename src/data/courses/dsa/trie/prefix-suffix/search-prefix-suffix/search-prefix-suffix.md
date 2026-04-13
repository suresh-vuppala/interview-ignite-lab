Find words matching both a prefix and suffix pattern.

<br>

> words=['apple'], prefix='a', suffix='e' → ['apple']
>
> **Key insight:** Insert all suffix#word combinations into trie. Query suffix#prefix in trie.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: Check each word for both conditions

### Time Complexity: O(N×L)

> **Drawback:**
> Linear scan — acceptable but trie enables faster repeated queries.

> **Key Insight for Improvement:**
> Trick: for each word, insert all suffix#word variants. Query suffix#prefix finds matches.

<br>

---

## Solution 2: Suffix#Word Trie (Optimal)

**Intuition:** Insert all suffix#word combinations into trie. Query suffix#prefix in trie.

**Algorithm:**
Insert: for word 'apple', insert 'e#apple','le#apple','ple#apple','pple#apple','apple#apple'
Query: search 'e#a' prefix in trie → finds 'apple'

### Time Complexity: O(N×L²) build, O(L) query
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
word='apple': insert 'e#apple' etc. Query suffix='e',prefix='a' → search 'e#a' in trie → found
```

### Space Complexity: O(N×L²)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Check each word for both conditions | O(N×L) | Varies | Baseline |
| Suffix#Word Trie | O(N×L²) build, O(L) query | O(N×L²) | Optimal |

**Recommended Solution:** Suffix#Word Trie

**Key Insights:**
1. **suffix#word trick:** Encodes both prefix and suffix into single trie path
2. **Space tradeoff:** L² insertions per word but O(L) queries
3. **LeetCode 745:** WordFilter problem

<br><br>

---

```code```
