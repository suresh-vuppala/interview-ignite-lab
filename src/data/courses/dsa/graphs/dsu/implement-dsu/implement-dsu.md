Implement Disjoint Set Union (Union-Find) with path compression and union by rank.

<br>

> Input: n=5, union(0,1), union(2,3), union(0,2), find(0)==find(3)? → true
> **Key insight:** Two optimizations: path compression (flatten tree on find) + union by rank (attach smaller tree under larger). Together: nearly O(1) amortized per operation — O(α(N)) where α is inverse Ackermann.

<br>

---

## Constraints
- `1 ≤ N ≤ 10⁵`

<br>

---

## Solution: Path Compression + Union by Rank (Optimal)

**Algorithm:**
- find(x): Follow parent pointers to root. Path compression: point all nodes on path directly to root.
- union(x,y): Find roots. If different, attach smaller rank tree under larger.

### Time Complexity: O(α(N)) ≈ O(1) amortized per operation
**Why?** Path compression + union by rank. α(N) ≤ 4 for all practical N.

**Detailed breakdown:** N = 100,000 → each find/union ≈ 4 operations

### Space Complexity: O(N)

> **Drawback:** None — this is the optimal DSU implementation.

> **Key Insight for Improvement:** Already optimal. Two optimizations together give inverse Ackermann amortized time — effectively constant.

<br>

---

## Complexity Progression Summary

| Optimization | find() | union() |
|-------------|--------|---------|
| None | O(N) | O(N) |
| Path compression only | O(log N) amortized | O(log N) |
| Union by rank only | O(log N) | O(log N) |
| Both | O(α(N)) ≈ O(1) | O(α(N)) ≈ O(1) |

**Key Insights:**
1. **Path compression:** Make every node point directly to root during find
2. **Union by rank:** Attach shorter tree under taller tree
3. **Applications:** Connected components, cycle detection, Kruskal's MST, accounts merge

<br><br>

---

```code```
