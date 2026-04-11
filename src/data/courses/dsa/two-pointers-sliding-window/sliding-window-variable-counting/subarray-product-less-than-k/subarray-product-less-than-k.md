Given an array of positive integers and an integer k, count the number of contiguous subarrays where the product of all elements is strictly less than k.

<br>

> Input:
> nums = [10, 5, 2, 6], k = 100

> Output:
> 8

> Explanation:
> The 8 subarrays with product < 100 are:
> [10], [5], [2], [6], [10,5], [5,2], [2,6], [5,2,6]
> 
> **Key insight:** Use sliding window - for each right position, count all valid subarrays ending at right.

<br>



---

## Constraints

- `1 ≤ nums.length ≤ 3 × 10⁴`
- `1 ≤ nums[i] ≤ 1000`
- `0 ≤ k ≤ 10⁶`

<br>

---

## All Possible Edge Cases

1. **k = 0 or k = 1:** No positive product can be < 0 or < 1 → return 0
2. **All elements are 1:** Product is always 1 — all subarrays valid if k > 1
3. **Single element ≥ k:** That element alone doesn't form valid subarray
4. **Single element < k:** Return 1
5. **Entire array product < k:** All subarrays are valid → n*(n+1)/2
6. **Large elements:** Window shrinks quickly
7. **Product overflow concern:** With max element 1000 and n=30000, product can be huge — shrink early

<br>

---

## Solution 1: Brute Force

**Intuition:**
Generate all possible subarrays, calculate their product, and count those with product < k.

**Algorithm:**
1. Initialize count = 0
2. For each starting index i (0 to n-1):
   - For each ending index j (i to n-1):
     - Calculate product of subarray [i...j]
     - If product < k, increment count
3. Return count

### Time Complexity: O(N³)
**Why?**
- Outer loop: N iterations (starting positions)
- Inner loop: N iterations (ending positions)
- Product calculation: O(N) for each subarray
- Total: N × N × N = O(N³)

**Detailed breakdown:**
- Total subarrays: N×(N+1)/2 ≈ N²/2
- Each subarray product: O(N) to calculate
- Total: N²/2 × N = O(N³)
- Example: Array size 100 → 1,000,000 operations

### Space Complexity: O(1)
**Why?**
- Only storing count and loop variables
- No extra data structures

> **Key Insight for Improvement:**
> We're recalculating product from scratch for each subarray. Can we reuse previous product? Yes! When extending from [i...j] to [i...j+1], just multiply by nums[j+1].

<br>

---

## Solution 2: Brute Force Optimized

**Intuition:**
For each starting position, maintain a running product as we extend the subarray. This avoids recalculating the entire product.

**Algorithm:**
1. Initialize count = 0
2. For each starting index i:
   - Initialize product = 1
   - For each ending index j from i to n-1:
     - Multiply product by nums[j]
     - If product < k, increment count
     - Else break (product will only increase)
3. Return count

### Time Complexity: O(N²)
**Why?**
- Outer loop: N iterations
- Inner loop: at most N iterations
- Product update: O(1)
- Total: N × N = O(N²)

**Detailed breakdown:**
- For each starting position: extend until product ≥ k
- Worst case: all subarrays valid
- Total: N + (N-1) + ... + 1 = N×(N+1)/2 ≈ O(N²)
- Example: Array size 1000 → 500,500 operations

**Improvement:** From O(N³) to O(N²)
- Example: Array size 100
- Brute force: 1,000,000 operations
- Optimized: 5,050 operations (200× faster!)

### Space Complexity: O(1)
**Why?**
- Only product and count variables
- No extra space

> **Key Insight for Improvement:**
> We're still checking from each starting position. Can we use sliding window? Yes! For each right position, count how many valid subarrays end at right = (right - left + 1).

<br>

---

## Solution 3: Sliding Window

**Intuition:**
Use two pointers to maintain a window where product < k. For each right position, all subarrays ending at right and starting from any position in [left, right] are valid. Count = (right - left + 1).

**Algorithm:**
1. Initialize left = 0, product = 1, count = 0
2. For right from 0 to n-1:
   - Multiply product by nums[right]
   - While product ≥ k and left ≤ right:
     - Divide product by nums[left]
     - Increment left
   - Add (right - left + 1) to count
3. Return count

### Time Complexity: O(N)
**Why?**
- Right pointer: moves from 0 to n-1 → N moves
- Left pointer: moves from 0 to n-1 → at most N moves
- Each element visited at most twice
- Total: 2N = O(N)

**Detailed breakdown:**
- Right pointer: N iterations
- Left pointer: at most N moves total (never goes backward)
- Each element added once, removed at most once
- Total: 2N operations
- Example: Array size 1000 → 2000 operations

**Improvement:** From O(N²) to O(N)
- Example: Array size 1000
- Previous: 500,500 operations
- Current: 2000 operations (250× faster!)

**Why (right - left + 1)?**
- Window [left...right] has product < k
- All subarrays ending at right are valid:
  - [right] (length 1)
  - [right-1, right] (length 2)
  - ...
  - [left, left+1, ..., right] (length right-left+1)
- Total: (right - left + 1) subarrays

**Example walkthrough:**
```
nums = [10, 5, 2, 6], k = 100

right=0: [10], product=10 < 100, count += 1 = 1
right=1: [5], [10,5], product=50 < 100, count += 2 = 3
right=2: [2], [5,2], [10,5,2], product=100 ≥ 100
         Shrink: remove 10, product=10, left=1
         [2], [5,2], count += 2 = 5
right=3: [6], [2,6], [5,2,6], product=60 < 100, count += 3 = 8
```

### Space Complexity: O(1)
**Why?**
- Only pointer variables and product tracker
- No extra data structures

**Why this is optimal:**
- Must visit each element at least once: O(N) minimum
- Cannot do better than O(N) time

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N³) | O(1) | Check all subarrays |
| Brute Optimized | O(N²) | O(1) | Running product - avoid recalc |
| Sliding Window | O(N) | O(1) | Count subarrays ending at right |

**Recommended Solution:** Sliding Window (Solution 3) - O(N) time, O(1) space.

**Key Insights:**
1. **Brute → Optimized:** Running product → avoid recalculation
2. **Optimized → Sliding Window:** For each right, count = (right - left + 1)
3. **Counting trick:** All subarrays ending at right within valid window are counted


<br>
<br>

---

```code```
