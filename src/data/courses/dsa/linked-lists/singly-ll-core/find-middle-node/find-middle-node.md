# Find Middle Node

## Overview
Learn multiple approaches to find the middle node of a linked list.

## Topics Covered
1. **Two-Pass Approach**: Count nodes then find middle
2. **Slow-Fast Pointer**: Find middle in one pass
3. **Handle Even Length**: Return first or second middle
4. **Handle Odd Length**: Return exact middle

## Problem Statement
Find the middle node of a singly linked list efficiently, handling both even and odd length lists.

## Approach

### 1. Two-Pass Approach
- Count total nodes (n)
- Traverse to n/2 position
- Time: O(n), Space: O(1)

### 2. Slow-Fast Pointer (Optimal)
- Slow moves 1 step, fast moves 2 steps
- When fast reaches end, slow is at middle
- Time: O(n), Space: O(1)

### 3. Even Length Lists
- For even length, slow points to second middle
- Adjust logic if first middle needed

### 4. Odd Length Lists
- Slow naturally points to exact middle

## Complexity Analysis

### Time Complexity: O(n)
### Space Complexity: O(1)

## Code

```code```