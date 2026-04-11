Check if a linked list is a palindrome.

<br>

---

## Solution 1: Copy to Array — Copy values, check palindrome on array

### Time: O(n) | Space: O(n)

<br>

---

## Solution 2: Reverse Second Half (Optimal)

**Algorithm:**
1. Find middle (slow/fast pointers)
2. Reverse second half
3. Compare first half with reversed second half
4. (Optional) Restore list

### Time: O(n) | Space: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Array Copy | O(n) | O(n) | Simple comparison |
| Reverse Half | O(n) | O(1) | In-place comparison |

<br>
<br>

---

```code```
