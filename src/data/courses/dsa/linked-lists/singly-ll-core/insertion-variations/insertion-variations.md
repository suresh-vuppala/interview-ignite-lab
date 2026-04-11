## Overview
Master all insertion operations in a singly linked list. This lesson covers inserting nodes at different positions to build and modify linked lists dynamically.

## Topics Covered
1. **Insert at Beginning**: Add a new node at the start of the list
2. **Insert at End**: Add a new node at the end of the list
3. **Insert at Position**: Add a new node at a specific index
4. **Insert After Node**: Add a new node after a given node value

## Problem Statement
Implement all four insertion operations for a singly linked list, handling edge cases like empty lists and invalid positions.


---

## Constraints

- `0 ≤ n ≤ 10⁴`
- `-10⁵ ≤ val ≤ 10⁵`
- `0 ≤ position ≤ n`

<br>

---

## All Possible Edge Cases

1. **Insert at head (position 0):** Update head pointer
2. **Insert at tail:** Traverse to end, append
3. **Insert in empty list:** New node becomes head
4. **Insert at invalid position:** Handle out-of-bounds
5. **Insert in middle:** Standard case
6. **Single node list, insert at pos 1:** Append after head

<br>

## Approach

### 1. Insert at Beginning
- Create new node
- Point new node's next to current head
- Update head to new node
- Time: O(1)

### 2. Insert at End
- Create new node
- If list is empty, make it head
- Otherwise, traverse to last node
- Point last node's next to new node
- Time: O(n)

### 3. Insert at Position
- Handle position 0 as insert at beginning
- Traverse to position-1
- Create new node and adjust pointers
- Time: O(n)

### 4. Insert After Node
- Search for the target node
- Create new node
- Insert after target node by adjusting pointers
- Time: O(n)

## Complexity Analysis

### Time Complexity
- **Insert at Beginning**: O(1)
- **Insert at End**: O(n)
- **Insert at Position**: O(n)
- **Insert After Node**: O(n)

### Space Complexity
- O(1) for all operations

## Key Points
- Insert at beginning is the fastest operation
- Always check for null pointers
- Handle edge cases: empty list, invalid position
- Pointer manipulation is crucial for correctness

## Code

```code```
