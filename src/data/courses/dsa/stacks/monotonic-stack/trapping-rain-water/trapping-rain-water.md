Given elevation map, compute how much water can be trapped after raining.

<br>

> Input: height = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
> Output: 6

> **Key insight:** Water at position i = min(maxLeft, maxRight) - height[i]

<br>

---

## Constraints

- `1 ≤ n ≤ 2 × 10⁴`
- `0 ≤ height[i] ≤ 10⁵`

<br>

---

## All Possible Edge Cases

1. **Less than 3 bars:** No water
2. **Monotonically increasing/decreasing:** No water
3. **All same height:** No water
4. **V-shape:** [3,0,3] → 3 units

<br>

---

## Solution 1: Brute Force

**Intuition:**
For each position, find max height to its left and right. Water = min(maxLeft, maxRight) - height[i].

### Time Complexity: O(n²) — scan left/right for each position
### Space Complexity: O(1)

<br>

---

## Solution 2: Prefix Max Arrays

**Intuition:**
Precompute leftMax[i] and rightMax[i] arrays. Water at i = min(leftMax[i], rightMax[i]) - height[i].

### Time Complexity: O(n) — three passes
### Space Complexity: O(n) — two extra arrays

<br>

---

## Solution 3: Two Pointers (Optimal)

**Intuition:**
Use left and right pointers. Track maxLeft and maxRight. The shorter side determines water level — process from that side.

**Algorithm:**
1. left = 0, right = n-1, maxLeft = 0, maxRight = 0, water = 0
2. While left < right:
   - If height[left] < height[right]:
     - If height[left] >= maxLeft → update maxLeft
     - Else → water += maxLeft - height[left]
     - left++
   - Else: mirror logic for right side

**Why this works:** When height[left] < height[right], we know maxRight ≥ height[right] > height[left], so water at left depends only on maxLeft.

### Time Complexity: O(n) — single pass
### Space Complexity: O(1) — just pointers

<br>

---

## Solution 4: Monotonic Stack

**Intuition:**
Maintain decreasing stack of heights. When we find a bar taller than stack top, we can trap water between the current bar, the popped bar, and the new stack top.

### Time Complexity: O(n)
### Space Complexity: O(n) for stack

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(n²) | O(1) | Find max left/right per position |
| Prefix Max | O(n) | O(n) | Precompute max arrays |
| Two Pointers | O(n) | O(1) | Shorter side determines water |
| Monotonic Stack | O(n) | O(n) | Process horizontal layers |

**Recommended:** Two Pointers — O(n) time, O(1) space.

<br>
<br>

---

```code```
