Find all unique quadruplets in the array that sum to a given target.

<br>

> Input:
> nums = [1, 0, -1, 0, -2, 2], target = 0

> Output:
> [[-2, -1, 1, 2], [-2, 0, 0, 2], [-1, 0, 0, 1]]

> Explanation:
> After sorting: [-2, -1, 0, 0, 1, 2]
> Fix i=0 (-2), j=1 (-1): two pointers find [0,0,1,2] sums → [-2,-1,1,2] ✓
> Fix i=0 (-2), j=2 (0): two pointers → [-2,0,0,2] ✓
> Fix i=1 (-1), j=2 (0): two pointers → [-1,0,0,1] ✓
> All other combinations either don't sum to 0 or are duplicates.
> 
> **Key insight:** Reduce to 3Sum by fixing one element, then to 2Sum with two pointers. Skip duplicates at all four levels.

<br>

---

## Constraints

- `1 ≤ nums.length ≤ 200`
- `-10⁹ ≤ nums[i] ≤ 10⁹`
- `-10⁹ ≤ target ≤ 10⁹`
- `Answer set must not contain duplicate quadruplets`

<br>

---

## All Possible Edge Cases

1. **Array smaller than 4:** Return empty — impossible to form a quadruplet
2. **All same elements:** [2,2,2,2] target=8 → [[2,2,2,2]]
3. **No valid quadruplet:** [1,2,3,4] target=100 → []
4. **Integer overflow:** nums[i] up to 10⁹ — sum of 4 can overflow int32, use long/long long
5. **Target is 0 with negatives and positives:** [-2,-1,0,0,1,2] target=0
6. **Many duplicates:** Must skip duplicates at all 4 levels
7. **Large negative target:** All elements negative, target very negative
8. **Exactly 4 elements:** Only one possible quadruplet to check

<br>

---

## Solution: Sort + Two Nested Loops + Two Pointers

**Intuition:**
Extension of 3Sum. Fix two elements with nested loops, use two pointers for the remaining two. Sort first to enable duplicate skipping and pointer movement.

**Algorithm:**
1. Sort the array
2. For each index i from 0 to n-4:
   - Skip duplicate i values
   - For each index j from i+1 to n-3:
     - Skip duplicate j values
     - Set left = j+1, right = n-1
     - Two pointer search for target - nums[i] - nums[j]
     - Skip duplicates in left and right

**⚠️ Overflow Warning:**
Sum of 4 elements can exceed int32 range. Use `long long` in C++ or `long` in Java.

**Example Walkthrough:**
```
nums = [1, 0, -1, 0, -2, 2], target = 0
Sorted: [-2, -1, 0, 0, 1, 2]

i=0(-2):
  j=1(-1): need sum=3 from [0,0,1,2]
    L=2(0), R=5(2): sum=2 < 3 → L++
    L=3(0), R=5(2): sum=2 < 3 → L++
    L=4(1), R=5(2): sum=3 == 3 ✓ → [-2,-1,1,2]
  j=2(0): need sum=2 from [0,1,2]
    L=3(0), R=5(2): sum=2 == 2 ✓ → [-2,0,0,2]
    L=4(1), R=4: done
  j=3(0): SKIP (duplicate of j=2)

i=1(-1):
  j=2(0): need sum=1 from [0,1,2]
    L=3(0), R=5(2): sum=2 > 1 → R--
    L=3(0), R=4(1): sum=1 == 1 ✓ → [-1,0,0,1]
  j=3(0): SKIP (duplicate of j=2)
```

<br>

### Time Complexity: O(n³)
**Why?**
- Sorting: O(n log n)
- Two nested loops: O(n²)
- Inner two-pointer: O(n) per pair
- Total: O(n³)

### Space Complexity: O(1)
- Only pointer variables (excluding output)

<br>
<br>

---

```code```
