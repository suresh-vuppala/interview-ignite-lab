Find longest interval where 'good' days (>8hrs) outnumber 'bad' days.

<br>

> hours=[9,9,6,0,6,6,9], threshold=8 → 3
>
> **Key insight:** Convert to +1/-1 (good/bad). Find longest subarray with positive sum using prefix sum + hash map.

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

## Solution 1: Check all intervals

**Intuition:**
The most straightforward approach. Quadratic — checking all subarrays.

**Algorithm:**
1. Enumerate all possible candidates
2. For each candidate, verify if it satisfies the condition
3. Track the best valid result
4. Return the optimal answer

### Time Complexity: O(N²)
**Why?**
Two nested loops each running up to N iterations.
Outer loop: N iterations × Inner loop: up to N iterations = N² total operations.

**Detailed breakdown:**
For N=1,000: ~1 million operations (OK). For N=10,000: ~100 million (borderline TLE).

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Quadratic — checking all subarrays.

> **Key Insight for Improvement:**
> Map to +1/-1. Track prefix sum. If prefix > 0 → length i+1 is valid. If prefix-1 was seen before → valid subarray.

<br>

---

## Solution 2: Prefix Sum + HashMap (Optimal)

**Intuition:** Convert to +1/-1 (good/bad). Find longest subarray with positive sum using prefix sum + hash map.

**Algorithm:**
1. Convert hours > 8 → +1, else → -1
2. Prefix sum, map stores first occurrence
3. If prefix > 0 → candidate length = i+1
4. If prefix-1 in map → candidate = i - map[prefix-1]

### Time Complexity: O(N)
**Why?**
Each element/state processed efficiently via the core technique.

**Detailed breakdown:**
Operations scale with input size as described by the complexity.

**Example walkthrough:**
```
hours=[9,9,6,0,6,6,9]→[1,1,-1,-1,-1,-1,1]
prefix: 1,2,1,0,-1,-2,-1
i=0: prefix=1>0→len=1
i=1: prefix=2>0→len=2
i=6: prefix=-1, check -2 in map?→yes(5)→len=6-5=1
Best: 3 (i=0..2, prefix=1>0)
```

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Check all intervals | O(N²) | Varies | Baseline |
| Prefix Sum + HashMap | O(N) | O(N) | Optimal approach |

**Recommended Solution:** Prefix Sum + HashMap — O(N) time.

**Key Insights:**
1. **Convert to +1/-1:** Reduces to longest positive-sum subarray
2. **prefix-1 trick:** Looking for earliest prefix that's exactly 1 less
3. **First occurrence only:** Gives longest interval

<br><br>

---

```code```
