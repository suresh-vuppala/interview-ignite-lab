Find subsequence sum closest to a goal.

<br>

> nums, goal → closest achievable sum
>
> **Key insight:** Meet in the middle: generate all sums for each half, sort one, binary search for closest to (goal - other_sum).

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: Try all subsequences

### Time Complexity: O(2^N)

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
