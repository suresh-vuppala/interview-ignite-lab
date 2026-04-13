Compare merge sort vs quicksort in practice.

<br>

> **Key insight:** Merge: stable, O(N log N) guaranteed, O(N) space. Quick: unstable, O(N²) worst, O(1) extra, faster in practice.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Baseline approach is less efficient — see optimal solution below.

> **Key Insight for Improvement:** Merge guaranteed O(N log N), Quick faster in practice

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Merge guaranteed O(N log N), Quick faster in practice`

### Time Complexity: Both O(N log N) avg
**Why?** Each element/state processed efficiently.

### Space Complexity: Merge O(N), Quick O(log N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | Both O(N log N) avg | Merge O(N), Quick O(log N) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
