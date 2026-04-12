Find longest substring with equal 0s and 1s.

<br>

> **Key insight:** Map 0→-1. Find longest subarray with sum 0. Prefix sum + hash map.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** 0→-1, longest subarray sum=0 via prefix map

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `0→-1, longest subarray sum=0 via prefix map`

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
