Merge K sorted lists into one sorted list.

<br>

> **Key insight:** Min-heap of K elements (one from each list). Extract min, push next from same list.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Min-heap tracks K list heads

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Min-heap tracks K list heads`

### Time Complexity: O(N log K)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(K)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N log K) | O(K) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
