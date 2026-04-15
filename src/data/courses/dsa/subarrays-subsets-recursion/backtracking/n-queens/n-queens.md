Place N queens on N×N board so no two attack each other.

<br>

> n=4 → [['.Q..','...Q','Q...','..Q.'],['..Q.','Q...','...Q','.Q..']]
>
> **Key insight:** Backtracking: place one queen per row. Track attacked columns and diagonals. If no valid column in a row, backtrack.

<br>

---

## Constraints
- 1 ≤ N ≤ 9

<br>

---

## Solution 1: Try all N^N placements

**Intuition:**
The most straightforward approach. Most placements are invalid — massive waste.

**Algorithm:**
1. Enumerate all possible candidates
2. For each candidate, verify if it satisfies the condition
3. Track the best valid result
4. Return the optimal answer

### Time Complexity: O(N^N)
**Why?**
Single pass through the input, doing O(1) work per element.
Total: N elements × O(1) per element = O(N).

**Detailed breakdown:**
For N=100,000: ~100,000 operations — very efficient.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Most placements are invalid — massive waste.

> **Key Insight for Improvement:**
> Row-by-row backtracking with column/diagonal sets for O(1) conflict checking.

<br>

---

## Solution 2: Backtracking + Diagonal Sets (Optimal)

**Intuition:** Backtracking: place one queen per row. Track attacked columns and diagonals. If no valid column in a row, backtrack.

**Algorithm:**
1. Place queen in row 0, try each column
2. Check conflicts: column set, diagonal (r-c) set, anti-diagonal (r+c) set
3. If valid: mark sets, place queen, recurse to next row
4. If no valid column: backtrack

### Time Complexity: O(N!)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
n=4: row0 col1→row1 col3→row2 col0→row3 col2→valid [.Q..,...Q,Q....,..Q.]
```

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Try all N^N placements | O(N^N) | Varies | Baseline |
| Backtracking + Diagonal Sets | O(N!) | O(N) | Optimal |

**Recommended Solution:** Backtracking + Diagonal Sets

**Key Insights:**
1. **Three sets:** columns, diag (r-c), anti-diag (r+c)
2. **O(1) conflict check:** Set lookup vs scanning board
3. **FAANG classic:** Tests backtracking + optimization
4. **N! not N^N:** Column constraint means decreasing choices per row

<br><br>

---

```code```
