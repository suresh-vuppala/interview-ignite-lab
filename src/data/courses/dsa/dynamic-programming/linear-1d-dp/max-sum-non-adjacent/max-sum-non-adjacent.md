Find maximum sum of non-adjacent elements in array (same as House Robber).

<br>

> Input:
> arr = [5, 1, 3, 8, 2]

> Output:
> 15

> Explanation:
> Select 5, 8, 2 (non-adjacent) = 15
> 
> **Key insight:** Same as House Robber problem.

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
maxSum(i) = max(arr[i] + maxSum(i-2), maxSum(i-1))
```

```code```

### Time: O(n) | Space: O(n)

---

## Solution 2: Tabulation (Bottom-Up DP)

**DP State:**
```
dp[i] = max sum using elements 0..i
dp[i] = max(arr[i] + dp[i-2], dp[i-1])
```

```code```

### Time: O(n) | Space: O(1) optimized

---
