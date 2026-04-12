Count subarrays with sum divisible by k.

<br>

> **Key insight:** Prefix sum mod k. Same remainder means difference divisible by k.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Count pairs with same prefix%k remainder

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Count pairs with same prefix%k remainder`

### Time Complexity: O(N)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(k)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N) | O(k) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
