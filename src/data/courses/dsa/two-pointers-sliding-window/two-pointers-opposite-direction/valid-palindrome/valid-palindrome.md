## Problem
Check if string is palindrome (considering only alphanumeric, ignoring case).

## Approach
Two pointers from both ends, skip non-alphanumeric, compare.

## Algorithm
1. Initialize left = 0, right = n-1
2. Skip non-alphanumeric characters
3. Compare characters (case-insensitive)
4. Move pointers inward
5. Return true if all match

## Time Complexity
O(n)

## Space Complexity
O(1)

## Code
```code```