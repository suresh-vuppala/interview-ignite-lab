## Binary Tree Core Operations

**Insert:** Add node at first available position (level order) — O(n) BFS.
**Search:** Traverse entire tree (no ordering like BST) — O(n).
**Delete:** Find node, replace with deepest rightmost node, delete that — O(n).
**Update:** Search then modify — O(n).

Unlike BST where operations are O(log n), basic binary tree operations are all O(n) since there's no ordering property.

<br>

---

## Complexity Summary

| Operation | Time | Space |
|-----------|------|-------|
| Insert | O(n) | O(n) BFS |
| Search | O(n) | O(h) DFS or O(n) BFS |
| Delete | O(n) | O(n) |
| Update | O(n) | O(h) |

<br>
<br>

---

```code```
