Given an array of integers `nums` and an integer `k`, return the total number of subarrays whose sum equals to `k`.

A subarray is a contiguous non-empty sequence of elements within an array.

<br>

> Input:
> nums = [1, 1, 1], k = 2

> Output:
> 2

> Explanation:
> There are 2 subarrays with sum = 2:
> - [1, 1] (indices 0-1)
> - [1, 1] (indices 1-2)
> 
> **Key insight:** Use prefix sum with HashMap to avoid checking all subarrays.

<br>

---

## Solution 1: Brute Force

**Intuition:**
Check every possible subarray and count those with sum equal to k.

**Algorithm:**
1. Use two nested loops to generate all subarrays
2. Calculate sum for each subarray
3. Count subarrays where sum equals k

### Time Complexity: O(n²)
**Why?**
- Outer loop: n iterations (starting positions)
- Inner loop: up to n iterations (ending positions)
- Sum calculation: O(1) per iteration (running sum)
- Total: O(n²)

### Space Complexity: O(1)
**Why?**
- Only storing count and running sum
- No additional data structures

**Problem:** Checking all n² subarrays is inefficient for large arrays.

> **Key Insight for Improvement:**
> If we know sum from index 0 to j is `PS[j]`, and sum from 0 to i is `PS[i]`, then sum from i to j is `PS[j] - PS[i]`. We want `PS[j] - PS[i] = k`, so we need `PS[i] = PS[j] - k`.

<br>

---

## Solution 2: Prefix Sum + HashMap (Optimal)

**Intuition:**
Use prefix sums with a HashMap to find subarrays in one pass. For each position, check if there's a previous prefix sum that would give us the target sum.

### Understanding Prefix Sum Array

A prefix sum array `PS` stores cumulative sums:
- `PS[0] = 0` (sum of zero elements - base case)
- `PS[i] = sum of first i elements` (for i ≥ 1)

**Example:** For `nums = [1, 2, 3, 4]`
```
Index:     0   1   2   3   4
PS:       [0,  1,  3,  6, 10]
          ↑   ↑   ↑   ↑   ↑
         sum  1  1+2 1+2+3 1+2+3+4
         of 0
        elements
```

### Core Formula

For subarray from index `start` to `end`:
```
sum(start, end) = PS[end+1] - PS[start]
```

**We want:** `sum(start, end) = k`

**Therefore:** `PS[end+1] - PS[start] = k`

**Rearranging:** `PS[start] = PS[end+1] - k`

### Implementation in C++

```cpp
int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    
    // Step 1: Build prefix sum array
    int PS[n+1];
    PS[0] = 0;  // Sum of zero elements
    
    for(int i = 1; i < n+1; i++) {
        PS[i] = PS[i-1] + nums[i-1];
    }
    
    // Step 2: Use HashMap to track prefix sum frequencies
    unordered_map<int, int> mp;
    mp[0] = 1;  // Base case: to handle subarrays starting at index 0
    
    int count = 0;
    
    // Step 3: For each ending position
    for(int end = 1; end < n+1; end++) {
        // We need PS[start] = PS[end] - k
        int sum = PS[end] - k;
        
        // Count how many times this sum appeared before
        if(mp.find(sum) != mp.end()) {
            count += mp[sum];
        }
        
        // Update frequency of current prefix sum
        mp[PS[end]]++;
    }
    
    return count;
}
```

### Code Walkthrough

**Step 1: Build Prefix Sum Array**
```cpp
int PS[n+1];
PS[0] = 0;  // Base case
for(int i = 1; i < n+1; i++) {
    PS[i] = PS[i-1] + nums[i-1];
}
```
- `PS[0] = 0`: Sum of zero elements
- `PS[i] = PS[i-1] + nums[i-1]`: Add current element to previous sum
- Example: `nums = [1, 2, 3]` → `PS = [0, 1, 3, 6]`

**Step 2: Initialize HashMap**
```cpp
unordered_map<int, int> mp;
mp[0] = 1;  // Critical for subarrays starting at index 0
```
- `mp[0] = 1`: Handles case when `PS[end] = k` (entire prefix is the answer)
- Example: `nums = [3], k = 3` → `PS[1] = 3`, need `PS[1] - k = 0` in map

**Step 3: Count Valid Subarrays**
```cpp
for(int end = 1; end < n+1; end++) {
    int sum = PS[end] - k;  // Need to find this in map
    
    if(mp.find(sum) != mp.end()) {
        count += mp[sum];  // Add frequency (multiple subarrays possible)
    }
    
    mp[PS[end]]++;  // Update current prefix sum frequency
}
```
- For each `end` position, look for `PS[start] = PS[end] - k`
- `mp[sum]` gives count of valid starting positions
- Update map AFTER checking (avoid counting same subarray twice)

### Time Complexity: O(n)
**Why?**
- Single pass through array: O(n)
- HashMap operations (insert/lookup): O(1) average
- Total: O(n)

**Improvement:**
- Before: O(n²)
- After: O(n)
- Example: n=10,000
  - Brute force: 100,000,000 operations
  - Prefix sum: 10,000 operations (10,000× faster!)

### Space Complexity: O(n)
**Why?**
- HashMap stores up to n unique prefix sums
- Worst case: all prefix sums are unique
- Space: O(n)

<br>

---

## Step-by-Step Example

**Input:** `nums = [1, 1, 1]`, `k = 2`

### Step 1: Build Prefix Sum Array
```cpp
PS[0] = 0
PS[1] = PS[0] + nums[0] = 0 + 1 = 1
PS[2] = PS[1] + nums[1] = 1 + 1 = 2
PS[3] = PS[2] + nums[2] = 2 + 1 = 3

Result: PS = [0, 1, 2, 3]
```

### Step 2: Initialize
```cpp
mp = {0: 1}
count = 0
```

### Step 3: Process Each Position

**end = 1, PS[1] = 1:**
```cpp
sum = PS[1] - k = 1 - 2 = -1
mp.find(-1) == mp.end()? Yes → count = 0
mp[PS[1]]++ → mp = {0: 1, 1: 1}
```

**end = 2, PS[2] = 2:**
```cpp
sum = PS[2] - k = 2 - 2 = 0
mp.find(0) != mp.end()? Yes → count += mp[0] = 0 + 1 = 1
mp[PS[2]]++ → mp = {0: 1, 1: 1, 2: 1}

Found: subarray [0...1] (PS[2] - PS[0] = 2 - 0 = 2)
```

**end = 3, PS[3] = 3:**
```cpp
sum = PS[3] - k = 3 - 2 = 1
mp.find(1) != mp.end()? Yes → count += mp[1] = 1 + 1 = 2
mp[PS[3]]++ → mp = {0: 1, 1: 1, 2: 1, 3: 1}

Found: subarray [1...2] (PS[3] - PS[1] = 3 - 1 = 2)
```

**Result:** `count = 2` ✓

<br>

---

## Why Track Frequency?

**Example:** `nums = [1, -1, 1]`, `k = 0`

```cpp
PS = [0, 1, 0, 1]
     ↑     ↑
   same value!
```

**Processing:**
```cpp
end = 1: PS[1] = 1
  sum = 1 - 0 = 1
  mp.find(1)? No → count = 0
  mp = {0: 1, 1: 1}

end = 2: PS[2] = 0
  sum = 0 - 0 = 0
  mp.find(0)? Yes → count += mp[0] = 0 + 1 = 1
  mp = {0: 2, 1: 1}  // PS[0] and PS[2] both equal 0

end = 3: PS[3] = 1
  sum = 1 - 0 = 1
  mp.find(1)? Yes → count += mp[1] = 1 + 1 = 2
  mp = {0: 2, 1: 2}
```

**Found 2 subarrays with sum = 0:**
- `[0...1]`: PS[2] - PS[0] = 0 - 0 = 0 ✓
- `[1...2]`: PS[3] - PS[1] = 1 - 1 = 0 ✓

Without frequency tracking (`mp[sum]`), we'd only count one!

<br>

---

## Complexity Summary

| Solution | Time | Space | Notes |
|----------|------|-------|-------|
| Brute Force | O(n²) | O(1) | Check all subarrays |
| Prefix Sum + HashMap | O(n) | O(n) | Optimal - single pass |

> **Recommended Solution:** Prefix Sum + HashMap - O(n) time

<br>
<br>

---

```code```
