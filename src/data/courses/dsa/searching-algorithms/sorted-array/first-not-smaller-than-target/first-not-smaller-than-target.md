This topic focuses on finding the first element in a sorted (or monotonic) array that is not smaller than a given target value. It is a common variation of binary search used in many algorithmic problems.

We'll look at how to formulate the condition and implement the search efficiently.

## Problem

Given a sorted array and a target value, find the **first element that is >= target**.
Return `-1` if no such element exists.

> **Input:**
>
> nums = [1, 3, 5, 7, 9, 11, 13]
> target = 6

> **Output:**
>
> 7 (index 3)

> **Explanation:**
> The first element >= 6 is `7` at index `3`.

> **Input:**
>
> nums = [1, 2, 3, 4, 5]
> target = 10

> **Output:**
>
> -1

> **Explanation:**
> No element >= 10 exists.

<br>

---

## Approach

We use **binary search** to find the leftmost position where the condition `nums[i] >= target` is satisfied.

**Algorithm:**
1. Initialize `left = 0`, `right = n`
2. While `left < right`:
   - Compute `mid = left + (right - left) / 2`
   - If `nums[mid] < target`:
     - Move left = mid + 1 (answer is in right half)
   - Else:
     - Move right = mid (answer might be at mid or left)
3. If `left < n`, return nums[left], else return -1

**Key Insights:**
- The **monotonic property** ensures: all elements before answer are < target, all after are >= target
- We search for the **boundary** between these two regions
- Using `right = n` handles the case when answer doesn't exist (returns position n)

<br>

---

## Complexity Analysis

### Time Complexity: O(log n)

**Detailed Explanation:**
- **Best Case: O(1)** - Answer is at middle position
- **Worst Case: O(log n)** - Answer is at last position or doesn't exist

**Why Binary Search Works:**
The array has a clear monotonic property:
- All elements at positions 0...k-1: `element < target`
- All elements at positions k...n-1: `element >= target`

Binary search finds the boundary k by halving the search space.

**Example Walkthrough:** Finding first >= 6 in [1,3,5,7,9,11,13]
```
Iteration 1: left=0, right=7, mid=3
  nums[3]=7 >= 6? Yes → right=3
Iteration 2: left=0, right=3, mid=1
  nums[1]=3 >= 6? No → left=2
Iteration 3: left=2, right=3, mid=2
  nums[2]=5 >= 6? No → left=3
Iteration 4: left=3, right=3 → Exit
Result: nums[3] = 7
```

### Space Complexity: O(1)

**Detailed Explanation:**
- We only use a constant number of variables: `left`, `right`, `mid`
- No extra arrays, no recursion stack
- Space is independent of input size

**Memory Breakdown:**
- `left`, `right`, `mid`: 3 integers = O(1)
- **Total extra space:** constant = O(1)

<br>

---

## Boundary Handling: Why `right = n`?

Using `right = n` instead of `right = n-1` is crucial:
- Allows us to return position n when no element >= target exists
- Simplifies the logic and avoids off-by-one errors
- Makes the binary search template more elegant

<br>

---

```code```