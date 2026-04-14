Search for target in a rotated sorted array.

<br>

> nums=[4,5,6,7,0,1,2], target=0 → index 4
>
> **Key insight:** Binary search: determine which half is sorted. Check if target falls in the sorted half's range. Search that half or the other.

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

## Solution 1: Linear scan

**Intuition:**
The most straightforward approach. Ignores sorted structure.

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
> Ignores sorted structure.

> **Key Insight for Improvement:**
> Identify sorted half → check if target is in its range → narrow search to correct half.

<br>

---

## Solution 2: Binary Search — Identify Sorted Half (Optimal)

**Intuition:** Binary search: determine which half is sorted. Check if target falls in the sorted half's range. Search that half or the other.

**Algorithm:**
1. lo=0, hi=N-1
2. While lo ≤ hi:
   - mid = lo+(hi-lo)/2
   - If nums[mid] == target → return mid
   - If nums[lo] ≤ nums[mid] (left sorted):
     - If nums[lo] ≤ target < nums[mid] → hi=mid-1
     - Else → lo=mid+1
   - Else (right sorted):
     - If nums[mid] < target ≤ nums[hi] → lo=mid+1
     - Else → hi=mid-1

### Time Complexity: O(log N)
**Why?**
Each element/state processed efficiently via the core technique.

**Detailed breakdown:**
Operations scale with input size as described by the complexity.

**Example walkthrough:**
```
[4,5,6,7,0,1,2] target=0: left [4,5,6,7] sorted, 0 not in [4,7]→lo=mid+1
Right half [0,1,2] sorted, 0 in [0,2]→found at index 4 ✓
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Linear scan | O(N) | Varies | Baseline |
| Binary Search — Identify Sorted Half | O(log N) | O(1) | Optimal approach |

**Recommended Solution:** Binary Search — Identify Sorted Half — O(log N) time.

**Key Insights:**
1. **One half always sorted:** In rotated array, at least one half is sorted
2. **Check target in sorted range:** Determines which half to search
3. **FAANG classic:** Tests binary search mastery

<br><br>

---

```code```
