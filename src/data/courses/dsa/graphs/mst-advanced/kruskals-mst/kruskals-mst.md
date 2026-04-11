Find the Minimum Spanning Tree using Kruskal's algorithm. Sort edges by weight, add edges using DSU if they don't form a cycle.

<br>

---

## Constraints

- `1 ≤ V ≤ 10⁵`
- `V-1 ≤ E ≤ V×(V-1)/2`
- `Connected undirected graph`
- `Edge weights can be negative`

<br>

---

## All Possible Edge Cases

1. **Already a tree:** MST = the tree itself
2. **All edges same weight:** Any spanning tree is MST
3. **Single node:** Empty MST
4. **Multiple MSTs:** When equal weight edges exist
5. **Disconnected graph:** MST doesn't exist — check components

<br>

---

```code```
