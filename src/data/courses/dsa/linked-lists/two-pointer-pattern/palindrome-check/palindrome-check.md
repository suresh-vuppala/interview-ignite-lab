## Overview
Check if linked list is palindrome using slow-fast pointer and reversal.

## Topics Covered
1. **Find Middle**: Use slow-fast pointers
2. **Reverse Second Half**: Reverse from middle
3. **Compare Halves**: Check if both halves match
4. **Restore List**: Optional restoration

## Complexity Analysis
### Time: O(n), Space: O(1)

## Code


---

## Constraints

- `1 ≤ n ≤ 10⁵`
- `0 ≤ Node.val ≤ 9`

<br>

---

## All Possible Edge Cases

1. **Single node:** Always palindrome
2. **Two nodes same:** Palindrome
3. **Two nodes different:** Not palindrome
4. **Odd length palindrome:** 1→2→1
5. **Even length palindrome:** 1→2→2→1
6. **Not palindrome:** 1→2→3

<br>

---

```code```
