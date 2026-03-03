## Problem
Find first negative number in each window of size K.

## Approach
Use deque to store indices of negative numbers.

## Algorithm
1. Use deque to track negative number indices
2. Remove indices outside current window
3. First element in deque is answer for current window

## Time Complexity
O(n)

## Space Complexity
O(k)

## Code
```code```