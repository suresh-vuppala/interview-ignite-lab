## Binary Search Trees — Sorted Tree Structure

A BST is a binary tree where for every node: **all left descendants < node < all right descendants**. This property enables O(log n) search, insert, and delete — combining the advantages of sorted arrays (fast search) with linked lists (fast insertion).

<br>

## Key BST Property

**Inorder traversal of a BST produces a sorted sequence.** This single fact is the key to solving most BST problems.

<br>

## What You'll Learn

1. **Core operations** — Insert, search, delete, validate BST
2. **BST-specific queries** — Floor, ceil, kth smallest, LCA in BST
3. **Construction** — From sorted array, from preorder/postorder, serialize/deserialize
4. **Views** — Left, right, top, bottom, vertical order, boundary, diagonal
5. **Transformations** — BST to DLL, recover swapped BST

<br>

## BST vs Hash Map

| Operation | BST (balanced) | Hash Map |
|-----------|---------------|----------|
| Search | O(log n) | O(1) average |
| Insert | O(log n) | O(1) average |
| Delete | O(log n) | O(1) average |
| Min/Max | O(log n) | O(n) |
| Range query | O(log n + k) | O(n) |
| Ordered traversal | O(n) | O(n log n) |

**Note:** All BST complexities above assume a **balanced** BST (e.g., AVL, Red-Black). An unbalanced BST degrades to O(n) in the worst case.

**Use BST when you need ordered operations.** Use hash map when you only need lookup.

<br>


## All Possible Edge Cases
1. **N/A — introductory overview**
