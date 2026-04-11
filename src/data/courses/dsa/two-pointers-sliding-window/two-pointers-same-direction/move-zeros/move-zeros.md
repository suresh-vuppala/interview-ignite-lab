Given an array nums, move all 0s to the end while maintaining the relative order of the non-zero elements. Must be done in-place.

<br>

> Input:
> nums = [0, 1, 0, 3, 12]

> Output:
> [1, 3, 12, 0, 0]

> Explanation:
> Non-zero elements [1, 3, 12] maintain their relative order. All zeros moved to the end.
> 
> **Key insight:** Use two pointers — fast finds non-zeros, slow marks where to place them. Swap to move zeros right naturally.

<br>



---

## Constraints

- `1 ≤ nums.length ≤ 10⁴`
- `-2³¹ ≤ nums[i] ≤ 2³¹ - 1`

<br>

---

## All Possible Edge Cases

1. **No zeros:** [1,2,3] → unchanged
2. **All zeros:** [0,0,0] → unchanged
3. **Zeros at end:** [1,2,0,0] → already correct
4. **Single element:** [0] or [1] → unchanged
5. **Alternating:** [0,1,0,1] → [1,1,0,0]

<br>

---

## Solution 1: Two-Pass (Copy then Fill)

**Intuition:**
First pass: copy all non-zero elements to the front. Second pass: fill remaining positions with zeros.

**Algorithm:**
1. j = 0
2. Pass 1: For each num in nums: if num ≠ 0 → nums[j++] = num
3. Pass 2: Fill nums[j..n-1] with 0

### Time Complexity: O(N)
**Why?**
- Pass 1: N iterations
- Pass 2: up to N iterations
- Total: 2N = O(N)

**Detailed breakdown:**
- Array size 10,000 → up to 20,000 operations (two passes)
- Second pass writes zeros even if they were already there

### Space Complexity: O(1)
**Why?**
- Only index variable j — all in-place

> **Drawback:**
> Requires two passes. The second pass writes zeros to positions that may already contain zeros (unnecessary writes). Can we do it in a single pass?

> **Key Insight for Improvement:**
> Single-pass swap: when we find a non-zero at position i, swap it with position j (the next non-zero write position). Zeros naturally "bubble" right via swaps. One pass, minimal writes.

<br>

---

## Solution 2: Single-Pass Swap (Optimal)

**Intuition:**
Slow pointer `j` = next position for a non-zero. Fast pointer `i` scans. When nums[i] ≠ 0, swap nums[i] with nums[j] and advance j.

**Algorithm:**
1. j = 0
2. For i = 0 to n-1:
   - If nums[i] ≠ 0 → swap(nums[i], nums[j]), j++

### Time Complexity: O(N)
**Why?**
- Single pass: N iterations
- Each swap: O(1)
- Total: O(N) with minimal writes

**Detailed breakdown:**
- Array size 10,000 → exactly 10,000 iterations
- Swaps: only when non-zero found (at most N swaps)
- No unnecessary zero-writes

**Example walkthrough:**
```
nums = [0, 1, 0, 3, 12], j=0

i=0: nums[0]=0 → skip
i=1: nums[1]=1 ≠ 0 → swap(nums[1],nums[0]) → [1,0,0,3,12], j=1
i=2: nums[2]=0 → skip
i=3: nums[3]=3 ≠ 0 → swap(nums[3],nums[1]) → [1,3,0,0,12], j=2
i=4: nums[4]=12 ≠ 0 → swap(nums[4],nums[2]) → [1,3,12,0,0], j=3

Result: [1, 3, 12, 0, 0] ✓
```

### Space Complexity: O(1)
**Why?**
- Only pointer variables — all in-place swaps

**Why this is optimal:**
- Must examine every element: O(N) minimum
- Single pass with O(1) space

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Two-Pass | O(N) | O(1) | Copy forward then fill zeros |
| Single-Pass Swap | O(N) | O(1) | Swap in one pass — fewer writes |

**Recommended Solution:** Single-Pass Swap (Solution 2) — O(N) time, O(1) space.

**Key Insights:**
1. **Two-pass → Single-pass:** Swap eliminates the separate zero-fill pass
2. **Same pattern as Remove Duplicates:** Slow writes, fast scans
3. **Order preserved:** Non-zero elements maintain relative order because we only swap forward


<br>
<br>

---

```code```
