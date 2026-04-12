Find unique combinations summing to target (each number used once).

<br>

> **Key insight:** Sort + backtracking. Skip duplicates at same level.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Sort + skip duplicates + backtrack with next index

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Sort + skip duplicates + backtrack with next index`

### Time Complexity: O(2^N)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(2^N) | O(N) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
