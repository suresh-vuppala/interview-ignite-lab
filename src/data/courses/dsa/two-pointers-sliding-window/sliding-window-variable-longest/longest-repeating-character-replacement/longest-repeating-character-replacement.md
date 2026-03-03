## Problem
Find longest substring with same character after K replacements.

## Approach
Sliding window tracking most frequent character.

## Algorithm
1. Track character frequencies in window
2. If (window_size - max_freq) > K, shrink window
3. Update maximum length

## Time Complexity
O(n)

## Space Complexity
O(1) - fixed alphabet

## Code
```code```