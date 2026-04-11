Find the nth node from the end.

<br>

---

## Solution 1: Count length, traverse (length - n)
## Solution 2: Two Pointers — Advance first pointer n steps, then move both. When first reaches end, second is at target.

### Time: O(n) | Space: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Two Pass | O(n) | O(1) | Count then traverse |
| Two Pointers | O(n) | O(1) | Single pass with gap |

<br>
<br>

---

```code```
