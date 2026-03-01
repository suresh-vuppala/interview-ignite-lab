
A rotated sorted array is an array that has been shifted circularly. Finding the minimum element in such an array is a classic binary search variation where the array appears "sorted" except at one pivot point.

This lesson demonstrates how to adapt search techniques to handle the rotation and locate the minimum efficiently.

## Problem

Given a **rotated sorted array** with distinct values, find the **minimum element**.

A rotated sorted array is a sorted array that has been rotated at some pivot point.

> **Input:**
>
> nums = [3, 4, 5, 1, 2]

> **Output:**
>
> 1

> **Explanation:**
> The array was originally [1,2,3,4,5], then rotated 3 times to get [3,4,5,1,2].

> **Input:**
>
> nums = [2, 1]

> **Output:**
>
> 1

> **Explanation:**
> One rotation of [1,2] gives [2,1].

<br>

---

## Approach

We use **binary search** by comparing middle element with the rightmost element to determine which half contains the minimum.

**Algorithm:**
1. Initialize `left = 0`, `right = n - 1`
2. While `left < right`:
   - Compute `mid = left + (right - left) / 2`
   - If `nums[mid] > nums[right]`:
     - Rotation point is in right half
     - Move left = mid + 1
   - Else:
     - Minimum is at mid or left half
     - Move right = mid
3. Return `nums[left]` (position of minimum)

**Key Insight:**
In a rotated sorted array, one half is always "properly sorted":
- Left half sorted: all elements >= nums[0]
- Right half sorted: all elements <= nums[n-1]

By comparing with the right end, we can determine which half is properly sorted.

<br>

---

## Complexity Analysis

### Time Complexity: O(log n)

**Detailed Explanation:**
- **Best Case: O(1)** - Minimum is at first position (no rotation)
- **Worst Case: O(log n)** - Minimum is hidden in rotation point

**Why Binary Search Works:**
At each step, we compare `nums[mid]` with `nums[right]`:
- If `nums[mid] > nums[right]`: rotation is in right half, search right
- If `nums[mid] <= nums[right]`: minimum is in left half or at mid, search left
- This eliminates half the search space each iteration

**Example:** Find min in [3,4,5,1,2]
```
Iteration 1: left=0, right=4, mid=2
  nums[2]=5 > nums[4]=2? Yes → left=3
Iteration 2: left=3, right=4, mid=3
  nums[3]=1 > nums[4]=2? No → right=3
Iteration 3: left=3, right=3 → Exit
Result: nums[3] = 1 (minimum!)
```

### Space Complexity: O(1)

**Detailed Explanation:**
- We only use constant variables: `left`, `right`, `mid`
- No extra arrays or recursive call stack
- Space is independent of input size

**Memory Breakdown:**
- `left`, `right`, `mid`: 3 integers = O(1)
- **Total extra space:** constant = O(1)

<br>

---

## Key Insight: Rotation Detection

A rotated array has a special property:
- **If not rotated:** nums[0] < nums[n-1] (sorted)
- **If rotated:** nums[0] > nums[n-1] (exists a "break point")

By comparing `nums[mid]` with `nums[right]`, we locate which side has the break point.

<br>

---

```code```

