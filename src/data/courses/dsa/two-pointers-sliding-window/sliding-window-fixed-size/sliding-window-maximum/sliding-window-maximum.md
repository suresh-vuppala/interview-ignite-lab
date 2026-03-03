## Problem
Find maximum in each window of size K.

## Approach
Use deque to maintain decreasing order of elements.

## Algorithm
1. Use deque to store indices
2. Remove indices outside window
3. Remove smaller elements from back
4. Front of deque is maximum

## Time Complexity
O(n)

## Space Complexity
O(k)

## Code
```code```