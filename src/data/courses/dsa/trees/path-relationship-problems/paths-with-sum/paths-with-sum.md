Find all downward paths with given sum (similar to count-paths-with-sum but return paths).

<br>

---

## Solution 1: DFS from Every Node — O(n²)
## Solution 2: Prefix Sum + Backtracking — O(n)

Same technique as count-paths-with-sum but collect actual paths.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| DFS all starts | O(n²) | O(n²) | Track paths from each node |
| Prefix Sum | O(n) | O(n) | Hash map path detection |

<br>
<br>

---

```code```
