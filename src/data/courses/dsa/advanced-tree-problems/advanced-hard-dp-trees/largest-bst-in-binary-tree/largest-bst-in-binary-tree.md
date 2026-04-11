Find the size of the largest BST subtree in a binary tree.

<br>

> Input:
> Tree: [10,5,15,1,8,null,7]
>      10
>     /  \
>    5    15
>   / \     \
>  1   8     7

> Output:
> 3

> Explanation:
> Largest BST subtree is rooted at node 5:
>     5
>    / \
>   1   8
> Size = 3 nodes
> 
> Node 10's subtree is not BST (15 > 10 but 7 < 10)
> 
> **Key insight:** Track (isBST, size, min, max) for each subtree.

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

## Solution: Post-order DFS with BST Validation

**Intuition:**
For each node to be BST root:
- Left subtree must be BST
- Right subtree must be BST
- left_max < node.val < right_min

Return (isBST, size, min, max) for each subtree.

**Algorithm:**
1. Post-order DFS (process children first)
2. For each node, check BST property
3. If valid BST: size = left_size + right_size + 1
4. If not BST: return max(left_size, right_size)



<br>

### Time Complexity: O(N)
**Why linear?**
- Visit each node exactly once
- At each node: O(1) validation
- Total: N × O(1) = O(N)

**Detailed breakdown:**
- Post-order traversal: O(N)
- BST check per node: compare 3 values O(1)
- Update min/max: O(1)
- No repeated subtree computation

**Why not O(N²)?**
- Naive: Check each subtree separately O(N) per node
- Optimized: Single pass with state tracking
- State: (isBST, size, min, max) computed bottom-up

### Space Complexity: O(H)
**Why height?**
- Recursion stack: O(H)
- Best case (balanced): O(log N)
- Worst case (skewed): O(N)
- Return tuple per call: O(1)

**Key optimization:**
- Single DFS pass (not multiple validations)
- Track all needed info in one traversal
- Bottom-up avoids redundant checks

> **Time Complexity:** O(N)
> **Space Complexity:** O(H)

<br>
<br>

---

---

```code```
