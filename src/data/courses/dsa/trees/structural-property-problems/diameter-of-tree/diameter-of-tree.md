Find the diameter of a binary tree. Diameter is the length of the longest path between any two nodes (may or may not pass through root).

<br>

> Input:
> Tree structure:
>       1
>      / \
>     2   3
>    / \
>   4   5

> Output:
> 3

> Explanation:
> Possible paths:
> - 4 → 2 → 1 → 3: length = 3 edges
> - 4 → 2 → 5: length = 2 edges
> - 5 → 2 → 1 → 3: length = 3 edges
> 
> Longest path = 3 edges (either 4→2→1→3 or 5→2→1→3)
> 
> Calculation at each node:
> - Node 4: diameter = 0, height = 0
> - Node 5: diameter = 0, height = 0
> - Node 2: diameter = max(0, 0, 0+0+2) = 2, height = 1
> - Node 3: diameter = 0, height = 0
> - Node 1: diameter = max(2, 0, 1+0+2) = 3, height = 2
> 
> At node 1: left_height=1, right_height=0, path through node 1 = 1+0+2 = 3

<br>

---

## Solution: Post-order DFS with Height Tracking

Use post-order DFS to calculate diameter efficiently:
1. For each node, calculate height of left and right subtrees
2. Diameter through current node = left_height + right_height + 2
3. Update global maximum diameter
4. Return height of current node to parent

**Key insight:** Diameter at any node = sum of heights of left and right subtrees.

```code```

<br>

### Time Complexity Analysis

**Single DFS Pass: O(n)**
- Visit each node exactly once
- At each node:
  - Calculate left subtree height: already computed
  - Calculate right subtree height: already computed
  - Compute diameter through node: O(1)
  - Update global max: O(1)
  - Return height: O(1)
- Total: n × O(1) = O(n)

**Why not O(n²)?**
- Naive approach: For each node, calculate height (O(n) per node) = O(n²)
- Optimized: Calculate height once during DFS, reuse for diameter = O(n)
- Post-order ensures children processed before parent

**Space Complexity: O(h)**
- Recursion stack depth = height of tree
- Best case (balanced): O(log n)
- Worst case (skewed): O(n)
- No extra data structures needed

**Algorithm efficiency:**
- Single pass through tree
- Each node contributes O(1) work
- Height and diameter computed simultaneously

> **Time Complexity:** O(n) - single DFS pass, each node visited once
> **Space Complexity:** O(h) - recursion stack for tree height

<br>
<br>

---