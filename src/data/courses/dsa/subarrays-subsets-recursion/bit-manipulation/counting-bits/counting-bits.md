For each number 0..N, count set bits.

<br>

> **Key insight:** dp[i] = dp[i>>1] + (i&1). Right-shift removes last bit, add back if it was 1.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** dp[i] = dp[i/2] + (i%2)

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `dp[i] = dp[i/2] + (i%2)`

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
