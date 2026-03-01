# Continuous Subarray Sum

## Problem Statement

Given an integer array `nums` and an integer `k`, return `true` if `nums` has a good subarray or `false` otherwise.

A **good subarray** is a subarray where:
- Its length is **at least two**, and
- The sum of the elements of the subarray is a multiple of `k`.

**Note** that:
- A subarray with size 0 is not considered.
- 0 is always a multiple of `k`.

### Example

```
Input: nums = [23,2,4,6,7], k = 6
Output: true
Explanation: [2,4] is a good subarray as 2 + 4 = 6 which is a multiple of 6.

Input: nums = [23,2,6,4,7], k = 6
Output: true
Explanation: [23,2,6,4,7] is good subarray as (23 + 2 + 6 + 4 + 7) % 6 == 0.

Input: nums = [23,2,6,4,7], k = 13
Output: false
```

## Approach

### Naive Approach
- Check all subarrays of length >= 2
- Check if their sum is divisible by k
- Time Complexity: O(n²)
- Space Complexity: O(1)

### Optimized Approach (Prefix Sum + Modulo + HashMap)
1. **Modulo Property**: Instead of checking if sum = multiple of k, check if `sum % k = 0`

2. **Prefix Sum Difference**: If `(prefix[j] - prefix[i]) % k = 0`, then `prefix[j] % k = prefix[i] % k`

3. **Store Prefix Modulos**: Use a hashmap to store the first occurrence index of each prefix modulo value

4. **Minimum Subarray Length**: We need length >= 2, so we track indices to ensure current_index - stored_index >= 2

5. **Algorithm**:
   - Use map to store {prefix_mod: first_occurrence_index}
   - For each element:
     - Add element to prefix_sum
     - Calculate current_mod = prefix_sum % k
     - If current_mod exists in map and (current_index - stored_index) >= 2, return true
     - If current_mod doesn't exist in map, store it with current index

## Complexity Analysis

### Time Complexity: O(n)

**Detailed Explanation:**
- Single pass through the array: O(n)
- HashMap operations (insert/lookup): O(1) average case
- Overall: O(n) average case

### Space Complexity: O(min(n, k))

**Detailed Explanation:**
- HashMap can store at most k different modulo values (0 to k-1)
- In practice, we may store fewer than k values
- Maximum space: O(min(n, k))

## Key Insights

- **Modulo Pattern**: When checking divisibility, use modulo arithmetic instead of checking exact sums
- **Prefix Modulo Reuse**: If two prefix sums have the same modulo, the subarray between them is divisible by k
- **Index Tracking**: Store indices to enforce the minimum length constraint (length >= 2)
- **Modulo Cycle**: There are only k possible modulo values, so conflicts are common and exploitable

## Code Implementation

Below are the complete implementations of the checkSubarraySum function in different programming languages:

**Key Implementation Details:**
- Store the first occurrence index of each modulo value
- Track the prefix sum as we iterate through the array
- When we see a modulo value again, check if the distance is at least 2
- Return true as soon as we find a valid subarray
- Handle edge cases where k might be negative or zero

Select a language above to view the implementation.

```code```
