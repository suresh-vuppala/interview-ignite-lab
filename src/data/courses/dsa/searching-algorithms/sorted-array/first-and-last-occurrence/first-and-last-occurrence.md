
Find the first and last position of a given target value in a sorted integer array.
If the target does not exist in the array, return `[-1, -1]`.

> **Input:**
>
> nums = [5,7,7,8,8,10]
> target = 8
>



> **Output:**
> 
> [3, 4]
> 

> **Explanation:**
> The value `8` first appears at index `3` and last appears at index `4`.

<br>

---

## Approach

Because the array is already sorted, we can use **binary search** to locate the boundaries
in logarithmic time. We perform two modified binary searches:

1. **First occurrence** – when we see the target we record the index and continue
   searching the left half to look for an earlier appearance.
2. **Last occurrence** – when we see the target we record the index and continue
   searching the right half to look for a later appearance.

Both searches require _O(log n)_ time and constant extra space.

<br>

---



---

## Constraints

- `0 ≤ nums.length ≤ 10⁵`
- `-10⁹ ≤ nums[i] ≤ 10⁹`
- `nums is sorted in non-decreasing order`

<br>

---

## All Possible Edge Cases

1. **Target not found:** Return [-1, -1]
2. **Single occurrence:** First == Last
3. **All elements are target:** First=0, Last=n-1
4. **Target at boundaries:** First or last position only
5. **Empty array:** Return [-1, -1]
6. **Large run of target:** Must binary search for both ends

<br>

---

```code```
