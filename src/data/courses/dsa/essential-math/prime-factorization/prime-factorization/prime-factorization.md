Find all prime factors of N.

<br>

> **Key insight:** Divide by smallest prime repeatedly. Use sieve for precomputation.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Divide by 2, then odd numbers up to √N

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Divide by 2, then odd numbers up to √N`

### Time Complexity: O(√N)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(√N) | O(1) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
