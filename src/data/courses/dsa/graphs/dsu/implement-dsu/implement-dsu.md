## Problem Statement

Solve Implement DSU problem using graph algorithms.

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
- `Operations: union(u,v), find(u)`

<br>

---

## All Possible Edge Cases

1. **Union same element:** No change
2. **Find on root:** Returns itself
3. **Long chain before compression:** Path compression flattens it
4. **All elements in one set:** Single root after all unions
5. **No unions performed:** Each element is its own set

<br>

---

```code```
