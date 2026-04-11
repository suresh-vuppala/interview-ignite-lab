Max envelopes you can nest (sort by width, LIS on height).

<br>

---

## Solution 1: Sort + LIS DP — O(n²)
## Solution 2: Sort + LIS with Binary Search (Optimal)

Sort by width ascending, height descending (for same width). Then LIS on heights using binary search.

### Time: O(n log n) | Space: O(n)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Sort + LIS DP | O(n²) | O(n) | Standard LIS |
| Sort + BS LIS | O(n log n) | O(n) | Patience sorting LIS |

<br>
<br>

---

```code```
