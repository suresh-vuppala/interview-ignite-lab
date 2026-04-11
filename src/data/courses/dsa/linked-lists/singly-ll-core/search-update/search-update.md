## Overview
Learn to search for elements and update node values in a linked list.

## Topics Covered
1. **Search by Value**: Find if a value exists in the list
2. **Search by Position**: Get value at specific position
3. **Update by Position**: Change value at specific position
4. **Update by Value**: Change first occurrence of a value

## Problem Statement
Implement search and update operations to query and modify linked list data.


---

## Constraints

- `0 ≤ n ≤ 10⁴`
- `-10⁵ ≤ val ≤ 10⁵`

<br>

---

## All Possible Edge Cases

1. **Value at head:** Found immediately
2. **Value at tail:** Full traversal
3. **Value not found:** Return -1 or false
4. **Empty list:** Not found
5. **Duplicate values:** Return first occurrence or update all
6. **Update head value:** No pointer change needed

<br>

## Approach

### 1. Search by Value
- Traverse list comparing each node's data
- Return true if found, false otherwise
- Time: O(n)

### 2. Search by Position
- Traverse to position
- Return node's data
- Time: O(n)

### 3. Update by Position
- Traverse to position
- Update node's data
- Time: O(n)

### 4. Update by Value
- Find node with target value
- Update its data
- Time: O(n)

## Complexity Analysis

### Time Complexity: O(n) for all operations
### Space Complexity: O(1)

## Code

```code```
