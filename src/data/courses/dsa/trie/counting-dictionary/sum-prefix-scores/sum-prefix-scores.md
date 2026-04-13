For each word, compute sum of scores where score of prefix = count of words having that prefix.

<br>

> words=['abc','ab','b'] → [5,4,1]
>
> **Key insight:** Same as prefix-score problem. Trie with count, sum counts along each word's path.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: Count each prefix manually

### Time Complexity: O(N²×L)

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
