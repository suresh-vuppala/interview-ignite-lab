# Partition Array Into Two Equal Sums (MITM)

## Problem Statement

Given an array of integers `nums`, determine if it is possible to partition the array into two subsets such that the sum of elements in both subsets is equal.

The constraint is that the array size can be up to 40, making traditional DP approaches (which require O(n × sum) space) infeasible when the sum is very large.

## Visual Example

```
Input: nums = [1, 5, 11, 5]

Total sum = 22
Target for each partition = 11

Split array into two halves:
Left: [1, 5]
Right: [11, 5]

Left sums: {0, 1, 5, 6}
  {} = 0
  {1} = 1
  {5} = 5
  {1,5} = 6

Right sums: {0, 11, 5, 16}
  {} = 0
  {11} = 11
  {5} = 5
  {11,5} = 16

For each right_sum, check if (target - right_sum) exists in left:
  right_sum = 5: need 11 - 5 = 6 → found in left! ✓
  
Partition: {1, 5, 5} and {11}
Both sum to 11 ✓

Answer: True
```

## Algorithm Explanation

### Approach: Meet in the Middle

The key insight is that if we can partition the array, each subset must sum to `total_sum / 2`. We use meet in the middle to efficiently find if such a subset exists.

**Prerequisite Check:**
- If total sum is odd, partition is impossible
- If total sum is even, target = total_sum / 2

**Algorithm Steps:**
1. Calculate total sum and check if it's even
2. Set target = total_sum / 2
3. Split array into two halves
4. Generate all possible subset sums for each half
5. For each right sum, check if (target - right_sum) exists in left sums
6. If found, partition exists

**Why Meet in the Middle?**
- Traditional DP: O(n × sum) - fails when sum is very large (e.g., 10^9)
- Meet in the Middle: O(2^(n/2)) - works for n up to 40

### Step-by-Step Process

```
nums = [1, 5, 11, 5]

Step 1: Check total sum
  total = 22 (even ✓)
  target = 11

Step 2: Split array
  left = [1, 5]
  right = [11, 5]

Step 3: Generate left sums
  left_sums = {0, 1, 5, 6}

Step 4: Generate right sums
  right_sums = {0, 11, 5, 16}

Step 5: For each right_sum, check (target - right_sum) in left
  right_sum = 0: need 11 → not in left
  right_sum = 11: need 0 → found! (but this uses all from right)
  right_sum = 5: need 6 → found! ✓
  
Subset with sum 11: {1, 5} from left + {5} from right
Remaining elements: {11} also sum to 11

Answer: True
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

**Time Complexity:** O(2^(n/2) × n/2)
- **Why?** Generate 2^(n/2) subsets for each half, use hash set for O(1) lookup
- For n=40: 2^20 × 20 ≈ 20 million operations

**Space Complexity:** O(2^(n/2))
- **Why?** Store all subset sums for both halves

## Edge Cases

1. **Empty array:** Return true (two empty subsets)
2. **Single element:** Return false (can't partition into two non-empty equal subsets)
3. **Two equal elements:** Return true
4. **Odd total sum:** Return false immediately
5. **All zeros:** Return true
6. **Negative numbers:** Handle correctly (sum can still be partitioned)
7. **Very large numbers:** May cause overflow

## Common Mistakes

1. Not checking if total sum is odd first
2. Forgetting that both subsets must be non-empty (if required)
3. Integer overflow when calculating total sum
4. Not handling the empty subset case correctly
5. Using inefficient lookup (linear search instead of hash set)
6. Not considering negative numbers

```code```
