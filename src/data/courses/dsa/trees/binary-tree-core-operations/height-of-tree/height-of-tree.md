Find the height (or depth) of a binary tree. Height is the number of edges on the longest path from root to any leaf node.

<br>

> Input:
> Tree structure:
>       1
>      / \
>     2   3
>    / \
>   4   5

> Output:
> 2

> Explanation:
> Paths from root to leaves:
> - 1 → 2 → 4: length = 2 edges
> - 1 → 2 → 5: length = 2 edges
> - 1 → 3: length = 1 edge
> 
> Maximum path length = 2
> 
> Recursive calculation:
> - height(4) = 0 (leaf node)
> - height(5) = 0 (leaf node)
> - height(2) = 1 + max(height(4), height(5)) = 1 + max(0, 0) = 1
> - height(3) = 0 (leaf node)
> - height(1) = 1 + max(height(2), height(3)) = 1 + max(1, 0) = 2

<br>


---

## Constraints

- `0 ≤ n ≤ 10⁴`
- `-100 ≤ Node.val ≤ 100`

<br>

---

## All Possible Edge Cases

1. **Empty tree:** Height = -1 or 0 (depends on convention)
2. **Single node:** Height = 0
3. **Skewed tree:** Height = n-1
4. **Balanced tree:** Height = log(n)

<br>

---

## Solution: Recursive DFS

Use post-order DFS to calculate height bottom-up:
1. **Base case**: Empty node has height -1 (or 0 if counting nodes)
2. **Recursive case**: height = 1 + max(left height, right height)
3. Process children first, then compute current node's height

**Convention:** Height in edges = -1 for null, 0 for leaf. Height in nodes = 0 for null, 1 for leaf.



<br>

### Time Complexity Analysis

**DFS Traversal: O(n)**
- Visit each node exactly once
- At each node:
  - Recursive call to left child: T(n/2)
  - Recursive call to right child: T(n/2)
  - Max operation: O(1)
  - Addition: O(1)
- Total: T(n) = T(n/2) + T(n/2) + O(1) = O(n)

**Why O(n)?**
- Must visit every node to find longest path
- Cannot skip any subtree
- Each node contributes O(1) work

**Space Complexity: O(h)**
- Recursion stack depth = height of tree
- Best case (balanced tree): O(log n)
- Worst case (skewed tree): O(n)
- Average case: O(log n)

**Iterative alternative:**
- Level-order traversal (BFS): O(n) time, O(w) space where w = max width
- Count levels instead of recursive calls

> **Time Complexity:** O(n) - visit each node once
> **Space Complexity:** O(h) - recursion stack, where h is height (O(log n) balanced, O(n) skewed)

<br>
<br>

---

---

```code```
