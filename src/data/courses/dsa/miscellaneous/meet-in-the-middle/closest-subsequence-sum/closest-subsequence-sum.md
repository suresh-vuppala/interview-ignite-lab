# Closest Subsequence Sum

## Problem Statement

You are given an integer array `nums` and an integer `goal`. You want to choose a subsequence of `nums` such that the sum of its elements is the closest possible to `goal`. That is, if the sum of the subsequence's elements is `sum`, then you want to minimize the absolute difference `abs(sum - goal)`.

Return the minimum possible value of `abs(sum - goal)`.

Note: A subsequence is an array formed by removing some elements (possibly all or none) from the original array.

## Visual Example

```
Input: nums = [5, -7, 3, 5], goal = 6

Split into two halves:
Left: [5, -7]
Right: [3, 5]

Left sums: {0, 5, -7, -2}
  {} = 0
  {5} = 5
  {-7} = -7
  {5,-7} = -2

Right sums: {0, 3, 5, 8}
  {} = 0
  {3} = 3
  {5} = 5
  {3,5} = 8

Sort left_sums: [-7, -2, 0, 5]

For each right_sum, find closest left_sum to (goal - right_sum):
  right_sum = 0: need 6, closest in left = 5 → total = 5, diff = |5-6| = 1
  right_sum = 3: need 3, closest in left = 5 → total = 8, diff = |8-6| = 2
  right_sum = 5: need 1, closest in left = 0 → total = 5, diff = |5-6| = 1
  right_sum = 8: need -2, closest in left = -2 → total = 6, diff = |6-6| = 0 ✓

Answer: 0 (subsequence {-7, 5, 8} = {-7, 5, 3, 5} sums to 6)
```

## Algorithm Explanation

### Approach: Meet in the Middle with Binary Search

The key insight is to split the array and use binary search to find the closest sum combination.

**Algorithm Steps:**
1. Split array into two halves
2. Generate all possible subset sums for each half
3. Sort the left sums array
4. For each right sum, use binary search to find the closest left sum to (goal - right_sum)
5. Track the minimum absolute difference

**Binary Search Strategy:**
- For target value `need = goal - right_sum`
- Find the position where `need` would be inserted in sorted left_sums
- Check both the element at that position and the previous element
- Both could be closest to the target

### Step-by-Step Process

```
nums = [5, -7, 3, 5], goal = 6

Step 1: Split
  left = [5, -7]
  right = [3, 5]

Step 2: Generate sums
  left_sums = [0, 5, -7, -2]
  right_sums = [0, 3, 5, 8]

Step 3: Sort left_sums
  left_sums = [-7, -2, 0, 5]

Step 4: For each right_sum, binary search for closest
  right_sum = 8, need = 6 - 8 = -2
    Binary search in [-7, -2, 0, 5] for -2
    Found exact match: -2
    Total sum = 8 + (-2) = 6
    Difference = |6 - 6| = 0 ✓

Answer: 0
```


---

## Constraints

- `Constraints vary by specific problem`
- `Check individual problem for exact bounds`

<br>

---

## All Possible Edge Cases

1. **Minimum input size:** Base case
2. **Maximum input size:** Performance boundary
3. **Edge values (0, INT_MAX, INT_MIN):** Boundary testing
4. **Empty or null input:** Handle gracefully

<br>

## Complexity Analysis

**Time Complexity:** O(2^(n/2) × n)
- **Why?** Generate 2^(n/2) subsets for each half, sort one half O(2^(n/2) log 2^(n/2)), then binary search for each right sum
- Dominant: O(2^(n/2) × n/2) for generation + O(2^(n/2) × n/2) for binary searches

**Space Complexity:** O(2^(n/2))
- **Why?** Store all subset sums for both halves

## Edge Cases

1. **Empty array:** Return abs(0 - goal)
2. **Single element:** Return min(abs(0 - goal), abs(nums[0] - goal))
3. **Goal is 0:** Find subsequence sum closest to 0
4. **All positive numbers:** Minimum sum is 0 (empty subset)
5. **All negative numbers:** Maximum sum is 0 (empty subset)
6. **Exact match possible:** Return 0
7. **Very large/small goal:** May require all elements

## Common Mistakes

1. Not checking both neighbors in binary search (floor and ceiling)
2. Forgetting the empty subset (sum = 0)
3. Integer overflow with large sums
4. Not handling negative numbers correctly
5. Using lower_bound incorrectly (need to check both positions)
6. Not initializing minimum difference properly

```code```
