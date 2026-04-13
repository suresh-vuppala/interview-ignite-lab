Array of 0..N with one missing. Find it.

<br>

> nums=[3,0,1] → 2
>
> **Key insight:** XOR 0..N with all array elements. Missing number remains (all others cancel in pairs).

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

## Solution 1: Sum formula: N(N+1)/2 - sum(array)

### Time Complexity: O(N)

> **Drawback:**
> Sum can overflow for large N.

> **Key Insight for Improvement:**
> XOR: (0^1^...^N) ^ (nums[0]^nums[1]^...) = missing. No overflow risk.

<br>

---

## Solution 2: XOR All (Optimal)

**Intuition:** XOR 0..N with all array elements. Missing number remains (all others cancel in pairs).

**Algorithm:**
1. result = N (start with N since array has indices 0..N-1)
2. For i=0 to N-1: result ^= i ^ nums[i]
3. Return result

### Time Complexity: O(N)
**Why?**
Each element/state processed efficiently via the core technique.

**Detailed breakdown:**
Operations scale with input size as described by the complexity.

**Example walkthrough:**
```
nums=[3,0,1], N=3: result=3^(0^3)^(1^0)^(2^1)=3^3^0^1^2^1=0^0^2=2 ✓
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Sum formula: N(N+1)/2 - sum(array) | O(N) | Varies | Baseline |
| XOR All | O(N) | O(1) | Optimal approach |

**Recommended Solution:** XOR All — O(N) time.

**Key Insights:**
1. **XOR pairs cancel:** Each number 0..N appears once in index or array (except missing)
2. **Sum alternative:** N*(N+1)/2 - sum(nums), but may overflow
3. **Both O(N) time, O(1) space**

<br><br>

---

```code```
