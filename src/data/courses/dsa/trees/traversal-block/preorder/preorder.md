## Overview
Preorder traversal visits nodes in Root-Left-Right order. Useful for copying trees and prefix expressions.

## Problem Statement
Implement preorder traversal (recursive and iterative).

## Approach
**Recursive**: Process root, visit left subtree, visit right subtree
**Iterative**: Use single stack

## Complexity Analysis
- **Time**: O(n)
- **Space**: O(h)

## Code



---

## Constraints

- `0 ≤ n ≤ 100`
- `-100 ≤ Node.val ≤ 100`

<br>

---

## All Possible Edge Cases

1. **Empty tree:** Return []
2. **Single node:** Return [val]
3. **Left-skewed:** Root first, then descending
4. **Right-skewed:** Root first, then ascending

<br>

---

```code```
