Given an array of positive integers and a target, find the minimal length subarray whose sum is ≥ target. Return 0 if no such subarray.

<br>

> Input:
> target = 7, nums = [2, 3, 1, 2, 4, 3]

> Output:
> 2

> Explanation:
> Subarray [4, 3] has sum 7 ≥ target and length 2 — the shortest.
> 
> **Key insight:** All positive → as right expands, sum only increases. When sum ≥ target, shrink from left to minimize length. Classic "minimum window" sliding pattern.

<br>



---

## Constraints

- `1 ≤ target ≤ 10⁹`
- `1 ≤ nums.length ≤ 10⁵`
- `1 ≤ nums[i] ≤ 10⁴`

<br>

---

## All Possible Edge Cases

1. **Entire array sum < target:** Return 0
2. **Single element ≥ target:** Return 1
3. **Entire array needed:** Sum exactly equals target → return n

<br>

---

## Solution 1: Brute Force — All Subarrays

**Intuition:**
The most straightforward approach. Checking all starting positions.

**Algorithm:**
1. For each element i (outer loop):
   - For each element j (inner loop):
     - Check if the pair/condition is satisfied
2. Return the best result found

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
> Checking all starting positions. Once a subarray sum ≥ target, extending it further only makes the length larger — we should stop and try shrinking from the left instead.

> **Key Insight for Improvement:**
> All elements are positive. Use a sliding window: expand right to increase sum, shrink left when sum ≥ target (to minimize length). Left pointer only moves forward → O(N) total.

<br>

---

## Solution 2: Sliding Window — Shrink When Valid (Optimal)

**Intuition:**
Expand right to increase sum. When sum ≥ target, record length and shrink from left (subtract nums[left], advance left). Repeat shrinking while sum ≥ target.

**Algorithm:**
1. left = 0, sum = 0, minLen = ∞
2. For right = 0 to n-1:
   - sum += nums[right]
   - While sum ≥ target:
     - minLen = min(minLen, right - left + 1)
     - sum -= nums[left], left++
3. Return minLen == ∞ ? 0 : minLen

### Time Complexity: O(N)
**Why?**
- Right pointer: N iterations
- Left pointer: moves at most N times total
- Total: 2N = O(N)

**Detailed breakdown:**
- N = 100,000 → at most 200,000 operations

**Example walkthrough:**
```
target = 7, nums = [2, 3, 1, 2, 4, 3]

right=0: sum=2 < 7
right=1: sum=5 < 7
right=2: sum=6 < 7
right=3: sum=8 ≥ 7 → minLen=4, shrink: sum=8-2=6 < 7 → left=1
right=4: sum=6+4=10 ≥ 7 → minLen=4, shrink:
  sum=10-3=7 ≥ 7 → minLen=3, shrink: sum=7-1=6 < 7 → left=3
right=5: sum=6+3=9 ≥ 7 → minLen=3, shrink:
  sum=9-2=7 ≥ 7 → minLen=2 ★, shrink: sum=7-4=3 < 7 → left=5

Result: 2 ✓
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N²) | O(1) | All subarrays |
| Sliding Window | O(N) | O(1) | Shrink left when sum ≥ target |

**Recommended Solution:** Sliding Window (Solution 2) — O(N) time, O(1) space.

**Key Insights:**
1. **All positive:** Sum only increases as window expands — monotonic property enables sliding window
2. **Shrink to minimize:** Once valid, keep shrinking left to find shortest window
3. **Would NOT work with negatives:** Sum isn't monotonic with negatives — need prefix sum + binary search


<br>
<br>

---

```code```
