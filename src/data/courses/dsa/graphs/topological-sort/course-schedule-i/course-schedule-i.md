There are numCourses courses with prerequisites. Determine if you can finish all courses (no circular dependency).

<br>

> Input: numCourses=2, prerequisites=[[1,0]]
> Output: true (take 0 first, then 1)
> **Key insight:** This is cycle detection in a directed graph. If DAG → can finish. If cycle → cannot. Use Kahn's or DFS 3-color.

<br>

---

## Constraints
- `1 ≤ numCourses ≤ 2000`, `0 ≤ prerequisites.length ≤ 5000`

<br>

---

## All Possible Edge Cases
1. **No prerequisites:** always possible
2. **Simple cycle:** [0,1] and [1,0] → impossible
3. **Self-dependency:** [0,0] → impossible
4. **Long chain:** A→B→C→D (possible)
5. **Multiple independent chains**

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
> Use Kahn's / DFS Cycle Detection (Optimal) for O(V + E) time.

<br>

---

## Solution 2: Kahn's / DFS Cycle Detection (Optimal)

**Algorithm:** Build directed graph from prerequisites. Check if graph has a cycle. No cycle → true. Cycle → false.

### Time Complexity: O(V + E)
### Space Complexity: O(V + E)

> **Drawback:** None.

> **Key Insight for Improvement:** Same as detect-cycle-directed. Kahn's: if topo sort includes all V nodes → no cycle → true.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Kahn's BFS | O(V+E) | O(V+E) |
| DFS 3-Color | O(V+E) | O(V+E) |

**Key Insights:**
1. **Course Schedule = Cycle Detection** on dependency graph
2. **Prerequisite [a,b] means:** b → a (take b before a)
3. **FAANG classic:** Frequently asked at Google, Amazon, Microsoft

<br><br>

---

```code```
