Insert a node into a circular linked list.

<br>

> Example: Insert 4 into circular 1→2→3→(back to 1) → 1→2→3→4→(back to 1)
> **Key insight:** Find the tail (node whose next is head). Insert new node: tail.next = new, new.next = head. For sorted insertion, find correct position.

<br>

---

## Constraints
- `0 ≤ N ≤ 10⁵`

## Solution: Find Tail + Insert (Optimal)

### Time Complexity: O(N)
### Space Complexity: O(1)

> **Drawback:** O(N) to find tail. With tail pointer maintained, insertion is O(1).

> **Key Insight for Improvement:** Circular list: last node points to head instead of null. No null termination — must check node.next == head for end detection.

<br>

---

**Key Insights:**
1. **No null:** Last node points back to head
2. **Empty list:** Single node points to itself
3. **Tail detection:** curr.next == head means curr is the tail

<br><br>

---

```code```
