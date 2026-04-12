Partition string so each letter appears in at most one part. Maximize partitions.

<br>

> **Key insight:** Track last occurrence of each char. Expand partition to include all last occurrences.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Track last index of each char, expand partition greedily

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Track last index of each char, expand partition greedily`

### Time Complexity: O(N)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(26)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N) | O(26) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
