## Overview
Learn to reverse a linked list using iterative approach with pointer manipulation.

## Topics Covered
1. **Three Pointer Technique**: Use prev, curr, next pointers
2. **In-place Reversal**: Reverse without extra space
3. **Handle Edge Cases**: Empty list, single node
4. **Step-by-step Process**: Understand each pointer update

## Problem Statement
Reverse a singly linked list iteratively by changing the direction of next pointers.


---

## Constraints

- `0 ≤ n ≤ 5000`
- `-5000 ≤ Node.val ≤ 5000`

<br>

---

## All Possible Edge Cases

1. **Empty list:** Return null
2. **Single node:** Return as-is
3. **Two nodes:** Swap them
4. **Already reversed (sorted desc):** Results in ascending
5. **Large list:** Must be O(n) time O(1) space

<br>

## Approach

### Iterative Reversal
- Initialize prev = null, curr = head
- For each node:
  - Save next node
  - Reverse current node's pointer
  - Move prev and curr forward
- Update head to prev
- Time: O(n), Space: O(1)

## Complexity Analysis

### Time Complexity: O(n)
### Space Complexity: O(1)

## Code

```code```
