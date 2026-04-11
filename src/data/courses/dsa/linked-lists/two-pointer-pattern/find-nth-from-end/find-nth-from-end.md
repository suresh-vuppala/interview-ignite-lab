## Overview
Find the nth node from the end using two-pointer technique in one pass.

## Topics Covered
1. **Two-Pointer Gap**: Maintain n-node gap between pointers
2. **One-Pass Solution**: Find in single traversal
3. **Handle Edge Cases**: n > length, n = length
4. **Applications**: Remove nth from end

## Complexity Analysis
### Time: O(n), Space: O(1)

## Code


---

## Constraints

- `1 ≤ n ≤ size of list`
- `List size ≥ 1`

<br>

---

## All Possible Edge Cases

1. **n = 1:** Return last node
2. **n = list size:** Return head
3. **n > list size:** Invalid — handle error
4. **Single node, n = 1:** Return that node
5. **n = 0:** Invalid input

<br>

---

```code```
