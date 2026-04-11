Vertical order traversal — group by horizontal distance, ordered by level.

<br>

---

## Solution 1: BFS + TreeMap — Track (HD, level) → values. Use TreeMap for sorted HD.

### Time: O(n log n) | Space: O(n)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| BFS + TreeMap | O(n log n) | O(n) | Sorted by HD then level |

<br>
<br>

---

```code```
