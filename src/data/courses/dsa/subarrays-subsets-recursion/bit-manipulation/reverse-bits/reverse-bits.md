Reverse all 32 bits of an integer.

<br>

---

## Solution 1: Bit by Bit — Extract LSB, shift into result
## Solution 2: Divide and Conquer — Swap halves recursively (16→8→4→2→1 bits)

### Time: O(32) = O(1) | Space: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Bit by Bit | O(1) | O(1) | Extract + shift 32 times |
| Divide & Conquer | O(1) | O(1) | Swap bit groups |

<br>
<br>

---

```code```
