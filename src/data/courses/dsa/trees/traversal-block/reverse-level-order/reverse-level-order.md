Return the reverse level-order traversal — nodes level by level from bottom to top.

<br>

> Input: root = [3,9,20,null,null,15,7]
> Output: [[15,7],[9,20],[3]]

> Explanation: Standard BFS gives [[3],[9,20],[15,7]]. Reverse → [[15,7],[9,20],[3]].
> 
> **Key insight:** Standard BFS level-order, then reverse the result array. Or use a stack to reverse naturally.

<br>

---

## Constraints
- `0 ≤ N ≤ 2000`

<br>

---

## Solution 1: Level order then reverse result

**Intuition:**
The most straightforward approach — bfs + reverse at end.

**Algorithm:**
1. Apply the naive/brute approach as described
2. Check all possibilities or use a simpler data structure
3. Return the result

### Time Complexity: O(N)
**Why?**
The brute approach doesn't exploit the problem's structure efficiently, leading to redundant work.

**Detailed breakdown:**
For typical constraint sizes, this approach may be too slow or use too much space.

### Space Complexity: O(1) or O(N) depending on approach

> **Drawback:**
> BFS + reverse at end. Can also use BFS with front-insertion.

> **Key Insight for Improvement:**
> Use BFS + Reverse (Optimal) for O(N) time.

<br>

---

## Solution 2: BFS + Reverse (Optimal)

**Algorithm:** Standard level-order BFS. After collecting all levels, reverse the result list.

### Time Complexity: O(N)
**Why?** BFS O(N) + reverse O(levels) = O(N).

**Detailed breakdown:** N = 2000 → 2000 BFS ops + ~11 level reversal

### Space Complexity: O(W)

> **Drawback:** None — this is optimal.

> **Key Insight for Improvement:** Already O(N). Alternative: insert each level at the FRONT of result list (no reversal needed).

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| BFS + Reverse | O(N) | O(W) | Standard BFS then reverse |

**Key Insights:**
1. **Simple variation:** Just reverse standard level-order output
2. **Front-insert alternative:** Use deque/linked-list to avoid reversal

<br><br>

---

```code```
