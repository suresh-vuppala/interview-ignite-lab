Flatten binary tree to linked list (preorder) in-place using right pointers.

<br>

> Input: [1,2,5,3,4,null,6]
> Output: 1→2→3→4→5→6 (right pointers)

<br>

---

## Solution 1: Preorder → Array → Relink

Collect preorder traversal, relink nodes.

### Time: O(n) | Space: O(n)

<br>

---

## Solution 2: Reverse Postorder (Optimal)

**Intuition:** Process right → left → root (reverse preorder). Maintain a `prev` pointer. Set current.right = prev, current.left = null.

### Time: O(n) | Space: O(h)

<br>

---

## Solution 3: Morris-Style O(1) Space

For each node with a left child: find rightmost node in left subtree, connect it to current.right. Move left subtree to right, set left to null.

### Time: O(n) | Space: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Array | O(n) | O(n) | Preorder → relink |
| Reverse Post | O(n) | O(h) | Process right-to-left |
| Morris-Style | O(n) | O(1) | Thread left subtree to right |

<br>
<br>

---

```code```
