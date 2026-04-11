Determine if a binary tree is height-balanced — the depth of the two subtrees of every node never differ by more than 1.

<br>

> Input: root = [3,9,20,null,null,15,7]
> Output: true

> Explanation: Every node's left and right subtree heights differ by ≤ 1.
> 
> **Key insight:** Compute height bottom-up. If any subtree is unbalanced, return -1 immediately (early termination). Otherwise return actual height.

<br>

---

## Constraints
- `0 ≤ N ≤ 5000`

<br>

---

## Solution 1: Top-Down — Check Height at Each Node

**Intuition:** For each node, compute heights of left and right subtrees and check if they differ by > 1.

### Time Complexity: O(N²)
**Why?** For each of N nodes, height computation takes O(N) → O(N²).

> **Drawback:** Recomputing heights from scratch at every node. Height of the same subtree computed multiple times.

> **Key Insight for Improvement:** Bottom-up: compute height recursively, returning -1 if any subtree is unbalanced. Each node visited exactly once → O(N).

<br>

---

## Solution 2: Bottom-Up Height Check (Optimal)

**Algorithm:**
1. Helper function returns height if balanced, -1 if unbalanced
2. If left or right subtree returns -1 → propagate -1
3. If |leftHeight - rightHeight| > 1 → return -1
4. Else return 1 + max(leftH, rightH)

### Time Complexity: O(N)
**Why?** Each node visited exactly once. Early termination when unbalanced.

**Detailed breakdown:** N = 5000 → at most 5000 operations

**Example walkthrough:**
```
Tree: [1, 2, 2, 3, 3, null, null, 4, 4]

height(4) = 1, height(4) = 1
height(3) = 2, height(3) = 2
height(2, left) = 3, height(2, right) = 1
|3 - 1| = 2 > 1 → return -1 → NOT BALANCED
```

### Space Complexity: O(H)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Top-Down | O(N²) | O(H) | Check each node, recompute heights |
| Bottom-Up | O(N) | O(H) | Compute height once, propagate -1 |

**Key Insights:**
1. **-1 sentinel:** Signals "unbalanced" — avoids separate boolean tracking
2. **Bottom-up avoids recomputation:** Height computed once per node
3. **Early termination:** -1 propagates upward immediately

<br><br>

---

```code```
