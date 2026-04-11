Insert a new interval into sorted non-overlapping intervals, merging if necessary.

<br>

---

## Solution 1: Linear Scan — Three phases

**Algorithm:**
1. Add all intervals ending before new interval starts
2. Merge overlapping intervals with new interval
3. Add remaining intervals

### Time: O(n) | Space: O(n) for result

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Three Phase | O(n) | O(n) | Before → merge → after |

<br>
<br>

---

```code```
