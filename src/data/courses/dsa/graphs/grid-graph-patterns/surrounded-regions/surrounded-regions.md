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

## Solution: Border DFS + Capture (Optimal)

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
