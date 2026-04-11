## Overview
Learn to reverse only the first K nodes of a linked list.

## Topics Covered
1. **Partial Reversal**: Reverse only first K nodes
2. **Connect Remaining**: Link reversed part to rest
3. **Handle K > Length**: Deal with edge cases
4. **Iterative Approach**: Use pointer manipulation

## Problem Statement
Reverse the first K nodes of a linked list and keep the rest unchanged.


---

## Constraints

- `1 ≤ k ≤ n`
- `1 ≤ n ≤ 10⁵`

<br>

---

## All Possible Edge Cases

1. **k = 1:** No change
2. **k = n:** Reverse entire list
3. **k = 2:** Swap first two nodes
4. **Single node, k = 1:** Return as-is

<br>

## Approach

### Reverse First K
- Reverse first K nodes using standard reversal
- Keep track of connection point
- Link reversed part to remaining list
- Time: O(n), Space: O(1)

## Complexity Analysis

### Time Complexity: O(n)
### Space Complexity: O(1)

## Code

```code```
