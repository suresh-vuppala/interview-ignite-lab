Implement double-ended queue (deque).

<br>

---

## Solution 1: Doubly Linked List

Push/pop from both ends in O(1) using head and tail pointers.

### Time: O(1) all operations | Space: O(n)

<br>

---

## Solution 2: Circular Array

Similar to circular queue but support both-end operations with front/rear modulo arithmetic.

### Time: O(1) amortized | Space: O(n)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Doubly LL | O(1) all ops | O(n) | Natural DLL operations |
| Circular Array | O(1) amortized | O(n) | Cache-friendly |

<br>
<br>

---

```code```
