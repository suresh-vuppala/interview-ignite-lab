Search in sorted array by halving search space each step.

<br>

> nums=[1,3,5,7,9,11], target=7 → index 3
>
> **Key insight:** Compare with middle element. If target < mid → search left half. If target > mid → search right half. Eliminate half each step.

<br>

---

## Constraints
- 1 ≤ N ≤ 10⁵
- Array is sorted in ascending order
- Elements are distinct (for basic version)

<br>

---

## All Possible Edge Cases
1. **Target not in array:** return -1
2. **Target at boundaries:** first or last element
3. **Single element array**
4. **Integer overflow in mid calculation:** use lo + (hi-lo)/2

<br>

---

## Solution 1: Linear scan

**Intuition:**
The most straightforward approach. Ignores the sorted structure entirely.

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
> Ignores the sorted structure entirely.

> **Key Insight for Improvement:**
> Binary search: lo=0, hi=N-1, mid=(lo+hi)/2. Compare and halve. O(log N).

<br>

---

## Solution 2: Binary Search (Optimal)

**Intuition:** Compare with middle element. If target < mid → search left half. If target > mid → search right half. Eliminate half each step.

**Algorithm:**
1. lo=0, hi=N-1
2. While lo ≤ hi:
   - mid = lo + (hi-lo)/2
   - If arr[mid] == target → return mid
   - If arr[mid] < target → lo = mid+1
   - Else → hi = mid-1
3. Return -1

### Time Complexity: O(log N)
**Why?**
Each element/state processed efficiently via the core technique.

**Detailed breakdown:**
Operations scale with input size as described by the complexity.

**Example walkthrough:**
```
[1,3,5,7,9,11] target=7: mid=5<7→lo=3, mid=9>7→hi=3, mid=7==7 ✓
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Linear scan | O(N) | Varies | Baseline |
| Binary Search | O(log N) | O(1) | Optimal approach |

**Recommended Solution:** Binary Search — O(log N) time.

**Key Insights:**
1. **lo + (hi-lo)/2:** Prevents integer overflow vs (lo+hi)/2
2. **lo ≤ hi:** Inclusive bounds — terminates when search space empty
3. **Foundation:** Every BS-on-answer problem builds on this

<br><br>

---

```code```
