Implement a double-ended queue supporting push/pop from both ends.

<br>

> **Key insight:** Circular array with front/rear. Push front: front=(front-1+cap)%cap.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Circular array with bidirectional access

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Circular array with bidirectional access`

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
