Dictionary supporting wildcard '.' search.

<br>

> Same as search-wildcard — AddWord/SearchWord design
>
> **Key insight:** Same DFS branching on '.' in trie.

<br>

---

## Constraints
- Same as search-wildcard

<br>

---

## All Possible Edge Cases
1. **Same as search-wildcard**

<br>

---

## Solution 1: Linear scan all words

**Intuition:**
The most straightforward approach. Slow for repeated queries.

**Algorithm:**
1. Scan through each element from left to right
2. For each element, check the required condition
3. Track and return the best result

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
> Slow for repeated queries.

> **Key Insight for Improvement:**
> Trie + DFS branching on '.'

<br>

---

## Solution 2: DFS Trie (Optimal)

**Intuition:** Same DFS branching on '.' in trie.

**Algorithm:**
Same as search-wildcard

### Time Complexity: O(26^dots × L)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
Same as search-wildcard
```

### Space Complexity: O(N×L)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Linear scan all words | O(N×L) | Varies | Baseline |
| DFS Trie | O(26^dots × L) | O(N×L) | Optimal |

**Recommended Solution:** DFS Trie

**Key Insights:**
1. **Same as search-wildcard / LeetCode 211**

<br><br>

---

```code```
