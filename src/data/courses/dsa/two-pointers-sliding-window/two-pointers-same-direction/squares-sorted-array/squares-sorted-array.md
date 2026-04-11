Given a sorted array of integers (may contain negatives), return a sorted array of the squares of each number.

<br>

> Input:
> nums = [-4, -1, 0, 3, 10]

> Output:
> [0, 1, 9, 16, 100]

> Explanation:
> Squares: [16, 1, 0, 9, 100] — not sorted!
> 
> Two pointer approach (fill result from end):
> - L=0(-4²=16), R=4(10²=100): 100 > 16 → result[4]=100, R--
> - L=0(-4²=16), R=3(3²=9): 16 > 9 → result[3]=16, L++
> - L=1(-1²=1), R=3(3²=9): 9 > 1 → result[2]=9, R--
> - L=1(-1²=1), R=2(0²=0): 1 > 0 → result[1]=1, L++
> - L=2(0²=0), R=2(0²=0): result[0]=0
> 
> **Key insight:** Largest squares are at the extremes (most negative or most positive). Fill result from end.

<br>

---

## Constraints

- `1 ≤ nums.length ≤ 10⁴`
- `-10⁴ ≤ nums[i] ≤ 10⁴`
- `nums is sorted in non-decreasing order`

<br>

---

## All Possible Edge Cases

1. **All non-negative:** [0, 1, 2, 3] → [0, 1, 4, 9] — already sorted after squaring
2. **All negative:** [-4, -3, -2, -1] → [1, 4, 9, 16] — reverse order
3. **Single element:** [5] → [25]
4. **Mix of negative and positive:** [-4, -1, 0, 3, 10]
5. **Contains zero:** Zero squared is still zero
6. **Symmetric around zero:** [-3, -2, 0, 2, 3] → [0, 4, 4, 9, 9]
7. **All same absolute value:** [-2, -2, 2, 2] → [4, 4, 4, 4]
8. **Very large negatives:** Squared values may be large — check int overflow

<br>

---

## Solution: Two Pointers (Opposite Direction)

**Intuition:**
In a sorted array with negatives, the largest squared values are at the ends (large negative or large positive). Use two pointers at both ends, compare absolute values, and fill the result array from the back.

**Algorithm:**
1. Create result array of size n
2. left = 0, right = n-1, write = n-1
3. While left <= right:
   - If |nums[left]| > |nums[right]|: result[write] = nums[left]², left++
   - Else: result[write] = nums[right]², right--
   - write--
4. Return result

<br>

### Time Complexity: O(n) — single pass
### Space Complexity: O(n) — result array (required by output)

<br>
<br>

---

```code```
