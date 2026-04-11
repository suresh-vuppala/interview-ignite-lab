Design stack with push, pop, top, peekMax, popMax.

<br>

---

## Solution 1: Two Stacks — O(1) for all except popMax O(n)
## Solution 2: Doubly Linked List + TreeMap — O(log n) for all

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Two Stacks | O(n) popMax | O(n) | Aux stack for max tracking |
| DLL + TreeMap | O(log n) all | O(n) | Ordered map finds max, DLL removes |

<br>
<br>

---

```code```
