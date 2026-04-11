Return the zigzag level order traversal — alternate left-to-right and right-to-left at each level.

<br>

> Input: root = [3,9,20,null,null,15,7]
> Output: [[3],[20,9],[15,7]]

> Explanation: Level 0: left→right [3]. Level 1: right→left [20,9]. Level 2: left→right [15,7].
> 
> **Key insight:** Standard BFS level-order, but reverse alternate levels. Or use a deque: even levels add to back, odd levels add to front.

<br>

---

## Constraints
- `0 ≤ N ≤ 2000`

<br>

---

## Solution 1: BFS + Reverse Alternate Levels (Optimal)

**Algorithm:** Standard level-order BFS. After collecting each level, if level index is odd → reverse the level list.

### Time Complexity: O(N)
**Why?** BFS visits each node once. Reversing a level: O(level size). Total reversal work across all levels: O(N).

**Detailed breakdown:** N = 2000 → 2000 BFS operations + O(N) total reversal

### Space Complexity: O(W)

> **Drawback:** Reversing after collection wastes a little work. But it's still O(N) total.

> **Key Insight for Improvement:** Use a deque: on even levels, append to level list normally. On odd levels, prepend. No reversal needed — but same Big-O.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| BFS + Reverse | O(N) | O(W) | Reverse alternate levels |

**Key Insights:**
1. **Zigzag = BFS + direction flag:** Toggle direction each level
2. **Deque alternative:** Prepend on odd levels instead of reversing
3. **Common variant:** Right-side view, average of levels — all BFS template variations

<br><br>

---

```code```
