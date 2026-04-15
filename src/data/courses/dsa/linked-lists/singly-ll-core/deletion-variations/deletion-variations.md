Delete a node at the head, tail, by value, or at a specific position.

<br>

> Input: list = 1→2→3→4→5, deleteHead → 2→3→4→5, deleteTail → 2→3→4, deleteValue(3) → 2→4
> **Key insight:** Find the predecessor of the node to delete. Set prev.next = target.next. Dummy node avoids special cases for head deletion.

<br>

---

## Constraints
- `0 ≤ N ≤ 10⁵`

<br>

---

## All Possible Edge Cases
1. **Delete from empty list**
2. **Delete only node**
3. **Delete head / tail**
4. **Delete at invalid position**

<br>

---

## Solution 1: Copy to new list skipping target

**Intuition:**
The most straightforward approach — build new list excluding the target element.

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
> Build new list excluding the target element. Wastes O(N) extra space.

> **Key Insight for Improvement:**
> Use Predecessor Rewiring (Optimal) for O(1) for head, O(N) for tail/value/position time.

<br>

---

## Solution 2: Predecessor Rewiring (Optimal)

**Algorithm:** Find node before target. Rewire: prev.next = prev.next.next. For head: just return head.next.

### Time Complexity: O(1) for head, O(N) for tail/value/position
### Space Complexity: O(1)

> **Drawback:** Must find predecessor — O(N) traversal for singly linked list. Doubly linked list gives O(1) deletion given the node.

> **Key Insight for Improvement:** Dummy head avoids null checks for head deletion. Always use dummy when deletion could affect head.

<br>

---

## Complexity Progression Summary

| Operation | Singly | Doubly |
|-----------|--------|--------|
| Delete head | O(1) | O(1) |
| Delete given node | O(N) | O(1) |
| Delete by value | O(N) | O(N) |

**Key Insights:**
1. **Rewire, don't remove:** prev.next = prev.next.next skips the target
2. **Memory management:** In C++, free/delete the removed node
3. **Dummy pattern:** Handles head deletion uniformly

<br><br>

---

```code```
