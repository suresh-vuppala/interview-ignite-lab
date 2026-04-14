Capture all 'O' regions surrounded by 'X'. Don't capture 'O's connected to the border.

<br>

> Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
> Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
> **Key insight:** Reverse thinking — mark border-connected 'O's as safe (DFS from borders). Then capture remaining 'O's (they're surrounded). Restore safe cells.

<br>

---

## Constraints
- `1 ≤ m, n ≤ 200`

<br>

---

## Solution 1: Brute Force / Naive Approach

**Intuition:**
The most straightforward approach — straightforward but suboptimal.

**Algorithm:**
1. Apply the naive/brute approach as described
2. Check all possibilities or use a simpler data structure
3. Return the result

### Time Complexity: O(N²) or higher
**Why?**
The brute approach doesn't exploit the problem's structure efficiently, leading to redundant work.

**Detailed breakdown:**
For typical constraint sizes, this approach may be too slow or use too much space.

### Space Complexity: O(1) or O(N) depending on approach

> **Drawback:**
> Straightforward but suboptimal. Does redundant work that can be avoided with a better algorithm or data structure.

> **Key Insight for Improvement:**
> Use Border DFS + Capture (Optimal) for O(M × N) time.

<br>

---

## Solution 2: Border DFS + Capture (Optimal)

**Algorithm:** DFS from all border 'O's → mark as 'S' (safe). Then: all remaining 'O' → 'X' (captured). All 'S' → 'O' (restored).

### Time Complexity: O(M × N)
### Space Complexity: O(M × N) for DFS

> **Drawback:** None. Reverse approach is cleaner than trying to detect "surrounded."

> **Key Insight for Improvement:** Instead of checking if each 'O' is surrounded (complex), mark the ones that AREN'T surrounded (border-connected). The rest are captured.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Border DFS | O(M×N) | O(M×N) |

**Key Insights:**
1. **Reverse thinking:** Find UNsurrounded (border-connected) instead of surrounded
2. **Three-pass:** Mark safe → capture remaining → restore safe
3. **Border DFS:** Only start DFS from 'O' cells on the grid border

<br><br>

---

```code```
