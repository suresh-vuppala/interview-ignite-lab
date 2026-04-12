Determine if a subset exists with sum equal to target.

<br>

> **Key insight:** Boolean knapsack: dp[j] = dp[j] || dp[j-nums[i]]. Process right to left (0/1 knapsack).

<br>

---

## Constraints
- Typical DP constraints

<br>

---

## Solution 1: Recursion

> **Drawback:** Overlapping subproblems.

> **Key Insight for Improvement:** Recurrence: `dp[j] = dp[j] || dp[j-nums[i]]`

<br>

---

## Solution 2: DP — Bottom-up

**Recurrence:** `dp[j] = dp[j] || dp[j-nums[i]]`

### Time Complexity: O(N×target)
**Why?** Each state computed once.

### Space Complexity: O(target)

**Example walkthrough:**
```
nums=[3,34,4,12,5,2], target=9 → true (4+5=9)
```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Recursion | Exponential | O(N) stack |
| DP | O(N×target) | O(target) |

**Key Insights:**
1. Identify states, transitions, base cases
2. Space optimization when possible


<br><br>

---

```code```
