## Overview
Merge two sorted linked lists into one sorted list.

## Topics Covered
1. **Two-Pointer Merge**: Compare and link nodes
2. **Dummy Node**: Simplify edge cases
3. **In-place Merging**: Reuse existing nodes
4. **Handle Different Lengths**: Process remaining nodes

## Complexity Analysis
### Time: O(m+n), Space: O(1)

## Code


---

## Constraints

- `0 ≤ n, m ≤ 50`
- `-100 ≤ Node.val ≤ 100`
- `Both lists sorted in non-decreasing order`

<br>

---

## All Possible Edge Cases

1. **One list empty:** Return the other
2. **Both empty:** Return null
3. **No overlap:** Append one after the other
4. **Interleaved values:** Standard merge
5. **All same values:** Merged list has all of them
6. **One list is single node:** Insert into correct position

<br>

---

```code```
