Perform preorder traversal (Root → Left → Right) of a binary tree.

<br>

> Input: [1,null,2,3]
> Output: [1,2,3]

<br>

---

## Constraints

- `0 ≤ n ≤ 100`
- `-100 ≤ Node.val ≤ 100`

<br>

---

## All Possible Edge Cases

1. **Empty tree:** Return []
2. **Single node:** Return [val]
3. **Left-skewed:** Root first, then descending
4. **Right-skewed:** Root first, then ascending

<br>

---

## Solution 1: Recursive

**Intuition:** Visit root, recurse left, recurse right.

```
void preorder(node):
    if node is null: return
    visit(node.val)
    preorder(node.left)
    preorder(node.right)
```

### Time: O(n) | Space: O(h) recursion stack

<br>

---

## Solution 2: Iterative (Stack)

**Intuition:** Use explicit stack. Push root, then repeatedly: pop → visit → push right → push left (right first so left is processed first).

### Time: O(n) | Space: O(h) stack

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursive | O(n) | O(h) | Natural tree recursion |
| Iterative | O(n) | O(h) | Explicit stack, no recursion limit |

<br>
<br>

---

```code```
