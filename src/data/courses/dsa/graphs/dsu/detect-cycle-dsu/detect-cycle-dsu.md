## Problem Statement

Solve Detect Cycle DSU problem using graph algorithms.

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

1. **Tree (no cycle):** All edges connect different components
2. **First edge creates cycle:** Two nodes already connected
3. **Cycle at the end:** Last edge connects already-connected nodes
4. **Single node:** No cycle
5. **Self-loop:** Cycle detected immediately

<br>

---

```code```
