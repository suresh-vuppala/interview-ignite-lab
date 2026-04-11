Find the maximum sum of values in any BST subtree of a binary tree.

<br>

> Input:
> Tree: [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
>        1
>      /   \
>     4     3
>    / \   / \
>   2   4 2   5
>            / \
>           4   6

> Output:
> 20

> Explanation:
> Maximum sum BST is rooted at node 3:
>     3
>    / \
>   2   5
>      / \
>     4   6
> Sum = 3 + 2 + 5 + 4 + 6 = 20
> 
> **Key insight:** Track (isBST, sum, min, max) and update global max.

<br>


---

## Constraints

- `1 ≤ n ≤ 10⁵`
- `-10⁵ ≤ Node.val ≤ 10⁵`

<br>

---

## All Possible Edge Cases

1. **Empty tree:** Return null or 0
2. **Single node:** Trivial case
3. **Skewed tree:** Degenerates to linked list behavior
4. **Balanced tree:** Optimal case for most tree algorithms
5. **Large tree:** Must be O(n) or O(n log n)

<br>

---

## Solution: Post-order DFS with Sum Tracking

**Intuition:**
Similar to Largest BST, but track sum instead of size.
For each valid BST subtree, update global maximum sum.

**Algorithm:**
1. Post-order DFS (children before parent)
2. Validate BST property at each node
3. If valid BST: sum = left_sum + right_sum + node.val
4. Update global max_sum if current sum is larger
5. Return (isBST, sum, min, max)



<br>

### Time Complexity: O(N)
**Why linear?**
- Single post-order traversal: O(N)
- Each node processed once
- BST validation: O(1) per node
- Sum computation: O(1) per node

**Detailed breakdown:**
- Visit all N nodes: O(N)
- At each node:
  - Check BST property: O(1)
  - Compute sum: O(1)
  - Update global max: O(1)
- Total: N × O(1) = O(N)

### Space Complexity: O(H)
**Why height?**
- Recursion stack: O(H)
- Best case (balanced): O(log N)
- Worst case (skewed): O(N)
- Global max variable: O(1)

**Why efficient?**
- Single pass solution
- No redundant subtree checks
- Bottom-up state propagation
- Early termination for non-BST subtrees

**Comparison:**
- Brute force: Check all subtrees O(N²)
- Optimized: Single DFS pass O(N)

> **Time Complexity:** O(N)
> **Space Complexity:** O(H)

<br>
<br>

---

---

```code```
