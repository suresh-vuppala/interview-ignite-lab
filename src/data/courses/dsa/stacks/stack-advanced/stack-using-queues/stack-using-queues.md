Implement stack using only queue operations.

<br>

---

## Solution 1: Two Queues — Push O(n), Pop O(1)
## Solution 2: One Queue — Push O(n): after enqueue, rotate n-1 elements to back

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Two Queues | Push O(n) | O(n) | Move all to other queue |
| One Queue | Push O(n) | O(n) | Self-rotate after enqueue |

<br>
<br>

---

```code```
