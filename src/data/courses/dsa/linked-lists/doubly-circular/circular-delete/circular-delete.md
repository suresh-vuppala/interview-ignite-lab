Delete a node from a circular linked list.

<br>

---

## Solution 1: Traverse + Delete

Find predecessor. Set predecessor.next = target.next. Handle single-node case.

### Time: O(n) | Space: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Traverse + Delete | O(n) | O(1) | Find predecessor, relink |

<br>
<br>

---

```code```
