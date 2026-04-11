Given an array of heights representing vertical lines, find two lines that together with the x-axis form a container holding the most water.

<br>

> Input:
> height = [1, 8, 6, 2, 5, 4, 8, 3, 7]

> Output:
> 49

> Explanation:
> The max area is between index 1 (height 8) and index 8 (height 7):
> Area = min(8, 7) × (8 - 1) = 7 × 7 = 49
> 
> Two pointer process:
> - L=0(1), R=8(7): area = 1×8 = 8, move L (shorter)
> - L=1(8), R=8(7): area = 7×7 = 49 ✓, move R (shorter)
> - L=1(8), R=7(3): area = 3×6 = 18, move R
> - L=1(8), R=6(8): area = 8×5 = 40, move either
> - ... continue until L meets R
> 
> **Key insight:** Always move the pointer with smaller height — keeping the shorter line can only decrease or maintain area.

<br>

---

## Constraints

- `2 ≤ height.length ≤ 10⁵`
- `0 ≤ height[i] ≤ 10⁴`

<br>

---

## All Possible Edge Cases

1. **Two elements only:** Only one possible container
2. **All same height:** Area determined purely by distance — first and last give max
3. **Descending heights:** [5,4,3,2,1] — max area is between first and last
4. **Ascending heights:** [1,2,3,4,5] — max area is between first and last
5. **One zero height:** [0, 5] → area = 0 (water can't be held)
6. **All zeros:** Area is always 0
7. **Spike in middle:** [1, 1, 100, 1, 1] — tall bar doesn't help if partner is short
8. **Maximum at non-obvious pair:** [1, 8, 6, 2, 5, 4, 8, 3, 7] — max between index 1 and 8

<br>

---

## Solution: Two Pointers (Opposite Direction)

**Intuition:**
Start with the widest container (L=0, R=n-1). The area is limited by the shorter line. Moving the taller line inward can only reduce width with no gain, but moving the shorter line might find a taller one.

**Algorithm:**
1. Initialize left = 0, right = n-1, maxArea = 0
2. While left < right:
   - area = min(height[left], height[right]) × (right - left)
   - maxArea = max(maxArea, area)
   - If height[left] < height[right]: left++
   - Else: right--
3. Return maxArea

**Why move the shorter pointer?**
- Area = min(h[L], h[R]) × width
- If h[L] < h[R]: area is bounded by h[L]
- Moving R (taller) inward: width decreases, min height stays h[L] → area only decreases
- Moving L (shorter) inward: width decreases, but min height might increase → area might increase
- Greedy: moving shorter is the only option that might improve

<br>

### Time Complexity: O(n)
**Why?**
- Each pointer moves at most n steps total
- One pointer moves per iteration
- O(1) work per iteration
- Total: O(n)

### Space Complexity: O(1)
- Only pointer and area variables

<br>
<br>

---

```code```
