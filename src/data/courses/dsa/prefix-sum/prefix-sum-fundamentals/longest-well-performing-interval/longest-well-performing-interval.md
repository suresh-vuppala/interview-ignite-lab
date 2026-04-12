Find longest interval where count of days > 8hrs exceeds ≤ 8hrs.

<br>

> **Key insight:** Convert to +1/-1 array. Find longest subarray with positive sum. Prefix sum + hash map.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Map values to +1/-1, longest positive-sum subarray

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Map values to +1/-1, longest positive-sum subarray`

### Time Complexity: O(N)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N) | O(N) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
