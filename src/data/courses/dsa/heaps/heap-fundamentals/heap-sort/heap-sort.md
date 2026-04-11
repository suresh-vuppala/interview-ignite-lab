Sort using heap — build max-heap, repeatedly extract max.

<br>

---

## Solution 1: Heap Sort

1. Build max-heap: O(n)
2. Repeatedly swap root with last, heapify: O(n log n)

### Time: O(n log n) | Space: O(1) in-place

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Heap Sort | O(n log n) | O(1) | In-place, not stable |

<br>
<br>

---

```code```
