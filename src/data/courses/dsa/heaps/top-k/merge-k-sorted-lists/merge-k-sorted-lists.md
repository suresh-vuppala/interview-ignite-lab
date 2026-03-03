# Merge K Sorted Lists

## Problem Statement

Merge k sorted linked lists into one sorted list.

## Approach

- Use min heap to track smallest element from each list
- Extract min, add to result, push next from that list
- Time: O(n log k) where n = total nodes

## Complexity Analysis

### Time Complexity: O(n log k)
- n total nodes
- Each operation O(log k)

### Space Complexity: O(k)

## Code

```code```