Delete a node by value from a circular linked list.

<br>

> Example: Delete 2 from circular 1→2→3→(back to 1) → 1→3→(back to 1)
> **Key insight:** Find predecessor of target node. Rewire: prev.next = target.next. Special case: deleting head requires updating the circular link.

<br>

---

## Constraints
- `1 ≤ N ≤ 10⁵`

## Solution: Find Predecessor + Rewire (Optimal)

### Time Complexity: O(N)
### Space Complexity: O(1)

> **Drawback:** Must handle head deletion specially — update the tail's next pointer.

> **Key Insight for Improvement:** Single node deletion: if head.next == head → return null (empty list).

<br>

---

**Key Insights:**
1. **Head deletion:** Find tail first, then tail.next = head.next, return head.next
2. **Single node:** head.next == head → return null
3. **Standard deletion:** Same as singly LL but with circular termination check

<br><br>

---

```code```
