Count subarrays with odd/even sum.

<br>

> **Key insight:** Prefix sum parity. Odd sum subarray: different parity prefix sums. Even: same parity.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Track prefix parity counts: odd_count * even_count for odd-sum subarrays

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Track prefix parity counts: odd_count * even_count for odd-sum subarrays`

### Time Complexity: O(N)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N) | O(1) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
