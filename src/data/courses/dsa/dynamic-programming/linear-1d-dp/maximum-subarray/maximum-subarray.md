Find the contiguous subarray with the largest sum (Kadane's Algorithm).

<br>

> Input:
> nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]

> Output:
> 6

> Explanation:
> Subarray [4, -1, 2, 1] has sum = 6
> 
> **Key insight:** At each position, either extend current subarray or start new.

<br>


---

## Constraints

- `0 ≤ n ≤ 10⁴`
- `Values fit in 32-bit integer`
- `DP state space fits in memory`

<br>

---

## All Possible Edge Cases

1. **n = 0 or empty input:** Base case — return 0 or empty
2. **n = 1:** Single element — trivial case
3. **All same elements:** Check if pattern still applies
4. **Maximum constraints:** Verify time complexity handles worst case
5. **Negative values (if applicable):** Affects min/max DP transitions
6. **Result requires modular arithmetic:** Use MOD = 10⁹ + 7 to prevent overflow

<br>

---

## Solution 1: Memoization (Top-Down DP)

**Recurrence:**
```
maxEndingHere(i) = max(nums[i], nums[i] + maxEndingHere(i-1))
maxSoFar = max of all maxEndingHere(i)
```

```code```

### Time: O(n) | Space: O(n)

---

## Solution 2: Tabulation (Bottom-Up DP)

**DP State:**
```
dp[i] = max sum ending at index i
dp[i] = max(nums[i], nums[i] + dp[i-1])
result = max(dp)
```

```code```

### Time: O(n) | Space: O(1) optimized (Kadane's)

---
