Print boundary nodes: left boundary + leaves + right boundary (reverse).

<br>

---

## Solution 1: Three Separate Passes

1. Left boundary (top-down, exclude leaf)
2. Leaves (left-to-right)
3. Right boundary (bottom-up, exclude leaf)

### Time: O(n) | Space: O(h)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Three Passes | O(n) | O(h) | Separate left/leaves/right collection |

<br>
<br>

---

```code```
