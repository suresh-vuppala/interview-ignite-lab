You are climbing a staircase with n steps. You can climb 1 or 2 steps at a time. How many distinct ways can you reach the top?

<br>

> Input:
> n = 5

> Output:
> 8

> Explanation:
> Ways to reach step 5:
> 1. 1+1+1+1+1
> 2. 1+1+1+2
> 3. 1+1+2+1
> 4. 1+2+1+1
> 5. 2+1+1+1
> 6. 1+2+2
> 7. 2+1+2
> 8. 2+2+1
> 
> **Key insight:** To reach step i, you can come from step i-1 or i-2.

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
ways(n) = ways(n-1) + ways(n-2)
Base: ways(0) = 1, ways(1) = 1
```

**Algorithm:**
1. Start from n, recursively solve subproblems
2. Store results in memo to avoid recomputation
3. Return memo[n]

**Key insight:** Same as Fibonacci - each step depends on previous two.

<br>

### Time Complexity: O(n)
- Each subproblem computed once
- Memoization prevents recomputation
- Total: n subproblems × O(1) = O(n)

### Space Complexity: O(n)
- Memo array: O(n)
- Recursion stack: O(n)

<br>

---

## Solution 2: Tabulation (Bottom-Up DP)

**DP State:**
```
dp[i] = number of ways to reach step i
```

**Transition:**
```
dp[i] = dp[i-1] + dp[i-2]
```

**Algorithm:**
1. Create dp array of size n+1
2. Initialize: dp[0] = 1, dp[1] = 1
3. Fill dp[i] for i from 2 to n
4. Return dp[n]

<br>

### Time Complexity: O(n)
- Single loop from 2 to n
- Each iteration: O(1)

### Space Complexity: O(n)
- DP array: O(n)

**Space Optimization: O(1)**
- Only need last 2 values
- Use two variables instead of array

<br>

---

## Comparison

| Approach | Time | Space | Pros | Cons |
|----------|------|-------|------|------|
| Memoization | O(n) | O(n) | Intuitive, solves only needed | Recursion overhead |
| Tabulation | O(n) | O(n) | Iterative, no stack | Must solve all subproblems |
| Optimized | O(n) | O(1) | Minimal space | Less readable |

> **Time Complexity:** O(n) for both approaches
> **Space Complexity:** O(n) or O(1) with optimization

<br>
<br>

---

## Code Implementation

```python
class Solution:
    # ============ MEMOIZATION (TOP-DOWN) ============
    def climbStairsMemo(self, n):
        memo = {}
        def dp(i):
            if i <= 1:
                return 1
            if i in memo:
                return memo[i]
            memo[i] = dp(i-1) + dp(i-2)
            return memo[i]
        return dp(n)
    
    # ============ TABULATION (BOTTOM-UP) ============
    def climbStairsTab(self, n):
        if n <= 1:
            return 1
        dp = [0] * (n + 1)
        dp[0], dp[1] = 1, 1
        for i in range(2, n + 1):
            dp[i] = dp[i-1] + dp[i-2]
        return dp[n]
    
    # ============ SPACE OPTIMIZED ============
    def climbStairs(self, n):
        if n <= 1:
            return 1
        prev2, prev1 = 1, 1
        for i in range(2, n + 1):
            curr = prev1 + prev2
            prev2, prev1 = prev1, curr
        return prev1
```

```cpp
class Solution {
public:
    // ============ MEMOIZATION (TOP-DOWN) ============
    int climbStairsMemo(int n) {
        unordered_map<int, int> memo;
        return dpMemo(n, memo);
    }
    
    int dpMemo(int n, unordered_map<int, int>& memo) {
        if (n <= 1) return 1;
        if (memo.count(n)) return memo[n];
        memo[n] = dpMemo(n-1, memo) + dpMemo(n-2, memo);
        return memo[n];
    }
    
    // ============ TABULATION (BOTTOM-UP) ============
    int climbStairsTab(int n) {
        if (n <= 1) return 1;
        vector<int> dp(n + 1);
        dp[0] = 1; dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    
    // ============ SPACE OPTIMIZED ============
    int climbStairs(int n) {
        if (n <= 1) return 1;
        int prev2 = 1, prev1 = 1;
        for (int i = 2; i <= n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
```

```java
class Solution {
    // ============ MEMOIZATION (TOP-DOWN) ============
    public int climbStairsMemo(int n) {
        HashMap<Integer, Integer> memo = new HashMap<>();
        return dpMemo(n, memo);
    }
    
    private int dpMemo(int n, HashMap<Integer, Integer> memo) {
        if (n <= 1) return 1;
        if (memo.containsKey(n)) return memo.get(n);
        int result = dpMemo(n-1, memo) + dpMemo(n-2, memo);
        memo.put(n, result);
        return result;
    }
    
    // ============ TABULATION (BOTTOM-UP) ============
    public int climbStairsTab(int n) {
        if (n <= 1) return 1;
        int[] dp = new int[n + 1];
        dp[0] = 1; dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    
    // ============ SPACE OPTIMIZED ============
    public int climbStairs(int n) {
        if (n <= 1) return 1;
        int prev2 = 1, prev1 = 1;
        for (int i = 2; i <= n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
}
```

---

```code```
