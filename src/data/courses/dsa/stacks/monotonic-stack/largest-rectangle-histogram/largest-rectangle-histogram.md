Find the largest rectangle area in a histogram.

<br>

> Input: heights = [2, 1, 5, 6, 2, 3]
> Output: 10 (width=2, height=5 at indices 2-3)

<br>

---

## Constraints

- `1 ≤ heights.length ≤ 10⁵`
- `0 ≤ heights[i] ≤ 10⁴`

<br>

---

## All Possible Edge Cases

1. **Single bar:** Area = height
2. **All same height:** Area = n × height
3. **Strictly increasing/decreasing:** Check all partial widths
4. **Contains zero:** Zero splits the histogram

<br>

---

## Solution 1: Brute Force

**Intuition:** For each bar, expand left and right while height ≥ current.

### Time Complexity: O(n²)
### Space Complexity: O(1)

<br>

---

## Solution 2: Monotonic Stack (Optimal)

**Intuition:**
Maintain increasing stack of indices. When a shorter bar appears, pop taller bars and calculate their area using the current position as right boundary and new stack top as left boundary.

**Algorithm:**
1. Push index 0
2. For each i (including sentinel i=n with height 0):
   - While stack not empty AND heights[i] < heights[stack.top()]:
     - height = heights[stack.pop()]
     - width = stack empty ? i : i - stack.top() - 1
     - maxArea = max(maxArea, height × width)
   - Push i

**Why stack.top()-1 as left boundary?** After popping, the new stack top is the first bar shorter than the popped bar — so everything between is ≥ popped height.

### Time Complexity: O(n) — each index pushed/popped once
### Space Complexity: O(n)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(n²) | O(1) | Expand from each bar |
| Monotonic Stack | O(n) | O(n) | Stack tracks left/right boundaries |

<br>
<br>

---

```code```
