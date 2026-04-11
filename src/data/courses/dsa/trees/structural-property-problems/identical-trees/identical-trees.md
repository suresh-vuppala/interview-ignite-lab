## Overview
Check if two binary trees are identical (same structure and values).

## Problem Statement
Determine if tree1 and tree2 are identical.

## Approach
- Base cases: both null (true), one null (false)
- Check values match, then recursively check subtrees
- Simple and elegant

## Complexity Analysis
- **Time**: O(min(n1, n2))
- **Space**: O(h)

## Code



---

## Constraints

- `0 ≤ n ≤ 100`
- `-10⁴ ≤ Node.val ≤ 10⁴`

<br>

---

## All Possible Edge Cases

1. **Both empty:** true
2. **One empty one not:** false
3. **Same structure different values:** false
4. **Same values different structure:** false
5. **Single node both:** Compare values

<br>

---

```code```
