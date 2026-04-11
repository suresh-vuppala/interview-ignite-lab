## Problem Statement

We are given `hours`, a list of the number of hours worked per day for a given employee.

A day is considered to be a **tiring day** if and only if the number of hours worked is **(strictly) greater than 8**.

A **well-performing interval** is an interval of days for which the number of tiring days is **strictly larger** than the number of non-tiring days.

Return the **length of the longest well-performing interval**.

### Example

```
Input: hours = [9,9,6,0,6,6,9]
Output: 3
Explanation: The longest well-performing interval is [9,9,6].

Input: hours = [6,6,6]
Output: 0
```

## Approach

### Naive Approach
- Check all possible intervals
- Count tiring and non-tiring days for each
- Time Complexity: O(n²)
- Space Complexity: O(1)

### Optimized Approach (Prefix Sum + HashMap)

1. **Convert Problem**: 
   - Tiring day (hours > 8): assign value +1
   - Non-tiring day (hours <= 8): assign value -1
   
2. **Reformulate**: Find longest subarray with positive sum (since tiring > non-tiring means sum > 0)

3. **Use Prefix Sum**:
   - Calculate prefix sum as we go
   - If prefix sum > 0, the interval from start to current index is well-performing
   
4. **HashMap for Earlier Occurrences**:
   - Store the first occurrence of each prefix sum value
   - For current prefix sum, check if (current_prefix - 1) was seen before
   - Why (current_prefix - 1)? Because we need prefix > 0, so we find when prefix was last = current_prefix - 1
   
5. **Algorithm**:
   - Initialize map with {0: -1} (prefix sum 0 at index -1)
   - For each index:
     - Update prefix sum based on hours[i]
     - If prefix sum > 0, update max_length = i + 1
     - If (prefix sum - 1) exists in map, update max_length = i - map[prefix-1]
     - Store current prefix sum if not seen before


---

## Constraints

- `1 ≤ n ≤ 10⁵`
- `-10⁵ ≤ nums[i] ≤ 10⁵`
- `Prefix sum may overflow — use long/long long if needed`

<br>

---

## All Possible Edge Cases

1. **Single element:** Subarray is the element itself
2. **All zeros:** All prefix sums are 0
3. **All same values:** Uniform prefix sum growth
4. **Negative values:** Prefix sum can decrease
5. **Target = 0:** Count subarrays summing to 0 (common trick)
6. **Entire array is the answer:** Sum of all elements matches target

<br>

## Complexity Analysis

### Time Complexity: O(n)

**Detailed Explanation:**
- Single pass through array: O(n)
- HashMap operations (insert/lookup): O(1)
- Overall: O(n) average case

### Space Complexity: O(n)

**Detailed Explanation:**
- HashMap stores at most n different prefix sum values
- Worst case: all unique prefix sums
- O(n) space

## Key Insights

- **Value Transformation**: Convert tiring/non-tiring into +1/-1 for easier computation
- **Prefix Sum Pattern**: Use prefix sum to track balance between tiring and non-tiring days
- **HashMap Trick**: Instead of checking all previous positions, use map to instantly find relevant positions
- **Target Difference**: Look for prefix differences of exactly 1 (to ensure sum > 0)
- **Early Occurrence**: Store first occurrence to maximize the interval length

## Code Implementation

Below are the complete implementations of the longestWPI function in different programming languages:

**Key Implementation Details:**
- Transform the problem: +1 for hours > 8, -1 for hours <= 8
- Find the longest subarray with positive prefix sum
- Store first occurrence of each prefix sum value
- If prefix sum > 0, update maximum length from start
- If (prefix sum - 1) exists in map, check if that interval is valid

Select a language above to view the implementation.



## Key Insights

- **Value Transformation**: Convert tiring/non-tiring into +1/-1 for easier computation
- **Prefix Sum Pattern**: Use prefix sum to track balance between tiring and non-tiring days
- **HashMap Trick**: Instead of checking all previous positions, use map to instantly find relevant positions
- **Target Difference**: Look for prefix differences of exactly 1 (to ensure sum > 0)
- **Early Occurrence**: Store first occurrence to maximize the interval length

---

```code```
