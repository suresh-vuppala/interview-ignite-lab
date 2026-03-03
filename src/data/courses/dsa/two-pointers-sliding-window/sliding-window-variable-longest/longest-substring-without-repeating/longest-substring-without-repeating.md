## Problem
Find length of longest substring without repeating characters.

## Approach
Variable sliding window with hashmap to track character positions.

## Algorithm
1. Use left and right pointers
2. Expand right, add characters to map
3. If duplicate found, shrink from left
4. Track maximum length

## Time Complexity
O(n)

## Space Complexity
O(min(n, alphabet size))

## Code
```code```