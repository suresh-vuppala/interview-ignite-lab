Count permutations where no element is in its original position.

<br>

---

## Solution 1: Recursion — D(n) = (n-1) × [D(n-1) + D(n-2)]
## Solution 2: DP — Bottom-up computation of recurrence

### Time: O(n) | Space: O(1) with two variables

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursion | O(2^n) without memo | O(n) | Exponential |
| DP | O(n) | O(1) | Linear recurrence |

<br>
<br>

---

```code```
