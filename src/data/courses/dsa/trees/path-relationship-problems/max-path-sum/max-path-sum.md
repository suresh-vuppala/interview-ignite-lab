# Max Path Sum

## Overview
Find the maximum path sum in a binary tree. Path can start/end at any node (not necessarily root to leaf).

## Problem Statement
Return the maximum path sum where path can include any nodes.

## Approach
- DFS postorder: calculate max path through each node
- At each node, decide: continue path or start new
- Track global max during traversal
- Handle negative values: can ignore subtrees

## Complexity Analysis
- **Time**: O(n) - visit each node
- **Space**: O(h) - recursion stack

## Code

```code```