Find minimum in each sliding window of size k.

<br>

> **Key insight:** Monotonic deque: maintain increasing deque of indices. Front = current min.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Deque stores indices in increasing value order

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Deque stores indices in increasing value order`

### Time Complexity: O(N)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(k)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N) | O(k) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
