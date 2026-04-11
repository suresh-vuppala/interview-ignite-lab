Given an array of positive integers and an integer k, return the number of contiguous subarrays where the product of all elements is strictly less than k.

<br>

> Input:
> nums = [10, 5, 2, 6], k = 100

> Output:
> 8

> Explanation:
> Valid subarrays: [10], [5], [2], [6], [10,5], [5,2], [2,6], [5,2,6]. Products: 10,5,2,6,50,10,12,60 — all < 100.
> 
> **Key insight:** All positive → product only increases as window expands. When product ≥ k, shrink from left. For each right position, the number of valid subarrays ENDING at right = right - left + 1.

<br>



---

## Constraints

- `1 ≤ nums.length ≤ 3 × 10⁴`
- `1 ≤ nums[i] ≤ 1000`
- `0 ≤ k ≤ 10⁶`

<br>

---

## All Possible Edge Cases

1. **k ≤ 1:** No subarray can have product < 1 (all elements ≥ 1) → return 0
2. **All elements = 1:** Every subarray valid → n(n+1)/2
3. **Single element ≥ k:** That element alone is invalid
4. **Large products:** May overflow — but constraints keep nums[i] ≤ 1000

<br>

---

## Solution 1: Brute Force — Check All Subarrays

**Intuition:**
For each subarray [i..j], compute the product and check if < k.

### Time Complexity: O(N²)
**Why?**
- O(N²) subarrays, product computed incrementally O(1) per extension

**Detailed breakdown:**
- N = 30,000 → ~450,000,000 operations — TLE

### Space Complexity: O(1)

> **Drawback:**
> All positive elements means product is monotonically non-decreasing as the window expands. Once a window's product ≥ k, extending it further only makes it worse. We should shrink from the left instead of starting over.

> **Key Insight for Improvement:**
> Sliding window: expand right (multiply product), shrink left when product ≥ k (divide by leaving element). For each right, all subarrays ending at right and starting at left..right are valid. Count = right - left + 1.

<br>

---

## Solution 2: Sliding Window — Count Subarrays (Optimal)

**Intuition:**
Maintain running product. When product ≥ k, divide by nums[left] and advance left. For each right position, the number of new valid subarrays ending at right = window size = right - left + 1.

**Algorithm:**
1. If k ≤ 1 → return 0
2. left = 0, product = 1, count = 0
3. For right = 0 to n-1:
   - product *= nums[right]
   - While product ≥ k: product /= nums[left], left++
   - count += right - left + 1 (all subarrays ending at right)
4. Return count

### Time Complexity: O(N)
**Why?**
- Right pointer: N iterations
- Left pointer: moves at most N times total
- Total: 2N = O(N)

**Detailed breakdown:**
- N = 30,000 → at most 60,000 operations

**Why count = right - left + 1?**
- Subarrays ending at `right` that start within [left..right]:
  - [right, right], [right-1, right], ..., [left, right]
  - Total = right - left + 1

**Example walkthrough:**
```
nums = [10, 5, 2, 6], k = 100

right=0: product=10 < 100, count += 0-0+1 = 1   → [10]
right=1: product=50 < 100, count += 1-0+1 = 2   → [5], [10,5]
right=2: product=100 ≥ 100 → shrink: product=100/10=10, left=1
         product=10 < 100, count += 2-1+1 = 2    → [2], [5,2]
right=3: product=60 < 100, count += 3-1+1 = 3    → [6], [2,6], [5,2,6]

Total: 1+2+2+3 = 8 ✓
```

### Space Complexity: O(1)
**Why?**
- Only product, left, count variables

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N²) | O(1) | Check all subarrays |
| Sliding Window | O(N) | O(1) | Shrink when product ≥ k, count = window size |

**Recommended Solution:** Sliding Window (Solution 2) — O(N) time, O(1) space.

**Key Insights:**
1. **All positive → monotonic product:** Product only increases on expand
2. **Counting trick:** Subarrays ending at right = right - left + 1
3. **k ≤ 1 edge case:** No positive product can be < 1, return 0 immediately


<br>
<br>

---

```code```
