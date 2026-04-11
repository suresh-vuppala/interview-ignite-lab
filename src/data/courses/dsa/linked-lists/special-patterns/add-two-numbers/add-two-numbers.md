## Overview
Add two numbers represented as linked lists (digits in reverse order).

## Topics Covered
1. **Digit-by-Digit Addition**: Process from least significant
2. **Carry Handling**: Propagate carry to next digit
3. **Different Lengths**: Handle lists of different sizes
4. **Result Construction**: Build result list

## Complexity Analysis
### Time: O(max(m,n)), Space: O(max(m,n))

## Code


---

## Constraints

- `1 ≤ list length ≤ 100`
- `0 ≤ Node.val ≤ 9`
- `Numbers don't have leading zeros (except 0 itself)`

<br>

---

## All Possible Edge Cases

1. **Carry propagation:** 9→9→9 + 1 → 0→0→0→1
2. **Different lengths:** 1→2 + 1→2→3 — shorter list runs out
3. **Both single digit:** 5 + 5 = 0→1
4. **Sum is 0:** 0 + 0 = 0
5. **One list empty:** Return the other (shouldn't happen per constraints)
6. **Large carry chain:** 999...9 + 1

<br>

---

```code```
