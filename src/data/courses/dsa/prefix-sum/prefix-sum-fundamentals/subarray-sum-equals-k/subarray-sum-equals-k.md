## Problem Statement

Given an integer array `nums` and an integer `k`, return the total number of subarrays whose sum equals `k`.

A subarray is a contiguous part of an array.

### Example

```
Input: nums = [1,1,1], k = 2
Output: 2

Input: nums = [1,2,1,1], k = 3
Output: 3
```

## Approach

### Naive Approach
- Check every possible subarray and count those with sum equal to k
- Time Complexity: O(n²) or O(n³)
- Space Complexity: O(1)

### Optimized Approach (Prefix Sum + HashMap)
1. **Calculate Prefix Sums**: As we iterate through the array, maintain a running sum (prefix sum)

2. **Use HashMap to Store Frequencies**: Store the frequency of each prefix sum encountered so far

3. **Key Insight**: If `prefix_sum[j] - prefix_sum[i] = k`, then the subarray from `i+1` to `j` has sum `k`
   - Rearranged: `prefix_sum[i] = prefix_sum[j] - k`
   - So we check if `(current_prefix_sum - k)` exists in our hashmap

4. **Algorithm**:
   - Initialize count = 0, prefix_sum = 0
   - Use map to store {prefix_sum: frequency}
   - For each element:
     - Add element to prefix_sum
     - If (prefix_sum - k) exists in map, add its frequency to count
     - Increment frequency of current prefix_sum

## Complexity Analysis

### Time Complexity: O(n)

**Detailed Explanation:**
- Single pass through the array: O(n)
- HashMap operations (insert/lookup): O(1) average case
- Overall: O(n) average case

### Space Complexity: O(n)

**Detailed Explanation:**
- HashMap stores at most n unique prefix sums
- In worst case, all prefix sums are unique: O(n)

## Key Insights

- **Prefix Sum Technique**: Convert the problem from finding subarrays to finding prefix sum pairs
- **HashMap Optimization**: Avoid nested loops by storing seen prefix sums
- **Difference Pattern**: If we want sum = k between indices i and j, check if (prefix_sum - k) was seen before
- **Zero Base Case**: Initialize map with {0: 1} to handle subarrays starting from index 0

## Code Implementation

Below are the complete implementations of the subarraySum function in different programming languages:

**Key Implementation Details:**
- Use a HashMap/dictionary to store prefix sum frequencies
- Initialize the map with {0: 1} to handle subarrays starting from the beginning
- For each element, calculate the prefix sum and check if (prefix_sum - k) exists
- Count all valid subarrays where the difference equals the target

Select a language above to view the implementation.

```code```
