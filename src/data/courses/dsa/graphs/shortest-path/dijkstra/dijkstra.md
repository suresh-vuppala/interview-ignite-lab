## Problem Statement

Solve Dijkstra problem using graph algorithms.

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
- `0 ≤ weight ≤ 10⁴ (non-negative weights only)`

<br>

---

## All Possible Edge Cases

1. **Source is destination:** Distance = 0
2. **Unreachable node:** Distance = infinity
3. **Single node:** Distance = 0
4. **Negative weights:** Dijkstra gives wrong answer — use Bellman-Ford
5. **Multiple shortest paths:** Any one is valid
6. **Disconnected graph:** Some nodes unreachable

<br>

---

```code```
