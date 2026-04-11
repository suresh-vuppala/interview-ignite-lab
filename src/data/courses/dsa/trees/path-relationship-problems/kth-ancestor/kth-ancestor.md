Find the kth ancestor of a given node.

<br>

---

## Solution 1: Parent Pointer — Walk up k times

Store parent pointers (or find path from root). Walk up k steps.

### Time: O(n + k) | Space: O(n)

<br>

---

## Solution 2: Binary Lifting (for repeated queries)

Preprocess: ancestor[i][j] = 2^j-th ancestor of node i. Answer query in O(log k).

### Time: O(n log n) preprocess, O(log k) per query
### Space: O(n log n)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Parent Walk | O(n+k) | O(n) | Simple traversal |
| Binary Lifting | O(log k) query | O(n log n) | Preprocessing for repeated queries |

<br>
<br>

---

```code```
