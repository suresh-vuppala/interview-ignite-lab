Delete a node from doubly linked list.

<br>

---

## Solution 1: Direct Relink

node.prev.next = node.next; node.next.prev = node.prev. Handle head/tail edge cases.

### Time: O(1) if node given, O(n) if search needed | Space: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Direct Relink | O(1) | O(1) | Doubly-linked enables direct removal |

<br>
<br>

---

```code```
