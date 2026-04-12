Understand the difference: contiguous vs ordered vs unordered selections.

<br>

> **Key insight:** Subarrays: contiguous O(N²). Subsequences: ordered, not contiguous O(2^N). Subsets: unordered O(2^N).

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Subarrays ⊂ Subsequences, Subsets = unordered subsequences

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Subarrays ⊂ Subsequences, Subsets = unordered subsequences`

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
