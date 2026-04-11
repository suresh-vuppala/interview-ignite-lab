Find the maximum width of a binary tree (max number of nodes between leftmost and rightmost non-null nodes at any level, including nulls between them).

<br>

---

## Solution 1: BFS with Index Tracking

**Intuition:** Assign indices: root=0, left child=2i+1, right child=2i+2. Width at any level = rightmost index - leftmost index + 1.

**Important:** Normalize indices per level to prevent overflow (subtract minimum index at each level).

### Time: O(n) | Space: O(n)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| BFS + Indexing | O(n) | O(n) | Track positional indices |

<br>
<br>

---

```code```
