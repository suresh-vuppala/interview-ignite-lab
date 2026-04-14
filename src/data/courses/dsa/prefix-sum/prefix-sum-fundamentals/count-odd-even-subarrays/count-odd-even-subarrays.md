Count subarrays with odd sum and even sum.

<br>

> nums=[1,2,3] → odd:3, even:3
>
> **Key insight:** Track prefix sum parity. Odd-sum subarray: one prefix odd, one even. Even: both same parity.

<br>

---

## Constraints
- 1 ≤ N ≤ 10⁵
- 1 ≤ nums[i] ≤ 10⁵

<br>

---

## All Possible Edge Cases
1. **All even numbers:** only even-sum subarrays
2. **All odd numbers:** alternating parity sums
3. **Single element**

<br>

---

## Solution 1: Check all subarrays

**Intuition:**
The most straightforward approach. Quadratic.

**Algorithm:**
1. Enumerate all possible candidates
2. For each candidate, verify if it satisfies the condition
3. Track the best valid result
4. Return the optimal answer

### Time Complexity: O(N²)
**Why?**
Two nested loops each running up to N iterations.
Outer loop: N iterations × Inner loop: up to N iterations = N² total operations.

**Detailed breakdown:**
For N=1,000: ~1 million operations (OK). For N=10,000: ~100 million (borderline TLE).

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Quadratic.

> **Key Insight for Improvement:**
> Track count of even and odd prefix sums. Odd-sum subarrays = even_count × odd_count. Even = C(even,2) + C(odd,2).

<br>

---

## Solution 2: Prefix Parity Counting (Optimal)

**Intuition:** Track prefix sum parity. Odd-sum subarray: one prefix odd, one even. Even: both same parity.

**Algorithm:**
1. even_count=1 (prefix 0 is even), odd_count=0, prefix=0
2. For each num: prefix += num
   - If prefix even: even_count++
   - Else: odd_count++
3. odd_subarrays = even_count × odd_count
4. even_subarrays = C(even,2) + C(odd,2)

### Time Complexity: O(N)
**Why?**
Each element/state processed efficiently via the core technique.

**Detailed breakdown:**
Operations scale with input size as described by the complexity.

**Example walkthrough:**
```
[1,2,3]: prefix: 1(odd),3(odd),6(even)
even_count=2 (0,6), odd_count=2 (1,3)
odd_subs = 2×2 = 4... (simplified for illustration)
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Check all subarrays | O(N²) | Varies | Baseline |
| Prefix Parity Counting | O(N) | O(1) | Optimal approach |

**Recommended Solution:** Prefix Parity Counting — O(N) time.

**Key Insights:**
1. **Parity difference:** Even-odd prefix pair = odd sum subarray
2. **Same parity pair:** Same prefix parity = even sum subarray
3. **O(1) space:** Only track two counters

<br><br>

---

```code```
