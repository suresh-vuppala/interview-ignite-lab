Implement circular queue operations (enqueue, dequeue, front, rear, isEmpty, isFull).

<br>

---

## Solution 1: Array with Modulo

Same as design-circular-queue. Key: next = (current + 1) % capacity.

### Time: O(1) all operations | Space: O(k)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Modulo Array | O(1) all ops | O(k) | Circular indexing |

<br>
<br>

---

```code```
