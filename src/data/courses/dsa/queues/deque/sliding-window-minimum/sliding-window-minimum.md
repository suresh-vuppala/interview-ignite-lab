Find the minimum value in each sliding window of size k as it moves across the array.

<br>

> nums=[1,3,-1,-3,5,3,6,7], k=3 → [-1,-3,-3,-3,3,3]
>
> **Key insight:** Monotonic increasing deque: front always holds the current window minimum. Remove elements that are larger than incoming (they'll never be the min).

<br>

---

## Constraints
- 1 ≤ N ≤ 10⁵
- 1 ≤ K ≤ N
- -10⁴ ≤ nums[i] ≤ 10⁴ apply

<br>

---

## All Possible Edge Cases
1. **K = 1:** output = input array
2. **K = N:** single element = global min
3. **Sorted ascending:** min always at window start
4. **Sorted descending:** min always at window end

<br>

---

## Solution 1: Scan window each time

**Intuition:**
The most straightforward approach. For each window position, scanning all k elements to find min is wasteful.

**Algorithm:**
1. Scan through each element from left to right
2. For each element, check the required condition
3. Track and return the best result

### Time Complexity: O(N×k)
**Why?**
Two factors multiply: one from iterating elements, one from the operation per element.
Total = product of both factors.

**Detailed breakdown:**
Depends on both dimensions of the input.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> For each window position, scanning all k elements to find min is wasteful. Previous work is discarded.

> **Key Insight for Improvement:**
> Monotonic deque: maintain indices in increasing value order. Front = current min. Remove expired indices and larger values.

<br>

---

## Solution 2: Monotonic Deque (Optimal)

**Intuition:** Monotonic increasing deque: front always holds the current window minimum. Remove elements that are larger than incoming (they'll never be the min).

**Algorithm:**
1. Deque stores indices (not values) in increasing value order
2. For each new element i:
   - Remove front if index ≤ i-k (expired)
   - Remove back while arr[back] ≥ arr[i] (never useful)
   - Push i to back
3. Front of deque = minimum of current window

### Time Complexity: O(N)
**Why?**
Each element processed at most once through the core data structure/algorithm.

**Detailed breakdown:**
For typical input sizes, operations stay well within time limits.

**Example walkthrough:**
```
nums=[1,3,-1,-3,5], k=3
i=0(1): deque=[0]
i=1(3): 3>1→push → deque=[0,1]
i=2(-1): pop 1,0 (both ≥ -1) → deque=[2]. Window [1,3,-1]→min=-1 ✓
i=3(-3): pop 2 → deque=[3]. Window [3,-1,-3]→min=-3 ✓
i=4(5): deque=[3,4]. Window [-1,-3,5]→min=-3 ✓
```

### Space Complexity: O(k)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Scan window each time | O(N×k) | Varies | Baseline |
| Monotonic Deque | O(N) | O(k) | Monotonic deque: maintain indices in increasing value order. |

**Recommended Solution:** Monotonic Deque — O(N) time, O(k) space.

**Key Insights:**
1. **Each element pushed/popped at most once:** Total 2N operations → O(N)
2. **Deque front = answer:** Always the minimum in current window
3. **Monotonic invariant:** Values increase from front to back
4. **For maximum:** Use decreasing deque instead

<br>
<br>

---

```code```
