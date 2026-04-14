Find first element ≥ target in sorted array (lower_bound).

<br>

> nums=[1,3,5,7,9], target=6 → index 3 (value 7)
>
> **Key insight:** Binary search: if nums[mid] ≥ target → candidate, search left for smaller candidate. Else search right.

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
The most straightforward approach. Doesn't exploit sorted order.

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
> Doesn't exploit sorted order.

> **Key Insight for Improvement:**
> Binary search for first ≥ target. Same as find-first-true with condition: nums[mid] >= target.

<br>

---

## Solution 2: Lower Bound Binary Search (Optimal)

**Intuition:** Binary search: if nums[mid] ≥ target → candidate, search left for smaller candidate. Else search right.

**Algorithm:**
1. lo=0, hi=N-1, ans=N (not found)
2. While lo ≤ hi:
   - mid = lo+(hi-lo)/2
   - If nums[mid] ≥ target: ans=mid, hi=mid-1
   - Else: lo=mid+1

### Time Complexity: O(log N)
**Why?**
Each element/state processed efficiently via the core technique.

**Detailed breakdown:**
Operations scale with input size as described by the complexity.

**Example walkthrough:**
```
[1,3,5,7,9] target=6: mid=5<6→lo=3, mid=7≥6→ans=3,hi=2→done. Index 3 ✓
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Linear scan | O(N) | Varies | Baseline |
| Lower Bound Binary Search | O(log N) | O(1) | Optimal approach |

**Recommended Solution:** Lower Bound Binary Search — O(log N) time.

**Key Insights:**
1. **= lower_bound in C++:** std::lower_bound does exactly this
2. **ans=N:** Default if all elements < target
3. **Variant:** Upper bound = first > target (strict)

<br><br>

---

```code```
