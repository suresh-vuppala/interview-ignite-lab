Answer range sum queries in O(1) after O(N) preprocessing.

<br>

> **Key insight:** Build prefix sum array. sum(l,r) = prefix[r+1] - prefix[l].

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** prefix[i] = sum of nums[0..i-1], query = prefix[r+1]-prefix[l]

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `prefix[i] = sum of nums[0..i-1], query = prefix[r+1]-prefix[l]`

### Time Complexity: O(1) per query
**Why?** Each element/state processed efficiently.

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(1) per query | O(N) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
