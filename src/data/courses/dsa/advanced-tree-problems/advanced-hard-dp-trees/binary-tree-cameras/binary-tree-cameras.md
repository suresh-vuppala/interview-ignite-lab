Install the minimum number of cameras to monitor all nodes in a binary tree. A camera at a node monitors its parent, itself, and its immediate children.

<br>

> Input:
> Tree structure:
>     0
>    / \
>   0   0
>    \
>     0
>      \
>       0

> Output:
> 2

> Explanation:
> Optimal camera placement:
> - Place camera at node with value at depth 2 (monitors parent, itself, children)
> - Place camera at node with value at depth 4 (monitors parent, itself, children)
> - Total cameras needed: 2
> 
> Greedy strategy:
> - Start from leaves (bottom-up)
> - Don't place camera at leaf (wasteful)
> - Place camera at leaf's parent (covers leaf, parent, and parent's parent)
> - This minimizes cameras needed

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

## Solution: Greedy Post-order DFS with States

Use post-order DFS with 3 states for each node:
1. **State 0 (Not Monitored)**: Node needs monitoring
2. **State 1 (Has Camera)**: Node has camera installed
3. **State 2 (Monitored)**: Node is monitored but no camera

**Greedy Strategy:**
- Process children before parent (post-order)
- If any child is not monitored (state 0), place camera at current node
- If any child has camera (state 1), current node is monitored
- If both children are monitored (state 2), current node is not monitored

**Key insight:** Never place camera at leaf; place at leaf's parent to cover more nodes.

```code```

<br>

### Time Complexity Analysis

**Post-order DFS: O(n)**
- Visit each node exactly once
- At each node:
  - Check states of left and right children: O(1)
  - Decide current node's state: O(1)
  - Update camera count if needed: O(1)
- Total: n × O(1) = O(n)

**Why post-order?**
- Need children's states before deciding parent's state
- Bottom-up approach ensures optimal placement
- Greedy choice at each level based on children

**Space Complexity: O(h)**
- Recursion stack depth = height of tree
- Best case (balanced): O(log n)
- Worst case (skewed): O(n)
- No extra data structures needed

**Greedy Correctness:**
- Placing camera at leaf's parent is always better than at leaf
- Camera at parent covers: parent, leaf, and parent's parent
- Camera at leaf covers: only leaf and parent
- Greedy choice leads to global optimum

**State Transitions:**
- If child is state 0 (not monitored) → parent must have camera (state 1)
- If child is state 1 (has camera) → parent is monitored (state 2)
- If both children are state 2 (monitored) → parent is not monitored (state 0)
- Root special case: If root is state 0, place camera at root

**Comparison with other approaches:**
- Brute force: Try all combinations O(2^n) - exponential
- DP: Track states for each subtree O(n) - same as greedy but more complex
- Greedy: O(n) with simple state tracking - optimal

> **Time Complexity:** O(n) - single post-order DFS pass
> **Space Complexity:** O(h) - recursion stack for tree height

<br>
<br>

---
