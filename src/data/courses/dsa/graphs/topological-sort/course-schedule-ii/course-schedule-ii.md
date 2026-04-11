## Problem Statement

Solve Course Schedule II problem using graph algorithms.

## Approach

- Apply appropriate graph traversal or algorithm
- Handle edge cases

## Complexity Analysis

### Time Complexity: O(V + E)
### Space Complexity: O(V)

## Code



---

## Constraints

- `1 ≤ numCourses ≤ 2000`
- `0 ≤ prerequisites.length ≤ 5000`

<br>

---

## All Possible Edge Cases

1. **No prerequisites:** Return [0,1,...,n-1] (any order)
2. **Cycle exists:** Return empty array
3. **Single course:** Return [0]
4. **Linear chain:** One valid order
5. **Multiple valid orders:** Return any valid topological order

<br>

---

```code```
