# Height of Tree

## Overview
The height of a tree is the longest path from root to any leaf node. Also called depth in some contexts.

## Problem Statement
Find the height of a binary tree.

## Approach
- **Base Case**: Empty tree has height -1 (or 0 depending on convention)
- **Recursive Case**: Height = 1 + max(height of left subtree, height of right subtree)
- Can use DFS with recursion

## Complexity Analysis
- **Time**: O(n) - visit each node
- **Space**: O(h) - recursion stack

## Code

```code```