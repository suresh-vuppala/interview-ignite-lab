## Overview
Leaf nodes have no children. Internal nodes have at least one child. This is a fundamental tree property counting problem.

## Problem Statement
Given a binary tree, count the number of leaf nodes and internal nodes.

## Approach
- **Leaf Node**: Node with no left and right children
- **Internal Node**: Node with at least one child
- Use DFS/recursion to traverse and count

## Complexity Analysis
- **Time**: O(n) - visit each node once
- **Space**: O(h) - recursion stack

## Code



---

## Constraints

- `0 ≤ n ≤ 10⁵`

<br>

---

## All Possible Edge Cases

1. **Single node:** 1 leaf, 0 internal
2. **All leaves at same level:** Count at that level
3. **Skewed tree:** 1 leaf, n-1 internal
4. **Empty tree:** 0 leaves, 0 internal

<br>

---

```code```
