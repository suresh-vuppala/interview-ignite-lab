Rob houses arranged in a binary tree without robbing two directly-linked nodes.

<br>

> Input:
> Tree: [3,2,3,null,3,null,1]
>     3
>    / \
>   2   3
>    \   \
>     3   1

> Output:
> 7

> Explanation:
> Rob node 3, skip children 2 and 3, rob grandchildren 3 and 1
> Total: 3 + 3 + 1 = 7
> 
> Cannot rob 3 and 2 (parent-child)
> Cannot rob 3 and 3 (parent-child)
> 
> **Key insight:** For each node, decide rob or skip based on children's states.

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

## Solution: Tree DP with Rob/Skip States

**Intuition:**
At each node, we have two choices:
1. Rob current node → cannot rob children, can rob grandchildren
2. Skip current node → can rob or skip children (take max)

Return both values [rob, skip] for each subtree.

**Recurrence Relation:**
```
rob[node] = node.val + skip[left] + skip[right]
skip[node] = max(rob[left], skip[left]) + max(rob[right], skip[right])
```

**Algorithm:**
1. DFS post-order traversal
2. For each node, compute [rob, skip] from children
3. Return max(rob[root], skip[root])



<br>

### Time Complexity: O(N)
**Why linear?**
- Visit each node exactly once
- At each node: O(1) computation
- Total: N × O(1) = O(N)

**Detailed breakdown:**
- Post-order DFS visits all N nodes
- Each node processes children's results: O(1)
- No repeated computation (each subtree solved once)

### Space Complexity: O(H)
**Why height?**
- Recursion stack depth = tree height
- Best case (balanced): O(log N)
- Worst case (skewed): O(N)
- Return array [rob, skip] per call: O(1)

**Why DP on trees?**
- Cannot use linear DP (not array structure)
- Tree structure requires post-order processing
- Children's states determine parent's optimal choice

**Comparison with brute force:**
- Brute force: Try all combinations O(2^N)
- DP: Each node computed once O(N)
- Massive improvement for large trees

> **Time Complexity:** O(N)
> **Space Complexity:** O(H)

<br>
<br>

---

---

```code```
