Given an unsorted integer array, find the smallest missing positive integer. Must run in O(N) time and O(1) extra space.

<br>

> Input:
> nums = [3, 4, -1, 1]

> Output:
> 2

> Explanation:
> Positive integers present: {1, 3, 4}. The smallest missing positive is 2.
> 
> **Key insight:** The answer is always in range [1, N+1]. Use the array itself as a hash map — place each value at index (value-1). First mismatch = answer.

<br>



---

## Constraints

- `1 ≤ nums.length ≤ 10⁵`
- `-2³¹ ≤ nums[i] ≤ 2³¹ - 1`

<br>

---

## All Possible Edge Cases

1. **[1,2,3]:** Answer is 4 (N+1)
2. **All negative:** [-1,-2,-3] → Answer is 1
3. **Contains 0:** [0,1,2] → Answer is 3
4. **Large numbers only:** [7,8,9] → Answer is 1
5. **Single element [1]:** Answer is 2
6. **Single element [2]:** Answer is 1

<br>

---

## Solution 1: Hash Set

**Intuition:**
Put all positive numbers in a hash set. Check 1, 2, 3, ... until we find one missing.

**Algorithm:**
1. Insert all elements into hash set
2. For i = 1 to N+1:
   - If i not in set → return i
3. Return N+1

### Time Complexity: O(N)
**Why?**
- Building set: O(N)
- Checking 1 to N+1: at most O(N+1)
- Total: O(N)

**Detailed breakdown:**
- Array size 100,000 → ~200,000 operations
- Correct time complexity but violates O(1) space requirement

### Space Complexity: O(N)
**Why?**
- Hash set stores up to N elements

> **Drawback:**
> Uses O(N) extra space for the hash set. The problem specifically requires O(1) auxiliary space. We need a way to "mark" which numbers are present without extra storage.

> **Key Insight for Improvement:**
> The answer must be in [1, N+1]. Use the array ITSELF as a hash map: place value v at index v-1 (cyclic sort). After this, the first index i where nums[i] ≠ i+1 gives the answer. Each swap places one element correctly, so total swaps ≤ N.

<br>

---

## Solution 2: Cyclic Sort — Array as Hash Map (Optimal)

**Intuition:**
Since the answer is in [1, N], we can use the array itself as a hash map. Place each number in its "correct" position: value 1 at index 0, value 2 at index 1, etc. After placing, scan for the first mismatch.

**Algorithm:**
1. For each index i:
   - While nums[i] is in range [1, N] AND nums[i] ≠ nums[nums[i]-1]:
     - Swap nums[i] with nums[nums[i]-1] (place it at correct position)
2. Scan: For each i from 0 to N-1:
   - If nums[i] ≠ i+1 → return i+1
3. Return N+1 (all 1..N are present)

### Time Complexity: O(N)
**Why?**
- Each element is swapped at most once to its correct position
- Total swaps across all iterations: ≤ N
- Scan: O(N)
- Total: O(N)

**Detailed breakdown:**
- Array size 100,000 → at most 200,000 operations (N swaps + N scan)
- Each swap permanently places one element → no element swapped twice

**Example walkthrough:**
```
nums = [3, 4, -1, 1]

i=0: nums[0]=3, should be at index 2 → swap with nums[2]
     [−1, 4, 3, 1]
     nums[0]=−1, out of range [1,4] → stop

i=1: nums[1]=4, should be at index 3 → swap with nums[3]
     [−1, 1, 3, 4]
     nums[1]=1, should be at index 0 → swap with nums[0]
     [1, −1, 3, 4]
     nums[1]=−1, out of range → stop

i=2: nums[2]=3, at index 2 → correct (3==2+1) → skip
i=3: nums[3]=4, at index 3 → correct (4==3+1) → skip

Scan: nums = [1, −1, 3, 4]
  i=0: nums[0]=1 == 0+1 ✓
  i=1: nums[1]=−1 ≠ 1+1=2 → return 2 ✓
```

### Space Complexity: O(1)
**Why?**
- Only swapping within the existing array
- No extra data structures

**Why this is optimal:**
- Must examine each element: O(N) minimum
- O(1) space — using array itself as storage

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Hash Set | O(N) | O(N) | Check 1,2,3... in set |
| Cyclic Sort | O(N) | O(1) | Array itself as hash map |

**Recommended Solution:** Cyclic Sort (Solution 2) — O(N) time, O(1) space.

**Key Insights:**
1. **Answer range:** Always in [1, N+1] — at most N+1 candidates
2. **Array as hash map:** Place value v at index v-1 (cyclic sort)
3. **Each swap is useful:** Every swap permanently places one element → total ≤ N swaps


<br>
<br>

---

```code```
