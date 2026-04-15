Replace words in sentence with their shortest root from a dictionary.

<br>

> dict=['cat','bat','rat'], sentence='the cattle was rattled' → 'the cat was rat'
>
> **Key insight:** Build trie from dictionary roots. For each word in sentence, find shortest prefix match in trie.

<br>

---

## Constraints
- 1 ≤ dict.length ≤ 1000
- 1 ≤ sentence words ≤ 1000

<br>

---

## All Possible Edge Cases
1. **No root matches: sentence unchanged**
2. **Multiple roots match same word: use shortest
3. **Root = entire word**

<br>

---

## Solution 1: Check each root against each word

**Intuition:**
The most straightforward approach. Checking every root against every word is slow.

**Algorithm:**
1. Enumerate all possible candidates
2. For each candidate, verify if it satisfies the condition
3. Track the best valid result
4. Return the optimal answer

### Time Complexity: O(D×N×L)
**Why?**
Two factors multiply: one from iterating elements, one from the operation per element.
Total = product of both factors.

**Detailed breakdown:**
Depends on both dimensions of the input.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Checking every root against every word is slow.

> **Key Insight for Improvement:**
> Trie of roots: for each word, traverse trie char by char. First isEnd hit = shortest root found.

<br>

---

## Solution 2: Trie Prefix Match (Optimal)

**Intuition:** Build trie from dictionary roots. For each word in sentence, find shortest prefix match in trie.

**Algorithm:**
1. Build trie from dictionary roots
2. For each word in sentence:
   - Walk trie char by char
   - If isEnd reached → replace with root
   - If no match → keep original word

### Time Complexity: O(N×L)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
Trie: c→a→t(end), b→a→t(end), r→a→t(end)
'cattle': c→a→t(end!) → replace with 'cat'
'rattled': r→a→t(end!) → replace with 'rat'
```

### Space Complexity: O(D×L)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Check each root against each word | O(D×N×L) | Varies | Baseline |
| Trie Prefix Match | O(N×L) | O(D×L) | Optimal |

**Recommended Solution:** Trie Prefix Match

**Key Insights:**
1. **Shortest prefix:** Trie finds it by stopping at first isEnd
2. **O(L) per word:** Only traverse word length, not entire dictionary
3. **LeetCode 648:** Medium — clean trie application

<br><br>

---

```code```
