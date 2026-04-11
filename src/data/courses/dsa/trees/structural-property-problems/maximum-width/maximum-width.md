Find the maximum width of a binary tree. Width = number of nodes between the leftmost and rightmost non-null nodes at any level (including null nodes in between).

<br>

> Input: root = [1,3,2,5,3,null,9]
> Output: 4

> Explanation: Level 2 has nodes at positions 0,1,_,3 → width = 3-0+1 = 4.
> 
> **Key insight:** Assign position indices: root=0, left=2*pos, right=2*pos+1. Width of a level = rightmost_pos - leftmost_pos + 1. BFS tracking positions.

<br>

---

## Constraints
- `1 ≤ N ≤ 3000`

<br>

---

## Solution: BFS with Position Indexing (Optimal)

**Algorithm:**
1. Queue of (node, position) pairs. Root at position 0.
2. For each level: track min and max positions. Width = max - min + 1.
3. Children: left = 2*pos, right = 2*pos+1
4. Normalize positions per level to prevent overflow: subtract min position.

### Time Complexity: O(N)
**Why?** BFS visits each node once.

**Detailed breakdown:** N = 3000 → 3000 operations

### Space Complexity: O(W)

> **Drawback:** Position values can overflow for deep trees. Need normalization.

> **Key Insight for Improvement:** Subtract leftmost position at each level to keep values small. Prevents integer overflow.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| BFS + Position | O(N) | O(W) | Index-based width calculation |

**Key Insights:**
1. **Position formula:** left = 2*pos, right = 2*pos+1 (heap indexing)
2. **Normalize per level:** Subtract leftmost to prevent overflow
3. **Width includes nulls:** Unlike simple node count — uses position difference

<br><br>

---

```code```
