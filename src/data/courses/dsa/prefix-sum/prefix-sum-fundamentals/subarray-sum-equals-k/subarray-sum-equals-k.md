Count subarrays with sum equal to k.

<br>

> **Key insight:** Prefix sum + hash map. If prefixSum-k exists in map → subarrays found.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** prefixSum - k in map → count of valid subarrays

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `prefixSum - k in map → count of valid subarrays`

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
