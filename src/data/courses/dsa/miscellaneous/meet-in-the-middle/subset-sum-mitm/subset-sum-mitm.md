# Subset Sum (Meet in the Middle)

## Problem Statement

Given an array of `n` integers and a target sum `target`, determine if there exists a subset of the array whose sum equals the target.

The constraint is that `n` can be up to 40, making traditional subset generation (2^n) too slow. We need an optimized approach.

## Visual Example

```
Input: arr = [1, 3, 5, 7, 9], target = 12

Traditional approach: Generate all 2^5 = 32 subsets
Meet in the Middle: Split into two halves

Left half: [1, 3, 5]
Right half: [7, 9]

Left sums: {0, 1, 3, 4, 5, 6, 8, 9}
  {} = 0
  {1} = 1
  {3} = 3
  {1,3} = 4
  {5} = 5
  {1,5} = 6
  {3,5} = 8
  {1,3,5} = 9

Right sums: {0, 7, 9, 16}
  {} = 0
  {7} = 7
  {9} = 9
  {7,9} = 16

For each right sum, check if (target - right_sum) exists in left sums:
  0: need 12 → not in left
  7: need 5 → found in left! ✓
  
Answer: Yes (subset {5, 7} sums to 12)
```

## Algorithm Explanation

### Approach: Meet in the Middle

The key insight is to split the array into two halves, generate all subset sums for each half separately, then combine them efficiently.

**Why this works:**
- Instead of 2^n subsets, we generate 2^(n/2) + 2^(n/2) subsets
- For n=40: 2^40 ≈ 10^12 vs 2×2^20 ≈ 2×10^6 (massive improvement!)

**Algorithm Steps:**
1. Split array into two halves: left and right
2. Generate all possible subset sums for left half
3. Generate all possible subset sums for right half
4. For each sum in right half, check if (target - sum) exists in left half
5. Use binary search or hash set for efficient lookup

### Step-by-Step Process

```
arr = [1, 3, 5, 7, 9], target = 12

Step 1: Split array
  left = [1, 3, 5]
  right = [7, 9]

Step 2: Generate left sums (2^3 = 8 subsets)
  left_sums = [0, 1, 3, 4, 5, 6, 8, 9]

Step 3: Generate right sums (2^2 = 4 subsets)
  right_sums = [0, 7, 9, 16]

Step 4: Sort left_sums for binary search
  left_sums = [0, 1, 3, 4, 5, 6, 8, 9]

Step 5: For each right_sum, search for (target - right_sum)
  right_sum = 0: search for 12 → not found
  right_sum = 7: search for 5 → found! ✓
  
Answer: True
```

## Complexity Analysis

**Time Complexity:** O(2^(n/2) × n/2)
- **Why?** Generate 2^(n/2) subsets for each half, each taking O(n/2) time. Binary search adds O(log(2^(n/2))) = O(n/2) per lookup
- For n=40: 2^20 × 20 ≈ 20 million operations (feasible!)

**Space Complexity:** O(2^(n/2))
- **Why?** Store all subset sums for both halves

## Edge Cases

1. **Empty array:** Return target == 0
2. **Single element:** Return arr[0] == target
3. **Target is 0:** Empty subset always sums to 0 → return true
4. **All negative numbers:** Handle negative sums correctly
5. **Duplicate elements:** May generate duplicate sums (use set or handle in logic)
6. **Very large target:** May not be achievable with given elements

## Common Mistakes

1. Not handling the empty subset (sum = 0)
2. Forgetting to sort left sums before binary search
3. Integer overflow with large sums
4. Not considering both halves can contribute to the sum
5. Using inefficient subset generation (recursion without optimization)
6. Not handling negative numbers correctly

```code```
