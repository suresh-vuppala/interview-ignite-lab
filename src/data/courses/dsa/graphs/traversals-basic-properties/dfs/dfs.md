## Problem Statement

Solve DFS problem using graph algorithms.

## Approach

- Apply appropriate graph traversal or algorithm
- Handle edge cases

## Complexity Analysis

### Time Complexity: O(V + E)
### Space Complexity: O(V)

## Code



---

## Constraints

- `0 ≤ n ≤ 10⁵`
- `0 ≤ edges.length ≤ 2 × 10⁵`

<br>

---

## All Possible Edge Cases

1. **Single node:** DFS returns just that node
2. **Disconnected graph:** DFS from one source misses other components
3. **Deep linear chain:** Recursion depth = n — may cause stack overflow
4. **Cycle in graph:** Must track visited to avoid infinite recursion
5. **Complete graph:** DFS goes deep through one path first
6. **Start node not in graph:** Handle invalid input

<br>

---

```code```
