Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

<br>

> Input:
> height = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]

> Output:
> 6

> Explanation:
> Water fills the valleys between tall bars. Total trapped = 6 units.
> 
> **Key insight:** Water at position i = min(maxLeft, maxRight) - height[i]. The shorter surrounding wall limits the water level.

<br>



---

## Constraints

- `1 ≤ n ≤ 2 × 10⁴`
- `0 ≤ height[i] ≤ 10⁵`

<br>

---

## All Possible Edge Cases

1. **Flat surface:** [1,1,1] → 0 (no valleys)
2. **Ascending/Descending:** [1,2,3] → 0 (water runs off)
3. **Single valley:** [3,0,3] → 3
4. **Single element:** → 0
5. **All zeros:** → 0

<br>

---

## Solution 1: Brute Force — Per-Position Left/Right Scan

**Intuition:**
For each position i, find the tallest bar to its left and the tallest to its right. Water at i = min(maxLeft, maxRight) - height[i] (if positive).

**Algorithm:**
1. For each index i (1 to n-2):
   - maxLeft = max(height[0..i])
   - maxRight = max(height[i..n-1])
   - water += max(0, min(maxLeft, maxRight) - height[i])
2. Return total water

### Time Complexity: O(N²)
**Why?**
- For each of N positions: scan left O(N) + scan right O(N)
- Total: N × 2N = O(N²)

**Detailed breakdown:**
- N = 20,000 → 20,000 × 40,000 = 800,000,000 — borderline TLE
- Recomputing maxLeft/maxRight from scratch each time is the bottleneck

### Space Complexity: O(1)
**Why?**
- Only variables for max values and water count

> **Drawback:**
> For each position, we scan the entire left and right sides to find maximums — O(N) per position × N positions = O(N²). We're recomputing the same prefix and suffix maximums repeatedly.

> **Key Insight for Improvement:**
> Precompute leftMax[i] and rightMax[i] arrays in O(N) each. Then water[i] = min(leftMax[i], rightMax[i]) - height[i] in a single O(N) pass.

<br>

---

## Solution 2: Prefix Max Arrays

**Intuition:**
Build two arrays: leftMax[i] = max height from 0 to i, rightMax[i] = max height from i to n-1. Water at each position is determined by the lower of the two surrounding maximums.

**Algorithm:**
1. Build leftMax: leftMax[0] = height[0], leftMax[i] = max(leftMax[i-1], height[i])
2. Build rightMax: rightMax[n-1] = height[n-1], rightMax[i] = max(rightMax[i+1], height[i])
3. For each i: water += min(leftMax[i], rightMax[i]) - height[i]
4. Return water

### Time Complexity: O(N)
**Why?**
- leftMax pass: O(N)
- rightMax pass: O(N)
- Water calculation: O(N)
- Total: 3N = O(N)

**Detailed breakdown:**
- N = 20,000 → 60,000 operations
- Compared to brute: 800,000,000 → 60,000 (13,333× faster!)

### Space Complexity: O(N)
**Why?**
- Two extra arrays of size N

> **Drawback:**
> Uses O(N) extra space for the two prefix/suffix arrays. Can we eliminate these arrays and achieve O(1) space?

> **Key Insight for Improvement:**
> Two pointers from both ends. Track maxLeft and maxRight as running values. Process from the SHORTER side: when height[left] < height[right], water at left is determined by maxLeft (since something taller exists on the right). No arrays needed — just two variables.

<br>

---

## Solution 3: Two Pointers (Optimal)

**Intuition:**
Left and right pointers converge. The side with the shorter max determines the water level. If height[left] < height[right], process left (water = maxLeft - height[left]). Otherwise process right.

**Algorithm:**
1. left = 0, right = n-1, maxLeft = 0, maxRight = 0, water = 0
2. While left < right:
   - If height[left] < height[right]:
     - If height[left] ≥ maxLeft → update maxLeft
     - Else → water += maxLeft - height[left]
     - left++
   - Else:
     - If height[right] ≥ maxRight → update maxRight
     - Else → water += maxRight - height[right]
     - right--
3. Return water

### Time Complexity: O(N)
**Why?**
- Each iteration: left++ or right--
- Total: exactly N iterations

**Detailed breakdown:**
- N = 20,000 → exactly 20,000 operations
- Same time as prefix arrays but O(1) space!

**Why process the shorter side?**
- If height[left] < height[right], we KNOW there's a taller bar on the right (at least height[right])
- So water at left depends only on maxLeft: water = maxLeft - height[left]
- The right side won't be the limiting factor

**Example walkthrough:**
```
height = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]

left=0, right=11, mL=0, mR=0, water=0

h[0]=0 < h[11]=1: h[0]=0 ≥ mL=0 → mL=0, left=1
h[1]=1 ≥ h[11]=1: h[11]=1 ≥ mR=0 → mR=1, right=10
h[1]=1 < h[10]=2: h[1]=1 ≥ mL=0 → mL=1, left=2
h[2]=0 < h[10]=2: h[2]=0 < mL=1 → water+=1-0=1, left=3
h[3]=2 ≥ h[10]=2: h[10]=2 ≥ mR=1 → mR=2, right=9
h[3]=2 ≥ h[9]=1: h[9]=1 < mR=2 → water+=2-1=1, right=8
h[3]=2 ≥ h[8]=2: h[8]=2 ≥ mR=2 → mR=2, right=7
h[3]=2 < h[7]=3: h[3]=2 ≥ mL=1 → mL=2, left=4
h[4]=1 < h[7]=3: h[4]=1 < mL=2 → water+=2-1=1, left=5
h[5]=0 < h[7]=3: h[5]=0 < mL=2 → water+=2-0=2, left=6
h[6]=1 < h[7]=3: h[6]=1 < mL=2 → water+=2-1=1, left=7

left=7 ≥ right=7 → stop. Total water = 1+1+1+2+1 = 6 ✓
```

### Space Complexity: O(1)
**Why?**
- Only 4 variables: left, right, maxLeft, maxRight

**Why this is optimal:**
- Must examine each element: O(N) minimum
- O(1) space — can't do better

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N²) | O(1) | Scan left/right max per position |
| Prefix Max Arrays | O(N) | O(N) | Precompute max arrays |
| Two Pointers | O(N) | O(1) | Process shorter side, running max |

**Recommended Solution:** Two Pointers (Solution 3) — O(N) time, O(1) space.

**Key Insights:**
1. **Brute → Prefix:** Precompute avoids redundant max scans
2. **Prefix → Two Pointers:** Shorter side determines water level — no arrays needed
3. **Core formula:** water[i] = min(maxLeft, maxRight) - height[i]


<br>
<br>

---

```code```
