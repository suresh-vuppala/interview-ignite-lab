Find all unique triplets in the array that sum to zero.

<br>

> Input: nums = [-1, 0, 1, 2, -1, -4]
> Output: [[-1, -1, 2], [-1, 0, 1]]

<br>

---

## Constraints

- `3 ≤ nums.length ≤ 3000`
- `-10⁵ ≤ nums[i] ≤ 10⁵`

<br>

---

## All Possible Edge Cases

1. **All zeros:** [0,0,0] → [[0,0,0]]
2. **No valid triplet:** [1,2,3] → []
3. **Duplicate triplets:** Must skip duplicates
4. **All positive or all negative:** No valid triplets

<br>

---

## Solution 1: Brute Force

**Intuition:** Check all triplets (i, j, k) where i < j < k.

### Time Complexity: O(n³)
### Space Complexity: O(1)

<br>

---

## Solution 2: Sort + Hash Set

**Intuition:** Sort array. For each pair (i, j), look up -(nums[i]+nums[j]) in a set.

### Time Complexity: O(n²)
### Space Complexity: O(n)

<br>

---

## Solution 3: Sort + Two Pointers (Optimal)

**Intuition:**
Sort array. Fix one element, use two pointers on the remaining array to find pairs that sum to negative of the fixed element.

**Algorithm:**
1. Sort nums
2. For each i from 0 to n-3:
   - Skip if nums[i] == nums[i-1] (avoid duplicate triplets)
   - left = i+1, right = n-1
   - While left < right:
     - sum = nums[i] + nums[left] + nums[right]
     - If sum == 0 → add triplet, skip duplicate lefts and rights
     - If sum < 0 → left++
     - If sum > 0 → right--

### Time Complexity: O(n²) — sort O(n log n) + nested loop O(n²)
### Space Complexity: O(1) extra (or O(n) for sort)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(n³) | O(1) | All triplets |
| Hash Set | O(n²) | O(n) | Two-sum with hash for third |
| Sort + Two Pointers | O(n²) | O(1) | Fix one, two-pointer for pair |

<br>
<br>

---

```code```
