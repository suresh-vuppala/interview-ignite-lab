Generate all N! permutations of an array.

<br>

> nums=[1,2,3] → [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
>
> **Key insight:** Backtracking: for each position, try all unused elements. Swap-based: swap element at current position with each remaining.

<br>

---

## Constraints
- 1 ≤ N ≤ 8
- All elements distinct

<br>

---

## All Possible Edge Cases
1. **Single element: 1 permutation
2. **N! permutations total
3. **All distinct elements assumed**

<br>

---

## Solution 1: Same — backtracking IS the approach

**Intuition:**
The most straightforward approach. N! permutations exist — must generate all.

**Algorithm:**
1. Define recursive function with current state
2. At each step, try all possible choices
3. Recurse on remaining subproblem
4. Base case: return when subproblem is solved

### Time Complexity: O(N×N!)
**Why?**
Generating all permutations requires N! arrangements.
Each permutation requires O(N) work to construct and verify.

**Detailed breakdown:**
For N=10: ~3.6 million. For N=12: ~479 million. For N=15: ~1.3 trillion — infeasible.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> N! permutations exist — must generate all.

> **Key Insight for Improvement:**
> Swap-based backtracking: swap current position with each element from current to end, recurse, swap back.

<br>

---

## Solution 2: Swap-Based Backtracking (Optimal)

**Intuition:** Backtracking: for each position, try all unused elements. Swap-based: swap element at current position with each remaining.

**Algorithm:**
1. permute(index):
2. If index == N: add arr copy to result
3. For i = index to N-1:
   - Swap arr[index] and arr[i]
   - permute(index + 1)
   - Swap back (backtrack)

### Time Complexity: O(N × N!)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
[1,2,3]: swap(0,0)→[1,2,3]→permute(1)→...6 permutations
```

### Space Complexity: O(N) stack

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Same — backtracking IS the approach | O(N×N!) | Varies | Baseline |
| Swap-Based Backtracking | O(N × N!) | O(N) stack | Optimal |

**Recommended Solution:** Swap-Based Backtracking

**Key Insights:**
1. **Swap-based:** In-place, no extra used[] array needed
2. **N! total:** Each of N positions has decreasing choices
3. **FAANG classic:** Foundation for permutation problems

<br><br>

---

```code```
