## Overview
Implement insertion operations in doubly linked list with prev and next pointers.

## Topics Covered
1. **Insert at Beginning**: Add node at start
2. **Insert at End**: Add node at end
3. **Insert at Position**: Add at specific index
4. **Update Both Pointers**: Maintain prev and next

## Complexity Analysis
### Time: O(1) beginning, O(n) end/position
### Space: O(1)

## Code


---

## Constraints

- `0 ≤ n ≤ 10⁴`
- `0 ≤ position ≤ n`

<br>

---

## All Possible Edge Cases

1. **Insert into empty list:** New node is both head and tail
2. **Insert at head:** Update prev pointer of old head
3. **Insert at tail:** Update next pointer of old tail
4. **Insert in middle:** Update both prev and next pointers

<br>

---

```code```
