Move N disks from source to destination using auxiliary peg.

<br>

> **Key insight:** Move N-1 disks to aux, move Nth to dest, move N-1 from aux to dest.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Recursive: move N-1, move largest, move N-1

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Recursive: move N-1, move largest, move N-1`

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
