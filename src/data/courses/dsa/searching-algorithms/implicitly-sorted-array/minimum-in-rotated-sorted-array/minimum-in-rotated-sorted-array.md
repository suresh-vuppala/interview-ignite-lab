Find the minimum element in a rotated sorted array.

<br>

> nums=[3,4,5,1,2] → 1
>
> **Key insight:** Binary search: if nums[mid] > nums[right] → min is in right half. Else min is in left half (including mid).

<br>

---

## Constraints
- 1 ≤ N ≤ 5000
- All values distinct
- Rotated 1 to N times

<br>

---

## All Possible Edge Cases
1. **Not rotated (sorted):** first element
2. **Rotated once:** last element is min
3. **Single element**

<br>

---

## Solution 1: Linear scan

**Intuition:**
The most straightforward approach. Ignores the sorted-then-rotated structure.

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
> Ignores the sorted-then-rotated structure.

> **Key Insight for Improvement:**
> Compare mid with right: mid > right → rotation point (min) is in right half. Else in left half.

<br>

---

## Solution 2: Binary Search — Compare with Right (Optimal)

**Intuition:** Binary search: if nums[mid] > nums[right] → min is in right half. Else min is in left half (including mid).

**Algorithm:**
1. lo=0, hi=N-1
2. While lo < hi:
   - mid = lo+(hi-lo)/2
   - If nums[mid] > nums[hi]: lo=mid+1 (min in right)
   - Else: hi=mid (min in left, including mid)
3. Return nums[lo]

### Time Complexity: O(log N)
**Why?**
Each element/state processed efficiently via the core technique.

**Detailed breakdown:**
Operations scale with input size as described by the complexity.

**Example walkthrough:**
```
[3,4,5,1,2]: mid=5>2→lo=3, mid=1<2→hi=3→lo==hi→return nums[3]=1 ✓
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Linear scan | O(N) | Varies | Baseline |
| Binary Search — Compare with Right | O(log N) | O(1) | Optimal approach |

**Recommended Solution:** Binary Search — Compare with Right — O(log N) time.

**Key Insights:**
1. **Compare with RIGHT, not left:** Handles non-rotated case correctly
2. **hi=mid, not mid-1:** Mid could be the minimum
3. **lo < hi (not ≤):** Terminates when lo==hi = answer

<br><br>

---

```code```
