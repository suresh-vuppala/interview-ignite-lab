## Problem
Find longest subarray of 1s after flipping at most K zeros.

## Approach
Sliding window counting zeros.

## Algorithm
1. Expand right, count zeros
2. If zeros > K, shrink from left
3. Track maximum window size

## Time Complexity
O(n)

## Space Complexity
O(1)

## Code
```code```