## Problem Statement

Solve BFS problem using graph algorithms.

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

1. **Single node:** BFS returns just that node
2. **Disconnected graph:** BFS from one node won't visit all — need multi-source
3. **Linear graph (chain):** BFS visits level by level
4. **Complete graph:** All nodes at distance 1 from start
5. **Cycle in graph:** Must use visited set to avoid infinite loop
6. **Start node not in graph:** Handle invalid input

<br>

---

```code```
