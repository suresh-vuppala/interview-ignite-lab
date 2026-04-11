Perform postorder traversal (Left → Right → Root) of a binary tree.

<br>

---

## Constraints

- `0 ≤ n ≤ 100`

<br>

---

## Solution 1: Recursive

Visit left, right, then root.

### Time: O(n) | Space: O(h)

<br>

---

## Solution 2: Iterative (Two Stacks)

**Intuition:** Modified preorder (Root→Right→Left) then reverse the result gives postorder (Left→Right→Root).

### Time: O(n) | Space: O(n)

<br>

---

## Solution 3: Iterative (One Stack)

Track last visited node to determine whether to go left, right, or visit current.

### Time: O(n) | Space: O(h)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursive | O(n) | O(h) | Natural recursion |
| Two Stacks | O(n) | O(n) | Reverse modified preorder |
| One Stack | O(n) | O(h) | Track last visited |

<br>
<br>

---

```code```
