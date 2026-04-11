Two nodes in BST are swapped. Fix the BST.

<br>

---

## Solution 1: Inorder → Array — Find two violations in sorted order, swap

### Time: O(n) | Space: O(n)

<br>

---

## Solution 2: Morris Traversal (Optimal)

Inorder traversal tracking prev. First violation: prev > curr → first = prev. Second violation: prev > curr → second = curr. Swap values.

### Time: O(n) | Space: O(1) with Morris

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Inorder Array | O(n) | O(n) | Find violations in sorted order |
| Morris | O(n) | O(1) | Track violations during O(1) space traversal |

<br>
<br>

---

```code```
