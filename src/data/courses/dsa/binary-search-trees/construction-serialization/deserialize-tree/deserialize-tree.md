Deserialize — reconstruct tree from serialized string. See serialize-tree.

<br>

---

## Solution 1: Preorder Token Parsing — Parse tokens recursively, "#" = null
## Solution 2: Level-Order Queue — Parse tokens into BFS queue reconstruction

### Time: O(n) | Space: O(n)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Preorder Parse | O(n) | O(n) | Recursive token consumption |
| BFS Parse | O(n) | O(n) | Queue-based reconstruction |

<br>
<br>

---

```code```
