Move coins in binary tree so each node has exactly 1. Return minimum moves.

<br>

> [3,0,0] → 2 moves (root gives 1 to each child)
>
> **Key insight:** Postorder: excess = node.val + left_excess + right_excess - 1. Total moves = sum of |excess| at each node.

<br>

---

## Constraints
- N nodes, N total coins
- 0 ≤ node.val ≤ N

<br>

---

## All Possible Edge Cases
1. **All coins at root: must push to leaves
2. **Each node already has 1 coin: 0 moves
3. **Leaf with 0 coins: parent must send 1
4. **Node with many coins: distribute to subtree**

<br>

---

## Solution 1: BFS redistribution

**Intuition:**
The most straightforward approach. Multiple redistribution passes.

**Algorithm:**
1. Initialize queue with starting state
2. While queue not empty: dequeue, process, enqueue neighbors
3. Track visited states to avoid cycles
4. Return result when target state reached

### Time Complexity: O(N²)
**Why?**
Two nested loops each running up to N iterations.
Outer loop: N iterations × Inner loop: up to N iterations = N² total operations.

**Detailed breakdown:**
For N=1,000: ~1 million operations (OK). For N=10,000: ~100 million (borderline TLE).

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Multiple redistribution passes.

> **Key Insight for Improvement:**
> Postorder: compute excess at each node. |excess| = coins passing through edge = moves for that edge.

<br>

---

## Solution 2: Postorder Excess Counting (Optimal)

**Intuition:** Postorder: excess = node.val + left_excess + right_excess - 1. Total moves = sum of |excess| at each node.

**Algorithm:**
1. DFS postorder returns excess coins
2. excess = node.val - 1 + left_excess + right_excess
3. moves += |left_excess| + |right_excess|
4. Return excess

### Time Complexity: O(N)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
[3,0,0]: left_excess=-1, right_excess=-1
moves=|-1|+|-1|=2. Root excess=3-1+(-1)+(-1)=0 ✓
```

### Space Complexity: O(H)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| BFS redistribution | O(N²) | Varies | Baseline |
| Postorder Excess Counting | O(N) | O(H) | Optimal |

**Recommended Solution:** Postorder Excess Counting

**Key Insights:**
1. **|excess| = moves through edge:** Coins flowing up or down
2. **Postorder accumulation:** Bottom-up excess calculation
3. **Elegant:** Single DFS solves it

<br><br>

---

```code```
