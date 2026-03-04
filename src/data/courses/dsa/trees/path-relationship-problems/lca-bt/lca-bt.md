Find the Lowest Common Ancestor (LCA) of two nodes in a binary tree. LCA is the lowest node that has both nodes as descendants (a node can be a descendant of itself).

<br>

> Input:
> Tree structure:
>       3
>      / \
>     5   1
>    / \ / \
>   6  2 0  8
>     / \
>    7   4
> 
> p = 5, q = 1

> Output:
> 3

> Explanation:
> LCA of nodes 5 and 1 is 3 (root)
> - Node 5 is in left subtree of 3
> - Node 1 is in right subtree of 3
> - Node 3 is the lowest node containing both

<br>

> Input:
> Same tree, p = 5, q = 4

> Output:
> 5

> Explanation:
> LCA of nodes 5 and 4 is 5
> - Node 4 is in left subtree of 5 (5→2→4)
> - Node 5 contains itself and node 4
> - Node 5 is the LCA (node can be ancestor of itself)

<br>

---

## Solution: Recursive Post-order DFS

Use post-order DFS to find LCA bottom-up:
1. **Base case**: If node is null or matches p or q, return node
2. **Recursive case**: Search in left and right subtrees
3. **Decision logic**:
   - If both left and right return non-null → current node is LCA
   - If only left returns non-null → LCA is in left subtree
   - If only right returns non-null → LCA is in right subtree

**Key insight:** First node where paths to p and q diverge is the LCA.

```code```

<br>

### Time Complexity Analysis

**DFS Traversal: O(n)**
- In worst case, visit all n nodes
- Occurs when p and q are at deepest levels
- Each node visited at most once
- At each node: O(1) comparison and decision

**Best Case: O(log n)**
- When tree is balanced and LCA is near root
- May not need to visit all nodes
- Early termination when both nodes found

**Average Case: O(n)**
- Must explore enough nodes to find both p and q
- Cannot determine LCA without finding both nodes

**Space Complexity: O(h)**
- Recursion stack depth = height of tree
- Best case (balanced): O(log n)
- Worst case (skewed): O(n)

**Why post-order?**
- Need information from children before deciding at parent
- Process left subtree, right subtree, then current node
- Bottom-up approach ensures correct LCA identification

**Comparison with other approaches:**
- Path storage: O(n) time, O(n) space - store paths to both nodes
- Parent pointers: O(n) time, O(n) space - track parents, find intersection
- Recursive: O(n) time, O(h) space - most efficient

> **Time Complexity:** O(n) - may visit all nodes in worst case
> **Space Complexity:** O(h) - recursion stack for tree height

<br>
<br>

---