## Problem Statement

Solve Detect Cycle Undirected problem using graph algorithms.

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
- `No self-loops or duplicate edges (typically)`

<br>

---

## All Possible Edge Cases

1. **Tree (no cycle):** n-1 edges, no cycle
2. **Single extra edge:** One cycle exists
3. **Disconnected graph with cycle in one component:** Must check all components
4. **Two nodes with edge:** No cycle (need 3+ nodes for cycle in undirected)
5. **Multiple cycles:** Detect any one
6. **Single node:** No cycle possible

<br>

---

```code```
