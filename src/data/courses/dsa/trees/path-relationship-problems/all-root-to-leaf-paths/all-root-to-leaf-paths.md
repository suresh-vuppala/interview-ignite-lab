Return all root-to-leaf paths as strings.

<br>

> Input: root = [1,2,3,null,5]
> Output: ["1->2->5", "1->3"]
> **Key insight:** DFS with path tracking. At leaf nodes, add the current path to results.

<br>

---

## Constraints
- `1 ≤ N ≤ 100`

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
> Use DFS with Path Tracking (Optimal) for O(N) time.

<br>

---

## Solution 2: DFS with Path Tracking (Optimal)

**Algorithm:** DFS passing current path string. At leaf → add to result. Else → recurse left/right.

### Time Complexity: O(N)
**Why?** Visit each node once. String copying: O(H) per path, O(N×H) worst case.

**Detailed breakdown:** N = 100 → 100 operations + path string building

### Space Complexity: O(H) recursion + O(N×H) for result paths

> **Drawback:** String concatenation can be expensive. Use vector<int> and join at leaf for efficiency.

> **Key Insight for Improvement:** Pass path by reference and backtrack (remove last element after recursion) for less memory allocation.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| DFS + Path String | O(N×H) | O(N×H) | Concatenate path, add at leaf |
| DFS + Backtrack | O(N×H) | O(H) | Reuse path vector |

**Key Insights:**
1. **Leaf check:** Both children null → complete path
2. **Backtracking:** Remove last node after recursing both children
3. **Foundation:** Template for path-sum, path-sum-II, all path problems

<br><br>

---

```code```
