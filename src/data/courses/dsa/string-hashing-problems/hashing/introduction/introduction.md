Introduction to string hashing concepts.

<br>

> **Key insight:** Hash function maps string to integer. Useful for O(1) string comparison.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Rolling hash: h = (h * base + char) % mod

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Rolling hash: h = (h * base + char) % mod`

### Time Complexity: O(N) to compute
**Why?** Each element/state processed efficiently.

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N) to compute | O(1) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
