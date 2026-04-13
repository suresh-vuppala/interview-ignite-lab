Move coins in binary tree so each node has exactly 1. Return minimum moves.

<br>

> [3,0,0] → 2 moves (root gives 1 to each child)
>
> **Key insight:** Postorder: excess = node.val + left_excess + right_excess - 1. Total moves = sum of |excess| at each node.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: BFS redistribution

### Time Complexity: O(N²)

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
