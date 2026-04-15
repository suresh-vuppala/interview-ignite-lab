For each word, compute sum of scores where score of prefix = count of words having that prefix.

<br>

> words=['abc','ab','b'] → [5,4,1]
>
> **Key insight:** Same as prefix-score problem. Trie with count, sum counts along each word's path.

<br>

---

## Constraints
- 1 ≤ N ≤ 1000
- 1 ≤ word.length ≤ 1000

<br>

---

## All Possible Edge Cases
1. **All words share a prefix: high scores
2. **No shared prefixes: each score = word length**

<br>

---

## Solution 1: Count each prefix manually

**Intuition:**
The most straightforward approach. Checking each prefix against all words.

**Algorithm:**
1. Enumerate all possible candidates
2. For each candidate, verify if it satisfies the condition
3. Track the best valid result
4. Return the optimal answer

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
> Checking each prefix against all words.

> **Key Insight for Improvement:**
> Trie path sum: insert all with counting, then sum counts for each word's path.

<br>

---

## Solution 2: Trie Path Sum (Optimal)

**Intuition:** Same as prefix-score problem. Trie with count, sum counts along each word's path.

**Algorithm:**
Same as prefix-score

### Time Complexity: O(N×L)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
Same as prefix-score
```

### Space Complexity: O(N×L)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Count each prefix manually | O(N²×L) | Varies | Baseline |
| Trie Path Sum | O(N×L) | O(N×L) | Optimal |

**Recommended Solution:** Trie Path Sum

**Key Insights:**
1. **Same as prefix-score:** Identical problem

<br><br>

---

```code```
