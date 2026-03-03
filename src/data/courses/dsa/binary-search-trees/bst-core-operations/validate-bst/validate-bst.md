# Validate BST

## Overview
Determine if a binary tree is a valid Binary Search Tree (BST). A valid BST must satisfy: left subtree values < node < right subtree values.

## Problem Statement
Given a binary tree, validate whether it is a Binary Search Tree (BST).

## Approach
1. **Min-Max Approach**: Track valid min/max bounds for each subtree
2. **Inorder Traversal**: Valid BST produces sorted inorder sequence
3. **Recursive**: For each node, ensure all left descendants < node < all right descendants

## Complexity Analysis
- **Time**: O(n) - visit each node once
- **Space**: O(h) - recursion depth

## Code

```code```