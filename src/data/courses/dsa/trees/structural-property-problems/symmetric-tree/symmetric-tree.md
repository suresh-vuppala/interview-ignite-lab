Check if a binary tree is symmetric (mirror of itself).

<br>

> Input: [1,2,2,3,4,4,3] → true

<br>

---

## Solution 1: Recursive

**Intuition:** A tree is symmetric if left subtree is a mirror of right subtree. Mirror check: left.val == right.val AND isMirror(left.left, right.right) AND isMirror(left.right, right.left).

### Time: O(n) | Space: O(h)

<br>

---

## Solution 2: Iterative (Queue)

Enqueue pairs: (left.left, right.right) and (left.right, right.left). Compare pairs.

### Time: O(n) | Space: O(n)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursive | O(n) | O(h) | Mirror comparison |
| Iterative | O(n) | O(n) | Queue pair comparison |

<br>
<br>

---

```code```
