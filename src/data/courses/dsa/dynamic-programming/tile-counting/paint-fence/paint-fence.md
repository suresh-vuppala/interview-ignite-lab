Paint n fence posts with k colors such that no more than 2 adjacent posts have the same color.

<br>

> Input:
> n = 3, k = 2

> Output:
> 6

> Explanation:
> With 2 colors (C1, C2) and 3 posts:
> Valid: C1-C1-C2, C1-C2-C1, C1-C2-C2, C2-C2-C1, C2-C1-C1, C2-C1-C2
> Invalid: C1-C1-C1, C2-C2-C2 (3 consecutive same)
> 
> **Key insight:** At post i, either paint different from i-1, or same as i-1 (but i-2 must differ).

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

## Solution 1: Recursive Approach (Brute Force)

**Intuition:**
At post i, we can:
- Paint different color from i-1: (k-1) × ways(i-1)
- Paint same color as i-1: only if i-1 differs from i-2: ways(i-2)

**Recurrence Relation:**
```
f(n) = (k-1) × f(n-1) + (k-1) × f(n-2)
     = (k-1) × (f(n-1) + f(n-2))
Base: f(1) = k, f(2) = k×k
```

### Time Complexity: O(2^n)
### Space Complexity: O(n)

> **Key Insight for Improvement:**
> Overlapping subproblems. Memoize to reduce to O(n).

<br>

---

## Solution 2: Memoization (Top-Down DP)

**Algorithm:**
1. Cache results in memo
2. Return cached value if exists

### Time Complexity: O(n)
### Space Complexity: O(n)

> **Key Insight for Improvement:**
> Remove recursion with iterative approach.

<br>

---

## Solution 3: Tabulation (Bottom-Up DP)

**DP State:**
```
dp[i] = ways to paint i posts
```

**Transition:**
```
dp[i] = (k-1) × (dp[i-1] + dp[i-2])
```

**Algorithm:**
1. Initialize: dp[1] = k, dp[2] = k×k
2. For i from 3 to n: dp[i] = (k-1) × (dp[i-1] + dp[i-2])

### Time Complexity: O(n)
### Space Complexity: O(n)

> **Key Insight for Improvement:**
> Only need last 2 values. Use two variables.

<br>

---

## Solution 4: Space Optimized

**Algorithm:**
1. Use prev2, prev1 variables
2. Update in sliding window

### Time Complexity: O(n)
### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursive | O(2^n) | O(n) | Baseline |
| Memoization | O(n) | O(n) | Cache results |
| Tabulation | O(n) | O(n) | Remove recursion |
| Space Optimized | O(n) | O(1) | Two variables |

> **Final Complexity:** O(n) time, O(1) space

<br>
<br>

---

```code```
