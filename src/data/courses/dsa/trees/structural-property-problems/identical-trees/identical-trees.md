Given two binary trees, check if they are structurally identical and have the same node values.

<br>

> Input: p = [1,2,3], q = [1,2,3]
> Output: true

> Explanation: Same structure, same values at every position.
> 
> **Key insight:** Recursively compare: both null → true. One null → false. Values differ → false. Both subtrees must match.

<br>

---

## Constraints
- `0 ≤ N ≤ 100`

<br>

---

## Solution: Recursive Comparison (Optimal)

**Algorithm:**
1. If both null → true
2. If one null or values differ → false
3. Return isSame(p.left, q.left) AND isSame(p.right, q.right)

### Time Complexity: O(min(N, M))
**Why?** Compare until first difference or both exhausted.

**Detailed breakdown:** N=M=100 → at most 100 comparisons

### Space Complexity: O(min(H1, H2))

> **Drawback:** None — this is optimal.

> **Key Insight for Improvement:** Already optimal. Iterative BFS with paired queue is an alternative with same complexity.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Recursive | O(N) | O(H) |

**Key Insights:**
1. **Three base cases:** Both null, one null, values differ
2. **Short-circuit:** Returns false at first mismatch
3. **Used in:** Subtree check problem (compare subtrees with isSameTree)

<br><br>

---

```code```
