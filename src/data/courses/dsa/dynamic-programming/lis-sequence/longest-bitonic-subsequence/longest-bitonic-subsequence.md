Find longest subsequence that first increases then decreases.

<br>

---

## Solution 1: LIS from left + LIS from right — For each i: bitonic[i] = LIS_left[i] + LIS_right[i] - 1

### Time: O(n²) | Space: O(n)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Two LIS passes | O(n²) | O(n) | LIS left + LIS right - 1 |

<br>
<br>

---

```code```
