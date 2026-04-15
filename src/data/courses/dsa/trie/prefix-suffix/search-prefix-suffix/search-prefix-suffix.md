Find words matching both a prefix and suffix pattern.

<br>

> words=['apple'], prefix='a', suffix='e' → ['apple']
>
> **Key insight:** Insert all suffix#word combinations into trie. Query suffix#prefix in trie.

<br>

---

## Constraints
- 1 ≤ N ≤ 10⁴
- 1 ≤ word.length ≤ 7

<br>

---

## All Possible Edge Cases
1. **No match for both prefix AND suffix
2. **Word = prefix = suffix
3. **Empty prefix or suffix**

<br>

---

## Solution 1: Check each word for both conditions

**Intuition:**
The most straightforward approach. Linear scan — acceptable but trie enables faster repeated queries.

**Algorithm:**
1. Enumerate all possible candidates
2. For each candidate, verify if it satisfies the condition
3. Track the best valid result
4. Return the optimal answer

### Time Complexity: O(N×L)
**Why?**
Two factors multiply: one from iterating elements, one from the operation per element.
Total = product of both factors.

**Detailed breakdown:**
Depends on both dimensions of the input.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

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
