Partition array into two equal-sum subsets using MITM for large N.

<br>

> nums with N up to 40 → can partition into equal sums?
>
> **Key insight:** Meet in the middle variant. Target = totalSum/2. Same MITM approach.

<br>

---

## Constraints
- 1 ≤ N ≤ 40

<br>

---

## All Possible Edge Cases
1. **Odd total sum: impossible
2. **All same elements + even count
3. **Single element: impossible (unless 0)**

<br>

---

## Solution 1: Standard DP

**Intuition:**
The most straightforward approach. Sum can be too large for DP.

**Algorithm:**
1. Define state: what information captures the subproblem
2. Define base cases
3. For each state, compute value using recurrence relation
4. Return dp[final_state]

### Time Complexity: O(N × sum)
**Why?**
Two factors multiply: one from iterating elements, one from the operation per element.
Total = product of both factors.

**Detailed breakdown:**
Depends on both dimensions of the input.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Sum can be too large for DP.

> **Key Insight for Improvement:**
> MITM: split, generate sums, search for target sum from combinations of both halves.

<br>

---

## Solution 2: Meet in the Middle (Optimal)

**Intuition:** Meet in the middle variant. Target = totalSum/2. Same MITM approach.

**Algorithm:**
Same MITM with target = sum/2

### Time Complexity: O(2^(N/2) × N)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
Same as subset-sum-mitm with target = totalSum/2
```

### Space Complexity: O(2^(N/2))

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Standard DP | O(N × sum) | Varies | Baseline |
| Meet in the Middle | O(2^(N/2) × N) | O(2^(N/2)) | Optimal |

**Recommended Solution:** Meet in the Middle

**Key Insights:**
1. **Equal partition = subset sum target sum/2**
2. **MITM when N > 25-30:** DP won't work, MITM will

<br><br>

---

```code```
