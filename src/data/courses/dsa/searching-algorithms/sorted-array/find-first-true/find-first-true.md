In a boolean array where all `false` values come before `true` values, the task is to find the index of the first `true` element. This can be efficiently solved using a binary search variation, exploiting the sorted property of the array.

We will examine the pattern and implement a solution that runs in logarithmic time.

## Problem

Given a sorted boolean array where `false` comes before `true`, find the **first index where the value is `true`**.
Return `-1` if no `true` value exists.

> **Input:**
>
> arr = [false, false, false, true, true, true]

> **Output:**
>
> 3

> **Explanation:**
> The first `true` appears at index `3`.

> **Input:**
>
> arr = [false, false, false, false]

> **Output:**
>
> -1

> **Explanation:**
> No `true` value exists in the array.

<br>

---

## Approach

Since the array is **monotonic** (all `false` before all `true`), we use **binary search** to find the boundary.

**Algorithm:**
1. Initialize `left = 0`, `right = n - 1`
2. While `left <= right`:
   - Compute `mid = left + (right - left) / 2`
   - If `arr[mid] == true`:
     - Record this as a potential answer
     - Continue searching left half for earlier `true` (right = mid - 1)
   - Else (arr[mid] == false):
     - Search right half (left = mid + 1)
3. Return the first recorded `true` index, or -1 if none found

**Why Binary Search Works:**
- The monotonic property guarantees all `false` are grouped together
- Once we find a `true`, any `true` to the left is earlier
- We can safely ignore halves

<br>

---

## Complexity Analysis

### Time Complexity: O(log n)

**Detailed Explanation:**
- **Best Case: O(1)** - First true is at the middle position
- **Worst Case: O(log n)** - First true is at position 0 or doesn't exist

**Why Binary Search?**
Since the array is monotonic (false | true), we can use binary search:
- If middle is true, answer is at mid or to the left
- If middle is false, answer must be to the right
- This allows us to eliminate half the search space each time

**Example:** Array of 1,000,000 elements
- Iteration 1: Check 500,000 → reduces to 500,000 elements
- Iteration 2: Check 250,000 → reduces to 250,000 elements
- ... continues ...
- Maximum 20 iterations to reach 1 element

### Space Complexity: **O(1)**

**Detailed Explanation:**
- We only use fixed variables: `left`, `right`, `mid`, `result`
- No additional data structures
- Space is independent of array size

**Memory Breakdown:**
- `left`, `right`, `mid`: 3 integers = O(1)
- `result`: 1 integer = O(1)
- **Total extra space:** constant = O(1)

<br>

---

## Key Insight: Monotonic Functions

This problem works because the array satisfies a **monotonic property:**
- All elements before the answer satisfy: `element < target`
- All elements at and after the answer satisfy: `element >= target`

Binary search can be applied to ANY problem with a monotonic condition, not just sorted arrays!

<br>

---

```code```