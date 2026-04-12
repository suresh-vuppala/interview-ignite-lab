String matching and substring problems using rolling hash.

<br>

> **Key insight:** Rabin-Karp: rolling hash for O(1) hash update when sliding window.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** hash = (hash - old*base^(L-1))*base + new

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `hash = (hash - old*base^(L-1))*base + new`

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
