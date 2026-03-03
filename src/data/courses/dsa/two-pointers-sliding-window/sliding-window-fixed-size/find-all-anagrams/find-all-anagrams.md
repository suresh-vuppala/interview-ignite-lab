## Problem
Find all start indices of anagrams of pattern in string.

## Approach
Fixed size sliding window with character frequency matching.

## Algorithm
1. Create frequency map of pattern
2. Slide window of pattern length
3. Compare frequencies at each position
4. Add index if frequencies match

## Time Complexity
O(n)

## Space Complexity
O(1) - fixed alphabet size

## Code
```code```