Find the peak element in a mountain (bitonic) array.

<br>

> nums=[0,1,3,5,4,2] → index 3 (value 5)
>
> **Key insight:** Binary search: if nums[mid] < nums[mid+1] → ascending, peak is right. Else peak is left (including mid).

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

## Solution 1: Linear scan for max

**Intuition:**
The most straightforward approach. Doesn't exploit the mountain structure.

**Algorithm:**
1. Scan through each element from left to right
2. For each element, check the required condition
3. Track and return the best result

### Time Complexity: O(N)
**Why?**
Single pass through the input, doing O(1) work per element.
Total: N elements × O(1) per element = O(N).

**Detailed breakdown:**
For N=100,000: ~100,000 operations — very efficient.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Doesn't exploit the mountain structure.

> **Key Insight for Improvement:**
> Binary search: ascending (mid < mid+1) → go right. Descending → go left. Peak where direction changes.

<br>

---

## Solution 2: Binary Search — Direction Check (Optimal)

**Intuition:** Binary search: if nums[mid] < nums[mid+1] → ascending, peak is right. Else peak is left (including mid).

**Algorithm:**
1. lo=0, hi=N-1
2. While lo < hi:
   - mid = lo+(hi-lo)/2
   - If nums[mid] < nums[mid+1]: lo=mid+1 (ascending → peak right)
   - Else: hi=mid (descending or peak → peak left/here)
3. Return lo

### Time Complexity: O(log N)
**Why?**
Each element/state processed efficiently via the core technique.

**Detailed breakdown:**
Operations scale with input size as described by the complexity.

**Example walkthrough:**
```
[0,1,3,5,4,2]: mid=3,5<4? No→hi=2, ... → converges to index 3
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Linear scan for max | O(N) | Varies | Baseline |
| Binary Search — Direction Check | O(log N) | O(1) | Optimal approach |

**Recommended Solution:** Binary Search — Direction Check — O(log N) time.

**Key Insights:**
1. **Ascending → go right:** Peak hasn't been reached yet
2. **Descending → go left:** Peak is at or before mid
3. **Same template:** Find first True where nums[mid] > nums[mid+1]

<br><br>

---

```code```
