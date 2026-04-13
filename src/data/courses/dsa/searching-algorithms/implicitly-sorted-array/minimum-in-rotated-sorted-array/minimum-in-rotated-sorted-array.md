Find the minimum element in a rotated sorted array.

<br>

> nums=[3,4,5,1,2] → 1
>
> **Key insight:** Binary search: if nums[mid] > nums[right] → min is in right half. Else min is in left half (including mid).

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

### Time Complexity: O(N)

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
