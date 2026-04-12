Partition array around pivot, recursively sort partitions.

<br>

> **Key insight:** Choose pivot, partition: elements < pivot left, > pivot right.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Lomuto/Hoare partition + recurse

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Lomuto/Hoare partition + recurse`

### Time Complexity: O(N log N) avg
**Why?** Each element/state processed efficiently.

### Space Complexity: O(log N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N log N) avg | O(log N) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
