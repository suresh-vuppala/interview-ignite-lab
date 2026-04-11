## Overview
Design and implement a Least Recently Used (LRU) cache with O(1) get and put operations.

## Topics Covered
1. **Doubly Linked List**: Store key-value pairs in order of use
2. **HashMap**: Quick access to nodes
3. **Get Operation**: Move accessed node to front
4. **Put Operation**: Add/update and evict least recently used

## Problem Statement
Implement LRUCache class with:
- `get(key)`: Return value if exists, else -1
- `put(key, value)`: Insert or update, evict LRU if capacity exceeded


---

## Constraints

- `1 ≤ capacity ≤ 3000`
- `0 ≤ key ≤ 10⁴`
- `0 ≤ value ≤ 10⁵`
- `At most 2 × 10⁵ calls to get and put`

<br>

---

## All Possible Edge Cases

1. **Get non-existent key:** Return -1
2. **Put when at capacity:** Evict LRU item
3. **Get moves item to most recent:** Subsequent eviction skips it
4. **Put existing key:** Update value and move to front
5. **Capacity = 1:** Every new put evicts the previous
6. **Sequential access pattern:** LRU always evicts earliest inserted

<br>

## Approach

### Data Structures
- Doubly linked list: Maintain access order (most recent at head)
- HashMap: Map keys to list nodes for O(1) access

### Get Operation
- If key exists: Move node to head, return value
- Else: Return -1
- Time: O(1)

### Put Operation
- If key exists: Update value, move to head
- If new key and at capacity: Remove tail node
- Add new node at head
- Time: O(1)

## Complexity Analysis

### Time Complexity: O(1) for both get and put
### Space Complexity: O(capacity)

## Code

```code```
