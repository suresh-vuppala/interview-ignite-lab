Sort a linked list in O(n log n) time and O(1) space.

<br>

---

## Solution 1: Copy to Array, Sort, Rebuild — O(n log n) time, O(n) space
## Solution 2: Merge Sort (Optimal)

**Intuition:** Find middle (slow/fast), split into two halves, recursively sort each, merge.

### Time: O(n log n) | Space: O(log n) recursion (or O(1) with bottom-up merge sort)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Array Sort | O(n log n) | O(n) | Use built-in sort |
| Merge Sort | O(n log n) | O(log n) | In-place on linked list |

<br>
<br>

---

```code```
