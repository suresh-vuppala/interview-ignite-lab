Design a circular queue with fixed capacity.

<br>

---

## Solution 1: Array with Front/Rear Pointers

Use array of fixed size. front and rear indices wrap around using modulo. Track count or use front == rear with size.

### Time: O(1) all operations | Space: O(k)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Circular Array | O(1) all ops | O(k) | Modulo-based wrap-around |

<br>
<br>

---

```code```
