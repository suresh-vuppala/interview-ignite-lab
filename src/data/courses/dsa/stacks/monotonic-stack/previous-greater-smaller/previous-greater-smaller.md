Given an array, find the previous greater element and previous smaller element for each element.

**Previous Greater Element (PGE):** First element to the left that is greater.
**Previous Smaller Element (PSE):** First element to the left that is smaller.

## Input
```
nums = [4, 5, 2, 10, 8]
```

## Output
```
PGE: [-1, -1, 5, -1, 10]
PSE: [-1, 4, -1, 2, 2]
```

## Explanation

The input array is `[4, 5, 2, 10, 8]`.

**Previous Greater Element:**
1. `4`: No element to left → `-1`
2. `5`: No greater to left → `-1`
3. `2`: Previous greater is `5`
4. `10`: No greater to left → `-1`
5. `8`: Previous greater is `10`

**Previous Smaller Element:**
1. `4`: No element to left → `-1`
2. `5`: Previous smaller is `4`
3. `2`: No smaller to left → `-1`
4. `10`: Previous smaller is `2`
5. `8`: Previous smaller is `2`


---

## Constraints

- `1 ≤ nums.length ≤ 10⁵`
- `-10⁹ ≤ nums[i] ≤ 10⁹`

<br>

---

## All Possible Edge Cases

1. **First element:** Always has no previous greater/smaller → -1
2. **Strictly increasing:** Previous greater is always -1; previous smaller is always the element before
3. **Strictly decreasing:** Previous smaller is always -1
4. **All same:** Previous greater and smaller are both -1
5. **Single element:** Both are -1

<br>

## Solution Approach

**For Previous Greater Element:**
1. Use monotonic decreasing stack (top to bottom)
2. For each element:
   - Pop elements ≤ current
   - Stack top is PGE (or -1 if empty)
   - Push current element

**For Previous Smaller Element:**
1. Use monotonic increasing stack (top to bottom)
2. For each element:
   - Pop elements ≥ current
   - Stack top is PSE (or -1 if empty)
   - Push current element

## Time Complexity Analysis

**Overall: O(n)**

**Phase 1 - Single Pass:** O(n)
- Each element pushed once, popped once
- Total operations: 3n (n iterations + 2n push/pop)

**Space Complexity:** O(n)
- Stack holds at most n elements
- Result array of size n

**Why O(n) is optimal:**
- Must process each element once
- Stack maintains monotonic property efficiently

---

```code```
