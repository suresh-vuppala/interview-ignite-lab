# Level Order Traversal

## Overview
BFS traversal visiting nodes level-by-level (breadth-first).

## Problem Statement
Perform level order traversal returning list of lists (each inner list is one level).

## Approach
- Use queue: enqueue root, process level by level
- For each level, process all current nodes
- Add their children to queue

## Complexity Analysis
- **Time**: O(n)
- **Space**: O(w) where w = max width

## Code

```code```