## Overview
Find the maximum path sum in a binary tree. Path can start/end at any node (not necessarily root to leaf).

## Problem Statement
Return the maximum path sum where path can include any nodes.

## Approach
- DFS postorder: calculate max path through each node
- At each node, decide: continue path or start new
- Track global max during traversal
- Handle negative values: can ignore subtrees

## Complexity Analysis
- **Time**: O(n) - visit each node
- **Space**: O(h) - recursion stack

## Code



---

## Constraints

- `1 ≤ n ≤ 3 × 10⁴`
- `-1000 ≤ Node.val ≤ 1000`

<br>

---

## All Possible Edge Cases

1. **All negative values:** Pick least negative single node
2. **Single node:** Return its value
3. **Path through root:** Sum of left path + root + right path
4. **Path entirely in one subtree:** Don't include root
5. **Negative child paths:** Exclude them (max with 0)

<br>

---

```code```
