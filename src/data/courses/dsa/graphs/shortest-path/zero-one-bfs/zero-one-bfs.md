## Problem Statement

Solve Zero One BFS problem using graph algorithms.

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
- `Edge weights are 0 or 1 only`

<br>

---

## All Possible Edge Cases

1. **All zero-weight edges:** All distances are 0 within component
2. **All weight-1 edges:** Same as standard BFS
3. **Mixed 0 and 1:** Deque-based BFS needed
4. **Source isolated:** All distances infinity except source=0
5. **Single node:** Distance = 0

<br>

---

```code```
