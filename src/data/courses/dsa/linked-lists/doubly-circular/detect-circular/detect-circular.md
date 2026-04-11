## Overview
Detect if a linked list is circular using Floyd's algorithm.

## Topics Covered
1. **Floyd's Algorithm**: Slow-fast pointer technique
2. **Circular vs Cycle**: Distinguish between types
3. **Check Last Node**: Verify if points to head
4. **Handle Edge Cases**: Empty and single node

## Complexity Analysis
### Time: O(n), Space: O(1)

## Code


---

## Constraints

- `0 ≤ n ≤ 10⁵`

<br>

---

## All Possible Edge Cases

1. **Not circular:** Traversal hits null
2. **Circular list:** Traversal revisits head
3. **Empty list:** Not circular
4. **Single node pointing to itself:** Circular
5. **Single node pointing to null:** Not circular

<br>

---

```code```
