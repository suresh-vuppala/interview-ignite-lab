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


---

## Constraints

- `1 ≤ capacity ≤ 10⁴`
- `0 ≤ key ≤ 10⁵`
- `0 ≤ value ≤ 10⁵`
- `At most 2 × 10⁵ calls`

<br>

---

## All Possible Edge Cases

1. **Get non-existent key:** Return -1
2. **Put when at capacity:** Evict least frequently used
3. **Tie in frequency:** Evict LRU among tied items
4. **Capacity = 1:** Frequent evictions
5. **Same key accessed many times:** Frequency increases, harder to evict
6. **All keys accessed once:** LRU tie-breaking among all

<br>

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
