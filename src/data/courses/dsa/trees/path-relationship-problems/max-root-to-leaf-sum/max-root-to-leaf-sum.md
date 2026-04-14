Find the maximum sum of any root-to-leaf path.

<br>

> Input: root = [10,5,-3,3,2,null,11]
> Output: 18 (path: 10→-3→11)
> **Key insight:** DFS returning max(leftPathSum, rightPathSum) + node.val. At leaf, return node.val.

<br>

---

## Constraints
- `1 ≤ N ≤ 10⁴`

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
> Use DFS — Max Path (Optimal) for O(N) time.

<br>

---

## Solution 2: DFS — Max Path (Optimal)

**Algorithm:** At leaf return val. Else return val + max(maxSum(left), maxSum(right)).

### Time Complexity: O(N)
### Space Complexity: O(H)

> **Drawback:** None — must visit all nodes.

> **Key Insight for Improvement:** Handle null children: if only one child, must go that way (can't choose null path).

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| DFS | O(N) | O(H) |

**Key Insights:**
1. **Leaf base case:** Return node.val (not 0)
2. **One child null:** Only consider the non-null child's path
3. **Different from max-path-sum:** This is root-to-LEAF only, not any-to-any

<br><br>

---

```code```
