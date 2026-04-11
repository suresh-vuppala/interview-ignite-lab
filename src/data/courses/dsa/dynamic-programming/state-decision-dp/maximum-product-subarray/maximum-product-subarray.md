Find contiguous subarray with largest product.

<br>

---

## Solution 1: Brute Force — Check all subarrays O(n²)
## Solution 2: Track Min and Max (Optimal)

At each step track maxProduct and minProduct (min needed because negative × negative = positive).

### Time: O(n) | Space: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(n²) | O(1) | All subarrays |
| Min-Max DP | O(n) | O(1) | Track both min and max |

<br>
<br>

---

```code```
