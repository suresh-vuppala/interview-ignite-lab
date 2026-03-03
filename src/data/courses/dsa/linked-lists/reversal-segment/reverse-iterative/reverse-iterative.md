# Reverse Iterative

## Overview
Learn to reverse a linked list using iterative approach with pointer manipulation.

## Topics Covered
1. **Three Pointer Technique**: Use prev, curr, next pointers
2. **In-place Reversal**: Reverse without extra space
3. **Handle Edge Cases**: Empty list, single node
4. **Step-by-step Process**: Understand each pointer update

## Problem Statement
Reverse a singly linked list iteratively by changing the direction of next pointers.

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