Implement Breadth-First Search (BFS) on a graph. Return nodes in BFS order.

<br>

> Input: n=5, adj={0:[1,2], 1:[0,3], 2:[0,4], 3:[1], 4:[2]}, start=0
> Output: [0, 1, 2, 3, 4]
> **Key insight:** Queue-based traversal. Visit all neighbors at current distance before moving farther. Naturally finds shortest path in unweighted graphs.

<br>

---

## Constraints
- `1 ≤ V ≤ 10⁵`, `0 ≤ E ≤ 10⁵`

<br>

---

## Solution 1: DFS (alternative traversal)

**Intuition:**
The most straightforward approach — dfs explores depth-first.

**Algorithm:**
1. Apply the naive/brute approach as described
2. Check all possibilities or use a simpler data structure
3. Return the result

### Time Complexity: O(V+E)
**Why?**
The brute approach doesn't exploit the problem's structure efficiently, leading to redundant work.

**Detailed breakdown:**
For typical constraint sizes, this approach may be too slow or use too much space.

### Space Complexity: O(1) or O(N) depending on approach

> **Drawback:**
> DFS explores depth-first. BFS is needed when shortest path or level-order is required.

> **Key Insight for Improvement:**
> Use Queue + Visited Set (Optimal) for O(V + E) time.

<br>

---

## Solution 2: Queue + Visited Set (Optimal)

**Algorithm:**
1. Queue = [start], visited = {start}
2. While queue not empty: dequeue node, process, enqueue unvisited neighbors (mark visited)

### Time Complexity: O(V + E)
**Why?** Each vertex dequeued once. Each edge examined once (or twice for undirected).

**Detailed breakdown:** V=100,000, E=100,000 → ~300,000 operations

### Space Complexity: O(V)
**Why?** Visited array + queue holds at most V nodes.

> **Drawback:** Uses O(V) space for visited set and queue. Cannot be avoided for graph traversal.

> **Key Insight for Improvement:** BFS gives shortest path in unweighted graphs. For weighted graphs, use Dijkstra instead.

<br>

---

## Complexity Progression Summary

| Algorithm | Time | Space | Use Case |
|-----------|------|-------|----------|
| BFS | O(V+E) | O(V) | Shortest path (unweighted), level-order |
| DFS | O(V+E) | O(V) | Cycle detection, topological sort, components |

**Key Insights:**
1. **FIFO queue:** Processes by distance — closer nodes first
2. **Shortest path:** BFS gives minimum edges from source in unweighted graphs
3. **Mark visited BEFORE enqueueing:** Prevents duplicates in queue
4. **Foundation:** Used in rotting oranges, word ladder, 0-1 BFS, multi-source BFS

<br><br>

---

```code```
