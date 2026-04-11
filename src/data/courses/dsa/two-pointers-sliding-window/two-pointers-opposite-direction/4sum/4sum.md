Given an array nums of n integers and a target, find all unique quadruplets [a, b, c, d] such that a + b + c + d = target.

<br>

> Input:
> nums = [1, 0, -1, 0, -2, 2], target = 0

> Output:
> [[-2, -1, 1, 2], [-2, 0, 0, 2], [-1, 0, 0, 1]]

> Explanation:
> Three unique quadruplets sum to 0.
> 
> **Key insight:** Extend 3Sum: fix TWO elements with nested loops, then use two-pointer for the remaining pair. O(N³) total.

<br>



---

## Constraints

- `1 ≤ nums.length ≤ 200`
- `-10⁹ ≤ nums[i] ≤ 10⁹`
- `-10⁹ ≤ target ≤ 10⁹`

<br>

---

## All Possible Edge Cases

1. **Less than 4 elements:** No quadruplets possible
2. **All same values:** [0,0,0,0], target=0 → [[0,0,0,0]]
3. **Integer overflow:** Large values — use long for sum

<br>

---

## Solution 1: Brute Force — All Quadruplets

**Intuition:**
Try all C(n,4) combinations of four elements.

### Time Complexity: O(N⁴)
### Space Complexity: O(1)

**Detailed breakdown:**
- N = 200 → C(200,4) ≈ 64,000,000 — slow but within limit barely

> **Drawback:**
> O(N⁴) is very slow. The inner two elements are essentially a Two Sum problem that we can solve in O(N) with two pointers.

> **Key Insight for Improvement:**
> Sort the array. Fix first two elements with nested loops (O(N²)). For the remaining pair, use two-pointer convergence (O(N)). Total: O(N³). Skip duplicates at all four levels.

<br>

---

## Solution 2: Sort + Two Nested Loops + Two Pointers (Optimal)

**Intuition:**
Generalize 3Sum: sort, fix first two elements, two-pointer for the pair. Skip duplicates to avoid repeated quadruplets.

**Algorithm:**
1. Sort the array
2. For i = 0 to n-4:
   - Skip if nums[i] == nums[i-1]
   - For j = i+1 to n-3:
     - Skip if nums[j] == nums[j-1] (and j > i+1)
     - left = j+1, right = n-1
     - Two-pointer: find pairs summing to target - nums[i] - nums[j]
     - Skip duplicate lefts and rights

### Time Complexity: O(N³)
**Why?**
- Two nested loops: O(N²)
- Two-pointer per inner iteration: O(N)
- Total: N² × N = O(N³)

**Detailed breakdown:**
- N = 200 → 200² × 200 = 8,000,000 operations — fast

**Note:** Use `long` for sum to avoid integer overflow with large values.

### Space Complexity: O(1) extra
**Why?**
- Only pointer variables

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N⁴) | O(1) | All quadruplets |
| Sort + Two Ptr | O(N³) | O(1) | Fix two + two-pointer for pair |

**Recommended Solution:** Sort + Two Pointers (Solution 2) — O(N³) time, O(1) space.

**Key Insights:**
1. **kSum generalization:** Fix (k-2) elements, two-pointer for last pair
2. **Integer overflow:** Use long for sum computation
3. **Four-level dedup:** Skip duplicates at i, j, left, right


<br>
<br>

---

```code```
