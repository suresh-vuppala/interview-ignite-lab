# House Robber III

## Overview
Tree DP problem: rob houses on tree without robbing adjacent nodes.

## Problem Statement
Each node is a house with money. Rob houses without robbing parent-child neighbors.

## Approach
- DP on tree: state = (rob current, skip current)
- For each node: max = rob + skip(children) OR skip + rob(children)
- DFS return [robbed, skipped]

## Complexity Analysis
- **Time**: O(n)
- **Space**: O(h)

## Code

```code```