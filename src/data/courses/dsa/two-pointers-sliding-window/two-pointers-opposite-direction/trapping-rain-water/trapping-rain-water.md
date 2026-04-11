Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

<br>

> Input:
> height = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]

> Output:
> 6

> Explanation:
> Water trapped at each position = min(leftMax, rightMax) - height[i]
> 
> Position:  0  1  2  3  4  5  6  7  8  9  10 11
> Height:    0  1  0  2  1  0  1  3  2  1  2  1
> LeftMax:   0  1  1  2  2  2  2  3  3  3  3  3
> RightMax:  3  3  3  3  3  3  3  3  2  2  2  1
> Water:     0  0  1  0  1  2  1  0  0  1  0  0  = 6
> 
> **Key insight:** Water at position i = min(max height to left, max height to right) - height[i]

<br>

---

## Constraints

- `1 ≤ height.length ≤ 2 × 10⁴`
- `0 ≤ height[i] ≤ 10⁵`

<br>

---

## All Possible Edge Cases

1. **Empty or single element:** No water can be trapped
2. **Two elements:** No water — need at least 3 bars
3. **Monotonically increasing:** [1,2,3,4,5] → 0 water trapped
4. **Monotonically decreasing:** [5,4,3,2,1] → 0 water trapped
5. **All same height:** [3,3,3,3] → 0 water
6. **All zeros:** 0 water
7. **V-shape:** [3,0,3] → 3 units of water
8. **Single valley:** [2,0,2] → 2 units
9. **Multiple valleys:** [3,0,1,0,3] → multiple pools
10. **Large heights with small gaps:** Potential integer overflow when summing

<br>

---

## Solution 1: Prefix Max Arrays

**Intuition:**
Precompute leftMax[i] (max height from 0 to i) and rightMax[i] (max height from i to n-1). Water at i = min(leftMax[i], rightMax[i]) - height[i].

**Algorithm:**
1. Build leftMax array (scan left to right)
2. Build rightMax array (scan right to left)
3. Sum up min(leftMax[i], rightMax[i]) - height[i] for each i

### Time Complexity: O(n) — three passes
### Space Complexity: O(n) — two auxiliary arrays

<br>

---

## Solution 2: Two Pointers (Optimal)

**Intuition:**
Instead of precomputing arrays, track running leftMax and rightMax with two pointers. Process whichever side has the smaller max — that side's water calculation is guaranteed correct.

**Algorithm:**
1. Initialize left = 0, right = n-1, leftMax = 0, rightMax = 0, water = 0
2. While left < right:
   - If height[left] < height[right]:
     - If height[left] >= leftMax: update leftMax
     - Else: water += leftMax - height[left]
     - left++
   - Else:
     - If height[right] >= rightMax: update rightMax
     - Else: water += rightMax - height[right]
     - right--
3. Return water

**Why this works:**
- When height[left] < height[right], we know rightMax >= height[right] > height[left]
- So min(leftMax, rightMax) for left position is determined by leftMax alone
- We can safely calculate water at left position using leftMax

<br>

### Time Complexity: O(n) — single pass
### Space Complexity: O(1) — only pointer and max variables

<br>

---

## Comparison

| Approach | Time | Space | Notes |
|----------|------|-------|-------|
| Brute Force | O(n²) | O(1) | For each position, scan left and right for max |
| Prefix Max | O(n) | O(n) | Precompute leftMax and rightMax arrays |
| Two Pointers | O(n) | O(1) | Optimal — single pass, constant space |
| Stack | O(n) | O(n) | Process by layers (horizontal) |

> **Recommended:** Two Pointers — O(n) time, O(1) space

<br>
<br>

---

```code```
