## Problem Statement

You are given an integer array `nums` where the `i-th` bag contains `nums[i]` balls. You are also given an integer `maxOperations`.

You can perform the following operation at most `maxOperations` times:
- Take any bag of balls and divide it into two new bags with a **positive** number of balls
- For example, a bag with 5 balls can become (1, 4), (2, 3), etc.

Your goal is to **minimize the maximum number of balls** in any bag after performing the operations.

Return the minimum possible maximum number of balls in a bag.

**Constraints:**
- `1 ≤ nums.length ≤ 10^5`
- `1 ≤ maxOperations ≤ 10^9`
- `1 ≤ nums[i] ≤ 10^9`

## Examples

### Example 1:
**Input:**
```
nums = [9]
maxOperations = 2
```

**Output:**
```
3
```

**Explanation:**
- Operation 1: Divide bag with 9 balls into (6, 3)
- Operation 2: Divide bag with 6 balls into (3, 3)
- Result: [3, 3, 3]
- Maximum = 3

### Example 2:
**Input:**
```
nums = [2, 4, 8, 2]
maxOperations = 4
```

**Output:**
```
2
```

**Explanation:**
- Divide bag with 8 balls:
  - Operation 1: (8) → (4, 4)
  - Operation 2: (4) → (2, 2)
  - Operation 3: (4) → (2, 2)
- Result: [2, 2, 2, 2, 2, 2]
- Maximum = 2
- Used 3 operations (1 remaining)

### Example 3:
**Input:**
```
nums = [7, 17]
maxOperations = 2
```

**Output:**
```
7
```

**Explanation:**
- Divide bag with 17 balls:
  - Operation 1: (17) → (10, 7)
  - Operation 2: (10) → (7, 3)
- Result: [7, 7, 7, 3]
- Maximum = 7

## Visual Example

For `nums = [9]`, `maxOperations = 2`:

```
Initial: [9]
         ↓
Step 1: Divide 9 → [6, 3]
         ↓
Step 2: Divide 6 → [3, 3, 3]
         ↓
Result: Maximum = 3

Alternative divisions:
[9] → [5, 4] → [3, 2, 4] → max = 4 (worse)
[9] → [4, 5] → [4, 3, 2] → max = 4 (worse)
```

## Binary Search Visualization

For `nums = [2, 4, 8, 2]`, `maxOperations = 4`:

```
Search Space: [1, 8]
              ↓
         mid = 4
         
Can achieve max 4 with 4 operations?
Bag 2: needs 0 operations (already ≤ 4)
Bag 4: needs 0 operations (already ≤ 4)
Bag 8: needs 1 operation (8 → 4, 4)
Bag 2: needs 0 operations (already ≤ 4)
Total: 1 operation ≤ 4 ✓
Yes! Try smaller → right = 3

         mid = 2
         
Can achieve max 2 with 4 operations?
Bag 2: needs 0 operations
Bag 4: needs 1 operation (4 → 2, 2)
Bag 8: needs 3 operations (8 → 4,4 → 2,2,2,2)
Bag 2: needs 0 operations
Total: 4 operations ≤ 4 ✓
Yes! Try smaller → right = 1

         mid = 1
         
Can achieve max 1 with 4 operations?
Bag 2: needs 1 operation (2 → 1, 1)
Bag 4: needs 3 operations (4 → 1,1,1,1)
Bag 8: needs 7 operations
Total: 11 operations > 4 ✗
No! Increase → left = 2

Answer = 2
```

## Approach: Binary Search on Answer

### Key Insight

We binary search on the **maximum number of balls** (the answer). For each candidate answer, we check if it's achievable within `maxOperations`.

**Search Space:** `[1, max(nums)]`
- Lower bound: 1 (minimum possible balls in a bag)
- Upper bound: max(nums) (no operations needed)

### Algorithm

1. **Define Search Space:**
   ```cpp
   left = 1
   right = max(nums)
   ```

2. **Binary Search:**
   ```cpp
   while (left <= right) {
       mid = (left + right) / 2
       
       if (canAchieve(nums, maxOperations, mid)) {
           answer = mid
           right = mid - 1  // try smaller maximum
       } else {
           left = mid + 1   // need larger maximum
       }
   }
   ```

3. **Feasibility Check:**
   ```cpp
   canAchieve(nums, maxOps, maxBalls):
       operations = 0
       
       for each bag in nums:
           if (bag > maxBalls) {
               // Calculate operations needed to split this bag
               operations += (bag - 1) / maxBalls
           }
       
       return operations <= maxOps
   ```

### Operations Calculation Formula

To split a bag with `n` balls into bags with at most `maxBalls`:

**Operations needed = ⌈n / maxBalls⌉ - 1 = (n - 1) / maxBalls**

**Why?**
- If `n = 9`, `maxBalls = 3`:
  - Need bags: [3, 3, 3] → 3 bags
  - Operations: 3 - 1 = 2 ✓
  - Formula: (9 - 1) / 3 = 8 / 3 = 2 ✓

- If `n = 8`, `maxBalls = 3`:
  - Need bags: [3, 3, 2] → 3 bags
  - Operations: 3 - 1 = 2 ✓
  - Formula: (8 - 1) / 3 = 7 / 3 = 2 ✓

### Step-by-Step Walkthrough

For `nums = [9]`, `maxOperations = 2`:

**Initial:** `left = 1`, `right = 9`

**Iteration 1:** `mid = 5`
- Bag 9: operations = (9 - 1) / 5 = 8 / 5 = 1
- Total: 1 ≤ 2 ✓
- Possible! `answer = 5`, `right = 4`

**Iteration 2:** `mid = 2`
- Bag 9: operations = (9 - 1) / 2 = 8 / 2 = 4
- Total: 4 > 2 ✗
- Not possible! `left = 3`

**Iteration 3:** `mid = 3`
- Bag 9: operations = (9 - 1) / 3 = 8 / 3 = 2
- Total: 2 ≤ 2 ✓
- Possible! `answer = 3`, `right = 2`

**Final:** `left = 3`, `right = 2` → Answer = **3**

## Complexity Analysis

### Time Complexity: **O(N × log(max(nums)))**

**Why?**
- Binary search: `O(log(max(nums)))` iterations
- Each iteration: `O(N)` to check all bags
- Total: `O(N × log(max(nums)))`

**Example:**
- `N = 10^5`, `max(nums) = 10^9`
- `log(10^9) ≈ 30` iterations
- Total: `10^5 × 30 = 3 × 10^6` operations

### Space Complexity: **O(1)**

**Why?**
- Only constant extra space for variables
- No additional data structures

## Edge Cases

1. **No operations needed:**
   ```
   nums = [2, 2, 2]
   maxOperations = 5
   Answer = 2 (already optimal)
   ```

2. **Single bag:**
   ```
   nums = [10]
   maxOperations = 3
   Answer = 3 (10 → 5,5 → 3,2,5 → 3,2,3,2)
   ```

3. **Insufficient operations:**
   ```
   nums = [100]
   maxOperations = 1
   Answer = 50 (100 → 50, 50)
   ```

4. **All bags size 1:**
   ```
   nums = [1, 1, 1, 1]
   maxOperations = 10
   Answer = 1 (already minimum)
   ```

5. **Large operations available:**
   ```
   nums = [9]
   maxOperations = 100
   Answer = 1 (can split to all 1s)
   ```

## Common Mistakes

1. **Wrong operations formula:**
   - ❌ Using `n / maxBalls` (incorrect)
   - ✅ Using `(n - 1) / maxBalls` (correct)

2. **Off-by-one in search space:**
   - ❌ Starting from 0
   - ✅ Starting from 1 (minimum possible)

3. **Integer overflow:**
   - ❌ Using `int` for operations count
   - ✅ Use `long long` for large inputs

4. **Not handling equal case:**
   - ❌ Counting operations for bags already ≤ maxBalls
   - ✅ Only count operations for bags > maxBalls

## Mathematical Insight

**Why does (n - 1) / maxBalls work?**

To split `n` balls into groups of at most `maxBalls`:
- Number of groups needed: `⌈n / maxBalls⌉`
- Operations needed: `⌈n / maxBalls⌉ - 1`

Using ceiling division:
- `⌈n / maxBalls⌉ = (n + maxBalls - 1) / maxBalls`
- Operations = `(n + maxBalls - 1) / maxBalls - 1`
- Simplify: `(n - 1) / maxBalls` (integer division)

## Related Problems

1. **Allocate Minimum Number of Pages** - Minimize maximum pattern
2. **Capacity To Ship Packages** - Similar binary search on answer
3. **Koko Eating Bananas** - Rate optimization variant
4. **Minimize Max Distance to Gas Station** - Distance optimization

## Key Takeaways

1. **Pattern:** "Minimize the maximum" → Binary search on answer
2. **Search Space:** `[1, max(nums)]`
3. **Operations Formula:** `(n - 1) / maxBalls` for each bag
4. **Greedy Check:** Sum operations for all bags
5. **Direction:** Feasible → try smaller; Not feasible → try larger

```code```