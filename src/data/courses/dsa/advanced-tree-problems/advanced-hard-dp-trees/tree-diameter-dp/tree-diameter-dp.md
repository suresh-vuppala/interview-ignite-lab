Find the diameter of a binary tree (longest path between any two nodes).

<br>

> Input:
> Tree: [1,2,3,4,5]
>       1
>      / \
>     2   3
>    / \
>   4   5

> Output:
> 3

> Explanation:
> Longest path: 4 → 2 → 1 → 3
> Length = 3 edges
> 
> Path doesn't have to go through root
> Could be entirely in left or right subtree
> 
> **Key insight:** At each node, diameter = left_height + right_height.

<br>

---

## Solution: Post-order DFS with Height Tracking

**Intuition:**
Diameter passing through a node = left_height + right_height.
Check all nodes, track maximum.

**Algorithm:**
1. Post-order DFS (children first)
2. For each node:
   - Get left and right heights
   - Update diameter = max(diameter, left + right)
   - Return height = max(left, right) + 1

```code```

<br>

### Time Complexity: O(N)
**Why linear?**
- Visit each node exactly once
- At each node: O(1) computation
- Total: N × O(1) = O(N)

**Detailed breakdown:**
- Post-order traversal: O(N)
- Per node operations:
  - Get children heights: O(1)
  - Update diameter: O(1)
  - Return height: O(1)

**Why not O(N²)?**
- Naive: Compute height for each node separately
- Optimized: Compute heights bottom-up in single pass

### Space Complexity: O(H)
**Why height?**
- Recursion stack: O(H)
- Best case (balanced): O(log N)
- Worst case (skewed): O(N)
- Global diameter variable: O(1)

**Key insight:**
- Diameter may not pass through root
- Must check all nodes as potential "turning points"
- Height returned to parent, diameter tracked globally

**Comparison:**
- Brute force: Check all pairs O(N²)
- DFS: Single pass O(N)

> **Time Complexity:** O(N)
> **Space Complexity:** O(H)

<br>
<br>

---
