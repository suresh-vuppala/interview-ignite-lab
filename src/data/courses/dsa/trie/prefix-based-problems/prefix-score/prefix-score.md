Sum of counts of prefixes of each word across all words.

<br>

> words=['abc','ab','b'] → scores based on prefix counts
>
> **Key insight:** Trie with count at each node. For each word, sum counts along its path = total prefix score.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: Check each prefix against all words

### Time Complexity: O(N²×L)

> **Drawback:**
> Quadratic — checking all prefixes against all words.

> **Key Insight for Improvement:**
> Trie: insert all words (incrementing count at each node). For each word, sum of counts along path = score.

<br>

---

## Solution 2: Trie Path Sum (Optimal)

**Intuition:** Trie with count at each node. For each word, sum counts along its path = total prefix score.

**Algorithm:**
1. Insert all words into trie, counting at each node
2. For each word: walk path, sum node.count values

### Time Complexity: O(N×L)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
words=['abc','ab','b']: a(2)→b(2)→c(1)
'abc': 2+2+1=5, 'ab': 2+2=4, 'b': 1
```

### Space Complexity: O(N×L)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Check each prefix against all words | O(N²×L) | Varies | Baseline |
| Trie Path Sum | O(N×L) | O(N×L) | Optimal |

**Recommended Solution:** Trie Path Sum

**Key Insights:**
1. **Count at node = words passing through:** Prefix popularity
2. **Sum along path = score:** Total prefix matches

<br><br>

---

```code```
