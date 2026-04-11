Flatten a multilevel doubly linked list. Child pointers become part of the main list.

<br>

---

## Solution 1: DFS/Stack

**Intuition:** When child exists, insert child list between current and next. Use stack to remember the next pointer.

### Time: O(n) | Space: O(depth) for stack

<br>

---

## Solution 2: Iterative

Traverse. When child found: find child list's tail, connect tail → current.next, set current.next = child.

### Time: O(n) | Space: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Stack/DFS | O(n) | O(depth) | Stack tracks paused next pointers |
| Iterative | O(n) | O(1) | Find child tail inline |

<br>
<br>

---

```code```
