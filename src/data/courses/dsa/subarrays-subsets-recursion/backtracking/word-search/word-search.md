Check if a word exists in grid by following adjacent cells (each cell used once).

<br>

> board=[['A','B'],['C','D']], word='ABDC' → true
>
> **Key insight:** DFS from each cell matching first character. Mark visited during DFS. Backtrack if path doesn't match.

<br>

---

## Constraints
- 1 ≤ M, N ≤ 6
- 1 ≤ word.length ≤ 15
- Lowercase/uppercase letters

<br>

---

## All Possible Edge Cases
1. **Word longer than total cells: impossible
2. **First letter not in grid: quick reject
3. **Same cell can't be reused in one path
4. **Single cell grid, single char word**

<br>

---

## Solution 1: Check all paths

**Intuition:**
The most straightforward approach. Same — must try all starting cells and paths.

**Algorithm:**
1. Enumerate all possible candidates
2. For each candidate, verify if it satisfies the condition
3. Track the best valid result
4. Return the optimal answer

### Time Complexity: O(M×N×4^L)
**Why?**
Two factors multiply: one from iterating elements, one from the operation per element.
Total = product of both factors.

**Detailed breakdown:**
Depends on both dimensions of the input.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

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
