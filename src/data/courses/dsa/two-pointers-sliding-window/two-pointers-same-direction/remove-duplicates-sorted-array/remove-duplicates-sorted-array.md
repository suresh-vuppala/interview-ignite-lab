Given a sorted array, remove duplicates in-place such that each element appears only once and return the new length.

<br>

> Input:
> nums = [1, 1, 2, 2, 2, 3, 4, 4, 5]

> Output:
> 5

> Explanation:
> Modified array: [1, 2, 3, 4, 5, _, _, _, _]
> 
> Two pointer process:
> - Start: write=0, read=1
> - read=1: nums[1]=1 == nums[0]=1, skip
> - read=2: nums[2]=2 != nums[0]=1, write++, nums[1]=2
> - read=3: nums[3]=2 == nums[1]=2, skip
> - read=4: nums[4]=2 == nums[1]=2, skip
> - read=5: nums[5]=3 != nums[1]=2, write++, nums[2]=3
> - read=6: nums[6]=4 != nums[2]=3, write++, nums[3]=4
> - read=7: nums[7]=4 == nums[3]=4, skip
> - read=8: nums[8]=5 != nums[3]=4, write++, nums[4]=5
> 
> New length: write + 1 = 5

<br>

---

## Solution: Two Pointers (Same Direction)

Use two pointers moving in same direction:
1. **Write pointer**: Tracks position for next unique element
2. **Read pointer**: Scans through array
3. When read finds new unique element, copy to write position
4. Return write + 1 as new length

```code```

<br>

### Time Complexity Analysis

**Single Pass: O(n)**
- Read pointer traverses array once: n iterations
- For each element:
  - Compare with last unique: O(1)
  - Copy if different: O(1)
- Total: n × O(1) = O(n)

**No nested loops:**
- Both pointers move forward only
- Each element processed exactly once
- No backtracking or revisiting

**Why in-place is efficient:**
- No extra array needed
- Modify original array as we scan
- Write pointer always ≤ read pointer

> **Time Complexity:** O(n) - single pass through array
> **Space Complexity:** O(1) - only two pointer variables, in-place modification

<br>
<br>

---