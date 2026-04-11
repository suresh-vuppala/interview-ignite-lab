## Problem Statement

Solve Shortest Path Weighted problem using graph algorithms.

## Approach

- Apply appropriate graph traversal or algorithm
- Handle edge cases

## Complexity Analysis

### Time Complexity: O(V + E)
### Space Complexity: O(V)

## Code



---

## Constraints

- `1 ≤ n ≤ 10⁵`
- `0 ≤ edges.length ≤ 2 × 10⁵`
- `Weights are non-negative`

<br>

---

## All Possible Edge Cases

1. **Source == destination:** Distance = 0
2. **No path exists:** Return -1 or infinity
3. **Single edge path:** Return edge weight
4. **Multiple shortest paths:** Return any
5. **Disconnected graph:** Some distances are infinity

<br>

---

```code```
