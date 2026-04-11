## Problem Statement

Solve Cheapest Flights problem using graph algorithms.

## Approach

- Apply appropriate graph traversal or algorithm
- Handle edge cases

## Complexity Analysis

### Time Complexity: O(V + E)
### Space Complexity: O(V)

## Code



---

## Constraints

- `1 ≤ n ≤ 100`
- `0 ≤ flights.length ≤ n*(n-1)/2`
- `0 ≤ price ≤ 10⁴`
- `0 ≤ k ≤ n-1`

<br>

---

## All Possible Edge Cases

1. **k = 0:** Direct flight or -1
2. **No flights:** Return -1 unless src == dst
3. **src == dst:** Return 0
4. **Cheaper path with more stops:** Must respect k limit
5. **All direct flights available:** Min direct price
6. **k = n-1:** No stop limit, find cheapest path

<br>

---

```code```
