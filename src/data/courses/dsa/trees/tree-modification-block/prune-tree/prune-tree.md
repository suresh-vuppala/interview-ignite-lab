Prune a binary tree so that subtrees not containing a 1 are removed. Return the pruned tree.

<br>

> Input: root = [1,null,0,0,1]
> Output: [1,null,0,null,1]
> **Key insight:** Postorder DFS. If a subtree contains no 1s → prune it (return null). A node is kept if its value is 1 OR any descendant has value 1.

<br>

---

## Constraints
- `1 ≤ N ≤ 200`, values are 0 or 1

<br>

---

## All Possible Edge Cases
1. **Entire tree contains no 1: return null**
2. **Root = 0 but subtrees have 1: keep root
3. **All nodes = 1: unchanged**

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

**Algorithm:** Process children first. If both children null AND node.val == 0 → prune (return null). Else keep.

### Time Complexity: O(N)
### Space Complexity: O(H)

> **Drawback:** None.

> **Key Insight for Improvement:** Same pattern as delete-leaves but condition is "subtree has no 1" instead of matching a target value.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Postorder | O(N) | O(H) |

**Key Insights:**
1. **Same as delete-leaves:** Postorder bottom-up pruning
2. **Keep condition:** node.val == 1 OR has any descendant with 1
3. **Prune condition:** node.val == 0 AND both children pruned

<br><br>

---

```code```
