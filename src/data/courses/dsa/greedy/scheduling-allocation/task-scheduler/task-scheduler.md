Schedule tasks with cooldown. Find minimum intervals to complete all.

<br>

> **Key insight:** Most frequent task determines gaps. Answer = max(N, (maxFreq-1)*(n+1)+countMax).

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Formula: (maxFreq-1)*(cooldown+1) + countOfMaxFreq

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Formula: (maxFreq-1)*(cooldown+1) + countOfMaxFreq`

### Time Complexity: O(N)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N) | O(1) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
