## Problem
Check if typed string could be name with some characters long-pressed.

## Approach
Two pointers: one for name, one for typed. Match characters and handle repeats.

## Algorithm
1. Use two pointers i (name), j (typed)
2. If characters match, advance both
3. If typed[j] matches previous character, advance j only
4. Otherwise return false
5. Check if all name characters matched

## Time Complexity
O(n + m)

## Space Complexity
O(1)

## Code
```code```