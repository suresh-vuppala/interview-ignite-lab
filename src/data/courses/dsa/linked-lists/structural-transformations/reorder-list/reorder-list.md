Reorder L0→L1→...→Ln to L0→Ln→L1→Ln-1→...

<br>

---

## Solution 1: Array + Two Pointers — Store in array, interleave from both ends

### Time: O(n) | Space: O(n)

<br>

---

## Solution 2: Find Middle + Reverse + Merge (Optimal)

**Algorithm:**
1. Find middle (slow/fast)
2. Reverse second half
3. Interleave merge both halves

### Time: O(n) | Space: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Array | O(n) | O(n) | Random access via array |
| Reverse + Merge | O(n) | O(1) | Three linked list operations |

<br>
<br>

---

```code```
