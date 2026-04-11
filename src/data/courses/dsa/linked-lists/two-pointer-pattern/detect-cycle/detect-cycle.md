## Overview
Learn Floyd's Cycle Detection Algorithm (Tortoise and Hare) to detect if a linked list has a cycle.

## Topics Covered
1. **Floyd's Algorithm**: Slow and fast pointer technique
2. **Cycle Detection Logic**: Why fast catches slow in cycle
3. **Handle No Cycle**: Fast reaches null
4. **Time Optimization**: O(n) single pass solution

## Problem Statement
Determine if a linked list has a cycle using two pointers.


---

## Constraints

- `0 ≤ n ≤ 10⁴`
- `-10⁵ ≤ Node.val ≤ 10⁵`
- `pos is -1 (no cycle) or valid index`

<br>

---

## All Possible Edge Cases

1. **No cycle:** Fast reaches null → false
2. **Cycle at head:** Tail connects back to head
3. **Cycle at middle:** Tail connects to mid-node
4. **Single node, self-loop:** Cycle of length 1
5. **Single node, no cycle:** false
6. **Two nodes with cycle:** Tail points to head

<br>

## Approach

### Floyd's Cycle Detection
- Use slow (1 step) and fast (2 steps) pointers
- If cycle exists, they will meet
- If no cycle, fast reaches null
- Time: O(n), Space: O(1)

## Complexity Analysis

### Time Complexity: O(n)
### Space Complexity: O(1)

## Code

```code```
