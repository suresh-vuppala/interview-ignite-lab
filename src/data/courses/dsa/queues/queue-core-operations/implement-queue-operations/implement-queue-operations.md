Implement queue with enqueue, dequeue, front, isEmpty operations.

<br>

> **Key insight:** Use array/linked list. Enqueue at back, dequeue from front. Circular array avoids shifting.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Circular array: front=(front+1)%cap, rear=(rear+1)%cap

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Circular array: front=(front+1)%cap, rear=(rear+1)%cap`

### Time Complexity: O(1) per op
**Why?** Each element/state processed efficiently.

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(1) per op | O(N) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
