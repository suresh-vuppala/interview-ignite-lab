Basic heap problems: kth largest, sort k-sorted array, merge k lists.

<br>

> **Key insight:** Heap maintains top-k or merges k streams efficiently.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Min/max heap for streaming top-k problems

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Min/max heap for streaming top-k problems`

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
