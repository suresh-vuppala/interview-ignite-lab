## Problem Statement

Solve Build Graph problem using graph algorithms.

## Approach

- Apply appropriate graph traversal or algorithm
- Handle edge cases

## Complexity Analysis

### Time Complexity: O(V + E)
### Space Complexity: O(V)

## Code



---

## Constraints

- `1 ≤ n ≤ 10⁵ (number of nodes)`
- `0 ≤ edges.length ≤ 2 × 10⁵`
- `Edges given as pairs [u, v]`

<br>

---

## All Possible Edge Cases

1. **Empty graph:** No edges — adjacency list has empty lists
2. **Single node:** Node with no connections
3. **Self-loop:** Edge [u, u] — handle or ignore based on problem
4. **Duplicate edges:** Same edge given twice
5. **Disconnected graph:** Multiple components
6. **Dense graph:** Close to n² edges — adjacency matrix may be better

<br>

---

```code```
