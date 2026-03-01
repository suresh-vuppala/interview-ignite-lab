# Peak of Mountain Array

A mountain array increases and then decreases. Finding the peak element efficiently is another search problem that can be solved using binary search by comparing midpoints with their neighbors.

This lesson covers the strategy to identify the peak in logarithmic time.

## Problem

Given a **mountain array**, find the **index of the peak element**.

A mountain array:
- Strictly increases up to a peak
- Strictly decreases after the peak
- Peak is at index 0 < i < n-1

> **Input:**
>
> nums = [1, 3, 5, 4, 2]

> **Output:**
>
> 2

> **Explanation:**
> The peak is at index `2` with value `5`.

> **Input:**
>
> nums = [0, 10, 5, 2]

> **Output:**
>
> 1

> **Explanation:**
> The peak is at index `1` with value `10`.

<br>

---

## Approach

We use **binary search** by comparing the middle element with its neighbors to determine which side goes uphill.

**Algorithm:**
1. Initialize `left = 0`, `right = n - 1`
2. While `left < right`:
   - Compute `mid = left + (right - left) / 2`
   - If `nums[mid] < nums[mid + 1]`:
     - Peak is to the right (we're on uphill side)
     - Move left = mid + 1
   - Else:
     - Peak is at mid or to the left (we're on downhill side)
     - Move right = mid
3. Return `left` (position of peak)

**Why This Works:**
- At any point, comparing `nums[mid]` with `nums[mid + 1]` tells us which half contains the peak
- If nums[mid] < nums[mid+1], we haven't reached peak yet, go right
- If nums[mid] >= nums[mid+1], we've passed or are at the peak, go left
- The mountain property ensures we'll find the peak

<br>

---

## Complexity Analysis

### Time Complexity: O(log n)

**Detailed Explanation:**
- **Best Case: O(1)** - Peak is at the middle position
- **Worst Case: O(log n)** - Peak is at one of the extremes

**Why Binary Search Works:**
At each step, we compare `nums[mid]` with `nums[mid + 1]`:
- If increasing: peak must be in right half (left = mid + 1)
- If decreasing: peak must be in left half or at mid (right = mid)
- Each decision eliminates half the search space

**Example:** Peak in [1,3,5,4,2]:
```
Iteration 1: left=0, right=4, mid=2
  nums[2]=5 < nums[3]=4? No → right=2
Iteration 2: left=0, right=2, mid=1
  nums[1]=3 < nums[2]=5? Yes → left=2
Iteration 3: left=2, right=2 → Exit
Result: nums[2] = 5 (peak!)
```

### Space Complexity: O(1)

**Detailed Explanation:**
- We only use constant variables: `left`, `right`, `mid`
- No extra arrays or recursive call stack
- Space is completely independent of input size

**Memory Breakdown:**
- `left`, `right`, `mid`: 3 integers = O(1)
- **Total extra space:** constant = O(1)

<br>

---

## Precondition: Mountain Array Property

⚠️ **This algorithm assumes:**
- Array strictly increases up to peak
- Array strictly decreases after peak
- Peak exists at 0 < i < n-1

If these conditions don't hold, the algorithm may not work correctly.

<br>

---

## Similar Problems

This pattern applies to many "compare with neighbor" problems:
- Bitonic array search
- Find element in rotated array
- Find the peak in a 2D mountain

<br>

---

```code```