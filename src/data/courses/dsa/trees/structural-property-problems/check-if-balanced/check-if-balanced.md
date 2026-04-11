## Overview
Determine if binary tree is height-balanced (height difference  1 for all subtrees).

## Problem Statement
A balanced tree has left/right height difference  1 at each node.

## Approach
- Recursive: get height, check balance at each level
- Return -1 if unbalanced (pruning)
- Time: O(n) due to early termination

## Complexity Analysis
- **Time**: O(n)
- **Space**: O(h)

## Code



---

## Constraints

- `0 ≤ n ≤ 5000`
- `-10⁴ ≤ Node.val ≤ 10⁴`

<br>

---

## All Possible Edge Cases

1. **Empty tree:** Balanced
2. **Single node:** Balanced
3. **Skewed tree:** Not balanced (depth diff > 1)
4. **Off by one:** Heights differ by exactly 1 — still balanced
5. **Off by two:** Not balanced

<br>

---

```code```
