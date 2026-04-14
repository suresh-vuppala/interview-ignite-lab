Find the distance (number of edges) between two nodes in a binary tree.

<br>

> Input: root = [3,5,1,6,2,0,8,null,null,7,4], p=5, q=0
> Output: 3 (path: 5→3→1→0, distance=3 edges)
> **Key insight:** distance(p, q) = depth(p) + depth(q) - 2 × depth(LCA(p, q)). Find LCA first, then compute depths.

<br>

---

## Constraints
- `2 ≤ N ≤ 10⁴`

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
> Use LCA + Depth Calculation (Optimal) for O(N) time.

<br>

---

## Solution 2: LCA + Depth Calculation (Optimal)

**Algorithm:**
1. Find LCA of p and q
2. dist(p, q) = depth(p, lca) + depth(q, lca)

### Time Complexity: O(N)
**Why?** LCA: O(N). Two depth calculations from LCA: O(H) each. Total: O(N).

### Space Complexity: O(H)

> **Drawback:** None — requires finding LCA which is O(N).

> **Key Insight for Improvement:** Already optimal. The formula dist = depthP + depthQ - 2*depthLCA is fundamental.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| LCA + Depths | O(N) | O(H) |

**Key Insights:**
1. **Formula:** dist(p,q) = depth(p from LCA) + depth(q from LCA)
2. **Reuses LCA:** Same algorithm from LCA problem
3. **Alternative formula:** dist = depth(p) + depth(q) - 2*depth(LCA)

<br><br>

---

```code```
