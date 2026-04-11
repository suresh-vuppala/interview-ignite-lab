## Solution #3: Bottom-Up Approach(Tabulation)
For the bottom-up dynamic programming, we want to start with subproblems first and work our way up to the main problem. This is normally done by filling up a table.
Here, In the Fibonacci problem, we want to fill a one-dimensional table dp where each entry at index i represents value of the Fibonacci number at index i. The last element of the array is the answer we want to return.

The order of filling matters because we cannot calculate dp[i] before we filled dp[i - 1] and dp[i - 2].

![Fibonacci](/Image/FibTabulation.png)


[code]

> **Time Complexity:** O(N)
> Here, we solve each subproblem only once in iterative manner. So the time complexity of the algorithm is also O(N).
> **Space Complexity:** O(N)
> we use an array of size N for remembering the results which contributes to a space complexity of O(N).



<br>
<br>

Note: Never look down upon the brute-force solution. the most difficult part of the dynamic programming problem is to write the state transfer equation, that is, the brute-force solution. The optimization method is nothing more than the use of the memo or DP table.

<br>
<br>
---

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

## Solution #4: Bottom-Up Approach + Space Optimization


![Fibonacci](/Image/FibSpaceOptimization.png)

[code]
> **Time Complexity:** O(N)
> Here, we solve each subproblem only once in iterative manner. So the time complexity of the algorithm is also O(N).
> **Space Complexity:** O(1)

<br>
<br>

### Should I do top-down or bottom-up?

| **Aspect**          | **Memoization**                                                                                      | **Tabulation**                                                       |
|---------------------|-----------------------------------------------------------------------------------------------------|----------------------------------------------------------------------|
| **State Definition** | Complicated to identify what a state should represent.                                             | Can be thought of easily.                                           |
| **Ease of Code**    | Code gets complicated when a lot of conditions are required.                                       | Code is easy and less complicated.                                   |
| **Speed of Execution** | Slower due to recursive calls and return statements.                                            | Fast, as we directly access previous states from the table.         |
| **Space**           | The cache entries are filled on demand during memorization.                                        | The table is fully computed.                                        |

<br>
<br>
---
### Comparison of Different Approaches:

| **Approach**            | **Time Complexity** | **Space Complexity** |
|-------------------------|---------------------|-----------------------|
| Recursive Approach       | O(2^N)              | O(N)                  |
| Top-down Approach        | O(N)                | O(N)                  |
| Bottom-up Approach       | O(N)                | O(N)                  |
| Space Optimization       | O(N)                | O(1)                  |

---

```code```
