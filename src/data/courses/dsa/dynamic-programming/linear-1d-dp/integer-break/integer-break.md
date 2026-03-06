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

## Solution 1: Memoization (Top-Down DP)

**Recurrence:**
```
maxProduct(n) = max(j * (n-j), j * maxProduct(n-j)) for all j
```

```code```

### Time: O(n²) | Space: O(n)

---

## Solution 2: Tabulation (Bottom-Up DP)

**DP State:**
```
dp[i] = max product for integer i
dp[i] = max(j * (i-j), j * dp[i-j]) for j in 1..i-1
```

```code```

### Time: O(n²) | Space: O(n)

---
