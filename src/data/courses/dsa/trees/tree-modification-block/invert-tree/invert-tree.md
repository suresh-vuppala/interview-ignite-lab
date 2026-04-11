## Overview
Swap left and right subtrees for all nodes (mirror the tree).

## Problem Statement
Invert a binary tree so left becomes right and right becomes left.

## Approach
- DFS: swap children at each node
- Base case: null nodes
- Simple recursive solution

## Complexity Analysis
- **Time**: O(n)
- **Space**: O(h)

## Code



---

## Constraints

- `0 ≤ n ≤ 100`
- `-100 ≤ Node.val ≤ 100`

<br>

---

## All Possible Edge Cases

1. **Empty tree:** Return null
2. **Single node:** Return as-is
3. **Already symmetric:** Inversion gives same tree
4. **Skewed left:** Becomes skewed right

<br>

---

```code```
