## Problem

**Binary Search** can be applied to various problem patterns beyond simple element search:

1. **Finding boundaries** (first/last occurrence)
2. **Finding values satisfying conditions** (first number >= target)
3. **Answer space search** (finding the minimum/maximum valid value)
4. **Peak finding** in mountains or rotated arrays

### Example: Find the Smallest Number >= Target

> **Input:**
>
> nums = [1, 3, 5, 7, 9, 11]
> target = 6

> **Output:**
>
> 7 (index 3)

> **Explanation:**
> The smallest number >= 6 is `7` at index `3`.

<br>

---

## Common Applications

### 1. **Finding First/Last Occurrence**
- Locate leftmost and rightmost positions of target
- Used in range queries

### 2. **Finding Ceiling/Floor**
- Smallest element >= target (ceiling)
- Largest element <= target (floor)
- Useful in range databases

### 3. **Peak Finding**
- Find local maximum in array
- Applications: finding maximum efficiency point

### 4. **Rotated Array Search**
- Extend binary search to handle rotated sorted arrays
- Determine which half is properly sorted

### 5. **Answer Space Search**
- Problem: "What is the minimum value such that...?"
- Use binary search on the answer itself
- Examples: minimum capacity ship, minimum days to eat bananas

**Why Binary Search Works for These:**
- All variations leverage the **monotonic property** of sorted data
- We need to identify which half of search space contains the answer

<br>

---



---

## Constraints

- `Conceptual lesson — applications of binary search`

<br>

---

## All Possible Edge Cases

1. **Search on answer:** Binary search on result space, not input
2. **Rotated arrays:** Modified binary search with pivot detection

<br>
