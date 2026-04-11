## Problem Statement

Solve Flood Fill problem using graph algorithms.

## Approach

- Apply appropriate graph traversal or algorithm
- Handle edge cases

## Complexity Analysis

### Time Complexity: O(V + E)
### Space Complexity: O(V)

## Code



---

## Constraints

- `1 ≤ m, n ≤ 50`
- `0 ≤ image[i][j] ≤ 65535`
- `0 ≤ newColor ≤ 65535`

<br>

---

## All Possible Edge Cases

1. **New color same as original:** No change needed — skip to avoid infinite loop
2. **Single cell:** Just change that cell
3. **Entire grid same color:** Flood fill covers everything
4. **Start cell different from neighbors:** Only start cell changes
5. **All different colors:** Only start cell changes

<br>

---

```code```
