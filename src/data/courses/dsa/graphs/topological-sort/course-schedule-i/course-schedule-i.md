## Problem Statement

Solve Course Schedule I problem using graph algorithms.

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
- `prerequisites[i].length == 2`
- `No duplicate prerequisites`

<br>

---

## All Possible Edge Cases

1. **No prerequisites:** All courses can be taken → true
2. **Simple chain:** A→B→C → true
3. **Cycle exists:** A→B→A → false
4. **Self-dependency:** [0,0] → false
5. **Disconnected courses:** Independent groups → true
6. **Single course:** Always true

<br>

---

```code```
