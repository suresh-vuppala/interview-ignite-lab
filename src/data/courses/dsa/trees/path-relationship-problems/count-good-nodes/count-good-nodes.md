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

## Solution: DFS with Max Tracking (Optimal)

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
