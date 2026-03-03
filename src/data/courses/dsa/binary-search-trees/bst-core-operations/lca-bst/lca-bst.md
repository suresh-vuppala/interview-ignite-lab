# LCA in BST

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

```code```