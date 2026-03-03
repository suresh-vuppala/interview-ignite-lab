Estimating the square root of a number using binary search is a classical application of the technique. By treating the problem as searching for a value whose square is close to a target, we can efficiently approximate roots.

This lesson walks through the formulation and implementation of square root estimation using binary search.

## Problem

Given a non-negative integer `n`, find the **integer square root** (floor of the square root).
In other words, find the largest integer `x` such that `x * x <= n`.

> **Input:**
>
> n = 16

> **Output:**
>
> 4

> **Explanation:**
> 4 * 4 = 16, so the square root is 4.

> **Input:**
>
> n = 17

> **Output:**
>
> 4

> **Explanation:**
> 4 * 4 = 16 < 17, and 5 * 5 = 25 > 17, so floor(√17) = 4.

<br>

---

## Approach

We use **binary search** on the answer space. The search space is all integers from 0 to n.

**Algorithm:**
1. Initialize `left = 0`, `right = n`
2. While `left <= right`:
   - Compute `mid = left + (right - left) / 2`
   - Compute `square = mid * mid`
   - If `square == n`, return `mid` (exact square root found)
   - If `square < n`, move left = mid + 1 (answer is larger)
   - If `square > n`, move right = mid - 1 (answer is smaller)
3. Return `right` (largest integer whose square <= n)

**Why This Works:**
- We search for a **condition**: "mid * mid <= n"
- When loop ends, `right` is the largest value satisfying the condition
- Binary search efficiently narrows down the answer in logarithmic time

<br>

---

## Complexity Analysis

### Time Complexity: O(log n)

**Detailed Explanation:**
- **Best Case: O(1)** - n is a perfect square and answer is at middle
- **Worst Case: O(log n)** - n is very large and we need multiple iterations

**Why Logarithmic?**
We're doing binary search on the number line from 0 to n:
- After 1st iteration: n/2 candidates remain
- After 2nd iteration: n/4 candidates remain
- ... continues ...
- Total iterations: log₂(n)

**Example:** For n = 1,000,000:
- Iteration 1: Check 500,000 → mid * mid vs 1,000,000
- Iteration 2: Check 250,000 → mid * mid vs 1,000,000
- ... continues ...
- Maximum ~20 iterations

### Space Complexity: **O(1)**

**Detailed Explanation:**
- We only use fixed variables: `left`, `right`, `mid`
- No extra data structures
- Space is completely independent of input

**Memory Breakdown:**
- `left`, `right`, `mid`: 3 integers = O(1)
- `square`: 1 long integer = O(1)
- **Total extra space:** constant = O(1)

<br>

---

## Advantages Over Math.sqrt()

✅ **Using Binary Search:**
- Works with integer arithmetic (no floating-point errors)
- More educational (learns binary search pattern)
- Consistent with other "search for answer" problems

❌ **Using Built-in sqrt():**
- May have precision issues with floating-point
- Less applicable to similar problem patterns

<br>

---

```code```