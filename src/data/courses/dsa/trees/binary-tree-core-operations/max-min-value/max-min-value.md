## Overview
Find the maximum and minimum values in a binary tree by traversing all nodes.

## Problem Statement
Given a binary tree, find both the maximum and minimum node values.

## Approach
- Traverse all nodes (preorder, inorder, or postorder)
- Track min and max during traversal
- Can use recursion or iteration with queue/stack

## Complexity Analysis
- **Time**: O(n) - visit every node
- **Space**: O(h) - recursion or queue space

## Code



---

## Constraints

- `1 ≤ n ≤ 10⁴`
- `-10⁴ ≤ Node.val ≤ 10⁴`

<br>

---

## All Possible Edge Cases

1. **Single node:** Max = Min = that value
2. **All same values:** Max = Min
3. **Sorted tree (BST):** Min at leftmost, max at rightmost
4. **Negative values:** Min can be very negative

<br>

---

```code```
