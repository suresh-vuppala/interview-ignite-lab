Rearrange string so no two adjacent characters are same.

<br>

> **Key insight:** Max-heap by frequency. Greedily place most frequent, then second most, alternate.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Max-heap: always place highest freq char, cooldown 1 step

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Max-heap: always place highest freq char, cooldown 1 step`

### Time Complexity: O(N log 26)=O(N)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(26)=O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N log 26)=O(N) | O(26)=O(1) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
