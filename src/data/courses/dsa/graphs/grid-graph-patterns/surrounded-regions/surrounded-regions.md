## Problem Statement

Solve Surrounded Regions problem using graph algorithms.

## Approach

- Apply appropriate graph traversal or algorithm
- Handle edge cases

## Complexity Analysis

### Time Complexity: O(V + E)
### Space Complexity: O(V)

## Code



---

## Constraints

- `1 ≤ m, n ≤ 200`
- `board[i][j] is 'X' or 'O'`

<br>

---

## All Possible Edge Cases

1. **No O cells:** Nothing to flip
2. **All O cells:** Border-connected O's survive
3. **O only on border:** None get flipped
4. **O not connected to border:** All get flipped
5. **Single cell board:** Never surrounded
6. **O in corner:** Connected to border — survives

<br>

---

```code```
