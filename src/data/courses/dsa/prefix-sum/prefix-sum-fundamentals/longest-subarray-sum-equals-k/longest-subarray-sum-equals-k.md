Find the longest subarray with sum exactly K.

<br>

> nums=[1,-1,5,-2,3], k=3 → 4 ([1,-1,5,-2]→sum=3)
>
> **Key insight:** Prefix sum + hash map storing first occurrence. If prefix-K in map → subarray found. Use first occurrence for longest.

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

## Solution 1: Check all subarrays

### Time Complexity: O(N²)

> **Drawback:**
> Quadratic.

> **Key Insight for Improvement:**
> Prefix + first occurrence map: if prefix-K was first seen at index j → subarray [j+1..i] has sum K and length i-j.

<br>

---

## Solution 2: Prefix + First Occurrence Map (Optimal)

**Intuition:** Prefix sum + hash map storing first occurrence. If prefix-K in map → subarray found. Use first occurrence for longest.

**Algorithm:**
1. map={0:-1}, prefix=0, maxLen=0
2. For each i: prefix += nums[i]
   - If prefix-K in map: maxLen = max(maxLen, i - map[prefix-K])
   - If prefix not in map: map[prefix] = i (first occurrence only!)

### Time Complexity: O(N)
**Why?**
Each element/state processed efficiently via the core technique.

**Detailed breakdown:**
Operations scale with input size as described by the complexity.

**Example walkthrough:**
```
[1,-1,5,-2,3] k=3: prefix: 1,0,5,3,6
i=3: prefix=3, 3-3=0 in map(-1)→len=3-(-1)=4 ✓
```

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Check all subarrays | O(N²) | Varies | Baseline |
| Prefix + First Occurrence Map | O(N) | O(N) | Optimal approach |

**Recommended Solution:** Prefix + First Occurrence Map — O(N) time.

**Key Insights:**
1. **First occurrence only:** Gives longest subarray for that prefix sum
2. **prefix-K in map:** Means subarray from map[prefix-K]+1 to i has sum K
3. **Works with negatives:** Unlike sliding window

<br><br>

---

```code```
