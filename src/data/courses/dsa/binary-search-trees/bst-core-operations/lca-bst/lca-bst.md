## Overview
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree using BST properties.

## Problem Statement
Given a BST and two node values, find their LCA.

## Approach
- **Using BST Property**: If both values < current, go left; if both > current, go right; otherwise found LCA
- **Time**: O(log n) average, O(n) worst case
- More efficient than general BT due to ordering property

## Complexity Analysis
- **Time**: O(log n) average, O(n) worst
- **Space**: O(1) iterative, O(h) recursive

## Code



---

## Constraints

- `2 ≤ n ≤ 10⁵`
- `All values unique`
- `BST property holds`

<br>

---

## All Possible Edge Cases

1. **Both in left subtree:** LCA is in left subtree
2. **Both in right subtree:** LCA is in right subtree
3. **Split point:** One in left, one in right — current node is LCA
4. **One node is ancestor of other:** That node is the LCA
5. **Both are root's children:** LCA is root

<br>

---

```code```
