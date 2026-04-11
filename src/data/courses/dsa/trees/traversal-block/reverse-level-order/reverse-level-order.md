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

## Solution: BFS + Reverse (Optimal)

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
