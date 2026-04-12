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

## Solution: Predecessor Rewiring (Optimal)

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
