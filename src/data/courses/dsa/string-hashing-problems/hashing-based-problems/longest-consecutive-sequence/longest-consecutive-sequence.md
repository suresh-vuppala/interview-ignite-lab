Given an unsorted array of integers, find the length of the longest consecutive elements sequence. Must run in O(N) time.

<br>

> Input:
> nums = [100, 4, 200, 1, 3, 2]

> Output:
> 4

> Explanation:
> The longest consecutive sequence is [1, 2, 3, 4]. Length = 4.
> 
> **Key insight:** Put all numbers in a HashSet. Only start counting from sequence BEGINNINGS (numbers where num-1 doesn't exist). This ensures each element is visited at most twice.

<br>



---

## Constraints

- `0 ≤ nums.length ≤ 10⁵`
- `-10⁹ ≤ nums[i] ≤ 10⁹`

<br>

---

## All Possible Edge Cases

1. **Empty array:** Return 0
2. **Single element:** Return 1
3. **All same:** [5,5,5] → length 1 (duplicates ignored)
4. **Already sorted:** [1,2,3,4,5] → 5
5. **Negative numbers:** [-1,0,1,2] → length 4
6. **Disjoint sequences:** [1,2,3,100,101] → length 3

<br>

---

## Solution 1: Sort + Linear Scan

**Intuition:**
Sort the array. Consecutive elements become adjacent. Scan for the longest run, skipping duplicates.

**Algorithm:**
1. If array is empty → return 0
2. Sort the array
3. Initialize currentLen = 1, maxLen = 1
4. For each i from 1 to n-1:
   - If nums[i] == nums[i-1] → skip (duplicate)
   - If nums[i] == nums[i-1] + 1 → currentLen++
   - Else → reset currentLen = 1
   - Update maxLen = max(maxLen, currentLen)
5. Return maxLen

### Time Complexity: O(N log N)
**Why?**
- Sorting: O(N log N) — dominates
- Linear scan: O(N)
- Total: O(N log N)

**Detailed breakdown:**
- Array size 100,000 → ~1,660,964 sort operations + 100,000 scan = ~1.76M
- Problem requires O(N) — sorting is too slow

### Space Complexity: O(1) or O(N)
**Why?**
- O(1) if in-place sort, O(N) for merge sort

> **Drawback:**
> Sorting takes O(N log N) which violates the O(N) requirement. Sorting also modifies the original array. We're imposing order on the entire array when we only need to find consecutive runs.

> **Key Insight for Improvement:**
> Put all numbers in a HashSet for O(1) lookups. For each number, check if it's a sequence START (num-1 not in set). Only from starts, count forward. Each element is part of exactly one sequence and counted once → O(N) total.

<br>

---

## Solution 2: Hash Set — Count from Beginnings Only (Optimal)

**Intuition:**
A number is a sequence beginning if (num - 1) is NOT in the set. Only start counting from beginnings. This avoids redundant counting — each element participates in exactly one count.

**Algorithm:**
1. Insert all numbers into HashSet
2. For each number in set:
   - If (num - 1) is NOT in set → this is a sequence start
   - Count forward: num, num+1, num+2, ... while in set
   - Update maxLen
3. Return maxLen

### Time Complexity: O(N)
**Why?**
- Building set: O(N)
- Outer loop: N iterations (checks each number)
- Inner counting: each element counted at most once across ALL iterations
- Total: N + N = O(N) amortized

**Detailed breakdown:**
- Array size 100,000 → ~200,000 operations (set build + one pass)
- Compared to sort: 1,760,000 → 200,000 (8.8× faster!)

**Why each element is counted at most once:**
- Only sequence STARTS trigger counting
- Each non-start element is counted only when its sequence start reaches it
- Example: [1,2,3,100,4] → only 1 and 100 trigger counting
  - From 1: count 1,2,3,4 (4 elements)
  - From 100: count 100 (1 element)
  - Total inner work: 5 = N

**Example walkthrough:**
```
nums = [100, 4, 200, 1, 3, 2]
set = {100, 4, 200, 1, 3, 2}

num=100: 99 not in set → START! Count: 100 → length 1
num=4:   3 IS in set → skip (not a start)
num=200: 199 not in set → START! Count: 200 → length 1
num=1:   0 not in set → START! Count: 1,2,3,4 → length 4 ★
num=3:   2 IS in set → skip
num=2:   1 IS in set → skip

Answer: 4 ✓
```

### Space Complexity: O(N)
**Why?**
- HashSet stores all N elements

**Why this is optimal:**
- Must examine each element at least once: O(N) minimum
- O(N) time achieved with amortized counting trick

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Sort + Scan | O(N log N) | O(1) | Sort then find runs |
| Hash Set | O(N) | O(N) | Only count from sequence beginnings |

**Recommended Solution:** Hash Set (Solution 2) — O(N) time, O(N) space.

**Key Insights:**
1. **Sort → Hash Set:** O(N log N) → O(N) by avoiding sort entirely
2. **Counting trick:** Only count from sequence STARTS (num-1 not in set)
3. **Amortized O(N):** Each element counted at most once across all sequences


<br>
<br>

---

```code```
