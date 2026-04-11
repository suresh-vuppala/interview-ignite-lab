## Problem Statement

Solve Network Delay Time problem using graph algorithms.

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
- `1 ≤ times.length ≤ 6000`
- `1 ≤ u, v ≤ n`
- `0 ≤ w ≤ 100`

<br>

---

## All Possible Edge Cases

1. **All nodes directly connected to source:** Max of direct edge weights
2. **Unreachable node:** Return -1
3. **Single node:** Return 0
4. **Chain graph:** Sum of all edge weights
5. **Multiple paths to same node:** Take shortest

<br>

---

```code```
