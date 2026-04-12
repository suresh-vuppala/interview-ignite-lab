Solve recurrence relations: T(N)=2T(N/2)+N → O(N log N).

<br>

> **Key insight:** Master theorem: T(N)=aT(N/b)+O(N^d). Compare log_b(a) with d.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Master theorem for divide-and-conquer recurrences

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Master theorem for divide-and-conquer recurrences`

### Time Complexity: Varies
**Why?** Each element/state processed efficiently.

### Space Complexity: Varies

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | Varies | Varies |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
