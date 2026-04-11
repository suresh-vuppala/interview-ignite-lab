Implement stack with push, pop, peek, isEmpty, size.

<br>

---

## Solution 1: Array-Based

**Operations:**
- Push: arr[++top] = val — O(1)
- Pop: return arr[top--] — O(1)
- Peek: return arr[top] — O(1)
- isEmpty: top == -1 — O(1)
- Size: top + 1 — O(1)

## Solution 2: Linked List-Based

**Operations:** All O(1) using head pointer. Push = prepend, Pop = remove head.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Array | O(1) all ops | O(n) | Fixed or dynamic array |
| Linked List | O(1) all ops | O(n) | No resize needed, more overhead per node |

<br>
<br>

---

```code```
