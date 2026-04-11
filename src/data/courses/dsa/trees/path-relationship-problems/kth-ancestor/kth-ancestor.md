Find the Kth ancestor of a given node in a binary tree.

<br>

> Input: root = [1,2,3,4,5], node=5, k=2
> Output: 1 (5→2→1, 2nd ancestor is 1)
> **Key insight:** Find path from root to target node. The Kth ancestor is path[len-1-k].

<br>

---

## Constraints
- `1 ≤ N ≤ 10⁴`

<br>

---

## Solution: Find Path from Root, Index Back (Optimal for single query)

**Algorithm:**
1. DFS to find path from root to target node
2. If path length > k: return path[path.length - 1 - k]
3. Else: no Kth ancestor exists

### Time Complexity: O(N)
### Space Complexity: O(H)

> **Drawback:** O(N) per query. For many queries, precompute with binary lifting O(N log N) preprocessing, O(log N) per query.

> **Key Insight for Improvement:** Binary lifting: precompute ancestor[node][k] = 2^k-th ancestor. Query any Kth ancestor in O(log K). But for single query, path-finding is simpler.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Use Case |
|----------|------|-------|----------|
| Path Finding | O(N) | O(H) | Single query |
| Binary Lifting | O(N log N) prep, O(log K) query | O(N log N) | Multiple queries |

**Key Insights:**
1. **Single query:** Find path, index back
2. **Multiple queries:** Binary lifting precomputation
3. **Path = ancestors:** path[i] is the (len-1-i)-th ancestor of the target

<br><br>

---

```code```
