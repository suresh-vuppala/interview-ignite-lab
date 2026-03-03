## Overview
Find Lowest Common Ancestor in a general binary tree (not necessarily BST).

## Problem Statement
Given binary tree and two nodes, find their LCA.

## Approach
- Post-order DFS
- If both found in left/right, recurse
- If found in current, return current
- Handle edge cases

## Complexity Analysis
- **Time**: O(n)
- **Space**: O(h)

## Code

```code```