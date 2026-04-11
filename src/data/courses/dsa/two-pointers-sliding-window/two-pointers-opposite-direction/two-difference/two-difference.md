Given a sorted array of integers and a target difference k, find if there exists a pair of elements with difference equal to k.

<br>

> Input:
> arr = [1, 3, 5, 8, 12], k = 3

> Output:
> true

> Explanation:
> The pair (5, 8) has difference 8 - 5 = 3.
> 
> **Key insight:** Use two pointers - if difference is too small, move right pointer; if too large, move left pointer.

<br>



---

## Constraints

- `1 ≤ nums.length ≤ 10⁵`
- `-10⁴ ≤ nums[i] ≤ 10⁴`
- `Array is sorted in non-decreasing order`
- `k ≥ 0`

<br>

---

## All Possible Edge Cases

1. **k = 0:** Need two distinct indices with same value — look for duplicates
2. **No valid pair:** No pair with the required difference
3. **Single element array:** Impossible to form a pair
4. **All same elements with k=0:** Any pair works
5. **Negative numbers:** Difference with negative sorted array
6. **Pair at adjacent positions:** Minimum gap pair
7. **Pair at extremes:** First and last element form the pair

<br>

---

## Solution 1: Brute Force

**Intuition:**
Check all possible pairs and see if any pair has the required difference k.

**Algorithm:**
1. For each element at index i (0 to n-2)
2. For each element at index j (i+1 to n-1)
3. If arr[j] - arr[i] == k, return true
4. Return false if no pair found

### Time Complexity: O(N²)
**Why?**
- Outer loop: N iterations
- Inner loop: N iterations
- Total: N × N = O(N²)

**Detailed breakdown:**
- Total pairs checked: N×(N-1)/2 ≈ N²/2
- Example: Array of size 1000 → 500,000 comparisons

### Space Complexity: O(1)
**Why?**
- Only using two loop variables
- No extra data structures

> **Key Insight for Improvement:**
> We're not using the sorted property. Since array is sorted, we can use two pointers to avoid checking all pairs.

<br>

---

## Solution 2: Two Pointers (Same Direction)

**Intuition:**
Use two pointers starting at positions 0 and 1. Calculate difference. If difference is too small, move right pointer forward. If too large, move left pointer forward.

**Algorithm:**
1. Initialize left = 0, right = 1
2. While right < n:
   - Calculate diff = arr[right] - arr[left]
   - If diff == k and left != right, return true
   - If diff < k, increment right
   - Else increment left
   - If left == right, increment right
3. Return false

### Time Complexity: O(N)
**Why?**
- Each pointer moves forward at most N times
- Total moves: at most 2N
- O(2N) = O(N)

**Detailed breakdown:**
- Left pointer: moves from 0 to n-1 → N moves max
- Right pointer: moves from 1 to n-1 → N moves max
- Total: 2N operations
- Example: Array of size 1000 → 2000 operations

**Improvement:** From O(N²) to O(N)
- Example: Array of size 1000
- Brute force: 500,000 operations
- Two pointers: 2000 operations (250× faster!)

### Space Complexity: O(1)
**Why?**
- Only two pointer variables
- No extra space used

> **Key Insight for Improvement:**
> Can use HashSet for unsorted arrays, but for sorted arrays, two pointers is optimal.

<br>

---

## Solution 3: HashSet (Works for Unsorted)

**Intuition:**
For each element x, check if (x + k) or (x - k) exists in a set. This works for both sorted and unsorted arrays.

**Algorithm:**
1. Create empty set
2. For each element in array:
   - If (element + k) in set, return true
   - If (element - k) in set, return true
   - Add element to set
3. Return false

### Time Complexity: O(N)
**Why?**
- Single pass through array: N iterations
- Set operations (add/contains): O(1) average
- Total: N × O(1) = O(N)

**Detailed breakdown:**
- One loop: N iterations
- Each iteration: O(1) set operations
- Total: N operations

### Space Complexity: O(N)
**Why?**
- Set stores all elements
- Maximum size: N elements
- O(N) space

**Trade-off:**
- Works for unsorted arrays (Solution 2 requires sorted)
- Uses O(N) space vs O(1) for two pointers
- For sorted arrays, Solution 2 is better (O(1) space)

<br>

---

## Solution 4: Binary Search

**Intuition:**
For each element, use binary search to find if (element + k) exists in the array.

**Algorithm:**
1. For each element at index i:
   - Use binary search to find (arr[i] + k) in arr[i+1...n-1]
   - If found, return true
2. Return false

### Time Complexity: O(N log N)
**Why?**
- Outer loop: N iterations
- Binary search: O(log N) per iteration
- Total: N × log N = O(N log N)

**Detailed breakdown:**
- For each of N elements: perform binary search
- Binary search: log N comparisons
- Total: N × log N
- Example: Array of size 1000 → 1000 × 10 = 10,000 operations

**Comparison:**
- Slower than two pointers O(N)
- But simpler to implement
- Good alternative if two pointers logic is complex

### Space Complexity: O(1)
**Why?**
- Only loop variables and binary search variables
- No extra data structures

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Works on Unsorted | Key Feature |
|----------|------|-------|-------------------|-------------|
| Brute Force | O(N²) | O(1) | Yes | Check all pairs |
| Two Pointers | O(N) | O(1) | No (needs sorted) | Optimal for sorted |
| HashSet | O(N) | O(N) | Yes | Works on any array |
| Binary Search | O(N log N) | O(1) | No (needs sorted) | Simple alternative |

**Recommended Solution:** Two Pointers (Solution 2) for sorted arrays - O(N) time, O(1) space.

**Key Insights:**
1. **Brute → Two Pointers:** Use sorted property → avoid checking all pairs
2. **Two Pointers vs HashSet:** Sorted array → use two pointers for O(1) space
3. **Binary Search:** Alternative approach but slower than two pointers

<br>
<br>

---

```code```
