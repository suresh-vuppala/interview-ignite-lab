## Overview
Check if one tree is a subtree of another (exact match at some node).

## Problem Statement
Check if tree s is a subtree of tree t (starting at some node in t).

## Approach
- For each node in t, check if it matches s
- Use isSameTree helper
- DFS on t to find potential roots

## Complexity Analysis
- **Time**: O(n*m) where n=t.size, m=s.size
- **Space**: O(h)

## Code



---

## Constraints

- `1 ≤ root nodes ≤ 2000`
- `1 ≤ subRoot nodes ≤ 1000`
- `-10⁴ ≤ Node.val ≤ 10⁴`

<br>

---

## All Possible Edge Cases

1. **subRoot is entire tree:** true
2. **subRoot is leaf of tree:** true
3. **Empty subRoot:** true (empty tree is subtree of any tree)
4. **subRoot not found:** false
5. **Multiple occurrences:** Match any one

<br>

---

```code```
