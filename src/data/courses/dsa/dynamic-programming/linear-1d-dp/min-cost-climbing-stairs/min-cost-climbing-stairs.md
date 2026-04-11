You are given an array cost where cost[i] is the cost of ith step. You can start from step 0 or 1. Find minimum cost to reach the top (beyond last step).

<br>

> Input:
> cost = [10, 15, 20]

> Output:
> 15

> Explanation:
> Start at index 1 (cost 15), climb one step to top
> Total cost: 15
> Alternative: Start at 0 (10), climb to 1 (15), climb to top = 25
> 
> **Key insight:** At each step, choose minimum of previous two steps.

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
minCost(i) = cost[i] + min(minCost(i-1), minCost(i-2))
Base: minCost(0) = cost[0], minCost(1) = cost[1]
```


### Time: O(n) | Space: O(n)

---

## Solution 2: Tabulation (Bottom-Up DP)

**DP State:**
```
dp[i] = min cost to reach step i
dp[i] = cost[i] + min(dp[i-1], dp[i-2])
```


### Time: O(n) | Space: O(n) or O(1) optimized

```code```
