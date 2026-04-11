## Problem Statement

Solve Number of Islands problem using graph algorithms.

## Approach

- Apply appropriate graph traversal or algorithm
- Handle edge cases

## Complexity Analysis

### Time Complexity: O(V + E)
### Space Complexity: O(V)

## Code



---

## Constraints

- `1 ≤ m, n ≤ 300`
- `grid[i][j] is '0' or '1'`

<br>

---

## All Possible Edge Cases

1. **All water:** 0 islands
2. **All land:** 1 island
3. **Single cell land:** 1 island
4. **Diagonal land cells:** Diagonals don't connect — separate islands
5. **Large single island:** Fills entire grid
6. **Checkerboard pattern:** Many small islands
7. **Island touching edge:** Still valid island

<br>

---

```code```
