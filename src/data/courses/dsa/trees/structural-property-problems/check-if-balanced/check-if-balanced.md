Check if a binary tree is height-balanced (height difference of left and right subtrees ≤ 1 for every node).

<br>

> Input: [3,9,20,null,null,15,7] → true
> Input: [1,2,2,3,3,null,null,4,4] → false

<br>

---

## Constraints

- `0 ≤ n ≤ 5000`

<br>

---

## Solution 1: Top-Down (Brute Force)

**Intuition:** For each node, compute height of left and right subtrees. Check if difference ≤ 1, then recurse.

**Problem:** Height computation is repeated for lower nodes → redundant work.

### Time: O(n²) — height called for every node
### Space: O(h)

<br>

---

## Solution 2: Bottom-Up (Optimal)

**Intuition:** Compute height AND check balance in a single pass. If any subtree is unbalanced, return -1 immediately.

**Algorithm:**
```
int checkHeight(node):
    if null: return 0
    left = checkHeight(node.left)
    if left == -1: return -1  // Left unbalanced
    right = checkHeight(node.right)
    if right == -1: return -1  // Right unbalanced
    if |left - right| > 1: return -1  // Current unbalanced
    return 1 + max(left, right)
```

### Time: O(n) — each node visited once
### Space: O(h)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Top-Down | O(n²) | O(h) | Recomputes height at every level |
| Bottom-Up | O(n) | O(h) | Compute height + check in one pass |

<br>
<br>

---

```code```
