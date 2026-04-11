Given an integer array of length n where all values are in [1, n] and each appears once or twice, find all elements that appear twice. O(N) time, O(1) extra space.

<br>

> Input:
> nums = [4, 3, 2, 7, 8, 2, 3, 1]

> Output:
> [2, 3]

> Explanation:
> 2 appears at indices 2 and 5, 3 appears at indices 1 and 6. All others appear once.
> 
> **Key insight:** Since values are in [1, N], use each value as an index. Mark visited by negating. Already negative = duplicate.

<br>



---

## Constraints

- `n == nums.length`
- `1 ≤ n ≤ 10⁵`
- `1 ≤ nums[i] ≤ n`
- `Each element appears once or twice`

<br>

---

## All Possible Edge Cases

1. **No duplicates:** All appear once → return []
2. **All duplicates:** [1,1,2,2] → [1,2]
3. **Single element:** [1] → no duplicate possible → []

<br>

---

## Solution 1: Hash Set

**Intuition:**
Track seen numbers. If a number is already in the set, it's a duplicate.

**Algorithm:**
1. Create hash set
2. For each num: if in set → add to result, else add to set
3. Return result

### Time Complexity: O(N)
**Why?**
- Single pass: N iterations
- Set operations: O(1) each

**Detailed breakdown:**
- Array size 100,000 → 100,000 set operations

### Space Complexity: O(N)
**Why?**
- Set stores up to N elements

> **Drawback:**
> Uses O(N) extra space for the hash set. The problem specifically requires O(1) auxiliary space. We need to mark visited elements without extra storage.

> **Key Insight for Improvement:**
> Since values are in [1, N], each value maps to a valid index (value-1). Use the sign of nums[value-1] as a visited flag. Negate to mark seen. If already negative → duplicate. The array itself becomes the hash set.

<br>

---

## Solution 2: Index Marking — Negate to Flag (Optimal)

**Intuition:**
For each number, treat |num|-1 as an index. If the value at that index is already negative, we've seen this number before (duplicate). Otherwise, negate it to mark as visited.

**Algorithm:**
1. For each num in nums:
   - idx = |num| - 1 (map value to 0-indexed position)
   - If nums[idx] < 0 → duplicate! Add idx+1 to result
   - Else → negate: nums[idx] = -nums[idx]
2. Return result

### Time Complexity: O(N)
**Why?**
- Single pass: N iterations
- Array access: O(1) per element

**Detailed breakdown:**
- Array size 100,000 → 100,000 array operations
- Same time as hash set but O(1) space!

**Example walkthrough:**
```
nums = [4, 3, 2, 7, 8, 2, 3, 1]

num=4: idx=3 → nums[3]=7 (pos) → negate → [4,3,2,-7,8,2,3,1]
num=3: idx=2 → nums[2]=2 (pos) → negate → [4,3,-2,-7,8,2,3,1]
num=2: idx=1 → nums[1]=3 (pos) → negate → [4,-3,-2,-7,8,2,3,1]
num=-7: idx=6 → nums[6]=3 (pos) → negate → [4,-3,-2,-7,8,2,-3,1]
num=8: idx=7 → nums[7]=1 (pos) → negate → [4,-3,-2,-7,8,2,-3,-1]
num=2: idx=1 → nums[1]=-3 (NEG!) → duplicate! → result=[2]
num=-3: idx=2 → nums[2]=-2 (NEG!) → duplicate! → result=[2,3]
num=-1: idx=0 → nums[0]=4 (pos) → negate → [-4,-3,-2,-7,8,2,-3,-1]

Result: [2, 3] ✓
```

### Space Complexity: O(1) extra
**Why?**
- Only modifying the input array in-place (sign bits)
- No extra data structures

**Why this is optimal:**
- Must see every element: O(N) minimum
- O(1) space — array itself as hash map

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Hash Set | O(N) | O(N) | Track seen elements |
| Index Marking | O(N) | O(1) | Array sign bit as visited flag |

**Recommended Solution:** Index Marking (Solution 2) — O(N) time, O(1) space.

**Key Insights:**
1. **Values in [1,N]:** Each value maps to a valid index → array = hash map
2. **Sign as flag:** Negate to mark visited, check sign before marking
3. **Absolute value:** Use |num| since values may already be negated


<br>
<br>

---

```code```
