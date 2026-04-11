Implement queue using two stacks.

<br>

---

## Solution 1: Push-Heavy — Push O(1), Pop O(n)
## Solution 2: Pop-Heavy (Amortized O(1))

Two stacks: input and output. Push to input. Pop from output; if empty, transfer all from input (reverse order gives FIFO).

### Time: O(1) amortized | Space: O(n)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Push-Heavy | Push O(1), Pop O(n) | O(n) | Transfer on every pop |
| Amortized | O(1) amortized | O(n) | Lazy transfer — only when output empty |

<br>
<br>

---

```code```
