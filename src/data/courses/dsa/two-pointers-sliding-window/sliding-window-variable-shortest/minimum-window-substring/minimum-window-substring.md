## Problem
Find minimum window in s containing all characters of t.

## Approach
Sliding window with character frequency tracking.

## Algorithm
1. Count characters in t
2. Expand right, decrease count
3. When all matched, shrink left to minimize
4. Track minimum window

## Time Complexity
O(n + m)

## Space Complexity
O(1) - fixed alphabet

## Code
```code```