## Problem Statement

Solve Rotting Oranges problem using graph algorithms.

## Approach

- Apply appropriate graph traversal or algorithm
- Handle edge cases

## Complexity Analysis

### Time Complexity: O(V + E)
### Space Complexity: O(V)

## Code



---

## Constraints

- `1 ≤ m, n ≤ 10`
- `grid[i][j] is 0, 1, or 2`

<br>

---

## All Possible Edge Cases

1. **No fresh oranges:** Return 0
2. **No rotten oranges but fresh exist:** Return -1 (impossible)
3. **All rotten already:** Return 0
4. **Isolated fresh orange:** Unreachable → return -1
5. **Single cell:** Return 0 if rotten, -1 if fresh, 0 if empty
6. **All fresh connected to rotten:** Multi-source BFS

<br>

---

```code```
