## Problem Statement

Solve Topological Sort DFS problem using graph algorithms.

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
- `Graph is a DAG`

<br>

---

## All Possible Edge Cases

1. **Single node:** Order is [0]
2. **Linear chain:** Only one valid ordering
3. **Diamond DAG:** Multiple valid orderings
4. **Disconnected DAG:** Include all components
5. **No edges:** Any permutation is valid

<br>

---

```code```
