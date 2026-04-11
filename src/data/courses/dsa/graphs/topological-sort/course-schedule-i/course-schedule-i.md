Can you finish all courses? (Detect cycle in prerequisite graph.)

<br>

> Input: numCourses=2, prerequisites=[[1,0]]
> Output: true (take 0 then 1)

<br>

---

## Solution 1: DFS Cycle Detection (3-Color)

Build directed graph. If cycle exists → false.

### Time: O(V + E) | Space: O(V)

<br>

---

## Solution 2: Kahn's Topological Sort

If topological sort processes all courses → true. Otherwise cycle → false.

### Time: O(V + E) | Space: O(V)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| DFS 3-Color | O(V+E) | O(V) | Gray node = cycle |
| Kahn's BFS | O(V+E) | O(V) | Incomplete sort = cycle |

<br>
<br>

---

```code```
