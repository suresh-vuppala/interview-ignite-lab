Given an integer array nums, return true if any value appears at least twice in the array, and false if every element is distinct.

<br>

> Input: nums = [1, 2, 3, 1]
> Output: true

> Input: nums = [1, 2, 3, 4]
> Output: false

> **Key insight:** Use a HashSet to track seen elements — if we try to add a duplicate, we've found one.

<br>

---

## Constraints

- `1 ≤ nums.length ≤ 10⁵`
- `-10⁹ ≤ nums[i] ≤ 10⁹`

<br>

---

## All Possible Edge Cases

1. **All unique:** Return false
2. **All same:** Return true
3. **Single element:** Return false
4. **Duplicate at extremes:** First and last are same
5. **Two elements, same value:** Return true

<br>

---

## Solution 1: Brute Force

**Intuition:**
Compare every pair of elements. If any pair matches, return true.

**Algorithm:**
1. For each i from 0 to n-2:
   - For each j from i+1 to n-1:
     - If nums[i] == nums[j] → return true
2. Return false

### Time Complexity: O(n²)
### Space Complexity: O(1)

> **Key Insight for Improvement:** Sorting groups duplicates together — adjacent elements can be compared in one pass.

<br>

---

## Solution 2: Sort + Scan

**Intuition:**
Sort the array. Duplicates will be adjacent. Scan for adjacent equal elements.

**Algorithm:**
1. Sort nums
2. For i from 1 to n-1:
   - If nums[i] == nums[i-1] → return true
3. Return false

### Time Complexity: O(n log n)
### Space Complexity: O(1) or O(n) depending on sort

> **Key Insight for Improvement:** A HashSet gives O(1) lookups — no need to sort.

<br>

---

## Solution 3: Hash Set

**Intuition:**
Insert each element into a HashSet. If insertion fails (already present), we found a duplicate.

**Algorithm:**
1. Create empty HashSet
2. For each num in nums:
   - If num is already in set → return true
   - Add num to set
3. Return false

### Time Complexity: O(n)
### Space Complexity: O(n)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(n²) | O(1) | Check all pairs |
| Sort + Scan | O(n log n) | O(1) | Duplicates become adjacent |
| Hash Set | O(n) | O(n) | O(1) existence check |

**Recommended:** Hash Set — O(n) time.

<br>
<br>

---

```code```
