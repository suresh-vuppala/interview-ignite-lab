Given an array of size n, find the majority element. The majority element appears more than ⌊n/2⌋ times. You may assume the majority element always exists.

<br>

> Input:
> nums = [2, 2, 1, 1, 1, 2, 2]

> Output:
> 2

> Explanation:
> 2 appears 4 times out of 7 elements. 4 > ⌊7/2⌋ = 3, so 2 is the majority element.
> 
> **Key insight:** Boyer-Moore Voting Algorithm — the majority element survives all cancellations because it appears more than n/2 times.

<br>



---

## Constraints

- `1 ≤ nums.length ≤ 5 × 10⁴`
- `-10⁹ ≤ nums[i] ≤ 10⁹`
- `Majority element is guaranteed to exist`

<br>

---

## All Possible Edge Cases

1. **Single element:** That element is majority
2. **All same:** Entire array is majority
3. **Minimum majority:** Exactly ⌊n/2⌋ + 1 occurrences
4. **Two distinct values:** Larger count wins

<br>

---

## Solution 1: Hash Map — Count Frequencies

**Intuition:**
Count frequency of each element. Return the one with count > n/2.

**Algorithm:**
1. Create frequency map: element → count
2. For each element: increment count in map
3. Return element with count > n/2

### Time Complexity: O(N)
**Why?**
- Single pass to count: O(N)
- Hash map operations: O(1) average
- Total: O(N)

**Detailed breakdown:**
- Array size 50,000 → 50,000 map operations

### Space Complexity: O(N)
**Why?**
- Hash map stores up to N/2 distinct elements in worst case

> **Drawback:**
> Uses O(N) extra space for the hash map. Can we find the majority element without any extra storage?

> **Key Insight for Improvement:**
> Boyer-Moore Voting: maintain a candidate and a counter. When counter hits 0, switch candidate. Increment for same, decrement for different. The majority element ALWAYS survives because it has more votes than all others combined.

<br>

---

## Solution 2: Sort + Middle Element

**Intuition:**
After sorting, the majority element (>n/2 occurrences) must be at index n/2.

**Algorithm:**
1. Sort the array
2. Return nums[n/2]

### Time Complexity: O(N log N)
**Why?**
- Sorting dominates

**Detailed breakdown:**
- Array size 50,000 → ~780,000 operations for sort

### Space Complexity: O(1) or O(N)
**Why?**
- Depends on sort implementation

> **Drawback:**
> Sorting takes O(N log N) — slower than hash map. Also modifies the array.

> **Key Insight for Improvement:**
> Boyer-Moore Voting achieves O(N) time AND O(1) space simultaneously — the best of both worlds.

<br>

---

## Solution 3: Boyer-Moore Voting Algorithm (Optimal)

**Intuition:**
Imagine pairing each majority element with a different non-majority element and "cancelling" them. Since majority > n/2, it will always have survivors. The algorithm simulates this: maintain a candidate with a vote counter.

**Algorithm:**
1. Initialize candidate = nums[0], count = 1
2. For each element from index 1:
   - If count == 0 → candidate = current element, count = 1
   - Else if current == candidate → count++
   - Else → count-- (cancellation)
3. Return candidate (guaranteed to be majority)

### Time Complexity: O(N)
**Why?**
- Single pass: N iterations
- Each iteration: O(1) work
- Total: O(N)

**Detailed breakdown:**
- Array size 50,000 → exactly 50,000 operations
- Compared to hash map: same time but O(1) space!

**Example walkthrough:**
```
nums = [2, 2, 1, 1, 1, 2, 2]

i=0: candidate=2, count=1
i=1: 2==2 → count=2
i=2: 1≠2 → count=1 (cancellation)
i=3: 1≠2 → count=0 (cancellation)
i=4: count==0 → candidate=1, count=1
i=5: 2≠1 → count=0 (cancellation)
i=6: count==0 → candidate=2, count=1

Result: 2 ✓
```

**Why it works:**
- Majority element appears > n/2 times
- Every cancellation removes one majority + one non-majority
- After all cancellations, majority element remains (it has more than all others combined)

### Space Complexity: O(1)
**Why?**
- Only two variables: candidate and count

**Why this is optimal:**
- Must see every element: O(N) time minimum
- O(1) space — can't do better

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Hash Map | O(N) | O(N) | Count frequencies |
| Sort | O(N log N) | O(1) | Middle element after sort |
| Boyer-Moore | O(N) | O(1) | Voting/cancellation — best of both |

**Recommended Solution:** Boyer-Moore Voting (Solution 3) — O(N) time, O(1) space.

**Key Insights:**
1. **Hash Map:** O(N) time but O(N) space
2. **Sort:** O(1) space but O(N log N) time
3. **Boyer-Moore:** O(N) time AND O(1) space — cancellation principle


<br>
<br>

---

```code```
