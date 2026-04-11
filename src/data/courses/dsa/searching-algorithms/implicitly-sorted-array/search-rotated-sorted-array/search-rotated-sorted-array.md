Search for target in rotated sorted array.

<br>

---

## Solution 1: Find Pivot + Binary Search — O(2 log n) = O(log n)
## Solution 2: Modified Binary Search (Optimal)

Identify which half is sorted. Check if target is in sorted half → narrow search.

### Time: O(log n) | Space: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Pivot + BS | O(log n) | O(1) | Two binary searches |
| Single Modified BS | O(log n) | O(1) | One-pass identification |

<br>
<br>

---

```code```
