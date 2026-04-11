## Overview
Implement deletion in circular linked list maintaining circularity.

## Topics Covered
1. **Delete from Beginning**: Remove first node
2. **Delete from End**: Remove last node
3. **Delete by Value**: Remove specific node
4. **Maintain Circle**: Keep circular structure intact

## Complexity Analysis
### Time: O(n), Space: O(1)

## Code


---

## Constraints

- `1 ≤ n ≤ 10⁵`

<br>

---

## All Possible Edge Cases

1. **Delete only node:** List becomes empty
2. **Delete head of circular:** Update tail's next pointer
3. **Delete tail of circular:** Update pointer to new tail
4. **Delete from two-node circular:** Single node circular remains

<br>

---

```code```
