For each element, find next smaller element to its right.

<br>

---

## Solution 1: Brute Force — O(n²)
## Solution 2: Monotonic Stack (Increasing) — O(n)

Same pattern as NGE but maintain increasing stack instead of decreasing.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(n²) | O(1) | Scan right |
| Monotonic Stack | O(n) | O(n) | Increasing stack |

<br>
<br>

---

```code```
