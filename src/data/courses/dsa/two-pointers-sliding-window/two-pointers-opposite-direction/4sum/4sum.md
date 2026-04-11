Find all unique quadruplets that sum to a target value.

<br>

> Input: nums = [1, 0, -1, 0, -2, 2], target = 0
> Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

<br>

---

## Constraints

- `1 ≤ nums.length ≤ 200`
- `-10⁹ ≤ nums[i] ≤ 10⁹`
- `-10⁹ ≤ target ≤ 10⁹`

<br>

---

## All Possible Edge Cases

1. **Less than 4 elements:** Return []
2. **All same elements:** [0,0,0,0] target=0 → [[0,0,0,0]]
3. **Integer overflow:** nums[i] can be 10⁹, sum of 4 can overflow int
4. **Duplicate quadruplets:** Must skip

<br>

---

## Solution 1: Brute Force

**Intuition:** Check all combinations of 4 elements.

### Time Complexity: O(n⁴)
### Space Complexity: O(1)

<br>

---

## Solution 2: Sort + Two Loops + Two Pointers (Optimal)

**Intuition:**
Extend 3Sum: fix two elements with nested loops, use two pointers for the remaining pair.

**Algorithm:**
1. Sort nums
2. For i from 0 to n-4 (skip duplicates):
   - For j from i+1 to n-3 (skip duplicates):
     - left = j+1, right = n-1
     - Two-pointer search for target - nums[i] - nums[j]

### Time Complexity: O(n³)
### Space Complexity: O(1)

**Optimization:** Early termination — if nums[i] × 4 > target or nums[i] + 3 × nums[n-1] < target, skip.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(n⁴) | O(1) | All quadruplets |
| Sort + Two Pointers | O(n³) | O(1) | Fix two, two-pointer for pair |

<br>
<br>

---

```code```
