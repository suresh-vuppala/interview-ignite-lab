## Overview
Learn to find the node where the cycle begins in a linked list.

## Topics Covered
1. **Detect Cycle First**: Use Floyd's algorithm
2. **Find Start Node**: Mathematical approach
3. **Two-Phase Algorithm**: Detection then finding start
4. **Proof Understanding**: Why the algorithm works

## Problem Statement
Find the node where the cycle begins in a linked list.


---

## Constraints

- `0 ≤ n ≤ 10⁴`
- `pos is -1 or valid index`

<br>

---

## All Possible Edge Cases

1. **No cycle:** Return null
2. **Cycle starts at head:** Return head
3. **Cycle starts at tail:** Return tail node
4. **Long tail, short cycle:** Phase 2 from meeting point and head converge
5. **Single node cycle:** Return that node

<br>

## Approach

### Find Cycle Start
- Phase 1: Detect cycle using slow/fast pointers
- Phase 2: Move one pointer to head, advance both by 1
- They meet at cycle start
- Time: O(n), Space: O(1)

## Complexity Analysis

### Time Complexity: O(n)
### Space Complexity: O(1)

## Code

```code```
