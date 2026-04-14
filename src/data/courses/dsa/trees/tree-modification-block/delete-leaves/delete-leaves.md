Delete all leaf nodes with a given target value. After deletion, new leaves with target value should also be deleted (repeat until stable).

<br>

> Input: root = [1,2,3,2,null,2,4], target = 2
> Output: [1,null,3,null,4]
> **Key insight:** Postorder DFS. Process children first, then check if current node became a leaf with target value. Return null to delete it.

<br>

---

## Constraints
- `1 ≤ N ≤ 3000`

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
> Use Postorder DFS (Optimal) for O(N) time.

<br>

---

## Solution 2: Postorder DFS (Optimal)

**Algorithm:** Process left and right children first (postorder). If current node is now a leaf AND val == target → return null (delete). Else return node.

### Time Complexity: O(N)
### Space Complexity: O(H)

> **Drawback:** None — postorder naturally handles cascading deletions.

> **Key Insight for Improvement:** Postorder ensures children are processed before parent. If deleting a child makes parent a target leaf, parent gets deleted too — automatically.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Postorder DFS | O(N) | O(H) |

**Key Insights:**
1. **Postorder = bottom-up:** Children processed before parents
2. **Cascading deletion:** Deleting children may expose parent as new target leaf
3. **Return null to delete:** Parent's pointer to child becomes null

<br><br>

---

```code```
