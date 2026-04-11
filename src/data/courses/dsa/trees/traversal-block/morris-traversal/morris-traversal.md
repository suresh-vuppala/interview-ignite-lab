Inorder traversal with O(1) space using Morris Traversal (threading).

<br>

---

## Solution 1: Standard Recursive — O(n) time, O(h) space
## Solution 2: Morris Traversal (Optimal)

**Intuition:** Temporarily modify tree: thread inorder predecessor's right to current node. This creates a "path back" without using a stack.

**Algorithm:**
1. While current != null:
   - If no left child → visit current, go right
   - If left child exists:
     - Find inorder predecessor (rightmost in left subtree)
     - If predecessor.right is null → thread to current, go left
     - If predecessor.right is current → unthread, visit current, go right

### Time: O(n) | Space: O(1) — no stack/recursion

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursive | O(n) | O(h) | Standard |
| Morris | O(n) | O(1) | Threading eliminates stack |

<br>
<br>

---

```code```
