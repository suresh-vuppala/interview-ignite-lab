Given n non-negative integers representing vertical lines, find two lines that together with the x-axis form a container holding the most water.

<br>

> Input:
> height = [1, 8, 6, 2, 5, 4, 8, 3, 7]

> Output:
> 49

> Explanation:
> Lines at index 1 (h=8) and index 8 (h=7). Area = min(8,7) × (8-1) = 7 × 7 = 49.
> 
> **Key insight:** Start with the widest container (both ends). The SHORTER line limits the area. Moving the taller line can only decrease width without increasing height — so always move the shorter one.

<br>



---

## Constraints

- `2 ≤ n ≤ 10⁵`
- `0 ≤ height[i] ≤ 10⁴`

<br>

---

## All Possible Edge Cases

1. **Two elements:** Only one possible container
2. **All same height:** Width matters most — widest wins
3. **Ascending order:** Max at first and last
4. **Tallest at center:** May not be part of max area

<br>

---

## Solution 1: Brute Force — Check All Pairs

**Intuition:**
Calculate area for every pair of lines. Track maximum.

**Algorithm:**
1. For each i from 0 to n-2:
   - For each j from i+1 to n-1:
     - area = min(height[i], height[j]) × (j - i)
     - maxArea = max(maxArea, area)

### Time Complexity: O(N²)
**Why?**
- N(N-1)/2 pairs
- Each area calculation: O(1)

**Detailed breakdown:**
- N = 100,000 → ~5 billion pair checks — TLE

### Space Complexity: O(1)
**Why?**
- Only tracking maxArea

> **Drawback:**
> Checking all O(N²) pairs. Most pairs are clearly suboptimal. We're not using any structure to eliminate bad pairs — specifically, we're not leveraging the fact that moving the taller line inward can never help.

> **Key Insight for Improvement:**
> Start with the widest container (left=0, right=n-1). The shorter side limits water height. Moving the TALLER side inward only decreases width without potentially increasing height (height is still limited by the short side). So always move the SHORTER side — it might find a taller line. This greedy approach never misses the optimal pair.

<br>

---

## Solution 2: Two Pointers — Move Shorter Side (Optimal)

**Intuition:**
Area = min(h[left], h[right]) × (right - left). Moving the shorter side is the only way to potentially increase the min-height, since width decreases regardless.

**Algorithm:**
1. left = 0, right = n-1, maxArea = 0
2. While left < right:
   - area = min(h[left], h[right]) × (right - left)
   - maxArea = max(maxArea, area)
   - If h[left] < h[right] → left++ (move shorter side)
   - Else → right--

### Time Complexity: O(N)
**Why?**
- Each iteration: left++ or right--
- Total: at most N iterations

**Detailed breakdown:**
- N = 100,000 → 100,000 iterations
- Compared to brute: 5,000,000,000 → 100,000 (50,000× faster!)

**Example walkthrough:**
```
height = [1, 8, 6, 2, 5, 4, 8, 3, 7]

left=0(h=1), right=8(h=7): area=1×8=8, h[0]<h[8] → left++
left=1(h=8), right=8(h=7): area=7×7=49, h[8]<h[1] → right--
left=1(h=8), right=7(h=3): area=3×6=18, h[7]<h[1] → right--
left=1(h=8), right=6(h=8): area=8×5=40, equal → right--
... continues ...

maxArea = 49 ✓
```

**Why greedy works (proof sketch):**
- When h[left] < h[right], ANY container with left and a different right has:
  - width ≤ (right - left)
  - height ≤ h[left] (because left is the shorter side)
  - area ≤ h[left] × (right - left) = current area
- So we can safely discard all pairs involving current left → move left right

### Space Complexity: O(1)
**Why?**
- Only pointer variables and maxArea

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N²) | O(1) | All pairs |
| Two Pointers | O(N) | O(1) | Greedy: always move the shorter side |

**Recommended Solution:** Two Pointers (Solution 2) — O(N) time, O(1) space.

**Key Insights:**
1. **Shorter side limits area:** Moving taller side can never increase min-height
2. **Greedy proof:** Moving shorter side eliminates all suboptimal pairs involving it
3. **Width vs height tradeoff:** Start widest, sacrifice width for taller lines


<br>
<br>

---

```code```
