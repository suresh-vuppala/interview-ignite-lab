## Problem Statement

Given an integer array `nums` and an integer `k`, split `nums` into `k` non-empty **contiguous** subarrays such that the **largest sum** among these subarrays is **minimized**.

Return the minimized largest sum of the split.

**Constraints:**
- `1 ≤ nums.length ≤ 1000`
- `0 ≤ nums[i] ≤ 10^6`
- `1 ≤ k ≤ min(50, nums.length)`

## Examples

### Example 1:
**Input:**
```
nums = [7, 2, 5, 10, 8]
k = 2
```

**Output:**
```
18
```

**Explanation:**
There are four ways to split nums into two subarrays:
- [7] | [2, 5, 10, 8] → max = 25
- [7, 2] | [5, 10, 8] → max = 23
- [7, 2, 5] | [10, 8] → max = 18 ✓ (minimum)
- [7, 2, 5, 10] | [8] → max = 24

### Example 2:
**Input:**
```
nums = [1, 2, 3, 4, 5]
k = 2
```

**Output:**
```
9
```

**Explanation:**
- Best split: [1, 2, 3, 4] | [5] → max = 10 ✗
- Better split: [1, 2, 3] | [4, 5] → max = 9 ✓

### Example 3:
**Input:**
```
nums = [1, 4, 4]
k = 3
```

**Output:**
```
4
```

**Explanation:**
- Each element in its own subarray: [1] | [4] | [4]
- Maximum sum = 4

## Visual Example

For `nums = [7, 2, 5, 10, 8]`, `k = 2`:

```
Array: [7, 2, 5, 10, 8]
       ─────────────────

Split Options:

Option 1: [7] | [2, 5, 10, 8]
          7     25
          Max = 25

Option 2: [7, 2] | [5, 10, 8]
          9        23
          Max = 23

Option 3: [7, 2, 5] | [10, 8]
          14          18
          Max = 18 ✓ (Optimal)

Option 4: [7, 2, 5, 10] | [8]
          24              8
          Max = 24
```

## Binary Search Visualization

```
Search Space: [10, 32]
              ↓
         mid = 21
         
Can split with max sum 21?
Subarray 1: [7, 2, 5] = 14 ✓
Subarray 2: [10] = 10 ✓
Subarray 3: [8] = 8 (need 3 subarrays) ✗
No! Try larger → left = 22

         mid = 27
         
Can split with max sum 27?
Subarray 1: [7, 2, 5, 10] = 24 ✓
Subarray 2: [8] = 8 ✓
Yes! Try smaller → right = 26

         mid = 24
         
Can split with max sum 24?
Subarray 1: [7, 2, 5, 10] = 24 ✓
Subarray 2: [8] = 8 ✓
Yes! Try smaller → right = 23

         mid = 22
Not possible → left = 23

         mid = 23
Possible → right = 22

Continue until left = 18

Answer = 18
```

## Approach: Binary Search on Answer

### Key Insight

This is **exactly the same** as Book Allocation and Painter's Partition:
- Array elements → Book pages / Board lengths
- k subarrays → Students / Painters
- Minimize largest sum → Minimize max pages/time

Search space: `[max(nums), sum(nums)]`

### Algorithm

1. **Define Search Space:**
   ```cpp
   left = max(nums)   // at least one subarray has max element
   right = sum(nums)  // one subarray contains all elements
   ```

2. **Binary Search:**
   ```cpp
   while (left <= right) {
       mid = (left + right) / 2
       
       if (canSplit(nums, k, mid)) {
           answer = mid
           right = mid - 1  // try to minimize
       } else {
           left = mid + 1   // increase limit
       }
   }
   ```

3. **Feasibility Check:**
   ```cpp
   canSplit(nums, k, maxSum):
       subarrays = 1
       currentSum = 0
       
       for each num in nums:
           if (currentSum + num > maxSum) {
               subarrays++
               currentSum = num
           } else {
               currentSum += num
           }
       
       return subarrays <= k
   ```

### Step-by-Step Walkthrough

For `nums = [7, 2, 5, 10, 8]`, `k = 2`:

**Initial Setup:**
- `left = 10` (max element)
- `right = 32` (sum of all elements)

**Iteration 1:** `mid = 21`
- Subarray 1: 7 + 2 + 5 = 14 ✓
- Subarray 2: 10 ✓
- Subarray 3: 8 (need 3rd subarray)
- Subarrays needed = 3 > 2 ✗
- Not possible! `left = 22`

**Iteration 2:** `mid = 27`
- Subarray 1: 7 + 2 + 5 + 10 = 24 ✓
- Subarray 2: 8 ✓
- Subarrays needed = 2 ≤ 2 ✓
- Possible! `answer = 27`, `right = 26`

**Iteration 3:** `mid = 24`
- Subarray 1: 7 + 2 + 5 + 10 = 24 ✓
- Subarray 2: 8 ✓
- Possible! `answer = 24`, `right = 23`

**Iteration 4:** `mid = 22`
- Not possible (needs 3 subarrays)
- `left = 23`

**Iteration 5:** `mid = 23`
- Subarray 1: 7 + 2 + 5 = 14 ✓
- Subarray 2: 10 + 8 = 18 ✓ (can't add, would be 28)
- Wait, let me recalculate...
- Subarray 1: 7 + 2 + 5 + 10 = 24 > 23 ✗
- Subarray 1: 7 + 2 + 5 = 14 ✓
- Subarray 2: 10 + 8 = 18 ✓
- Possible! `answer = 23`, `right = 22`

Continue binary search...

**Final Answer:** 18

## Complexity Analysis

### Time Complexity: **O(N × log(sum - max))**

**Why?**
- Binary search: `O(log(sum - max))` iterations
- Each iteration: `O(N)` for feasibility check
- Total: `O(N × log(sum - max))`

**Example:**
- `N = 1000`, `sum = 10^9`
- `log(10^9) ≈ 30` iterations
- Total: `1000 × 30 = 30,000` operations

### Space Complexity: **O(1)**

**Why?**
- Only constant extra space
- No additional data structures

## Edge Cases

1. **k = 1 (No split):**
   ```
   nums = [1, 2, 3, 4]
   k = 1
   Answer = 10 (sum of all elements)
   ```

2. **k = n (Each element in separate subarray):**
   ```
   nums = [1, 2, 3, 4]
   k = 4
   Answer = 4 (maximum element)
   ```

3. **All elements equal:**
   ```
   nums = [5, 5, 5, 5]
   k = 2
   Answer = 10 (each subarray gets 2 elements)
   ```

4. **One very large element:**
   ```
   nums = [1, 1, 1, 100]
   k = 2
   Answer = 100 (one subarray must contain it)
   ```

5. **Array with zeros:**
   ```
   nums = [0, 0, 0, 5]
   k = 2
   Answer = 5
   ```

## Common Mistakes

1. **Allowing non-contiguous subarrays:**
   - ❌ Splitting [1, 2, 3, 4] as [1, 3] | [2, 4]
   - ✅ Must be contiguous: [1, 2] | [3, 4]

2. **Wrong search space:**
   - ❌ Starting from 0 or 1
   - ✅ Start from `max(nums)`

3. **Off-by-one in binary search:**
   - ❌ Using `right = mid` when feasible
   - ✅ Use `right = mid - 1` to minimize

4. **Integer overflow:**
   - ❌ Using `int` for sum
   - ✅ Use `long long` for large sums

## Comparison with Similar Problems

| Problem | Items | Groups | Measure | Goal |
|---------|-------|--------|---------|------|
| Book Allocation | Books | Students | Pages | Minimize max pages |
| Painter's Partition | Boards | Painters | Time | Minimize max time |
| Split Array | Array | Subarrays | Sum | Minimize max sum |
| **Algorithm** | **Identical** | **Identical** | **Identical** | **Identical** |

## Related Problems

1. **Allocate Minimum Number of Pages** - Same algorithm
2. **Painter's Partition Problem** - Same algorithm
3. **Capacity To Ship Packages** - Similar pattern
4. **Minimize Max Distance to Gas Station** - Distance variant

## Key Takeaways

1. **Pattern Recognition:** "Minimize the maximum" → Binary search on answer
2. **Search Space:** Always `[max(nums), sum(nums)]`
3. **Greedy Feasibility:** Check if split possible with given limit
4. **Contiguous Constraint:** Subarrays must be consecutive elements
5. **Universal Pattern:** Same as Book Allocation and Painter's Partition

```code```