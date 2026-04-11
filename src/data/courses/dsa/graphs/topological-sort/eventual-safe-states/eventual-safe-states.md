## Problem Statement

Solve Eventual Safe States problem using graph algorithms.

## Approach

- Apply appropriate graph traversal or algorithm
- Handle edge cases

## Complexity Analysis

### Time Complexity: O(V + E)
### Space Complexity: O(V)

## Code



---

## Constraints

- `1 ≤ n ≤ 10⁴`
- `0 ≤ graph[i].length ≤ n`

<br>

---

## All Possible Edge Cases

1. **All terminal nodes:** All nodes are safe
2. **All in cycle:** No safe nodes
3. **Mix of safe and cyclic:** Only non-cyclic paths lead to safe
4. **Single node, no edges:** Safe (terminal)
5. **Self-loop:** Not safe

<br>

---

```code```
