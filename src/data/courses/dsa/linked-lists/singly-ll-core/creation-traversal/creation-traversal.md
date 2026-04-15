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

## All Possible Edge Cases
1. **Empty list**
2. **Single node**
3. **Traverse null list**

<br>

---

## Solution 1: Array-based simulation

**Intuition:**
The most straightforward approach — store elements in array.

**Algorithm:**
1. Apply the naive/brute approach as described
2. Check all possibilities or use a simpler data structure
3. Return the result

### Time Complexity: O(N)
**Why?**
The brute approach doesn't exploit the problem's structure efficiently, leading to redundant work.

**Detailed breakdown:**
For typical constraint sizes, this approach may be too slow or use too much space.

### Space Complexity: O(1) or O(N) depending on approach

> **Drawback:**
> Store elements in array. Simulates linked list without actual pointer structure. Loses O(1) insert/delete advantage.

> **Key Insight for Improvement:**
> Use Iterate with Pointer (Optimal) for O(N) time.

<br>

---

## Solution 2: Iterate with Pointer (Optimal)

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
