Insert into doubly linked list at given position.

<br>

---

## Solution 1: Traverse + Relink

Traverse to position. newNode.prev = prev, newNode.next = next, prev.next = newNode, next.prev = newNode.

### Time: O(n) | Space: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Traverse + Relink | O(n) | O(1) | Update 4 pointers |

<br>
<br>

---

```code```
