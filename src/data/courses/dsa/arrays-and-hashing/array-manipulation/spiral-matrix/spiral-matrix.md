Given an m×n matrix, return all elements in spiral order.

<br>

> Input:
> [[1,2,3],[4,5,6],[7,8,9]]

> Output:
> [1,2,3,6,9,8,7,4,5]

> Explanation:
> Traverse: right along top → down right column → left along bottom → up left column → repeat inward.
> 
> **Key insight:** Maintain four boundaries (top, bottom, left, right). After traversing one direction, shrink the corresponding boundary.

<br>



---

## Constraints

- `1 ≤ m, n ≤ 10`

<br>

---

## All Possible Edge Cases

1. **Single row:** [1,2,3] → [1,2,3]
2. **Single column:** [[1],[2],[3]] → [1,2,3]
3. **1×1 matrix:** [[5]] → [5]
4. **Wide vs tall:** Different aspect ratios

<br>

---

## Solution 1: Simulation with Direction + Visited

**Intuition:**
Start at (0,0), move in current direction. When hitting boundary or visited cell, turn clockwise. Repeat until all cells visited.

**Algorithm:**
1. Create visited matrix
2. Direction array: right→down→left→up
3. Move in current direction; if blocked → turn clockwise
4. Collect elements until m×n collected

### Time Complexity: O(M × N)
**Why?**
- Visit each cell exactly once

**Detailed breakdown:**
- Matrix 10×10 → 100 operations + direction checks

### Space Complexity: O(M × N)
**Why?**
- Visited matrix of same size

> **Drawback:**
> Uses O(M×N) extra space for the visited matrix. Direction-change logic with boundary+visited checks is also error-prone.

> **Key Insight for Improvement:**
> Instead of tracking visited cells, maintain 4 boundary variables (top, bottom, left, right). After traversing right → shrink top. After down → shrink right. And so on. No extra matrix needed.

<br>

---

## Solution 2: Shrinking Boundaries (Optimal)

**Intuition:**
Four boundaries define the unvisited rectangle. Traverse one edge, then shrink that boundary. Repeat until all cells visited.

**Algorithm:**
1. top=0, bottom=m-1, left=0, right=n-1
2. While top≤bottom AND left≤right:
   - Traverse right: j from left to right → result.add(matrix[top][j]); top++
   - Traverse down: i from top to bottom → result.add(matrix[i][right]); right--
   - Traverse left (if top≤bottom): j from right to left → result.add(matrix[bottom][j]); bottom--
   - Traverse up (if left≤right): i from bottom to top → result.add(matrix[i][left]); left++

### Time Complexity: O(M × N)
**Why?**
- Each element visited exactly once across all traversals

**Detailed breakdown:**
- Matrix 10×10 → exactly 100 element accesses

**Example walkthrough:**
```
Matrix: [[1,2,3],[4,5,6],[7,8,9]]
top=0, bot=2, left=0, right=2

Step 1: Right → [1,2,3], top=1
Step 2: Down → [6,9], right=1
Step 3: Left → [8,7], bot=1
Step 4: Up → [4], left=1
Step 5: Right → [5], top=2 > bot=1 → stop

Result: [1,2,3,6,9,8,7,4,5] ✓
```

### Space Complexity: O(1) extra
**Why?**
- Only 4 boundary variables

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Simulation + Visited | O(M×N) | O(M×N) | Direction + visited tracking |
| Shrinking Boundaries | O(M×N) | O(1) | Four boundary variables |

**Recommended Solution:** Shrinking Boundaries (Solution 2) — O(M×N) time, O(1) space.

**Key Insights:**
1. **Boundaries vs visited:** Four integers replace an M×N boolean matrix
2. **Guard conditions:** Check top≤bottom before left traverse, left≤right before up traverse
3. **Pattern:** Traverse edge → shrink boundary → repeat


<br>
<br>

---

```code```
