## Trees — Hierarchical Data Structures

A tree is a connected, acyclic graph with a designated root. Binary trees (each node has at most 2 children) are the most common variant in interviews, appearing in **~15% of all FAANG questions**.

<br>

## Why Trees Are So Important

- **Recursion playground** — Most tree problems have elegant recursive solutions
- **Foundation for BST, heaps, tries** — All specialized tree variants
- **Path problems** — Maximum path sum, LCA, diameter — Google favorites
- **Traversal mastery** — Inorder, preorder, postorder, level-order, Morris

<br>

## Core Traversals

| Traversal | Order | Use Case |
|-----------|-------|----------|
| Inorder | Left → Root → Right | BST gives sorted order |
| Preorder | Root → Left → Right | Serialize tree, copy tree |
| Postorder | Left → Right → Root | Delete tree, evaluate expression |
| Level-Order | Level by level (BFS) | Zigzag, right view, width |
| Morris | O(1) space inorder | When recursion stack is too expensive |

<br>

## Problem Categories in This Module

1. **Core operations** — Height, node count, min/max
2. **Traversals** — All 5 traversal types + variants
3. **Structural properties** — Balanced, symmetric, identical, subtree check
4. **Path problems** — Path sum, max path, LCA, distance
5. **Modifications** — Invert, flatten, prune, trim

<br>


## All Possible Edge Cases
1. **N/A — introductory overview**
