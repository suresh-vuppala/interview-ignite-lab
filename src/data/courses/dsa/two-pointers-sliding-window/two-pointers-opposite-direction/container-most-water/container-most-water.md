Given heights representing vertical lines, find two lines that form a container holding the most water.

<br>

> Input: height = [1, 8, 6, 2, 5, 4, 8, 3, 7]
> Output: 49 (lines at index 1 and 8, height = min(8,7) = 7, width = 7)

<br>

---

## Constraints

- `2 ≤ n ≤ 10⁵`
- `0 ≤ height[i] ≤ 10⁴`

<br>

---

## All Possible Edge Cases

1. **Two elements:** Only one possible container
2. **All same height:** Width determines area → widest
3. **Tallest at ends:** Answer is likely the full width
4. **One zero:** That line holds no water

<br>

---

## Solution 1: Brute Force

**Intuition:** Check every pair of lines, compute area.

### Time Complexity: O(n²)
### Space Complexity: O(1)

<br>

---

## Solution 2: Two Pointers (Optimal)

**Intuition:**
Start with widest container (both ends). The shorter line limits the area. Moving the shorter line inward might find a taller line and increase area. Moving the taller line can only decrease width without improving height.

**Algorithm:**
1. left = 0, right = n-1, maxArea = 0
2. While left < right:
   - area = min(height[left], height[right]) × (right - left)
   - maxArea = max(maxArea, area)
   - Move the shorter side inward:
     - If height[left] < height[right] → left++
     - Else → right--

**Why this is correct:** We never skip a potentially better pair. The shorter line can't do better with any other partner (width can only decrease). So we discard it.

### Time Complexity: O(n) — single pass
### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(n²) | O(1) | Check all pairs |
| Two Pointers | O(n) | O(1) | Move shorter line — greedy proof |

<br>
<br>

---

```code```
