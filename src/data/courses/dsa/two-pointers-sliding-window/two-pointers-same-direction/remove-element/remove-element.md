Given an integer array nums and an integer val, remove all occurrences of val in-place. Return the number of elements not equal to val.

<br>

> Input:
> nums = [3, 2, 2, 3], val = 3

> Output:
> 2, nums = [2, 2, _, _]

> Explanation:
> Two pointer process (write=w, read=r):
> - r=0: nums[0]=3 == val, skip
> - r=1: nums[1]=2 ≠ val, nums[w=0]=2, w=1
> - r=2: nums[2]=2 ≠ val, nums[w=1]=2, w=2
> - r=3: nums[3]=3 == val, skip
> - Return w=2
> 
> **Key insight:** Copy non-val elements forward, overwriting val elements.

<br>

---

## Constraints

- `0 ≤ nums.length ≤ 100`
- `0 ≤ nums[i] ≤ 50`
- `0 ≤ val ≤ 100`
- `Must modify array in-place with O(1) extra memory`

<br>

---

## All Possible Edge Cases

1. **Empty array:** Return 0
2. **All elements equal val:** [3,3,3] val=3 → return 0
3. **No elements equal val:** [1,2,3] val=4 → return 3, array unchanged
4. **Single element equals val:** [3] val=3 → return 0
5. **Single element not val:** [3] val=2 → return 1
6. **Val at beginning:** [val, 1, 2, 3]
7. **Val at end:** [1, 2, 3, val]
8. **All same, not val:** [5, 5, 5] val=3 → return 3

<br>

---

## Solution: Two Pointers (Same Direction)

**Intuition:**
Write pointer marks position for next valid element. Read pointer scans the array. Copy non-val elements to write position.

**Algorithm:**
1. Initialize write = 0
2. For read = 0 to n-1:
   - If nums[read] ≠ val:
     - nums[write] = nums[read]
     - write++
3. Return write

<br>

### Time Complexity: O(n) — single pass
### Space Complexity: O(1) — in-place

<br>
<br>

---

```code```
