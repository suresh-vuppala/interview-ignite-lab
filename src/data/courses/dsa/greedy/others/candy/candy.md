Distribute candies: each child gets ≥ 1, higher-rated gets more than neighbors.

<br>

---

## Solution 1: Two-Pass (Left + Right)

Pass 1 (left→right): if rating[i] > rating[i-1], candy[i] = candy[i-1]+1.
Pass 2 (right→left): if rating[i] > rating[i+1], candy[i] = max(candy[i], candy[i+1]+1).

### Time: O(n) | Space: O(n)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Two-Pass | O(n) | O(n) | Left constraint then right constraint |

<br>
<br>

---

```code```
