Distribute coins in a binary tree so each node has exactly one coin. Return minimum moves needed.

<br>

> Input:
> Tree: [3,0,0]
>     3
>    / \
>   0   0

> Output:
> 2

> Explanation:
> Node 3 has 3 coins (excess = 2)
> Left child needs 1 coin (deficit = 1)
> Right child needs 1 coin (deficit = 1)
> 
> Move 1 coin from root to left: 1 move
> Move 1 coin from root to right: 1 move
> Total moves = 2
> 
> **Key insight:** Each node's excess/deficit = coins - 1. Sum absolute values.

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

## Solution: Post-order DFS with Excess/Deficit

**Intuition:**
Each node needs exactly 1 coin.
- Excess coins (val > 1) must move to neighbors
- Deficit coins (val < 1) must receive from neighbors
- Each coin movement = 1 move

Return excess/deficit for each subtree.

**Algorithm:**
1. Post-order DFS (children first)
2. For each node: excess = node.val + left_excess + right_excess - 1
3. Moves += |left_excess| + |right_excess|
4. Return excess to parent

```code```

<br>

### Time Complexity: O(N)
**Why linear?**
- Visit each node once: O(N)
- At each node: O(1) computation
- Total: N × O(1) = O(N)

**Detailed breakdown:**
- Post-order traversal: O(N)
- Per node operations:
  - Compute excess: O(1)
  - Update moves: O(1)
  - Return to parent: O(1)

### Space Complexity: O(H)
**Why height?**
- Recursion stack: O(H)
- Best case (balanced): O(log N)
- Worst case (skewed): O(N)
- Global moves counter: O(1)

**Why this works:**
- Excess/deficit propagates up tree
- Each edge crossed = 1 move
- Absolute value counts moves in both directions
- Post-order ensures children settled first

**Key insight:**
- Don't track actual coin movements
- Just count excess/deficit flow
- Each unit of flow = 1 move

> **Time Complexity:** O(N)
> **Space Complexity:** O(H)

<br>
<br>

---
