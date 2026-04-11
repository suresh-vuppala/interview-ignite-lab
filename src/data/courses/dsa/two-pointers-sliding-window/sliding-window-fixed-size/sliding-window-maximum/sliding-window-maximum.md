Given an array and a window size k, find the maximum value in each sliding window.

<br>

> Input:
> nums = [1, 3, -1, -3, 5, 3, 6, 7], k = 3

> Output:
> [3, 3, 5, 5, 6, 7]

> Explanation:
> Window [1,3,-1]=3. [3,-1,-3]=3. [-1,-3,5]=5. [-3,5,3]=5. [5,3,6]=6. [3,6,7]=7.
> 
> **Key insight:** Monotonic decreasing deque of indices. Front = current max. Remove from back if smaller than incoming (they'll never be max). Expire front if outside window. Each element pushed/popped at most once → amortized O(1).

<br>



---

## Constraints

- `1 ≤ n ≤ 10⁵`
- `-10⁴ ≤ nums[i] ≤ 10⁴`
- `1 ≤ k ≤ n`

<br>

---

## All Possible Edge Cases

1. **k = 1:** Each element is the max of its window
2. **k = n:** Single window, find overall max
3. **Sorted ascending:** Max always at right end
4. **Sorted descending:** Max always at left end (expires each slide)
5. **All same:** Max is always that value

<br>

---

## Solution 1: Brute Force — Scan Each Window

**Intuition:**
For each window, find the maximum by scanning all K elements.

### Time Complexity: O(N × K)
**Why?**
- (N-K+1) windows × K comparisons per window

**Detailed breakdown:**
- N = 100,000, K = 1,000 → 100,000,000 operations

### Space Complexity: O(1) extra

> **Drawback:**
> Finding the max by scanning K elements per window. When the window slides by one, the max either stays (if it didn't leave) or needs recalculating. We're doing O(K) work even when the max hasn't changed.

> **Key Insight for Improvement:**
> Use a monotonic decreasing deque of indices. The front always holds the current window's maximum. When a new element enters: remove all smaller elements from the back (they can never be a future max). When the front's index is outside the window: expire it. Each element is pushed and popped at most once → O(1) amortized per element.

<br>

---

## Solution 2: Monotonic Decreasing Deque (Optimal)

**Intuition:**
Maintain a deque where elements (by index) are in decreasing order of their values. Front = max. New elements push out smaller ones from the back. Expired indices are removed from the front.

**Algorithm:**
1. Initialize deque (stores indices)
2. For each i from 0 to n-1:
   - Remove from front if index < i-k+1 (expired)
   - Remove from back while nums[back] ≤ nums[i] (they'll never be max)
   - Push i to back
   - If i ≥ k-1: result.add(nums[front]) — front is the max

### Time Complexity: O(N)
**Why?**
- Each element pushed exactly once, popped at most once
- Total: ≤ 2N operations across all iterations = O(N)
- Amortized O(1) per element

**Detailed breakdown:**
- N = 100,000 → at most 200,000 deque operations
- Compared to brute: 100,000,000 → 200,000 (500× faster!)

**Example walkthrough:**
```
nums = [1, 3, -1, -3, 5, 3, 6, 7], k = 3
deque = [] (stores indices, front=max)

i=0: nums[0]=1, deque=[] → push → deque=[0]
i=1: nums[1]=3 > nums[0]=1 → pop 0, push 1 → deque=[1]
i=2: nums[2]=-1 ≤ nums[1]=3 → push → deque=[1,2]
     i≥k-1 → result=[nums[1]]=3

i=3: expire? front=1 ≥ 3-3+1=1 ✓
     nums[3]=-3 ≤ nums[2]=-1 → push → deque=[1,2,3]
     result=[3, nums[1]]=3

i=4: expire? front=1, 1 < 4-3+1=2 → pop! → deque=[2,3]
     nums[4]=5 > nums[3]=-3 → pop, > nums[2]=-1 → pop → deque=[]
     push → deque=[4], result=[3,3,5]

i=5: nums[5]=3 ≤ nums[4]=5 → push → deque=[4,5]
     result=[3,3,5,nums[4]]=5

i=6: expire? front=4 ≥ 4 ✓
     nums[6]=6 > 3 → pop 5, > 5 → pop 4 → deque=[6]
     result=[3,3,5,5,6]

i=7: nums[7]=7 > 6 → pop → deque=[7]
     result=[3,3,5,5,6,7] ✓
```

### Space Complexity: O(K)
**Why?**
- Deque holds at most K indices (one window's worth)

**Why this is optimal:**
- Must examine each element: O(N) minimum
- O(1) amortized per element — optimal

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N×K) | O(1) | Scan each window |
| Monotonic Deque | O(N) | O(K) | Amortized O(1) per element |

**Recommended Solution:** Monotonic Deque (Solution 2) — O(N) time, O(K) space.

**Key Insights:**
1. **Monotonic property:** Deque is decreasing — front is always max
2. **Back removal:** Smaller elements will never be max while current exists — safe to remove
3. **Front expiration:** Remove when index falls outside window
4. **Pattern reuse:** Same deque technique works for sliding window minimum (use increasing deque)


<br>
<br>

---

```code```
