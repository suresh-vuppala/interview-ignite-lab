A node X in the tree is "good" if there are no nodes with a greater value on the path from root to X. Count all good nodes.

<br>

> Input: root = [3,1,4,3,null,1,5]
> Output: 4 (good: 3, 3, 4, 5)

> Explanation: Root 3 is always good. Node 4 > 3 = good. Node 5 > max(3,4) = good. Node 3 (left-left): 3 ≥ max(3,1) = good. Node 1: 1 < 3 = not good.
> 
> **Key insight:** DFS tracking the maximum value seen on the path from root. If node.val ≥ maxSoFar → good node. Pass updated max to children.

<br>

---

## Constraints
- `1 ≤ N ≤ 10⁵`

<br>

---

## All Possible Edge Cases
1. **Root is always good**
2. **Strictly decreasing path:** only root
3. **All same values:** all nodes good
4. **Single node: 1 good node**

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
> Use DFS with Max Tracking (Optimal) for O(N) time.

<br>

---

## Solution 2: DFS with Max Tracking (Optimal)

**Algorithm:** DFS passing maxSoFar. If node.val ≥ maxSoFar → count++, update maxSoFar. Recurse children.

### Time Complexity: O(N)
**Why?** Visit each node once.

**Detailed breakdown:** N = 100,000 → 100,000 operations

### Space Complexity: O(H)

> **Drawback:** None — must visit all nodes.

> **Key Insight for Improvement:** Already optimal. Simple DFS with one parameter.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| DFS + Max | O(N) | O(H) |

**Key Insights:**
1. **Good = no greater ancestor:** node.val ≥ max of all ancestors
2. **Root is always good:** maxSoFar starts at -infinity (or root.val)
3. **Update max when going down:** Children see the updated maximum

<br><br>

---

```code```
