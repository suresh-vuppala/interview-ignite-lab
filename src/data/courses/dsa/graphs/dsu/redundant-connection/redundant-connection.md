## Problem Statement

Solve Redundant Connection problem using graph algorithms.

## Approach

- Apply appropriate graph traversal or algorithm
- Handle edge cases

## Complexity Analysis

### Time Complexity: O(V + E)
### Space Complexity: O(V)

## Code



---

## Constraints

- `n == edges.length`
- `1 ≤ n ≤ 1000`
- `1 ≤ edges[i][0], edges[i][1] ≤ n`
- `No repeated edges`

<br>

---

## All Possible Edge Cases

1. **Cycle formed by last edge:** Return last edge
2. **Cycle formed early:** Return the edge that first creates redundancy
3. **Triangle:** First edge completing the triangle
4. **All edges form one big cycle:** Last edge in the cycle

<br>

---

```code```
