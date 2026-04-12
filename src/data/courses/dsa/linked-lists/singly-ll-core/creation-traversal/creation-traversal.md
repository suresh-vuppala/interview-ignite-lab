Create a singly linked list and traverse it. Print all node values.

<br>

> Input: values = [1, 2, 3, 4, 5]
> Output: 1 → 2 → 3 → 4 → 5
> **Key insight:** Each node stores a value and a pointer to the next node. Traverse by following next pointers until null.

<br>

---

## Constraints
- `0 ≤ N ≤ 10⁵`

<br>

---

## Solution: Iterate with Pointer (Optimal)

**Algorithm:** Start from head. While current ≠ null: process current, move to current.next.

### Time Complexity: O(N)
**Why?** Visit each node exactly once.

**Detailed breakdown:** N = 100,000 → 100,000 pointer follows

### Space Complexity: O(1) for traversal, O(N) for creation

> **Drawback:** Singly linked list only supports forward traversal. No random access.

> **Key Insight for Improvement:** For bidirectional traversal, use doubly linked list. For O(1) random access, use array. Linked list trades random access for O(1) insert/delete at known positions.

<br>

---

## Complexity Progression Summary

| Operation | Array | Linked List |
|-----------|-------|-------------|
| Access i-th | O(1) | O(N) |
| Insert at head | O(N) | O(1) |
| Insert at tail | O(1) amortized | O(1) with tail ptr |
| Delete at known position | O(N) | O(1) |

**Key Insights:**
1. **Node = value + next pointer:** Fundamental building block
2. **Head pointer:** Only entry point — lose it, lose the list
3. **Null termination:** Last node's next = null signals end

<br><br>

---

```code```
