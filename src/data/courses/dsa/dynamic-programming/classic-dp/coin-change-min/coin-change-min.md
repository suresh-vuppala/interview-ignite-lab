Find the minimum number of coins needed to make amount. You have infinite supply of each coin denomination.

<br>

> Input:
> coins = [1, 2, 5], amount = 11

> Output:
> 3

> Explanation:
> 11 = 5 + 5 + 1 (3 coins)
> Other ways: 5+2+2+2 (4 coins), 2+2+2+2+2+1 (6 coins)
> Minimum: 3 coins
> 
> **Key insight:** For each amount, try all coins and take minimum.

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

**Recurrence Relation:**
```
minCoins(amount) = 1 + min(minCoins(amount - coin)) for all coins
Base: minCoins(0) = 0, minCoins(negative) = infinity
```

**Algorithm:**
1. For current amount, try each coin
2. Recursively solve for (amount - coin)
3. Take minimum + 1
4. Store in memo

**Key insight:** Build solution from target amount down to 0.

```code```

<br>

### Time Complexity: O(amount × n)
- amount subproblems
- Each tries n coins
- Total: O(amount × n)

### Space Complexity: O(amount)
- Memo array: O(amount)
- Recursion stack: O(amount)

<br>

---

## Solution 2: Tabulation (Bottom-Up DP)

**DP State:**
```
dp[i] = minimum coins needed to make amount i
```

**Transition:**
```
dp[i] = min(dp[i], 1 + dp[i - coin]) for all coins where coin ≤ i
```

**Algorithm:**
1. Create dp array, initialize with infinity
2. Set dp[0] = 0
3. For each amount from 1 to target:
   - Try each coin
   - Update dp[amount] with minimum
4. Return dp[target]

```code```

<br>

### Time Complexity: O(amount × n)
- Outer loop: amount iterations
- Inner loop: n coins
- Total: O(amount × n)

### Space Complexity: O(amount)
- DP array: O(amount)
- No recursion stack

<br>

---

## Comparison

| Approach | Time | Space | Pros | Cons |
|----------|------|-------|------|------|
| Memoization | O(amount×n) | O(amount) | Natural recursion | Stack overhead |
| Tabulation | O(amount×n) | O(amount) | Iterative, efficient | Must solve all |

**When to use:**
- Memoization: When not all subproblems needed
- Tabulation: When all subproblems needed (this problem)

**Applications:**
- Currency exchange
- Resource allocation
- Knapsack variants

> **Time Complexity:** O(amount × n)
> **Space Complexity:** O(amount)

<br>
<br>

---
