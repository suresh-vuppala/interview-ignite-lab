## Sliding Window — Efficient Subarray/Substring Processing

The sliding window technique processes contiguous subarrays or substrings by maintaining a "window" that slides across the data, avoiding redundant computation.

<br>

## Why Sliding Window?

- Transforms O(n²) or O(n×k) brute force into **O(n)**
- Essential for **substring** and **subarray** problems
- One of the **top 5 most-asked patterns** at FAANG companies

<br>

## Four Variations

| Type | Question Pattern | Example |
|------|-----------------|---------|
| **Fixed Size** | "Window of size K" | Max Sum Subarray of Size K |
| **Variable — Longest** | "Longest subarray/substring where..." | Longest Substring Without Repeating |
| **Variable — Shortest** | "Shortest subarray where..." | Minimum Window Substring |
| **Variable — Counting** | "Count subarrays where..." | Subarrays with Product < K |

<br>

## Template (Variable Window)

```
left = 0
for right in range(n):
    // expand: add nums[right] to window

    while window_condition_violated:
        // shrink: remove nums[left] from window
        left++

    // update answer (longest: max, shortest: min, count: accumulate)
```

<br>

## Key Decision: When to Shrink?

- **Longest:** Shrink only when constraint is **violated**
- **Shortest:** Shrink while constraint is **satisfied**
- **Counting:** Use `atMost(k) - atMost(k-1)` trick for "exactly K" problems

<br>


## All Possible Edge Cases
1. **N/A — introductory overview**

<br>

---

## When Sliding Window Fails

Sliding window **fails** when the problem doesn't have the **monotonicity property** required for the window to expand/shrink predictably.

<br>

### 1. Array Contains Negative Numbers (Sum-Based Problems)

**Why it fails:**  
Expanding the window doesn't guarantee the sum increases; shrinking doesn't guarantee it decreases.  

**Example:** `arr = [3, -2, 5]`, `k = 5`.  
Window `[3, -2]` sum = 1 ≤ 5, but adding 5 gives sum 6 > 5. You can't simply shrink from left because removing 3 might still keep sum > 5.  
The two-pointer approach that works for non-negative numbers would miscount subarrays.

<br>

### 2. Problems Requiring "Exactly K" (With Non-Negative Numbers)

**Why it fails:**  
The standard sliding window counts subarrays with sum **≤ K** or **≥ K**. For "exactly K", you'd need two windows (`atMost(K) - atMost(K-1)`). Direct sliding window doesn't work because there's no monotonic way to find exact match without extra data structures.

<br>

### 3. Problems With Non-Monotonic Constraints (Product, Bitwise AND/OR)

**Why it fails:**  
For example, subarray product ≤ K with positive numbers works (monotonic). But if numbers can be fractions or zero, product may not increase monotonically with window expansion.  

For bitwise AND: expanding window can only **decrease** or stay same (AND is monotonic decreasing), so sliding window can work but with different logic. However, for OR it's non-monotonic – expanding window can increase OR but shrinking doesn't guarantee decrease, making two-pointer invalid.

<br>

### 4. Multiple Constraints (Sum ≤ K AND Length ≥ L)

**Why it fails:**  
Simple two-pointer adjusts only one condition at a time. With multiple constraints, moving left pointer to fix sum may break length constraint, and vice versa. You may need binary search on answer or more complex data structures (e.g., prefix sums + monotonic deque).

<br>

### 5. Non-Static Arrays (Stream Processing With Deletions)

**Why it fails:**  
Sliding window assumes you can only add to right and remove from left. If you need arbitrary removal (e.g., "subarrays with sum ≤ K after updates"), the O(1) amortized pointer movement breaks.

<br>

### Summary table

| Problem type | Sliding window works? | Reason |
|--------------|----------------------|--------|
| Sum ≤ K (non-negative) | ✅ Yes | Monotonic sum |
| Sum ≤ K (with negatives) | ❌ No | Non-monotonic sum |
| Sum ≥ K (non-negative) | ✅ Yes (modified) | Monotonic (shrink when sum ≥ K) |
| Sum exactly K | ❌ No (needs two windows or hashmap) | No monotonic target |
| Product ≤ K (positive) | ✅ Yes | Monotonic product |
| Product ≤ K (with zeros/negatives) | ❌ No | Non-monotonic |
| Longest substring with ≤ K distinct chars | ✅ Yes | Monotonic character count |
| Longest substring with all unique chars | ✅ Yes | Sliding window works |
| Subarray with max sum (Kadane) | ❌ Not sliding window | Different DP approach |

### Bottom line
**Sliding window fails whenever the condition you're checking is not monotonic with respect to window expansion.**  
For sum-based problems, that means **negative numbers break it**. For other constraints, you need to verify that adding an element can only make the condition "harder" to satisfy, and removing an element can only make it "easier". If that's not true, two-pointer sliding window is invalid.

