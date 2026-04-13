Check if a word exists in grid by following adjacent cells (each cell used once).

<br>

> board=[['A','B'],['C','D']], word='ABDC' → true
>
> **Key insight:** DFS from each cell matching first character. Mark visited during DFS. Backtrack if path doesn't match.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: Check all paths

### Time Complexity: O(M×N×4^L)

> **Drawback:**
> Same — must try all starting cells and paths.

> **Key Insight for Improvement:**
> DFS backtracking from each matching start cell. Mark cell visited during recursion, unmark on backtrack.

<br>

---

## Solution 2: DFS Backtracking (Optimal)

**Intuition:** DFS from each cell matching first character. Mark visited during DFS. Backtrack if path doesn't match.

**Algorithm:**
1. For each cell (i,j) matching word[0]: DFS(i,j,0)
2. DFS(r,c,idx): if idx==len → true
3. Check bounds, visited, char match
4. Mark visited, try 4 neighbors, unmark

### Time Complexity: O(M×N×4^L)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
board=[['A','B'],['C','D']] word='ABDC'
Start A(0,0)→B(0,1)→D(1,1)→C(1,0) → found! ✓
```

### Space Complexity: O(L) stack

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Check all paths | O(M×N×4^L) | Varies | Baseline |
| DFS Backtracking | O(M×N×4^L) | O(L) stack | Optimal |

**Recommended Solution:** DFS Backtracking

**Key Insights:**
1. **In-place marking:** Set cell to '#' to mark, restore on backtrack
2. **Early termination:** Return true immediately on first match
3. **LeetCode 79:** Classic backtracking on grid

<br><br>

---

```code```
