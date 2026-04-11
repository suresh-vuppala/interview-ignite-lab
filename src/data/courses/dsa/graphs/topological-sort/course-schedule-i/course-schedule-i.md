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

## Solution: Kahn's / DFS Cycle Detection (Optimal)

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
