Break integer n into sum of at least two positive integers and maximize their product.

<br>

> Input:
> n = 10

> Output:
> 36

> Explanation:
> 10 = 3 + 3 + 4, product = 3 × 3 × 4 = 36
> 
> **Key insight:** For each number, try all possible first breaks.

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
maxProduct(n) = max(j * (n-j), j * maxProduct(n-j)) for all j
```



### Time: O(n²) | Space: O(n)

---

## Solution 2: Tabulation (Bottom-Up DP)

**DP State:**
```
dp[i] = max product for integer i
dp[i] = max(j * (i-j), j * dp[i-j]) for j in 1..i-1
```



### Time: O(n²) | Space: O(n)

---

---

```code```
