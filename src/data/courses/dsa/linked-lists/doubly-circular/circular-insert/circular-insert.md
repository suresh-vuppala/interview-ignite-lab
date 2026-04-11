## Overview
Implement insertion in circular linked list where last node points to first.

## Topics Covered
1. **Insert at Beginning**: Add node and maintain circularity
2. **Insert at End**: Add node and update last pointer
3. **Maintain Circle**: Ensure last.next points to head
4. **Handle Empty List**: Initialize circular structure

## Complexity Analysis
### Time: O(1) beginning, O(n) end
### Space: O(1)

## Code


---

## Constraints

- `0 ≤ n ≤ 10⁵`

<br>

---

## All Possible Edge Cases

1. **Insert into empty circular list:** Node points to itself
2. **Insert at head:** Update tail's next to new head
3. **Insert in middle:** Update circular links
4. **Single node circular:** After insert, two nodes form circle

<br>

---

```code```
