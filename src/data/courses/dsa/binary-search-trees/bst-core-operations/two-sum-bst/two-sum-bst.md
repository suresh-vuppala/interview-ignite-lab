Given a BST and a target sum, find if there exist two nodes whose values add up to the target.

<br>

> Input: root = [5,3,6,2,4,null,7], k=9
> Output: true (2+7=9)
> **Key insight:** BST iterator approach: one iterator from smallest (inorder), one from largest (reverse inorder). Two-pointer technique on sorted sequence without materializing the array.

<br>

---

## Constraints
- `1 ≤ N ≤ 10⁴`

<br>

---

## Solution 1: Inorder to Array + Two Pointers — O(N) time, O(N) space

> **Drawback:** O(N) extra space for the sorted array.

> **Key Insight for Improvement:** Use two BST iterators (one forward, one reverse) for O(H) space. Or use a hash set during traversal for O(N) space but simpler code.

<br>

---

## Solution 2: Hash Set During Traversal (Simple Optimal)

**Algorithm:** DFS. For each node, check if (target - node.val) is in the set. Add node.val to set. If found → true.

### Time Complexity: O(N)
### Space Complexity: O(N)

> **Drawback:** O(N) space for hash set. BST iterator approach uses O(H).

> **Key Insight for Improvement:** Two BST iterators: one scanning left→right (smallest up), one right→left (largest down). Same as two-pointer on sorted array but O(H) space.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Array + Two Ptr | O(N) | O(N) |
| Hash Set | O(N) | O(N) |
| Two BST Iterators | O(N) | O(H) |

**Key Insights:**
1. **BST = sorted:** Two-pointer technique applies
2. **Hash set is simpler:** O(N) space but easy to implement
3. **Iterator approach is optimal space:** O(H) using two stacks

<br><br>

---

```code```
