## Problem Statement

Solve Topological Sort Kahns problem using graph algorithms.

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

1. **Graph has cycle:** Kahn's detects it — not all nodes processed
2. **Multiple sources (in-degree 0):** Multiple valid orderings
3. **Single source:** Unique start point
4. **All nodes independent:** Any order works
5. **Single node:** Trivial ordering

<br>

---

```code```
