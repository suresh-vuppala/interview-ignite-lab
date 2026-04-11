## Problem

Find the index of a target value in an unsorted array. Return `-1` if the target is not found.

> **Input:**
>
> nums = [3, 1, 4, 1, 5, 9, 2, 6]
> target = 5

> **Output:**
>
> 4

> **Explanation:**
> The target `5` is found at index `4`.

<br>

---

## Approach

**Linear Search** examines each element sequentially until the target is found or the array is exhausted.

**Algorithm:**
1. Start from the first element
2. Compare current element with target
3. If match found, return index
4. Move to next element
5. If end reached without finding, return -1

<br>

---


---

## Constraints

- `0 ≤ nums.length ≤ 10⁴`
- `-10⁴ ≤ nums[i] ≤ 10⁴`

<br>

---

## All Possible Edge Cases

1. **Empty array:** Return -1
2. **Target at beginning:** Found in first iteration
3. **Target at end:** Found in last iteration
4. **Target not present:** Full traversal then -1
5. **Duplicate targets:** Return first occurrence
6. **Single element:** Match or not

<br>

## Complexity Analysis

### Time Complexity: O(n)

**Detailed Explanation:**
- **Best Case: O(1)** - Target is at the first position
- **Average Case: O(n)** - Target is somewhere in the middle, on average we check n/2 elements
- **Worst Case: O(n)** - Target is at the last position or not present, we check all n elements

**Why O(n)?**
Since the array is unsorted, we have no information about where the target is located. In the worst case, we must examine every single element in the array. There's no way to eliminate parts of the array without checking them.

**Example:**
- Array size: 1,000,000 elements
- If target is at position 999,999 or not found: ~1,000,000 comparisons

### Space Complexity: O(1)

**Detailed Explanation:**
- We only use a fixed amount of extra space: loop counter `i` and one variable to store the result
- No additional data structures (no arrays, no hash maps, no recursion stack)
- Space used is **independent** of input size n

**Memory Breakdown:**
- `i` (loop counter): 1 integer = O(1)
- `target` (input parameter): already allocated = O(1)
- `nums` (input array): doesn't count as extra space = O(1)
- **Total extra space:** constant = O(1)

<br>

---

## When to Use Linear Search?

✅ **Use when:**
- Array is unsorted
- Array size is very small
- Need to find ALL occurrences
- You don't have time to sort

❌ **Don't use when:**
- Array is already sorted (use binary search instead)
- You need to do many searches on the same array (preprocess with sorting)

<br>

---

```code```
