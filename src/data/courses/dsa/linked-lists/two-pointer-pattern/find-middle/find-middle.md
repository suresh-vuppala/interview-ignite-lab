Find the middle node of a linked list.

<br>

> Input: 1→2→3→4→5 → Output: 3
> Input: 1→2→3→4→5→6 → Output: 4 (second middle for even)

<br>

---

## Solution 1: Count + Traverse — Two passes: count length, then traverse n/2

### Time: O(n) | Space: O(1) — Two passes

<br>

---

## Solution 2: Slow & Fast Pointers (Optimal)

**Intuition:** Slow moves 1 step, fast moves 2 steps. When fast reaches end, slow is at middle.

### Time: O(n) | Space: O(1) — Single pass

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Count + Traverse | O(n) | O(1) | Two passes |
| Slow & Fast | O(n) | O(1) | Single pass |

<br>
<br>

---

```code```
