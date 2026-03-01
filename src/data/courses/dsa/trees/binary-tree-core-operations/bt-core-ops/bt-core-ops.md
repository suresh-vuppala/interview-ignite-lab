# Binary Tree Core Operations

## Overview
Core operations on binary trees include insertion, search, update, and deletion. These fundamental operations form the basis for all tree-based algorithms.

## Problem Statement
Implement the four fundamental operations on a binary tree:
1. **Insert**: Add a node to the tree
2. **Search**: Find a node with a specific value
3. **Update**: Modify a node's value
4. **Delete**: Remove a node from the tree

## Approach

### 1. Insert Operation
- Use level-order traversal to find the first empty position (if complete tree)
- Or use recursive approach to insert at appropriate position
- For binary search trees, insert based on value comparison

### 2. Search Operation
- Traverse the tree (level-order, inorder, preorder)
- Compare each node's value with target
- Return node if found, null otherwise

### 3. Update Operation
- Search for the node with given value
- Update its value if found

### 4. Delete Operation
- Find the node to delete
- Handle three cases:
  - **No children (leaf)**: Simply remove
  - **One child**: Replace with child
  - **Two children**: Replace with inorder successor/predecessor

## Complexity Analysis
- **Time**: O(n) for all operations (worst case)
- **Space**: O(h) for recursion stack, O(n) for search

## Code

```code
```