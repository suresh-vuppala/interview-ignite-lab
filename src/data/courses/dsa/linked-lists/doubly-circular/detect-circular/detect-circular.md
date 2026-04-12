Detect if a linked list is circular (last node points back to head, not just any cycle).

<br>

> Example: 1→2→3→(back to 1) → true. 1→2→3→null → false.
> **Key insight:** Traverse from head.next. If we return to head → circular. If we hit null → not circular. Different from cycle detection (which detects any cycle, not just full circular).

<br>

---

## Constraints
- `0 ≤ N ≤ 10⁵`

## Solution: Traverse and Check (Optimal)

### Time Complexity: O(N)
### Space Complexity: O(1)

> **Drawback:** None.

> **Key Insight for Improvement:** Different from Floyd's cycle detection: we specifically check if any node points back to HEAD (not just any visited node). Simpler traversal suffices.

<br>

---

**Key Insights:**
1. **Circular ≠ cycle:** Circular means tail→head. Cycle means any node→any previous node.
2. **Simple check:** Start from head.next, traverse until null or head found
3. **Floyd's not needed:** We know exactly what we're looking for (head)

<br><br>

---

```code```
