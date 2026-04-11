## BST Core Operations

| Operation | Average | Worst (Skewed) |
|-----------|---------|----------------|
| Search | O(log n) | O(n) |
| Insert | O(log n) | O(n) |
| Delete | O(log n) | O(n) |
| Min/Max | O(log n) | O(n) |

**Delete cases:** Leaf → remove. One child → replace with child. Two children → replace with inorder successor/predecessor.

<br>
<br>

---

```code```
