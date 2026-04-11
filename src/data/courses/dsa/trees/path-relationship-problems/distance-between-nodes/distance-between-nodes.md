## Overview
Comprehensive solution for Distance Between Nodes

## Problem Statement
Implement Distance Between Nodes

## Approach
Use appropriate tree algorithms and data structures

## Complexity Analysis
- **Time**: O(n) or O(n log n)
- **Space**: O(h) or O(n)

## Code



---

## Constraints

- `2 ≤ n ≤ 10⁵`
- `Both nodes exist in tree`

<br>

---

## All Possible Edge Cases

1. **Nodes are same:** Distance = 0
2. **Parent and child:** Distance = 1
3. **Nodes in different subtrees:** Distance = depth(p) + depth(q) - 2×depth(LCA)
4. **Node is root:** Distance = depth of other node

<br>

---

```code```
