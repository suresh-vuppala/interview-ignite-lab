Rearrange numbers into the lexicographically next greater permutation. If already the largest, wrap to smallest.

<br>

> Input: [1, 2, 3] → Output: [1, 3, 2]
> Input: [3, 2, 1] → Output: [1, 2, 3] (wrap around)
> Input: [1, 1, 5] → Output: [1, 5, 1]

<br>

---

## Constraints

- `1 ≤ nums.length ≤ 100`
- `0 ≤ nums[i] ≤ 100`

<br>

---

## All Possible Edge Cases

1. **Already largest:** [3,2,1] → [1,2,3]
2. **Already smallest:** [1,2,3] → [1,3,2]
3. **Single element:** No change
4. **All same:** No change
5. **Duplicates:** [1,1,5] → [1,5,1]

<br>

---

## Solution 1: Generate All Permutations

**Intuition:**
Generate all permutations sorted, find current one, return next.

### Time Complexity: O(n! × n)
### Space Complexity: O(n!)

<br>

---

## Solution 2: Three-Step Algorithm (Optimal)

**Intuition:**
Find the rightmost "dip" (element smaller than its right neighbor). Swap it with the smallest element to its right that is larger than it. Reverse the suffix.

**Algorithm:**
1. Find largest i where nums[i] < nums[i+1] (rightmost ascent)
2. Find largest j where nums[j] > nums[i] (rightmost element bigger than dip)
3. Swap nums[i] and nums[j]
4. Reverse nums[i+1..end] (make suffix smallest possible)
5. If no dip found (step 1 fails) → reverse entire array (wrap to smallest)

### Time Complexity: O(n) — at most 3 linear scans
### Space Complexity: O(1) — in-place

**Example: [1, 5, 8, 4, 7, 6, 5, 3, 1]**
- Step 1: Dip at index 3 (nums[3]=4 < nums[4]=7)
- Step 2: Rightmost > 4 is index 6 (nums[6]=5)
- Step 3: Swap → [1, 5, 8, 5, 7, 6, 4, 3, 1]
- Step 4: Reverse suffix → [1, 5, 8, 5, 1, 3, 4, 6, 7]

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| All Permutations | O(n! × n) | O(n!) | Generate and find |
| Three-Step | O(n) | O(1) | Find dip, swap, reverse |

<br>
<br>

---

```code```
