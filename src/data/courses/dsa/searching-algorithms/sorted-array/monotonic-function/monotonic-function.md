## Problem

Determine if an array is **monotonic increasing**, **monotonic decreasing**, or both.

A monotonic array is one where elements consistently move in one direction (never reversing direction).

> **Input:**
>
> nums = [1, 2, 2, 3, 5, 5, 8]

> **Output:**
>
> true (monotonic increasing)

> **Explanation:**
> Each element is >= the previous element.

> **Input:**
>
> nums = [8, 5, 5, 3, 2, 2, 1]

> **Output:**
>
> true (monotonic decreasing)

<br>

---

## Approach

**Key Insight:** A monotonic function is one that either:
- Never decreases: `nums[i] <= nums[i+1]` for all i (monotonic increasing)
- Never increases: `nums[i] >= nums[i+1]` for all i (monotonic decreasing)

**Algorithm:**
1. Check if array is monotonic increasing by verifying all elements follow the pattern
2. Check if array is monotonic decreasing by verifying the opposite pattern
3. Return true if either condition holds

**Why This Matters for Binary Search:**
- Binary search requires a **monotonic condition** to eliminate search space
- A monotonic array is the simplest case - perfect for binary search
- Extensions of binary search work on any monotonic property, not just sorted arrays

<br>

---


---

## Constraints

- `Binary search on monotonic function over range [lo, hi]`

<br>

---

## All Possible Edge Cases

1. **Function always true:** Return lo
2. **Function always false:** Return hi + 1 or no answer
3. **Transition at boundary:** lo or hi is the answer
4. **Single point range:** lo == hi

<br>

## Complexity Analysis

### Time Complexity: O(n)

**Detailed Explanation:**
- **Best Case: O(1)** - Array has length 0 or 1, trivially monotonic
- **Average Case: O(n)** - Must check most/all pairs of adjacent elements
- **Worst Case: O(n)** - Single pass through entire array to verify

**Why Linear?**
We need to check adjacent pairs to determine monotonicity. Even if we could determine the direction early, we still need to verify all remaining elements follow that direction.

**Example:** Array of 1,000,000 elements
- Worst case: check all 999,999 adjacent pairs = 1,000,000 operations

### Space Complexity: O(1)

**Detailed Explanation:**
- We only use a constant number of boolean flags: `increasing`, `decreasing`
- No additional data structures
- Space is completely independent of array size

**Memory Breakdown:**
- `increasing` flag: 1 boolean = O(1)
- `decreasing` flag: 1 boolean = O(1)
- Loop counter: 1 integer = O(1)
- **Total extra space:** 3 variables (constant) = O(1)

<br>

---

## Monotonicity: Foundation for Binary Search

A **monotonic function** is the key property that makes binary search work:

**Why Does Binary Search Require Monotonicity?**
- If array is monotonic, we can make definite decisions
- If `nums[mid]` < `target` and array increases → answer must be right
- If `nums[mid]` > `target` and array increases → answer must be left
- Without monotonicity, we can't make these guarantees

**Examples of Monotonic Problems:**
- Sorted arrays (strictly increasing)
- Rotated sorted arrays (two increasing regions)
- Mountain arrays (increase then decrease)
- Boolean arrays (false then true)

<br>

---

```code```
