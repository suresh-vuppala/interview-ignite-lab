Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i]. You must solve it in O(N) time without using the division operator.

<br>

> Input:
> nums = [1, 2, 3, 4]

> Output:
> [24, 12, 8, 6]

> Explanation:
> answer[0] = 2×3×4 = 24, answer[1] = 1×3×4 = 12, answer[2] = 1×2×4 = 8, answer[3] = 1×2×3 = 6
> 
> **Key insight:** result[i] = (product of everything LEFT of i) × (product of everything RIGHT of i). Build these with two passes.

<br>



---

## Constraints

- `2 ≤ nums.length ≤ 10⁵`
- `-30 ≤ nums[i] ≤ 30`
- `Product of any prefix/suffix fits in 32-bit integer`
- `Must solve without division`

<br>

---

## All Possible Edge Cases

1. **Contains zero:** All other products are 0 except at zero's position
2. **Multiple zeros:** Entire result array is 0
3. **Two elements:** [a,b] → [b,a]
4. **All ones:** Result is all 1s
5. **Negative numbers:** Sign handling — odd negatives flip sign

<br>

---

## Solution 1: Brute Force — Multiply All Except Self

**Intuition:**
For each index i, iterate through the entire array and multiply all elements except nums[i].

**Algorithm:**
1. For each index i (0 to n-1):
   - Initialize product = 1
   - For each index j (0 to n-1):
     - If j ≠ i → product *= nums[j]
   - result[i] = product
2. Return result

### Time Complexity: O(N²)
**Why?**
- Outer loop: N iterations
- Inner loop: N multiplications per element
- Total: N × N = O(N²)

**Detailed breakdown:**
- Array size 100 → 10,000 multiplications
- Array size 100,000 → 10,000,000,000 multiplications — TLE

### Space Complexity: O(1) extra
**Why?**
- Only result array (required) and loop variables

> **Drawback:**
> For each element, we multiply all N-1 other elements from scratch — O(N) per element × N elements = O(N²). Adjacent elements share almost all the same factors, but we're recomputing from scratch every time.

> **Key Insight for Improvement:**
> result[i] = leftProduct(0..i-1) × rightProduct(i+1..n-1). We can precompute prefix products (left pass) and suffix products (right pass) in O(N) each.

<br>

---

## Solution 2: Prefix + Suffix Product Arrays

**Intuition:**
Build two arrays: prefix[i] = product of nums[0..i-1], suffix[i] = product of nums[i+1..n-1]. Then result[i] = prefix[i] × suffix[i].

**Algorithm:**
1. Build prefix array: prefix[0] = 1, prefix[i] = prefix[i-1] × nums[i-1]
2. Build suffix array: suffix[n-1] = 1, suffix[i] = suffix[i+1] × nums[i+1]
3. For each i: result[i] = prefix[i] × suffix[i]
4. Return result

### Time Complexity: O(N)
**Why?**
- Prefix pass: O(N)
- Suffix pass: O(N)
- Result pass: O(N)
- Total: 3N = O(N)

**Detailed breakdown:**
- Array size 100,000 → 300,000 operations
- Compared to brute force: 10,000,000,000 → 300,000 (33,333× faster!)

### Space Complexity: O(N)
**Why?**
- Two extra arrays (prefix and suffix) of size N each
- Total: 2N extra space

> **Drawback:**
> Uses O(N) extra space for the prefix and suffix arrays. The problem asks for O(1) extra space (excluding result array).

> **Key Insight for Improvement:**
> Use the result array itself as the prefix array (left pass). Then multiply in the suffix products using a single running variable (right pass). No extra arrays needed — just one variable.

<br>

---

## Solution 3: Two-Pass with Running Variable (Optimal)

**Intuition:**
Pass 1 (left→right): Fill result with prefix products.
Pass 2 (right→left): Multiply each result by suffix product using a running variable.

**Algorithm:**
1. Pass 1 — Left prefix products:
   - leftProduct = 1
   - For i = 0 to n-1: result[i] = leftProduct, then leftProduct *= nums[i]
2. Pass 2 — Right suffix products:
   - rightProduct = 1
   - For i = n-1 to 0: result[i] *= rightProduct, then rightProduct *= nums[i]
3. Return result

### Time Complexity: O(N)
**Why?**
- Left pass: O(N)
- Right pass: O(N)
- Total: 2N = O(N)

**Detailed breakdown:**
- Array size 100,000 → 200,000 operations
- Same asymptotic as Solution 2 but uses less space

**Example walkthrough:**
```
nums = [1, 2, 3, 4]

Pass 1 (left prefix):
  i=0: result=[1,_,_,_], leftProduct=1→1
  i=1: result=[1,1,_,_], leftProduct=1→2
  i=2: result=[1,1,2,_], leftProduct=2→6
  i=3: result=[1,1,2,6], leftProduct=6→24

Pass 2 (right suffix):
  i=3: result=[1,1,2,6×1=6], rightProduct=1→4
  i=2: result=[1,1,2×4=8,6], rightProduct=4→12
  i=1: result=[1,1×12=12,8,6], rightProduct=12→24
  i=0: result=[1×24=24,12,8,6], rightProduct=24→24

Final: [24, 12, 8, 6] ✓
```

### Space Complexity: O(1) extra
**Why?**
- Only two variables (leftProduct, rightProduct)
- Result array doesn't count as extra space (it's required output)

**Why this is optimal:**
- Must compute N products: O(N) minimum
- O(1) extra space — can't do better

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N²) | O(1) | Multiply N-1 elements per position |
| Prefix + Suffix | O(N) | O(N) | Precompute left/right products |
| Two-Pass Variable | O(N) | O(1) | Running variable replaces suffix array |

**Recommended Solution:** Two-Pass Variable (Solution 3) — O(N) time, O(1) extra space.

**Key Insights:**
1. **Brute → Prefix/Suffix:** result[i] = leftProduct × rightProduct
2. **Prefix/Suffix → Two-Pass:** Reuse result array for prefix, single variable for suffix
3. **No division needed:** Prefix/suffix decomposition avoids division entirely


<br>
<br>

---

```code```
