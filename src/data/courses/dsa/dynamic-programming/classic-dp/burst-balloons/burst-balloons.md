Maximize coins from bursting balloons (when balloon i bursts, coins = nums[left] × nums[i] × nums[right]).

<br>

---

## Solution 1: Backtracking — Try all orderings O(n!)
## Solution 2: DP — Think of last balloon to burst in range [i,j]. dp[i][j] = max coins for range.

### Time: O(n³) | Space: O(n²)

**Key insight:** Instead of first-to-burst, think LAST-to-burst. When k is last in [i,j], its neighbors are i-1 and j+1 (guaranteed to still exist).

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Backtracking | O(n!) | O(n) | Try all orderings |
| Interval DP | O(n³) | O(n²) | Last-to-burst insight |

<br>
<br>

---

```code```
