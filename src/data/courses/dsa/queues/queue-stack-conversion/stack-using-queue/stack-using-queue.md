Implement stack using queue(s).

<br>

---

## Solution 1: Two Queues — Push O(n), Pop O(1)
## Solution 2: One Queue — After enqueue, rotate n-1 elements to back

### Time: Push O(n) | Space: O(n)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Two Queues | Push O(n) | O(n) | Transfer between queues |
| One Queue | Push O(n) | O(n) | Self-rotate |

<br>
<br>

---

```code```
