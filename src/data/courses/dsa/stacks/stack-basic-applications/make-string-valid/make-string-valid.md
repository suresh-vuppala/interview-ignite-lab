Return minimum additions to make parentheses string valid.

<br>

---

## Solution 1: Stack — O(n) time, O(n) space
Push '(' to stack. For ')', pop if stack has '(', else count unmatched ')'. Answer = stack size + unmatched count.

## Solution 2: Counter (Optimal) — O(n) time, O(1) space
Track open count. If ')' with open=0, increment additions. End: additions += remaining open.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Stack | O(n) | O(n) | Track unmatched brackets |
| Counter | O(n) | O(1) | Just count open/unmatched |

<br>
<br>

---

```code```
