Check if two binary trees are structurally identical with same values.

<br>

---

## Solution 1: Recursive

Same structure: both null → true, one null → false, vals differ → false, recurse on children.

### Time: O(n) | Space: O(h)

<br>

---

## Solution 2: Iterative (BFS with Two Queues)

Pair nodes from both trees in queues, compare level by level.

### Time: O(n) | Space: O(n)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursive | O(n) | O(h) | Natural comparison |
| Iterative BFS | O(n) | O(n) | Queue-based pairing |

<br>
<br>

---

```code```
