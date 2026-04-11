Find all root-to-leaf paths where the sum equals a given target. Return the actual paths.

<br>

> Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], target = 22
> Output: [[5,4,11,2],[5,8,4,5]]
> **Key insight:** DFS with backtracking path. At leaf, if sum matches, copy path to result.

<br>

---

## Constraints
- `0 ≤ N ≤ 5000`

<br>

---

## Solution: DFS + Backtracking (Optimal)

**Algorithm:** Maintain current path. Add node. At leaf: if sum==target, copy path. Recurse. Remove node (backtrack).

### Time Complexity: O(N²) worst case
**Why?** Visit N nodes, copy path of O(H) at each leaf. Worst case: all paths valid → O(N × H).

### Space Complexity: O(H) path + O(N×H) result

> **Drawback:** Path copying at leaves. But unavoidable if we need to return paths.

> **Key Insight for Improvement:** Backtracking reuses the path vector — memory efficient compared to creating new paths at each level.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| DFS + Backtrack | O(N×H) | O(H) |

**Key Insights:**
1. **Backtrack pattern:** push_back before recursion, pop_back after
2. **Copy at leaf:** Only add path to result when target reached at leaf
3. **Path Sum I → II → III:** Increasing complexity of the same pattern

<br><br>

---

```code```
