Find k most frequent elements.

<br>

---

## Solution 1: Sort by Frequency — O(n log n)
## Solution 2: Min-Heap of Size k — O(n log k)
## Solution 3: Bucket Sort (Optimal)

Index = frequency, value = list of elements. Scan from highest index.

### Time: O(n) | Space: O(n)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Sort | O(n log n) | O(n) | Sort all by frequency |
| Min-Heap k | O(n log k) | O(k) | Maintain top-k heap |
| Bucket Sort | O(n) | O(n) | Frequency as array index |

<br>
<br>

---

```code```
