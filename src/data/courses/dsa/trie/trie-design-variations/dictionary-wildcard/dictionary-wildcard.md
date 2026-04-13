Dictionary supporting wildcard '.' search.

<br>

> Same as search-wildcard — AddWord/SearchWord design
>
> **Key insight:** Same DFS branching on '.' in trie.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: Linear scan all words

### Time Complexity: O(N×L)

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
