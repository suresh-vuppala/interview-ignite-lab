# LFU Cache

## Overview
Design and implement a Least Frequently Used (LFU) cache with O(1) get and put operations.

## Topics Covered
1. **Frequency Tracking**: Count access frequency for each key
2. **Multiple Data Structures**: HashMap + Doubly Linked Lists
3. **Get Operation**: Increment frequency, return value
4. **Put Operation**: Add/update and evict least frequently used

## Problem Statement
Implement LFUCache class with:
- `get(key)`: Return value and increment frequency, else -1
- `put(key, value)`: Insert/update, evict LFU (tie-break by LRU) if capacity exceeded

## Approach

### Data Structures
- keyToVal: Map key to value
- keyToFreq: Map key to frequency
- freqToKeys: Map frequency to doubly linked list of keys
- minFreq: Track minimum frequency

### Get Operation
- If key exists: Increment frequency, update structures, return value
- Else: Return -1
- Time: O(1)

### Put Operation
- If key exists: Update value and frequency
- If new key and at capacity: Remove LFU key (use minFreq)
- Add new key with frequency 1
- Time: O(1)

## Complexity Analysis

### Time Complexity: O(1) for both get and put
### Space Complexity: O(capacity)

## Code

```code```