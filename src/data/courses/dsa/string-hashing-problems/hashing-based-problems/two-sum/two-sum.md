Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target. You may assume that each input would have exactly one solution, and you may not use the same element twice.

<br>

> Input:
> nums = [2, 7, 11, 15], target = 9

> Output:
> [0, 1]

> Explanation:
> nums[0] + nums[1] = 2 + 7 = 9, so we return [0, 1].
> 
> **Key insight:** For each number, its complement (target - num) is uniquely determined. Use a hash map to look up complements in O(1).

<br>



---

## Constraints

- `2 ≤ nums.length ≤ 10⁴`
- `-10⁹ ≤ nums[i] ≤ 10⁹`
- `-10⁹ ≤ target ≤ 10⁹`
- `Exactly one solution exists`
- `Cannot use the same element twice`

<br>

---

## All Possible Edge Cases

1. **Two elements only:** Must be the answer pair
2. **Negative numbers:** [-3, 4, 3, 90] target=0 → [0,2]
3. **Target is 0:** Need a + b = 0
4. **Duplicate values:** [3,3] target=6 → [0,1] — same value, different indices
5. **Large values:** Watch for integer overflow in sum
6. **First and last elements:** Answer at array extremes

<br>

---

## Solution 1: Brute Force

**Intuition:**
The most straightforward approach — check every pair of elements. For each element, scan all elements after it to find one that makes the sum equal to target.

**Algorithm:**
1. For each index i from 0 to n-2:
   - For each index j from i+1 to n-1:
     - If nums[i] + nums[j] == target → return [i, j]
2. No solution found (shouldn't happen per constraints)

### Time Complexity: O(N²)
**Why?**
- Outer loop: N-1 iterations (starting positions)
- Inner loop: up to N-1 iterations per outer iteration
- Each comparison: O(1)
- Total pairs checked: N×(N-1)/2 ≈ N²/2

**Detailed breakdown:**
- For array size 100 → 4,950 pairs checked
- For array size 10,000 → ~50,000,000 pairs checked
- At 10⁴ constraint: 50 million operations — borderline TLE

### Space Complexity: O(1)
**Why?**
- Only loop variables i, j
- No extra data structures

> **Key Insight for Improvement:**
> For each number, we're scanning the rest of the array to find its complement — this linear scan inside a loop creates O(N²) redundant work. The key observation: we're looking for one specific value (target - nums[i]). Can we look it up in O(1) instead of O(N)? Yes — use a hash map to store numbers we've already seen.

<br>

---

## Solution 2: Hash Map — One Pass

**Intuition:**
As we iterate through the array, we build a hash map of {value → index}. For each new number, we compute its complement (target - num) and check if the complement is already in the map. If it is, we've found our pair.

**Algorithm:**
1. Create empty hash map: value → index
2. For each index i (0 to n-1):
   - complement = target - nums[i]
   - If complement exists in map → return [map[complement], i]
   - Else store nums[i] → i in map
3. Return empty (shouldn't reach here)

### Time Complexity: O(N)
**Why?**
- Single pass through array: N iterations
- Hash map lookup: O(1) average per operation
- Hash map insert: O(1) average per operation
- Total: N × O(1) = O(N)

**Detailed breakdown:**
- For array size 10,000 → 10,000 operations
- Compared to brute force: 50,000,000 → 10,000 (5000× faster!)

**Why one-pass works:**
- We check complement BEFORE inserting current number
- This prevents using the same element twice
- If complement exists, it was inserted at an earlier index → different element

**Example walkthrough:**
```
nums = [2, 7, 11, 15], target = 9

i=0: num=2, complement=7, map={} → 7 not found → map={2:0}
i=1: num=7, complement=2, map={2:0} → 2 FOUND at index 0!
     → return [0, 1] ✓
```

### Space Complexity: O(N)
**Why?**
- Hash map stores at most N entries (one per element)
- In the worst case, we insert all elements before finding the pair

**Why this is optimal:**
- Must examine each element at least once: O(N) minimum
- Cannot do better than O(N) time

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N²) | O(1) | Check all N²/2 pairs |
| Hash Map | O(N) | O(N) | O(1) complement lookup via hash map |

**Recommended Solution:** Hash Map (Solution 2) — O(N) time, O(N) space.

**Key Insights:**
1. **Brute → Hash Map:** Trade O(N) space for O(N²) → O(N) time improvement
2. **One-pass trick:** Check complement BEFORE inserting current element — avoids using same element twice
3. **Pattern recognition:** Whenever you need "find element with property X in array," consider hash map for O(1) lookup


<br>
<br>

---

```code```
