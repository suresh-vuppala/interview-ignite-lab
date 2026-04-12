Minimum eating speed to finish all bananas in H hours.

<br>

> **Key insight:** Binary search on speed. At speed k, time = sum(ceil(pile/k)).

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Binary search on speed, sum ceil(pile/k) <= H

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Binary search on speed, sum ceil(pile/k) <= H`

### Time Complexity: O(N log M)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N log M) | O(1) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
