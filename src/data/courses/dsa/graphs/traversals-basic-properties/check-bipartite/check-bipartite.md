## Problem Statement

Solve Check Bipartite problem using graph algorithms.

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

<br>

---

## All Possible Edge Cases

1. **Tree:** Always bipartite
2. **Odd-length cycle:** Not bipartite
3. **Even-length cycle:** Bipartite
4. **Single node:** Bipartite
5. **Disconnected graph:** Each component must be bipartite
6. **Complete graph K3+:** Not bipartite for n ≥ 3
7. **Two nodes with edge:** Bipartite

<br>

---

```code```
