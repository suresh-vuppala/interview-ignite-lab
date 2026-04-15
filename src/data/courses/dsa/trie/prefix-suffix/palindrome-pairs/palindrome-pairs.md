Find all index pairs where words[i]+words[j] forms a palindrome.

<br>

> words=['abcd','dcba','lls','s','sssll'] → [[0,1],[1,0],[3,2],[2,4]]
>
> **Key insight:** Trie of reversed words. For each word, check if a prefix matches a reversed word AND remaining suffix is palindrome.

<br>

---

## Constraints
- 1 ≤ N ≤ 5000
- 0 ≤ word.length ≤ 300

<br>

---

## All Possible Edge Cases
1. **Empty string: pairs with any palindrome word
2. **Reverse pairs: "abc" and "cba"
3. **Single character words**

<br>

---

## Solution 1: Check all pairs

**Intuition:**
The most straightforward approach. Quadratic pair checking × length.

**Algorithm:**
1. For each element i (outer loop):
   - For each element j (inner loop):
     - Check if the pair/condition is satisfied
2. Return the best result found

### Time Complexity: O(N²×L)
**Why?**
Two nested loops each running up to N iterations.
Outer loop: N iterations × Inner loop: up to N iterations = N² total operations.

**Detailed breakdown:**
For N=1,000: ~1 million operations (OK). For N=10,000: ~100 million (borderline TLE).

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Quadratic pair checking × length.

> **Key Insight for Improvement:**
> Trie of reversed words: walk each word through trie. At each node, check if remaining suffix is palindrome. At word end, check if trie has longer reversed words with palindrome prefix.

<br>

---

## Solution 2: Reverse Trie + Palindrome Check (Optimal)

**Intuition:** Trie of reversed words. For each word, check if a prefix matches a reversed word AND remaining suffix is palindrome.

**Algorithm:**
1. Insert all reversed words into trie (with index)
2. For each word: walk through trie
   - At each node with isEnd: check if remaining word suffix is palindrome
   - At word end: check trie subtree for words with palindromic remaining parts

### Time Complexity: O(N×L²)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
words=['abcd','dcba']: reversed trie has 'dcba'→idx0, 'abcd'→idx1
'abcd' walks reversed trie: matches 'abcd'(reversed of 'dcba') → pair [0,1]
```

### Space Complexity: O(N×L)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Check all pairs | O(N²×L) | Varies | Baseline |
| Reverse Trie + Palindrome Check | O(N×L²) | O(N×L) | Optimal |

**Recommended Solution:** Reverse Trie + Palindrome Check

**Key Insights:**
1. **Reverse trie:** Enables suffix matching for palindrome concatenation
2. **Palindrome suffix check:** O(L) per check
3. **Three cases:** Equal length, word shorter, word longer

<br><br>

---

```code```
