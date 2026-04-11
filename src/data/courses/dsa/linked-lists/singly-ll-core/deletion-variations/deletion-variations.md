## Overview
Master all deletion operations in a singly linked list including deleting from beginning, end, specific position, and by value.

## Topics Covered
1. **Delete from Beginning**: Remove the first node
2. **Delete from End**: Remove the last node
3. **Delete at Position**: Remove node at specific index
4. **Delete by Value**: Remove first node with given value

## Problem Statement
Implement all four deletion operations handling edge cases like empty list, single node, and node not found.


---

## Constraints

- `0 ≤ n ≤ 10⁴`
- `Node to delete exists in the list (usually)`

<br>

---

## All Possible Edge Cases

1. **Delete head:** Update head to head.next
2. **Delete tail:** Traverse to second-last, set next to null
3. **Delete only node:** List becomes empty
4. **Delete from empty list:** Handle gracefully
5. **Delete middle node:** Standard prev.next = curr.next
6. **Node not found:** Return list unchanged

<br>

## Approach

### 1. Delete from Beginning
- Update head to head.next
- Time: O(1)

### 2. Delete from End
- Traverse to second-last node
- Set its next to null
- Time: O(n)

### 3. Delete at Position
- Traverse to position-1
- Adjust pointers to skip target node
- Time: O(n)

### 4. Delete by Value
- Find node with target value
- Adjust pointers to remove it
- Time: O(n)

## Complexity Analysis

### Time Complexity
- Delete from Beginning: O(1)
- Delete from End: O(n)
- Delete at Position: O(n)
- Delete by Value: O(n)

### Space Complexity
- O(1) for all operations

## Code

```code```
