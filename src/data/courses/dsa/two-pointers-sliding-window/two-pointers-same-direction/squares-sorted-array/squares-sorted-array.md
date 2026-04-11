Given a sorted array (may contain negatives), return a new array of the squares of each number, sorted in non-decreasing order.

<br>

> Input:
> nums = [-4, -1, 0, 3, 10]

> Output:
> [0, 1, 9, 16, 100]

> Explanation:
> Squares: [16, 1, 0, 9, 100]. Sorted: [0, 1, 9, 16, 100].
> 
> **Key insight:** The largest squares are at the two ENDS of the sorted array (most negative or most positive). Compare from both ends, fill result from back to front.

<br>



---

## Constraints

- `1 ≤ nums.length ≤ 10⁴`
- `-10⁴ ≤ nums[i] ≤ 10⁴`
- `nums is sorted in non-decreasing order`

<br>

---

## All Possible Edge Cases

1. **All positive:** Already sorted after squaring
2. **All negative:** Reversed after squaring
3. **Mix of pos/neg:** Largest at extremes
4. **Contains zero:** Square is 0 (smallest)
5. **Single element:** Return [num²]

<br>

---

## Solution 1: Square + Sort

**Intuition:**
Square every element, then sort the result array.

**Algorithm:**
1. Square each element in-place
2. Sort the array
3. Return result

### Time Complexity: O(N log N)
**Why?**
- Squaring: O(N)
- Sorting: O(N log N) — dominates
- Total: O(N log N)

**Detailed breakdown:**
- Array size 10,000 → 10,000 squares + ~133,000 sort comparisons ≈ 143,000 operations
- We're ignoring the original sorted structure entirely!

### Space Complexity: O(1) or O(N)
**Why?**
- O(1) if sort is in-place, O(N) for merge sort

> **Drawback:**
> Sorting after squaring takes O(N log N), ignoring the fact that the input is already sorted. The largest squares come from the extremes of the original sorted array — we can exploit this order.

> **Key Insight for Improvement:**
> Two pointers at both ends. Compare |nums[left]| vs |nums[right]|. Place the larger square at the end of the result array, move that pointer inward. Single pass = O(N). The sorted order gives us the largest candidates at the extremes.

<br>

---

## Solution 2: Two Pointers from Ends (Optimal)

**Intuition:**
Left and right pointers start at array extremes. The larger absolute value produces the larger square. Fill result array from the end (position n-1 down to 0).

**Algorithm:**
1. Create result array of size n
2. left = 0, right = n-1, pos = n-1
3. While left ≤ right:
   - If |nums[left]| > |nums[right]|: result[pos] = nums[left]², left++
   - Else: result[pos] = nums[right]², right--
   - pos--
4. Return result

### Time Complexity: O(N)
**Why?**
- Single pass: each element processed exactly once
- N comparisons + N writes

**Detailed breakdown:**
- Array size 10,000 → exactly 10,000 operations
- Compared to sort: 143,000 → 10,000 (14× faster!)

**Example walkthrough:**
```
nums = [-4, -1, 0, 3, 10]
left=0, right=4, pos=4

|-4|=4 vs |10|=10 → 10 wins → result[4]=100, right=3, pos=3
|-4|=4 vs |3|=3 → -4 wins → result[3]=16, left=1, pos=2
|-1|=1 vs |3|=3 → 3 wins → result[2]=9, right=2, pos=1
|-1|=1 vs |0|=0 → -1 wins → result[1]=1, left=2, pos=0
left==right=2 → result[0]=0

Result: [0, 1, 9, 16, 100] ✓
```

### Space Complexity: O(N)
**Why?**
- Result array of size N (required for output)

**Why this is optimal:**
- Must produce N elements: O(N) minimum
- Single pass using sorted property

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Square + Sort | O(N log N) | O(N) | Ignores sorted input |
| Two Pointers | O(N) | O(N) | Exploit sorted order — largest at ends |

**Recommended Solution:** Two Pointers from Ends (Solution 2) — O(N) time.

**Key Insights:**
1. **Sorted input → extremes matter:** Largest absolute values at ends
2. **Fill from back:** Place largest squares first, working inward
3. **No sorting needed:** The two-pointer merge produces sorted output directly


<br>
<br>

---

```code```
