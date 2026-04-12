Check if subarray with sum multiple of k exists (length ≥ 2).

<br>

> **Key insight:** Prefix sum mod k. If same remainder seen before (gap ≥ 2) → true.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** prefix % k seen before → subarray sum divisible by k

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `prefix % k seen before → subarray sum divisible by k`

### Time Complexity: O(N)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(min(N,k))

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N) | O(min(N,k)) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
