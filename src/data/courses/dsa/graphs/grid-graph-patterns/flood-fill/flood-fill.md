Perform a flood fill on an image. Starting from pixel (sr, sc), change all connected pixels of the same color to newColor.

<br>

> Input: image=[[1,1,1],[1,1,0],[1,0,1]], sr=1, sc=1, color=2
> Output: [[2,2,2],[2,2,0],[2,0,1]]
> **Key insight:** DFS/BFS from starting pixel. Only visit cells with the original color. Change to new color.

<br>

---

## Constraints
- `1 ≤ m, n ≤ 50`

<br>

---

## All Possible Edge Cases
1. **New color same as original:** no change needed (avoid infinite loop!)
2. **Single pixel image**
3. **Entire image same color:** fill everything
4. **Isolated pixel:** no neighbors match

<br>

---

## Solution 1: BFS with queue

**Intuition:**
The most straightforward approach — bfs works but dfs recursive is simpler for flood fill.

**Algorithm:**
1. Apply the naive/brute approach as described
2. Check all possibilities or use a simpler data structure
3. Return the result

### Time Complexity: O(M×N)
**Why?**
The brute approach doesn't exploit the problem's structure efficiently, leading to redundant work.

**Detailed breakdown:**
For typical constraint sizes, this approach may be too slow or use too much space.

### Space Complexity: O(1) or O(N) depending on approach

> **Drawback:**
> BFS works but DFS recursive is simpler for flood fill.

> **Key Insight for Improvement:**
> Use DFS Fill (Optimal) for O(M × N) time.

<br>

---

## Solution 2: DFS Fill (Optimal)

**Algorithm:** Record original color. If same as newColor → return (no-op). DFS: change color, recurse 4 directions.

### Time Complexity: O(M × N)
### Space Complexity: O(M × N) recursion

> **Drawback:** None. Edge case: if original == newColor, must return immediately to avoid infinite loop.

> **Key Insight for Improvement:** The "original == newColor" check is critical — without it, DFS never terminates.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| DFS Fill | O(M×N) | O(M×N) |

**Key Insights:**
1. **No-op check:** If original color == newColor → return immediately
2. **Same as island exploration:** But changes color instead of sinking
3. **Paint bucket tool:** This IS how paint fill works in image editors

<br><br>

---

```code```
