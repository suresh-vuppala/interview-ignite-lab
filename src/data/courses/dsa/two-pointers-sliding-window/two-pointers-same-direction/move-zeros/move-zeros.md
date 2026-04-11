Given an integer array, move all zeros to the end while maintaining the relative order of the non-zero elements. Must be done in-place.

<br>

> Input:
> nums = [0, 1, 0, 3, 12]

> Output:
> [1, 3, 12, 0, 0]

> Explanation:
> Two pointer process (write=w, read=r):
> - r=0: nums[0]=0, skip
> - r=1: nums[1]=1 ≠ 0, swap nums[w=0] and nums[r=1] → [1, 0, 0, 3, 12], w=1
> - r=2: nums[2]=0, skip
> - r=3: nums[3]=3 ≠ 0, swap nums[w=1] and nums[r=3] → [1, 3, 0, 0, 12], w=2
> - r=4: nums[4]=12 ≠ 0, swap nums[w=2] and nums[r=4] → [1, 3, 12, 0, 0], w=3
> 
> **Key insight:** Write pointer marks the position for the next non-zero element. Read pointer scans forward.

<br>

---

## Constraints

- `1 ≤ nums.length ≤ 10⁴`
- `-2³¹ ≤ nums[i] ≤ 2³¹ - 1`
- `Must be done in-place without making a copy of the array`
- `Minimize the total number of operations`

<br>

---

## All Possible Edge Cases

1. **No zeros:** [1, 2, 3] → array unchanged
2. **All zeros:** [0, 0, 0] → [0, 0, 0]
3. **Single element:** [0] or [5] → unchanged
4. **Zeros at beginning:** [0, 0, 1, 2] → [1, 2, 0, 0]
5. **Zeros at end:** [1, 2, 0, 0] → already correct
6. **Alternating zeros:** [0, 1, 0, 2, 0, 3] → [1, 2, 3, 0, 0, 0]
7. **Single zero in middle:** [1, 0, 2] → [1, 2, 0]
8. **Large array all zeros except one:** [0, 0, ..., 0, 1] — write pointer barely moves

<br>

---

## Solution: Two Pointers (Same Direction)

**Intuition:**
Use a write pointer to track where the next non-zero should go. Scan with a read pointer. Every time we find a non-zero, swap it to the write position and advance write.

**Algorithm:**
1. Initialize write = 0
2. For read = 0 to n-1:
   - If nums[read] ≠ 0:
     - Swap nums[write] and nums[read]
     - write++
3. All zeros are now at the end

**Why swap instead of overwrite?**
- Swap preserves all values — zeros naturally end up at the end
- No second pass needed to fill trailing zeros

<br>

### Time Complexity: O(n)
**Why?**
- Single pass with read pointer
- Each element visited exactly once
- Swap is O(1)

### Space Complexity: O(1)
**Why?**
- Only two pointer variables
- In-place modification

<br>
<br>

---

```code```
