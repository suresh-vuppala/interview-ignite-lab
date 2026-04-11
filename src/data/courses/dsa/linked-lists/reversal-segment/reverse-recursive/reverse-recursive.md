## Overview
Learn to reverse a linked list using recursive approach.

## Topics Covered
1. **Recursive Logic**: Understand base case and recursive case
2. **Call Stack**: How recursion builds and unwinds
3. **Pointer Adjustment**: Reverse pointers during unwinding
4. **Compare with Iterative**: Understand trade-offs

## Problem Statement
Reverse a singly linked list using recursion.


---

## Constraints

- `0 ≤ n ≤ 5000`
- `-5000 ≤ Node.val ≤ 5000`

<br>

---

## All Possible Edge Cases

1. **Empty list:** Return null
2. **Single node:** Return as-is
3. **Large list:** Recursion depth = n — potential stack overflow
4. **Two nodes:** Base recursive case

<br>

## Approach

### Recursive Reversal
- Base case: If head is null or single node, return
- Recursive case: Reverse rest of list
- Adjust pointers during unwinding
- Time: O(n), Space: O(n) for call stack

## Complexity Analysis

### Time Complexity: O(n)
### Space Complexity: O(n) due to recursion stack

## Code

```code```
