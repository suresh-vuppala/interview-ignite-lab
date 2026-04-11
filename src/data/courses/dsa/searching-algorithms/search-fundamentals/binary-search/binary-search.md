## Problem

Find the index of a target value in a **sorted** array. Return `-1` if the target is not found.

> **Input:**
>
> nums = [1, 3, 5, 7, 9, 11, 13]
> target = 7

> **Output:**
>
> 3

> **Explanation:**
> The target `7` is found at index `3` in the sorted array.

<br>

---

## Approach

**Binary Search** leverages the sorted property to eliminate half the search space with each comparison.

**Algorithm:**
1. Initialize `left = 0` and `right = n - 1`
2. While `left <= right`:
   - Compute `mid = left + (right - left) / 2`
   - If `nums[mid] == target`, return `mid`
   - If `nums[mid] < target`, move left = mid + 1 (search right half)
   - If `nums[mid] > target`, move right = mid - 1 (search left half)
3. If loop ends, return -1

**Why It Works:**
- The array is sorted, so we can make informed decisions about where to look next
- Each comparison eliminates half the remaining elements

<br>

---


---

## Constraints

- `1 ≤ nums.length ≤ 10⁴`
- `-10⁴ ≤ nums[i] ≤ 10⁴`
- `All elements are unique`
- `nums is sorted in ascending order`

<br>

---

## All Possible Edge Cases

1. **Target at first position:** Found immediately on low side
2. **Target at last position:** Found after converging to high side
3. **Target at middle:** Found in first comparison
4. **Target not in array:** Return -1
5. **Single element, is target:** Return 0
6. **Single element, not target:** Return -1
7. **Two elements:** Test both boundary conditions
8. **Integer overflow in mid calculation:** Use low + (high - low) / 2

<br>

## Complexity Analysis

### Time Complexity: O(log n)

**Detailed Explanation:**
- **Best Case: O(1)** - Target is at the middle position on first check
- **Average Case: O(log n)** - We eliminate half the search space each iteration
- **Worst Case: O(log n)** - Target is at one end or not found

**Why Logarithmic?**
Each iteration halves the search space:
- Start: n elements
- After 1st check: n/2 elements remain
- After 2nd check: n/4 elements remain
- After 3rd check: n/8 elements remain
- ... and so on

To reach 1 element from n: we need log₂(n) iterations

**Example:** For an array of 1,000,000 elements:
- Linear search: up to 1,000,000 comparisons
- Binary search: approximately log₂(1,000,000) ≈ 20 comparisons

**Math Formula:**
- log₂(1,000,000) ≈ 19.93, so maximum 20 iterations

### Space Complexity: O(1)

**Detailed Explanation:**
- We only use fixed variables: `left`, `right`, `mid`
- No extra arrays, hash maps, or recursive call stack (if using iterative approach)
- Space does not grow with input size

**Memory Breakdown:**
- `left` (pointer): 1 integer = O(1)
- `right` (pointer): 1 integer = O(1)
- `mid` (pointer): 1 integer = O(1)
- **Total extra space:** 3 integers (constant) = O(1)

**Note:** If using recursive binary search, space becomes O(log n) due to call stack depth.

<br>

---

## Precondition: Array Must Be Sorted!

⚠️ **Binary search ONLY works on sorted arrays**

If the array is unsorted:
1. Either sort it first: O(n log n) + O(log n) = O(n log n)
2. Or use linear search: O(n)

<br>

---

```code```
