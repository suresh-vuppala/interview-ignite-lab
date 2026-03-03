## Overview
Check if one tree is a subtree of another (exact match at some node).

## Problem Statement
Check if tree s is a subtree of tree t (starting at some node in t).

## Approach
- For each node in t, check if it matches s
- Use isSameTree helper
- DFS on t to find potential roots

## Complexity Analysis
- **Time**: O(n*m) where n=t.size, m=s.size
- **Space**: O(h)

## Code

```code```