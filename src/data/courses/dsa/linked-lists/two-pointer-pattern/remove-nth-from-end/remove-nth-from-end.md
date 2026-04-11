Remove the nth node from the end. Return head.

<br>

---

## Solution 1: Two Pass — Count length, remove at position (length - n)
## Solution 2: Two Pointers + Dummy (Optimal)

**Intuition:** Use dummy node before head. Fast advances n+1 steps. Move both until fast is null. Slow.next = slow.next.next.

### Time: O(n) | Space: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Two Pass | O(n) | O(1) | Count then delete |
| Two Pointers | O(n) | O(1) | Single pass, dummy handles edge cases |

<br>
<br>

---

```code```
