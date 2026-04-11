## Overview
Convert sorted array to height-balanced BST using divide-and-conquer.

## Problem Statement
Build height-balanced BST from sorted array (O(n) time).

## Approach
- Pick middle element as root (ensures balance)
- Recursively build left from left half
- Recursively build right from right half

## Complexity Analysis
- **Time**: O(n)
- **Space**: O(log n)

## Code



---

## Constraints

- `1 ≤ nums.length ≤ 10⁴`
- `nums is sorted in ascending order`

<br>

---

## All Possible Edge Cases

1. **Single element:** Return single node
2. **Two elements:** Root + one child
3. **Odd length:** Middle element is root
4. **Even length:** Either middle works

<br>

---

```code```
