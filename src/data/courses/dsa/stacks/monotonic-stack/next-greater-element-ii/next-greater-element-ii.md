Given a circular array `nums`, find the next greater element for every element. The next greater element of `nums[i]` is the first greater element to its right in a circular manner. If it doesn't exist, return -1.

## Input
```
nums = [1, 2, 1]
```

## Output
```
[2, -1, 2]
```

## Explanation

The input array is `[1, 2, 1]` (circular).

**Step-by-step breakdown:**
1. For `nums[0] = 1`: Next greater in circular array is `2` at index 1
2. For `nums[1] = 2`: No greater element exists (largest), return `-1`
3. For `nums[2] = 1`: Next greater in circular array is `2` at index 1 (wraps around)

**Result:** `[2, -1, 2]`

**Key insight:** Process array twice (2n iterations) to handle circular nature.


---

## Constraints

- `1 ≤ nums.length ≤ 10⁴`
- `-10⁹ ≤ nums[i] ≤ 10⁹`

<br>

---

## All Possible Edge Cases

1. **All same elements:** [5,5,5] → [-1,-1,-1]
2. **Single element:** [1] → [-1] (wraps to itself, no greater)
3. **Two elements:** [1,2] → [2,-1] (circular: 2 wraps but finds nothing)
4. **Strictly increasing:** Last element wraps to find its NGE at the start
5. **Maximum at single position:** That element's answer is -1, all others can wrap

<br>

## Solution Approach

Use monotonic decreasing stack with circular traversal:
1. Initialize result array with -1
2. Traverse array twice (indices 0 to 2n-1)
3. Use `i % n` to get actual index
4. Maintain stack of indices in decreasing order of values
5. For each element:
   - Pop smaller elements and update their result
   - Push current index (only in first pass)

## Time Complexity Analysis

**Overall: O(n)**

**Phase 1 - Two Pass Traversal:** O(2n) = O(n)
- Iterate 2n times for circular behavior
- Each element pushed once, popped once
- Total operations: 4n (2n iterations + 2n push/pop)

**Space Complexity:** O(n)
- Stack holds at most n indices
- Result array of size n

**Why O(n) is optimal:**
- Must examine each element at least once
- Circular nature requires checking wrap-around
- Stack ensures each element processed exactly twice

---

```code```
