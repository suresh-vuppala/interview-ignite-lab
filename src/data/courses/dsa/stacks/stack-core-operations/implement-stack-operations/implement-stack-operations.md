Design a stack that supports push, pop, top, and isEmpty operations. All operations must be O(1).

<br>

> Input:
> push(1), push(2), top(), pop(), isEmpty()

> Output:
> 2, 2, false

> Explanation:
> Push 1 then 2. Top returns 2 (last in). Pop removes and returns 2. Stack has [1] remaining, so isEmpty = false.
> 
> **Key insight:** Use a dynamic array (vector/list). Push/pop at the END for O(1) amortized. The top of the stack is the last element.

<br>



---

## Constraints

- Operations: push, pop, top, isEmpty
- Pop and top only called on non-empty stack

<br>

---

## All Possible Edge Cases

1. **Pop on empty:** Undefined behavior — check isEmpty first
2. **Single element:** Push then pop returns to empty
3. **Many operations:** Amortized O(1) for dynamic array resizing

<br>

---

## Solution 1: Array-Based Stack (Optimal)

**Intuition:**
Use a dynamic array. Push adds to the end, pop removes from the end. Both are O(1) amortized because array resizing doubles capacity.

**Algorithm:**
- push(x): append x to array
- pop(): remove and return last element
- top(): return last element without removing
- isEmpty(): check if array is empty

### Time Complexity: O(1) amortized per operation
**Why?**
- Array append: O(1) amortized (occasional O(N) resize, but averaged over N operations = O(1) each)
- Array pop from end: O(1)
- Top: O(1) — just read last element
- isEmpty: O(1)

**Detailed breakdown:**
- 100,000 push operations → ~100,000 total work (amortized)
- Each resize doubles capacity → at most log₂(N) resizes total

### Space Complexity: O(N)
**Why?**
- Stores N elements in the array

<br>

---

## Complexity Progression Summary

| Operation | Time | Space |
|-----------|------|-------|
| push | O(1) amortized | O(1) |
| pop | O(1) | O(1) |
| top | O(1) | O(1) |
| isEmpty | O(1) | O(1) |

**Key Insights:**
1. **Array-based stacks:** Most practical implementation — cache-friendly
2. **Linked-list alternative:** O(1) worst-case but higher constant factor (pointer overhead)
3. **LIFO principle:** Last In, First Out — fundamental to recursion, DFS, expression parsing


<br>
<br>

---

```code```
