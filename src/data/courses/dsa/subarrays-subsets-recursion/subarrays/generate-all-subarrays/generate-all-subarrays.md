Generate all contiguous subarrays.

<br>

> **Key insight:** Two nested loops for start and end indices.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** for i in range(N): for j in range(i, N): yield arr[i:j+1]

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `for i in range(N): for j in range(i, N): yield arr[i:j+1]`

### Time Complexity: O(N²)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N²) | O(N) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
