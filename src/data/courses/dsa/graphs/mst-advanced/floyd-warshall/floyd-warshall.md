All-pairs shortest paths.

<br>

---

## Solution 1: Floyd-Warshall DP

**Intuition:** For each intermediate vertex k, check if path i→k→j is shorter than current i→j.

**Algorithm:**
```
for k = 0 to V-1:
    for i = 0 to V-1:
        for j = 0 to V-1:
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
```

**Negative cycle detection:** If dist[i][i] < 0 after algorithm → negative cycle.

### Time: O(V³) | Space: O(V²)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Floyd-Warshall | O(V³) | O(V²) | DP over intermediate vertices |

<br>
<br>

---

```code```
