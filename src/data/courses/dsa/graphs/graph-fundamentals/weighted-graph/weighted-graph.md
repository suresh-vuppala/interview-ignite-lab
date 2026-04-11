## Problem Statement

Solve Weighted Graph problem using graph algorithms.

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
- `-10⁴ ≤ weight ≤ 10⁴`

<br>

---

## All Possible Edge Cases

1. **Negative weights:** Dijkstra fails — need Bellman-Ford
2. **Zero weight edges:** Valid but may cause issues in some algorithms
3. **All same weights:** Equivalent to unweighted BFS
4. **Very large weights:** Potential overflow when summing path costs
5. **Single node:** No edges to process

<br>

---

```code```
