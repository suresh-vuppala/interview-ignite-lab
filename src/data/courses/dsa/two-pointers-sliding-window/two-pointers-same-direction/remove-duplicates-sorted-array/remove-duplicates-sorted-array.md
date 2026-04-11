Given a sorted array, remove duplicates in-place such that each element appears only once and return the new length.

<br>

> Input: nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]
> Output: 5, nums = [0, 1, 2, 3, 4, ...]
>
> **Key insight:** Use a slow pointer for the write position and a fast pointer to scan for new unique values.

<br>

---

## Constraints

- `1 ≤ nums.length ≤ 3 × 10⁴`
- `-100 ≤ nums[i] ≤ 100`
- `nums is sorted in non-decreasing order`

<br>

---

## All Possible Edge Cases

1. **All unique:** No duplicates to remove — return n
2. **All same:** Return 1
3. **Single element:** Return 1
4. **Two elements, same:** Return 1
5. **Two elements, different:** Return 2

<br>

---

## Solution 1: Extra Array (Not In-Place)

**Intuition:**
Create new array, copy unique elements.

**Algorithm:**
1. Create result array
2. Scan original, add element only if different from last added
3. Copy back

### Time Complexity: O(n)
### Space Complexity: O(n) — extra array

> **Key Insight:** Since array is sorted, duplicates are adjacent. A two-pointer approach handles this in-place.

<br>

---

## Solution 2: Two Pointers (Optimal)

**Intuition:**
Slow pointer `j` marks the write position. Fast pointer `i` scans forward. When `nums[i] != nums[j]`, copy `nums[i]` to `nums[++j]`.

**Algorithm:**
1. j = 0 (last unique position)
2. For i = 1 to n-1:
   - If nums[i] != nums[j] → j++, nums[j] = nums[i]
3. Return j + 1

**Example: [0, 0, 1, 1, 2]**
```
i=1: nums[1]=0 == nums[0]=0 → skip
i=2: nums[2]=1 != nums[0]=0 → j=1, nums[1]=1 → [0,1,1,1,2]
i=3: nums[3]=1 == nums[1]=1 → skip
i=4: nums[4]=2 != nums[1]=1 → j=2, nums[2]=2 → [0,1,2,1,2]
Return 3
```

### Time Complexity: O(n) — single pass
### Space Complexity: O(1) — in-place

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Extra Array | O(n) | O(n) | Copy uniques |
| Two Pointers | O(n) | O(1) | Slow/fast pointer in-place |

**Recommended:** Two Pointers — O(n) time, O(1) space.

<br>
<br>

---

```code```
