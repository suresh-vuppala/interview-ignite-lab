Find minimum in each sliding window of size k (complement of sliding window maximum).

<br>

---

## Solution 1: Brute Force — Scan k elements per window O(nk)
## Solution 2: Monotonic Deque (Optimal)

Maintain increasing deque. Front = minimum. Remove from front if expired, back if larger than incoming.

### Time: O(n) | Space: O(k)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(nk) | O(1) | Scan each window |
| Monotonic Deque | O(n) | O(k) | Increasing deque tracks minimums |

<br>
<br>

---

```code```
