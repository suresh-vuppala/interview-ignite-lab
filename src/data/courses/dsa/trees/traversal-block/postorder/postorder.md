## Overview
Postorder traversal visits nodes in Left-Right-Root order. Used for deletion and solving subproblem-based problems.

## Problem Statement
Implement postorder traversal (recursive and iterative).

## Approach
**Recursive**: Visit left, visit right, process root
**Iterative**: Use two stacks or one stack with tracking

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
3. **Root is last:** Always the last element visited
4. **Leaf nodes first:** All leaves before any internal node

<br>

---

```code```
