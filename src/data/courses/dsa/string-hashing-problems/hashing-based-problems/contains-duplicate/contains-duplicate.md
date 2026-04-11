Given an integer array nums, return true if any value appears at least twice in the array, and false if every element is distinct.

<br>

> Input:
> nums = [1, 2, 3, 1]

> Output:
> true

> Explanation:
> nums[0] and nums[3] are both 1. Since a duplicate exists, return true.
> 
> **Key insight:** The fastest way to detect duplicates is to check if an element was already "seen" — a hash set gives O(1) lookups.

<br>



---

## Constraints

- `1 ≤ nums.length ≤ 10⁵`
- `-10⁹ ≤ nums[i] ≤ 10⁹`

<br>

---

## All Possible Edge Cases

1. **All unique elements:** [1,2,3,4] → false
2. **All same elements:** [1,1,1] → true
3. **Single element:** [5] → false (no pair possible)
4. **Duplicate at extremes:** [1,2,3,4,1] → true (first and last)
5. **Two elements same:** [1,1] → true
6. **Large array, one duplicate:** Duplicate hidden deep in array

<br>

---

## Solution 1: Brute Force — Check All Pairs

**Intuition:**
The most direct approach — compare every element with every other element. If any two match, we have a duplicate.

**Algorithm:**
1. For each index i from 0 to n-2:
   - For each index j from i+1 to n-1:
     - If nums[i] == nums[j] → return true
2. No duplicates found → return false

### Time Complexity: O(N²)
**Why?**
- Outer loop: N-1 iterations
- Inner loop: up to N-1 iterations per outer
- Total comparisons: N×(N-1)/2

**Detailed breakdown:**
- Array size 100 → 4,950 comparisons
- Array size 10,000 → ~50,000,000 comparisons
- Array size 100,000 → ~5,000,000,000 comparisons — TLE guaranteed

### Space Complexity: O(1)
**Why?**
- Only loop variables i, j
- No extra data structures

> **Drawback:**
> Comparing every pair creates O(N²) comparisons. For the constraint N = 10⁵, that's ~5 billion operations — far too slow. We're not leveraging any structure or preprocessing.

> **Key Insight for Improvement:**
> If we sort the array first, duplicate elements become adjacent. Instead of checking all N² pairs, we only check N-1 adjacent pairs — a single linear scan after sorting.

<br>

---

## Solution 2: Sort + Adjacent Check

**Intuition:**
After sorting, any duplicates must be next to each other. A single pass comparing adjacent elements detects duplicates.

**Algorithm:**
1. Sort the array
2. For each index i from 1 to n-1:
   - If nums[i] == nums[i-1] → return true
3. No adjacent duplicates → return false

### Time Complexity: O(N log N)
**Why?**
- Sorting: O(N log N) — dominates
- Linear scan: O(N)
- Total: O(N log N)

**Detailed breakdown:**
- Array size 100 → ~664 operations (sort) + 99 (scan) ≈ 763
- Array size 100,000 → ~1,660,964 operations
- Compared to brute force: 5,000,000,000 → 1,660,964 (3000× faster!)

**Improvement:** From O(N²) to O(N log N)

### Space Complexity: O(1) or O(N)
**Why?**
- O(1) if sort is in-place (modifies input)
- O(N) if we need to preserve the original array

> **Drawback:**
> Sorting takes O(N log N) time and modifies the original array. We're doing more work than necessary — we don't need elements in sorted order, we just need to know "have I seen this value before?"

> **Key Insight for Improvement:**
> A hash set provides O(1) insert and O(1) lookup. For each element, check "have I seen this before?" in constant time. Total: N lookups × O(1) each = O(N). No sorting needed.

<br>

---

## Solution 3: Hash Set — O(1) Lookup

**Intuition:**
As we scan the array, insert each element into a hash set. Before inserting, check if it's already in the set. If yes — duplicate found.

**Algorithm:**
1. Create empty hash set
2. For each element num in nums:
   - If num is in set → return true (duplicate!)
   - Add num to set
3. No duplicates found → return false

### Time Complexity: O(N)
**Why?**
- Single pass: N iterations
- Hash set lookup: O(1) average
- Hash set insert: O(1) average
- Total: N × O(1) = O(N)

**Detailed breakdown:**
- Array size 100 → 100 operations
- Array size 100,000 → 100,000 operations
- Compared to sort: 1,660,964 → 100,000 (16× faster!)
- Compared to brute: 5,000,000,000 → 100,000 (50,000× faster!)

**Example walkthrough:**
```
nums = [1, 2, 3, 1]

num=1: set={} → 1 not in set → set={1}
num=2: set={1} → 2 not in set → set={1,2}
num=3: set={1,2} → 3 not in set → set={1,2,3}
num=1: set={1,2,3} → 1 IS in set → return true ✓
```

### Space Complexity: O(N)
**Why?**
- Hash set stores at most N elements (if all unique)
- Worst case: no duplicates → all N elements in set

**Why this is optimal:**
- Must examine each element at least once: O(N) minimum
- Cannot detect duplicates without seeing every element
- O(N) time is the theoretical lower bound

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N²) | O(1) | Check all N²/2 pairs |
| Sort + Scan | O(N log N) | O(1) | Sorting groups duplicates adjacent |
| Hash Set | O(N) | O(N) | O(1) existence check per element |

**Recommended Solution:** Hash Set (Solution 3) — O(N) time, O(N) space.

**Key Insights:**
1. **Brute → Sort:** Sorting groups duplicates together — O(N²) → O(N log N)
2. **Sort → Hash Set:** We don't need order, just existence check — O(N log N) → O(N)
3. **Space-time tradeoff:** Each improvement trades space for time. Hash set uses O(N) space but achieves optimal O(N) time.


<br>
<br>

---

```code```
