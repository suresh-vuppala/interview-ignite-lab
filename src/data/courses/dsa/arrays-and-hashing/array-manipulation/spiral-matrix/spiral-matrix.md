Given an m×n matrix, return all elements in spiral order.

<br>

> Input: [[1,2,3],[4,5,6],[7,8,9]]
> Output: [1,2,3,6,9,8,7,4,5]

<br>

---

## Constraints

- `1 ≤ m, n ≤ 10`

<br>

---

## All Possible Edge Cases

1. **1×1:** Return single element
2. **Single row:** Return left to right
3. **Single column:** Return top to bottom

<br>

---

## Solution 1: Simulation with Visited Matrix

**Intuition:**
Move in spiral direction (right→down→left→up). Mark cells as visited. Change direction when hitting boundary or visited cell.

### Time Complexity: O(m × n)
### Space Complexity: O(m × n) for visited matrix

<br>

---

## Solution 2: Shrinking Boundaries (Optimal)

**Intuition:**
Maintain top, bottom, left, right boundaries. Traverse one direction at a time, then shrink the corresponding boundary.

**Algorithm:**
1. While top ≤ bottom AND left ≤ right:
   - Traverse right: top row, left→right. Then top++
   - Traverse down: right col, top→bottom. Then right--
   - Traverse left (if top ≤ bottom): bottom row, right→left. Then bottom--
   - Traverse up (if left ≤ right): left col, bottom→top. Then left++

### Time Complexity: O(m × n)
### Space Complexity: O(1) — only boundary variables

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Visited Matrix | O(m×n) | O(m×n) | Direction change on visited |
| Shrinking Boundaries | O(m×n) | O(1) | Four boundary pointers |

<br>
<br>

---

```code```
