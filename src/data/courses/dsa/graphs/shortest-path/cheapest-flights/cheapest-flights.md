Find cheapest flight with at most k stops.

<br>

---

## Solution 1: BFS with Pruning

BFS level by level (level = stops). Track min cost to each node. Prune paths exceeding k stops.

### Time: O(V × E) worst case | Space: O(V)

<br>

---

## Solution 2: Bellman-Ford with K Iterations

Run Bellman-Ford but only k+1 iterations (not V-1). This limits path length.

### Time: O(k × E) | Space: O(V)

<br>

---

## Solution 3: Dijkstra with (cost, city, stops) State

Modified Dijkstra where state = (cost, city, stops_remaining). Skip if stops < 0.

### Time: O(E × k × log(E×k)) | Space: O(V × k)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| BFS | O(V×E) | O(V) | Level = stops |
| Bellman-Ford k-iter | O(k×E) | O(V) | Limit iterations to k+1 |
| Modified Dijkstra | O(Ek log) | O(Vk) | Priority queue with stop count |

<br>
<br>

---

```code```
