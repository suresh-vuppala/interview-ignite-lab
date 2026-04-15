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

## All Possible Edge Cases
1. **Both null:** identical
2. **One null, one not:** not identical
3. **Same structure, different values**
4. **Same values, different structure**

<br>

---

## Solution 1: Serialize both, compare strings

**Intuition:**
The most straightforward approach — string comparison uses o(n) space.

**Algorithm:**
1. Apply the naive/brute approach as described
2. Check all possibilities or use a simpler data structure
3. Return the result

### Time Complexity: O(N) time, O(N) space
**Why?**
The brute approach doesn't exploit the problem's structure efficiently, leading to redundant work.

**Detailed breakdown:**
For typical constraint sizes, this approach may be too slow or use too much space.

### Space Complexity: O(1) or O(N) depending on approach

> **Drawback:**
> String comparison uses O(N) space. Recursive comparison is O(1) extra.

> **Key Insight for Improvement:**
> Use Recursive Comparison (Optimal) for O(min(N, M)) time.

<br>

---

## Solution 2: Recursive Comparison (Optimal)

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
