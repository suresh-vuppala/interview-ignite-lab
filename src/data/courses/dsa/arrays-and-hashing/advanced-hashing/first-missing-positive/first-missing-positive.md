Given an unsorted integer array, find the smallest missing positive integer. Must solve in O(n) time and O(1) extra space.

<br>

> Input: [3, 4, -1, 1] → Output: 2
> Input: [1, 2, 0] → Output: 3

<br>

---

## Constraints

- `1 ≤ nums.length ≤ 10⁵`
- `-2³¹ ≤ nums[i] ≤ 2³¹ - 1`

<br>

---

## All Possible Edge Cases

1. **[1,2,3]:** Return 4
2. **All negative:** Return 1
3. **[7,8,9]:** Return 1
4. **Contains 0:** 0 is not positive
5. **Duplicates:** [1,1] → return 2

<br>

---

## Solution 1: Hash Set

**Intuition:**
Put all positive numbers in a set. Check 1, 2, 3, ... until we find one missing.

### Time Complexity: O(n)
### Space Complexity: O(n)

<br>

---

## Solution 2: Sort + Scan

**Intuition:**
Sort, skip non-positives and duplicates, check if expected == actual.

### Time Complexity: O(n log n)
### Space Complexity: O(1)

<br>

---

## Solution 3: Cyclic Sort (Optimal)

**Intuition:**
Place each number at its "correct" index: nums[i] should be at index nums[i]-1. After sorting, the first index where nums[i] ≠ i+1 is the answer.

**Algorithm:**
1. Cyclic sort: while nums[i] is in [1, n] and not in correct position, swap
2. Scan: first i where nums[i] ≠ i+1 → return i+1
3. If all correct → return n+1

### Time Complexity: O(n) — each element swapped at most once
### Space Complexity: O(1) — in-place

**Example: [3, 4, -1, 1]**
- Swap 3 to index 2: [-1, 4, 3, 1]
- -1 is out of range, skip
- Swap 4 to index 3: [-1, 1, 3, 4]
- Swap 1 to index 0: [1, -1, 3, 4]
- Scan: index 1 has -1, not 2 → answer is 2

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Hash Set | O(n) | O(n) | Check 1,2,3... in set |
| Sort + Scan | O(n log n) | O(1) | Sequential check after sort |
| Cyclic Sort | O(n) | O(1) | Place each num at correct index |

**Recommended:** Cyclic Sort — O(n) time, O(1) space.

<br>
<br>

---

```code```
