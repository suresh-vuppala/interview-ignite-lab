Return the preorder traversal of a binary tree (Root → Left → Right).

<br>

> Input: root = [1, null, 2, 3]
> Output: [1, 2, 3]

> Explanation: Visit root first, then left subtree, then right subtree.
> 
> **Key insight:** Iterative: push right child first, then left (so left is processed first from stack). Or use same push-left-go-right pattern as inorder but process node BEFORE pushing.

<br>

---

## Constraints
- `0 ≤ N ≤ 100`

<br>

---

## Solution 1: Recursive

### Time Complexity: O(N) | Space: O(H)

> **Drawback:** O(H) stack space.

> **Key Insight for Improvement:** Iterative with stack: push root, pop → process → push right then left. Simple and clean.

<br>

---

## Solution 2: Iterative with Stack (Optimal)

**Algorithm:**
1. stack = [root]
2. While stack not empty:
   - node = pop → process (add to result)
   - Push right child first (processed later)
   - Push left child (processed next)

### Time Complexity: O(N)
### Space Complexity: O(H)

**Example walkthrough:**
```
Tree: [1, 2, 3]

Pop 1 → result=[1], push 3, push 2 → stack=[3,2]
Pop 2 → result=[1,2] → stack=[3]
Pop 3 → result=[1,2,3] → stack=[]

Result: [1, 2, 3] ✓
```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursive | O(N) | O(H) | Simple |
| Iterative | O(N) | O(H) | Push right first, then left |

**Key Insights:**
1. **Push order matters:** Right before left → left processed first (LIFO)
2. **Preorder = DFS order:** Used in serialization, tree copying, prefix expression
3. **vs Inorder:** Process BEFORE going left (not after)

<br><br>

---

```code```
