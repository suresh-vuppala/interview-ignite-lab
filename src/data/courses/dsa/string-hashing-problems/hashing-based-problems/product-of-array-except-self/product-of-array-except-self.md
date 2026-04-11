Given an integer array nums, return an array where answer[i] is the product of all elements except nums[i]. Must run in O(n) without division.

<br>

> Input: nums = [1, 2, 3, 4]
> Output: [24, 12, 8, 6]

> Explanation: answer[0] = 2×3×4 = 24, answer[1] = 1×3×4 = 12, etc.

<br>

---

## Constraints

- `2 ≤ nums.length ≤ 10⁵`
- `-30 ≤ nums[i] ≤ 30`
- `Must solve in O(n) without division`

<br>

---

## All Possible Edge Cases

1. **Contains one zero:** All products 0 except at the zero's position
2. **Contains multiple zeros:** All products are 0
3. **All ones:** Result is all ones
4. **Two elements:** [a,b] → [b,a]
5. **Negative numbers:** Product signs alternate

<br>

---

## Solution 1: Brute Force

**Intuition:**
For each index, multiply all other elements.

**Algorithm:**
1. For each i: result[i] = product of all nums[j] where j ≠ i

### Time Complexity: O(n²)
### Space Complexity: O(1) extra

> **Key Insight:** result[i] = (product of left side) × (product of right side). Precompute prefix/suffix products.

<br>

---

## Solution 2: Prefix + Suffix Arrays

**Intuition:**
Build left prefix products and right suffix products. result[i] = prefix[i] × suffix[i].

**Algorithm:**
1. prefix[i] = product of nums[0..i-1]
2. suffix[i] = product of nums[i+1..n-1]
3. result[i] = prefix[i] × suffix[i]

### Time Complexity: O(n)
### Space Complexity: O(n) — two extra arrays

> **Key Insight:** We can compute left products into result array, then multiply right products in-place.

<br>

---

## Solution 3: Two-Pass (Optimal)

**Intuition:**
Pass 1: Fill result with left prefix products. Pass 2: Multiply by right suffix products using a running variable.

**Algorithm:**
1. result[0] = 1
2. For i = 1 to n-1: result[i] = result[i-1] × nums[i-1] (left products)
3. rightProduct = 1
4. For i = n-1 to 0: result[i] × = rightProduct; rightProduct × = nums[i]

### Time Complexity: O(n)
### Space Complexity: O(1) extra (result array doesn't count)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(n²) | O(1) | Multiply all others for each |
| Prefix + Suffix | O(n) | O(n) | Precompute prefix/suffix products |
| Two-Pass | O(n) | O(1) | Running right product eliminates suffix array |

**Recommended:** Two-Pass — O(n) time, O(1) extra space.

<br>
<br>

---

```code```
