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

## All Possible Edge Cases
1. **K = 0:** the node itself
2. **K exceeds depth:** doesn't exist
3. **K = depth:** root
4. **Node is root, K > 0: doesn't exist**

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
> Use Find Path from Root, Index Back (Optimal for single query) for O(N) time.

<br>

---

## Solution 2: Find Path from Root, Index Back (Optimal for single query)

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
