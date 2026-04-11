Return the postorder traversal of a binary tree (Left → Right → Root).

<br>

> Input: root = [1, null, 2, 3]
> Output: [3, 2, 1]

> Explanation: Visit left subtree, right subtree, then root. Root is processed LAST.
> 
> **Key insight:** Iterative trick: Preorder is Root→Left→Right. If we do Root→Right→Left (push left before right) then REVERSE the result → Left→Right→Root = Postorder!

<br>

---

## Constraints
- `0 ≤ N ≤ 100`

<br>

---

## Solution 1: Recursive

### Time: O(N) | Space: O(H)

> **Drawback:** O(H) stack space.

> **Key Insight for Improvement:** Modified preorder: do Root→Right→Left, then reverse. Or use two stacks.

<br>

---

## Solution 2: Modified Preorder + Reverse (Optimal trick)

**Algorithm:**
1. Same as preorder but push LEFT first, then RIGHT (so right processed next)
2. This gives Root→Right→Left order
3. Reverse → Left→Right→Root = Postorder

### Time Complexity: O(N)
### Space Complexity: O(N) (for result reversal)

**Example walkthrough:**
```
Tree: [1, 2, 3]

Pop 1 → [1], push 2, push 3 → stack=[2,3]
Pop 3 → [1,3], push children...
Pop 2 → [1,3,2]
Reverse: [2,3,1] = postorder ✓
```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursive | O(N) | O(H) | Simple L→R→Root |
| Modified Preorder | O(N) | O(N) | Root→R→L reversed = postorder |

**Key Insights:**
1. **Reverse trick:** Preorder(Root→R→L) reversed = Postorder
2. **Push order:** Left before right → right processed first
3. **Postorder use cases:** Delete tree, evaluate expression tree, dependency resolution

<br><br>

---

```code```
