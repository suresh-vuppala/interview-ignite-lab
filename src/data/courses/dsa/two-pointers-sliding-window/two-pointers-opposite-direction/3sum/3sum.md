Find all unique triplets in the array that sum to zero.

<br>

> Input:
> nums = [-1, 0, 1, 2, -1, -4]

> Output:
> [[-1, -1, 2], [-1, 0, 1]]

> Explanation:
> After sorting: [-4, -1, -1, 0, 1, 2]
> 
> Fix i=0 (-4): two pointers on [-1,-1,0,1,2], no pair sums to 4
> Fix i=1 (-1): two pointers on [-1,0,1,2]
>   - left=-1, right=2: sum=0 ✓ → [-1,-1,2]
>   - left=0, right=1: sum=0 ✓ → [-1,0,1]
> Fix i=2 (-1): skip (duplicate of i=1)
> Fix i=3 (0): two pointers on [1,2], no pair sums to 0
> 
> **Key insight:** Sort first, fix one element, reduce to Two Sum with two pointers. Skip duplicates at every level.

<br>

---

## Constraints

- `3 ≤ nums.length ≤ 3000`
- `-10⁵ ≤ nums[i] ≤ 10⁵`
- `Answer set must not contain duplicate triplets`

<br>

---

## All Possible Edge Cases

1. **All zeros:** [0, 0, 0] → [[0, 0, 0]]
2. **No valid triplet:** [1, 2, 3] → []
3. **All negative:** [-5, -4, -3, -2, -1] → []
4. **All positive:** [1, 2, 3, 4] → []
5. **Multiple duplicates:** [-1, -1, -1, 0, 1, 1, 1] — must skip duplicates at every level
6. **Minimum size array:** Exactly 3 elements
7. **Large array with many duplicates:** Must handle duplicate-skipping efficiently to avoid TLE
8. **Mix of positive, negative, zero:** [-2, -1, 0, 1, 2] → [[-2,0,2], [-1,0,1]]

<br>

---

## Solution: Sort + Two Pointers

**Intuition:**
Sort the array. For each element, reduce to a Two Sum problem on the remaining portion using two pointers. Skip duplicates at all three positions to avoid duplicate triplets.

**Algorithm:**
1. Sort array
2. For each index i from 0 to n-3:
   - Skip if nums[i] == nums[i-1] (avoid duplicate first element)
   - Set left = i+1, right = n-1
   - While left < right:
     - If sum == 0: add triplet, skip duplicate lefts and rights
     - If sum < 0: left++
     - If sum > 0: right--

**Why sort first?**
- Enables two-pointer approach (needs sorted order)
- Makes duplicate skipping trivial (duplicates are adjacent)
- Enables early termination (if nums[i] > 0, no more triplets possible)

**Example Walkthrough:**
```
nums = [-1, 0, 1, 2, -1, -4]
Sorted: [-4, -1, -1, 0, 1, 2]

i=0, nums[i]=-4, target=4:
  L=1(-1), R=5(2): sum=1 < 4 → L++
  L=2(-1), R=5(2): sum=1 < 4 → L++
  L=3(0),  R=5(2): sum=2 < 4 → L++
  L=4(1),  R=5(2): sum=3 < 4 → L++
  L=5 >= R → done

i=1, nums[i]=-1, target=1:
  L=2(-1), R=5(2): sum=1 == target ✓ → add [-1,-1,2]
    skip dup L, skip dup R → L=3, R=4
  L=3(0), R=4(1): sum=1 == target ✓ → add [-1,0,1]
    L=4 >= R → done

i=2, nums[i]=-1: SKIP (same as nums[1])

i=3, nums[i]=0, target=0:
  L=4(1), R=5(2): sum=3 > 0 → R--
  L=4 >= R → done

Result: [[-1,-1,2], [-1,0,1]]
```

<br>

### Time Complexity: O(n²)
**Why?**
- Sorting: O(n log n)
- Outer loop: O(n) iterations
- Inner two-pointer loop: O(n) per iteration
- Total: O(n log n) + O(n²) = O(n²)

### Space Complexity: O(1)
**Why?**
- Sorting is in-place (or O(log n) stack space)
- Only pointer variables used
- Excluding the output array

<br>
<br>

---

```code```
