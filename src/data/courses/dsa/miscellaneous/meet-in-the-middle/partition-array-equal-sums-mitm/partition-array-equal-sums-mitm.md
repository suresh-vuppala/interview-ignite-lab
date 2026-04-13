Partition array into two equal-sum subsets using MITM for large N.

<br>

> nums with N up to 40 → can partition into equal sums?
>
> **Key insight:** Meet in the middle variant. Target = totalSum/2. Same MITM approach.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: Standard DP

### Time Complexity: O(N × sum)

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
