Flatten a binary tree to a linked list in-place using preorder traversal. Use right pointers as next, set all left pointers to null.

<br>

> Input: root = [1,2,5,3,4,null,6]
> Output: [1,null,2,null,3,null,4,null,5,null,6]
> **Key insight:** Process right-to-left postorder (right→left→root). Maintain a `prev` pointer. Each node's right points to prev, left to null.

<br>

---

## Constraints
- `0 ≤ N ≤ 2000`

<br>

---

## Solution 1: Preorder to Array, Rebuild

### Time: O(N) | Space: O(N) — stores all nodes

> **Drawback:** Extra O(N) space. Can we do it in-place?

> **Key Insight for Improvement:** Reverse postorder (right→left→root) with a prev pointer. Each node's right = prev, left = null. This modifies the tree in-place with O(H) stack space.

<br>

---

## Solution 2: Reverse Postorder with Prev Pointer (Optimal)

**Algorithm:** Process in reverse preorder (right→left→root). Each node: right = prev, left = null. Update prev = current.

### Time Complexity: O(N)
### Space Complexity: O(H)

**Example walkthrough:**
```
Tree: [1,2,5,3,4,null,6]
Reverse preorder: 6, 5, 4, 3, 2, 1

Process 6: right=null(prev), prev=6
Process 5: right=6(prev), prev=5
Process 4: right=5(prev), prev=4
Process 3: right=4(prev), prev=3
Process 2: right=3(prev), prev=2
Process 1: right=2(prev), prev=1

Result: 1→2→3→4→5→6 ✓
```

> **Drawback:** Recursive O(H) space.

> **Key Insight for Improvement:** Morris-style O(1) space: for each node, find rightmost of left subtree, point it to right child, then move left subtree to right.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Array rebuild | O(N) | O(N) | Preorder → array → linked list |
| Reverse postorder | O(N) | O(H) | Prev pointer technique |

**Key Insights:**
1. **Reverse postorder:** right→left→root → processes last node first
2. **Prev pointer:** Links nodes in preorder without extra storage
3. **Morris variant:** O(1) space by threading left subtree's rightmost to right child

<br><br>

---

```code```
