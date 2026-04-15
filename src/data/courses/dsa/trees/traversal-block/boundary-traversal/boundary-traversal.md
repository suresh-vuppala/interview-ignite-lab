Print the boundary of a binary tree in anti-clockwise direction: left boundary (top-down) → leaf nodes (left-right) → right boundary (bottom-up).

<br>

> Input: root = [1,2,3,4,5,6,7,null,null,8,9]
> Output: [1, 2, 4, 8, 9, 6, 7, 3]

> Explanation: Left boundary: [1,2,4]. Leaves: [8,9,6,7]. Right boundary (bottom-up): [3]. Combined without duplicates.
> 
> **Key insight:** Three separate traversals: left boundary (exclude leaves), all leaves (left to right), right boundary in reverse (exclude leaves). Combine results.

<br>

---

## Constraints
- `1 ≤ N ≤ 10⁵`

<br>

---

## All Possible Edge Cases
1. **Single node:** just the root
2. **Only left / only right children**
3. **Complete tree**

<br>

---

## Solution 1: DFS collecting all then filtering

**Intuition:**
The most straightforward approach — three-part approach (left boundary + leaves + right boundary) is cleaner.

**Algorithm:**
1. Apply the naive/brute approach as described
2. Check all possibilities or use a simpler data structure
3. Return the result

### Time Complexity: O(N)
**Why?**
The brute approach doesn't exploit the problem's structure efficiently, leading to redundant work.

**Detailed breakdown:**
For typical constraint sizes, this approach may be too slow or use too much space.

### Space Complexity: O(1) or O(N) depending on approach

> **Drawback:**
> Three-part approach (left boundary + leaves + right boundary) is cleaner.

> **Key Insight for Improvement:**
> Use Three-Part Traversal (Optimal) for O(N) time.

<br>

---

## Solution 2: Three-Part Traversal (Optimal)

**Algorithm:**
1. Add root (if not leaf)
2. Left boundary: go left (or right if no left) until leaf, add each node
3. All leaves: DFS, add only leaves
4. Right boundary: go right (or left if no right) until leaf, add to temp, reverse temp

### Time Complexity: O(N)
**Why?** Leaves traversal visits all nodes. Boundary paths are at most O(H) each. Total: O(N).

**Detailed breakdown:** N = 100,000 → one full DFS for leaves + two O(H) boundary walks

### Space Complexity: O(H) for DFS recursion

> **Drawback:** Three separate passes. But combined work is still O(N).

> **Key Insight for Improvement:** Can be done in single DFS with flags, but three-part approach is cleaner and easier to debug.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Three-Part | O(N) | O(H) | Left boundary + leaves + right boundary reversed |

**Key Insights:**
1. **Avoid duplicates:** Root is not re-added in leaf traversal if it's a leaf
2. **Right boundary reversed:** Collect top-down, then reverse for bottom-up order
3. **Interview tip:** Draw the tree and trace the anti-clockwise boundary before coding

<br><br>

---

```code```
