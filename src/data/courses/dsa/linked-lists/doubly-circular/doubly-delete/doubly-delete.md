## Overview
Implement deletion operations in doubly linked list.

## Topics Covered
1. **Delete from Beginning**: Remove first node
2. **Delete from End**: Remove last node
3. **Delete by Value**: Remove specific node
4. **Update Both Pointers**: Maintain prev and next

## Complexity Analysis
### Time: O(1) beginning, O(n) end/value
### Space: O(1)

## Code


---

## Constraints

- `1 ≤ n ≤ 10⁴`

<br>

---

## All Possible Edge Cases

1. **Delete head:** Update head and new head's prev
2. **Delete tail:** Update tail and new tail's next
3. **Delete only node:** List becomes empty
4. **Delete middle:** Update both neighbors' pointers

<br>

---

```code```
