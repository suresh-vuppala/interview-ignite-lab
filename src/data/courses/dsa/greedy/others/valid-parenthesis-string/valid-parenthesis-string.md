Check if string with '(', ')', '*' can be valid. * can be '(', ')', or empty.

<br>

---

## Solution 1: Brute Force / DP — Try all possibilities for *

### Time: O(3^n) or O(n²) with DP

<br>

---

## Solution 2: Min-Max Open Count (Optimal)

Track range [minOpen, maxOpen]. For '(': both++. For ')': both--. For '*': min--, max++. Clamp min ≥ 0.

### Time: O(n) | Space: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| DP | O(n²) | O(n) | Track possible open counts |
| Min-Max | O(n) | O(1) | Range tracking replaces all states |

<br>
<br>

---

```code```
