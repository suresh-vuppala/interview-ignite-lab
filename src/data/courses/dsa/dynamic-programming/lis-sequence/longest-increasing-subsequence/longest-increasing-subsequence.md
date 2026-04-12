Find length of the longest strictly increasing subsequence.

<br>

> **Key insight:** O(N²) DP: dp[i] = max(dp[j]+1) for all j<i where nums[j]<nums[i]. O(N log N): maintain sorted tails array, binary search for insertion point.

<br>

---

## Constraints
- Typical DP constraints

<br>

---

## Solution 1: Recursion

> **Drawback:** Overlapping subproblems.

> **Key Insight for Improvement:** Recurrence: `dp[i] = 1 + max(dp[j]) for j<i where nums[j]<nums[i]`

<br>

---

## Solution 2: DP — Bottom-up

**Recurrence:** `dp[i] = 1 + max(dp[j]) for j<i where nums[j]<nums[i]`

### Time Complexity: O(N log N) with patience sorting
**Why?** Each state computed once.

### Space Complexity: O(N)

**Example walkthrough:**
```
nums=[10,9,2,5,3,7,101,18] → LIS=4 ([2,3,7,101] or [2,5,7,101])
```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Recursion | Exponential | O(N) stack |
| DP | O(N log N) with patience sorting | O(N) |

**Key Insights:**
1. Identify states, transitions, base cases
2. Space optimization when possible
3. **O(N log N) trick:** Maintain array of smallest tail elements. Binary search for position.
4. **FAANG critical:** Top-10 DP problem

<br><br>

---

```code```
