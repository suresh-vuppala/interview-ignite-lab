## Problem
Find sum of all subarrays of size K.

## Approach
Sliding window: add new element, remove old element.

## Algorithm
1. Calculate sum of first K elements
2. Slide window: add arr[i], remove arr[i-K]
3. Store/process each window sum

## Time Complexity
O(n)

## Space Complexity
O(1)

## Code
```code```