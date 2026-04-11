## Overview
Comprehensive solution for Paths with Sum

## Problem Statement
Implement Paths with Sum

## Approach
Use appropriate tree algorithms and data structures

## Complexity Analysis
- **Time**: O(n) or O(n log n)
- **Space**: O(h) or O(n)

## Code



---

## Constraints

- `0 ≤ n ≤ 1000`
- `-10⁹ ≤ Node.val ≤ 10⁹`
- `-1000 ≤ targetSum ≤ 1000`

<br>

---

## All Possible Edge Cases

1. **Path can start at any node:** Not just root
2. **Path must go downward:** No going up to parent
3. **Single node equals target:** Count it
4. **Empty tree:** Return 0
5. **Prefix sum technique:** Use hashmap for O(n)

<br>

---

```code```
