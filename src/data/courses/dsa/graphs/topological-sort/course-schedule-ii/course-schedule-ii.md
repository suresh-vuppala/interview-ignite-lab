Return the ordering of courses to take to finish all courses. If impossible (cycle), return empty array.

<br>

> Input: numCourses=4, prerequisites=[[1,0],[2,0],[3,1],[3,2]]
> Output: [0,1,2,3] or [0,2,1,3]
> **Key insight:** Topological sort of the course dependency graph. If cycle → return []. Kahn's returns the order directly.

<br>

---

## Constraints
- `1 ≤ numCourses ≤ 2000`

<br>

---

## All Possible Edge Cases
1. **Cycle present:** return empty array
2. **No prerequisites:** any order works
3. **Linear chain:** unique ordering
4. **Multiple valid orderings**

<br>

---

## Solution 1: Brute Force / Naive Approach

**Intuition:**
The most straightforward approach — straightforward but suboptimal.

**Algorithm:**
1. Apply the naive/brute approach as described
2. Check all possibilities or use a simpler data structure
3. Return the result

### Time Complexity: O(N²) or higher
**Why?**
The brute approach doesn't exploit the problem's structure efficiently, leading to redundant work.

**Detailed breakdown:**
For typical constraint sizes, this approach may be too slow or use too much space.

### Space Complexity: O(1) or O(N) depending on approach

> **Drawback:**
> Straightforward but suboptimal. Does redundant work that can be avoided with a better algorithm or data structure.

> **Key Insight for Improvement:**
> Use Kahn's Topological Sort (Optimal) for O(V + E) time.

<br>

---

## Solution 2: Kahn's Topological Sort (Optimal)

**Algorithm:** Same as Course Schedule I, but return the BFS processing order as the course schedule.

### Time Complexity: O(V + E)
### Space Complexity: O(V + E)

> **Drawback:** None.

> **Key Insight for Improvement:** Kahn's naturally produces a valid ordering AND detects cycles.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Kahn's | O(V+E) | O(V+E) |

**Key Insights:**
1. **Course Schedule I = can we?** Course Schedule II = what order?
2. **Kahn's gives both:** Order + cycle detection
3. **Multiple valid orderings:** Any topological order is valid

<br><br>

---

```code```
