Check if a subset with given sum exists.

<br>

---

## Solution 1: Recursion — Try include/exclude each element O(2^n)
## Solution 2: DP Table (Optimal)

dp[i][s] = can we make sum s using first i elements. dp[i][s] = dp[i-1][s] || dp[i-1][s-nums[i]].

### Time: O(n × sum) | Space: O(n × sum) → O(sum) with space optimization

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursion | O(2^n) | O(n) | Exponential |
| DP | O(n × sum) | O(sum) | Pseudo-polynomial |

<br>
<br>

---

```code```
