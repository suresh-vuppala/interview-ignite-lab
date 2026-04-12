Implement a circular queue with fixed capacity.

<br>

> **Key insight:** Use array with front/rear pointers that wrap around using modulo.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** front=(front+1)%k, rear=(rear+1)%k

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `front=(front+1)%k, rear=(rear+1)%k`

### Time Complexity: O(1) per op
**Why?** Each element/state processed efficiently.

### Space Complexity: O(k)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(1) per op | O(k) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
