Two nodes in a BST are swapped by mistake. Recover the BST without changing its structure.

<br>

> Input: [3,1,4,null,null,2] (2 and 3 swapped)
> Output: [2,1,4,null,null,3]
> **Key insight:** Inorder should be sorted. Find two violations: first violation = first node too large, second violation = second node too small. Swap their values.

<br>

---

## Constraints
- `2 ≤ N ≤ 1000`

<br>

---

## Solution: Inorder + Find Two Violations (Optimal)

**Algorithm:** Inorder traversal tracking prev. If prev.val > curr.val → violation. First violation: first = prev. Second violation: second = curr. After traversal: swap first.val and second.val.

### Time Complexity: O(N)
### Space Complexity: O(H)

> **Drawback:** Recursive uses O(H) space. Morris traversal gives O(1) space.

> **Key Insight for Improvement:** Adjacent swap: only one violation. Non-adjacent: two violations at different places. Handle both cases with first/second tracking.

<br>

---

**Key Insights:**
1. **Inorder must be sorted:** Violations indicate swapped nodes
2. **First violation: prev is the larger swapped node**
3. **Second violation: curr is the smaller swapped node**
4. **Just swap values:** Don't restructure the tree

<br><br>

---

```code```
