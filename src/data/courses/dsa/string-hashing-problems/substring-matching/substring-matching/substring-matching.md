Find all occurrences of pattern in text.

<br>

> **Key insight:** KMP: build failure function. Rabin-Karp: rolling hash comparison.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** KMP prefix function or Rabin-Karp rolling hash

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `KMP prefix function or Rabin-Karp rolling hash`

### Time Complexity: O(N+M)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(M)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N+M) | O(M) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
