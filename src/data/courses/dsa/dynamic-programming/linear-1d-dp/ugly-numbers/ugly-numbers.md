Find the nth ugly number. Ugly numbers are positive numbers whose prime factors are only 2, 3, or 5.

<br>

> Input:
> n = 10

> Output:
> 12

> Explanation:
> Sequence: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12
> 10th ugly number is 12
> 
> **Key insight:** Generate ugly numbers by multiplying previous ugly numbers by 2, 3, 5.

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

**Not ideal for this problem - use tabulation**

---

## Solution 2: Tabulation (Bottom-Up DP)

**DP State:**
```
dp[i] = ith ugly number
Use 3 pointers (i2, i3, i5)
dp[i] = min(dp[i2]*2, dp[i3]*3, dp[i5]*5)
```



### Time: O(n) | Space: O(n)

---

---

```code```
