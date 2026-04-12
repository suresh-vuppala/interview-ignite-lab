Generate unique permutations when array has duplicates.

<br>

> **Key insight:** Sort array. Skip duplicate elements at the same recursion level.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Sort + skip if nums[i]==nums[i-1] and i-1 not used

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Sort + skip if nums[i]==nums[i-1] and i-1 not used`

### Time Complexity: O(N!)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N!) | O(N) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
