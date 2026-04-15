Find subsequence sum closest to a goal.

<br>

> nums, goal → closest achievable sum
>
> **Key insight:** Meet in the middle: generate all sums for each half, sort one, binary search for closest to (goal - other_sum).

<br>

---

## Constraints
- 1 ≤ N ≤ 40
- -10⁷ ≤ nums[i] ≤ 10⁷
- -10⁹ ≤ goal ≤ 10⁹

<br>

---

## All Possible Edge Cases
1. **Exact match possible: diff = 0
2. **Empty subsequence (sum=0) is closest
3. **All positive or all negative**

<br>

---

## Solution 1: Try all subsequences

**Intuition:**
The most straightforward approach. Exponential.

**Algorithm:**
1. Enumerate all possible candidates
2. For each candidate, verify if it satisfies the condition
3. Track the best valid result
4. Return the optimal answer

### Time Complexity: O(2^N)
**Why?**
Each element has multiple choices (include/exclude, take/skip), leading to exponential branching.
For N elements, the total states explored grow as 2^N or worse.

**Detailed breakdown:**
For N=20: ~1 million states. For N=30: ~1 billion states — too slow.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Exponential.

> **Key Insight for Improvement:**
> Same MITM as subset-sum but find closest instead of exact match. Binary search finds nearest value.

<br>

---

## Solution 2: Meet in the Middle + Closest (Optimal)

**Intuition:** Meet in the middle: generate all sums for each half, sort one, binary search for closest to (goal - other_sum).

**Algorithm:**
Same as subset-sum-mitm but binary search for closest value to (goal - left_sum) in sorted right sums

### Time Complexity: O(2^(N/2) × N)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
For each left_sum: find right_sum closest to (goal - left_sum). Track global minimum difference.
```

### Space Complexity: O(2^(N/2))

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Try all subsequences | O(2^N) | Varies | Baseline |
| Meet in the Middle + Closest | O(2^(N/2) × N) | O(2^(N/2)) | Optimal |

**Recommended Solution:** Meet in the Middle + Closest

**Key Insights:**
1. **Closest variant:** Binary search returns nearest, not exact
2. **Two candidates:** Check both lower_bound and predecessor
3. **LeetCode 1755:** Hard — MITM is the key technique

<br><br>

---

```code```
