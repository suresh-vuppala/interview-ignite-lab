## Problem Statement

Solve Detect Cycle Directed problem using graph algorithms.

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

1. **DAG (no cycle):** Return false
2. **Self-loop:** Single node cycle
3. **Two nodes cycling:** A→B→A
4. **Long cycle:** Requires full DFS path tracking
5. **Multiple disconnected components:** Must check each
6. **Single node, no edges:** No cycle

<br>

---

```code```
