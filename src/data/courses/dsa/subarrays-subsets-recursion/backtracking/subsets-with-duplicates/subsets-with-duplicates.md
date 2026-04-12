Generate unique subsets when array has duplicates.

<br>

> **Key insight:** Sort. Skip consecutive duplicates at same recursion level.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Sort + skip nums[i]==nums[i-1] at same level

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Sort + skip nums[i]==nums[i-1] at same level`

### Time Complexity: O(2^N)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(2^N) | O(N) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
