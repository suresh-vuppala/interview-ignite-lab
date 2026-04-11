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

## Solution: Postorder DFS (Optimal)

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
