Introduction to arrays: creation, access, basic operations.

<br>

> **Key insight:** Arrays store elements contiguously. O(1) random access, O(N) insert/delete.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Contiguous memory, index-based access

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Contiguous memory, index-based access`

### Time Complexity: O(1) access
**Why?** Each element/state processed efficiently.

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(1) access | O(N) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
