Convert a binary tree to a doubly linked list using inorder traversal. Left pointer = prev, Right pointer = next.

<br>

> Input: root = [4,2,5,1,3]
> Output: DLL: 1↔2↔3↔4↔5 (inorder)
> **Key insight:** Inorder DFS. Maintain a `prev` pointer. For each node: node.left = prev, prev.right = node. Track head (first node visited).

<br>

---

## Constraints
- `1 ≤ N ≤ 10⁵`

<br>

---

## Solution: Inorder DFS with Prev Pointer (Optimal)

**Algorithm:** Inorder traversal. Maintain prev. First node (prev == null) = head. For each subsequent node: node.left = prev, prev.right = node. Update prev.

### Time Complexity: O(N)
### Space Complexity: O(H)

> **Drawback:** Recursive O(H) space. Morris inorder can achieve O(1) space.

> **Key Insight for Improvement:** Same prev-pointer technique as flatten, but using inorder instead of reverse postorder.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Inorder + Prev | O(N) | O(H) |

**Key Insights:**
1. **Inorder = sorted order for BST:** DLL will be sorted
2. **Prev pointer pattern:** Same as flatten — link nodes during traversal
3. **Track head:** First node in inorder is the DLL head

<br><br>

---

```code```
