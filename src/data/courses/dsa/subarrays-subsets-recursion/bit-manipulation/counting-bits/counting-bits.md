For each number 0 to N, count the number of set bits.

<br>

> n=5 → [0,1,1,2,1,2]
>
> **Key insight:** DP: dp[i] = dp[i>>1] + (i&1). Right shift removes last bit; add 1 if last bit was set.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## All Possible Edge Cases
1. **Empty/single element input**
2. **Boundary values** (min/max of range)
3. **All elements same / sorted / reverse sorted**

<br>

---

## Solution 1: Count bits individually

**Intuition:**
The most straightforward approach. 32 operations per number.

**Algorithm:**
1. Enumerate all possible candidates
2. For each candidate, verify if it satisfies the condition
3. Track the best valid result
4. Return the optimal answer

### Time Complexity: O(N × 32)
**Why?**
Two factors multiply: one from iterating elements, one from the operation per element.
Total = product of both factors.

**Detailed breakdown:**
Depends on both dimensions of the input.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> 32 operations per number.

> **Key Insight for Improvement:**
> DP relation: number of bits in i = bits in i/2 + last bit. O(1) per number.

<br>

---

## Solution 2: DP — Shift Relation (Optimal)

**Intuition:** DP: dp[i] = dp[i>>1] + (i&1). Right shift removes last bit; add 1 if last bit was set.

**Algorithm:**
1. dp[0] = 0
2. For i = 1 to N: dp[i] = dp[i >> 1] + (i & 1)
3. Return dp

### Time Complexity: O(N)
**Why?**
Each element/state processed efficiently via the core technique.

**Detailed breakdown:**
Operations scale with input size as described by the complexity.

**Example walkthrough:**
```
dp[0]=0, dp[1]=dp[0]+1=1, dp[2]=dp[1]+0=1, dp[3]=dp[1]+1=2, dp[4]=dp[2]+0=1, dp[5]=dp[2]+1=2
```

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Count bits individually | O(N × 32) | Varies | Baseline |
| DP — Shift Relation | O(N) | O(N) | Optimal approach |

**Recommended Solution:** DP — Shift Relation — O(N) time.

**Key Insights:**
1. **dp[i>>1]:** Bits in i with last bit removed = bits in i/2
2. **(i&1):** Add 1 if last bit is set
3. **O(1) per number:** Just one lookup + one operation

<br><br>

---

```code```
