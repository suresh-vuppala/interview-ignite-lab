## Overview
Flatten a multilevel doubly linked list where nodes can have child pointers.

## Topics Covered
1. **DFS Traversal**: Process child lists recursively
2. **Pointer Adjustment**: Connect child lists properly
3. **Maintain Doubly Links**: Update both next and prev
4. **Stack/Recursion**: Handle multilevel structure

## Complexity Analysis
### Time: O(n), Space: O(n) recursion

## Code


---

## Constraints

- `0 ≤ n ≤ 1000`
- `1 ≤ Node.val ≤ 10⁵`

<br>

---

## All Possible Edge Cases

1. **No child pointers:** Already flat
2. **Single level of children:** Insert children between current and next
3. **Deeply nested children:** Recursive flattening
4. **Child at tail:** Append child list at end
5. **Empty list:** Return null
6. **Child list longer than parent:** Expanded list is much longer

<br>

---

```code```
