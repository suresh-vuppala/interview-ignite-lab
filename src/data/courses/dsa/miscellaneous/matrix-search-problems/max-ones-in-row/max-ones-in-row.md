Find the row with maximum number of 1s in a binary matrix (rows sorted, 0s then 1s).

<br>

> matrix=[[0,0,1],[0,1,1],[1,1,1]] → row 2
>
> **Key insight:** Staircase: start top-right. Move left while 1 (better row found), move down when 0. Track best row.

<br>

---

## Constraints
- 1 ≤ M, N ≤ 100
- Rows sorted (0s then 1s)

<br>

---

## All Possible Edge Cases
1. **No 1s in any row: return -1
2. **All rows same number of 1s: first row
3. **First row has all 1s**

<br>

---

## Solution 1: Count 1s in each row

**Intuition:**
The most straightforward approach. Checking every element.

**Algorithm:**
1. Iterate through all possible candidates/states
2. For each candidate, evaluate the required condition
3. Track the best result seen so far
4. Return the optimal answer

### Time Complexity: O(M×N)
**Why?**
Two factors multiply: one from iterating elements, one from the operation per element.
Total = product of both factors.

**Detailed breakdown:**
Depends on both dimensions of the input.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Checking every element.

> **Key Insight for Improvement:**
> Staircase from top-right: go left on 1 (extends count), down on 0 (try next row).

<br>

---

## Solution 2: Staircase Search (Optimal)

**Intuition:** Staircase: start top-right. Move left while 1 (better row found), move down when 0. Track best row.

**Algorithm:**
1. Start at (0, N-1)
2. While in bounds:
   - If matrix[r][c] == 1: bestRow=r, c-- (look for more 1s)
   - Else: r++ (try next row)

### Time Complexity: O(M+N)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
Start (0,2)=1→bestRow=0,c=1. (0,1)=0→r=1. (1,1)=1→bestRow=1,c=0. (1,0)=0→r=2. (2,0)=1→bestRow=2
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Count 1s in each row | O(M×N) | Varies | Baseline |
| Staircase Search | O(M+N) | O(1) | Optimal |

**Recommended Solution:** Staircase Search

**Key Insights:**
1. **Left on 1:** Found more 1s in this row
2. **Down on 0:** This row can't beat current best
3. **O(M+N):** At most M+N steps

<br><br>

---

```code```
