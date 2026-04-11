Given an array nums and a value val, remove all occurrences of val in-place and return the new length.

<br>

> Input:
> nums = [3, 2, 2, 3], val = 3

> Output:
> 2, nums = [2, 2, ...]

> Explanation:
> Remove all 3s. Two elements remain: [2, 2]. Order of remaining elements may change.
> 
> **Key insight:** Two approaches — copy non-val forward (preserves order), or swap val with end (fewer writes when val is rare).

<br>



---

## Constraints

- `0 ≤ nums.length ≤ 100`
- `0 ≤ nums[i] ≤ 50`
- `0 ≤ val ≤ 100`

<br>

---

## All Possible Edge Cases

1. **All elements equal val:** Return 0
2. **No elements equal val:** Return n, unchanged
3. **Empty array:** Return 0
4. **Single element:** Either remove or keep

<br>

---

## Solution 1: Fast/Slow — Copy Non-Val Forward

**Intuition:**
Scan with fast pointer. Copy every non-val element to the slow pointer position.

**Algorithm:**
1. j = 0
2. For each num in nums: if num ≠ val → nums[j++] = num
3. Return j

### Time Complexity: O(N)
**Why?**
- Single pass: N iterations
- At most N writes

**Detailed breakdown:**
- Array size 100 → 100 iterations, up to 100 writes
- Always N iterations regardless of val frequency

### Space Complexity: O(1)
**Why?**
- Only pointer variable j

> **Drawback:**
> When val is rare (e.g., 1 out of 100), we still copy ~99 elements forward — many unnecessary writes for just 1 removal.

> **Key Insight for Improvement:**
> When we find val, swap it with the LAST element and shrink the array. Each removal is O(1). Total writes = number of val occurrences (not N). Order is not preserved but the problem allows that.

<br>

---

## Solution 2: Swap with End — Fewer Writes (Optimal for Rare Val)

**Intuition:**
When nums[i] == val, replace it with the last element and shrink n. Don't advance i (the swapped-in element needs checking).

**Algorithm:**
1. n = nums.length, i = 0
2. While i < n:
   - If nums[i] == val → nums[i] = nums[n-1], n--
   - Else → i++
3. Return n

### Time Complexity: O(N)
**Why?**
- Each iteration either advances i or shrinks n
- Total: at most N iterations

**Detailed breakdown:**
- Array size 100 with 2 vals → 2 swaps + 98 comparisons = 100 operations
- Writes: only 2 (vs 98 in Solution 1!)

**Example walkthrough:**
```
nums = [3, 2, 2, 3], val = 3, n = 4

i=0: nums[0]=3 == val → nums[0]=nums[3]=3 → n=3 → [3,2,2], still i=0
i=0: nums[0]=3 == val → nums[0]=nums[2]=2 → n=2 → [2,2], still i=0
i=0: nums[0]=2 ≠ val → i=1
i=1: nums[1]=2 ≠ val → i=2, but i=2 ≥ n=2 → stop

Return 2, nums = [2, 2] ✓
```

### Space Complexity: O(1)
**Why?**
- Only variables i and n

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Copy Forward | O(N) | O(1) | Copy every non-val element (up to N writes) |
| Swap with End | O(N) | O(1) | Swap val with end (writes = val count only) |

**Recommended Solution:** Depends on use case.
- **Preserve order needed:** Solution 1 (copy forward)
- **Minimize writes:** Solution 2 (swap with end)

**Key Insights:**
1. **Copy forward:** Preserves order, always N writes
2. **Swap with end:** Doesn't preserve order, but writes = val count
3. **Don't advance i after swap:** The swapped-in element hasn't been checked yet


<br>
<br>

---

```code```
