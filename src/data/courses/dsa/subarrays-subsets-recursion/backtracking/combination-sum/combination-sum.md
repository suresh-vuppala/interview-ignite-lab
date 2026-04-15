Find all unique combinations that sum to target. Each number can be used unlimited times.

<br>

> candidates=[2,3,6,7], target=7 → [[2,2,3],[7]]
>
> **Key insight:** Backtracking: for each candidate, include it (recurse with SAME start index for reuse) or skip to next candidate.

<br>

---

## Constraints
- 1 ≤ candidates.length ≤ 30
- 2 ≤ candidates[i] ≤ 40
- 1 ≤ target ≤ 40

<br>

---

## All Possible Edge Cases
1. **Target = 0: empty combination
2. **No valid combination
3. **Same candidate used multiple times
4. **Target < smallest candidate**

<br>

---

## Solution 1: Try all combinations

**Intuition:**
The most straightforward approach. Exponential but necessary — must explore all valid combinations.

**Algorithm:**
1. Enumerate all possible candidates
2. For each candidate, verify if it satisfies the condition
3. Track the best valid result
4. Return the optimal answer

### Time Complexity: O(N^(T/min))
**Why?**
Single pass through the input, doing O(1) work per element.
Total: N elements × O(1) per element = O(N).

**Detailed breakdown:**
For N=100,000: ~100,000 operations — very efficient.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Exponential but necessary — must explore all valid combinations.

> **Key Insight for Improvement:**
> Backtracking with reuse: recurse with same index (not i+1) to allow repeated use. Skip when sum exceeds target.

<br>

---

## Solution 2: Backtracking with Reuse (Optimal)

**Intuition:** Backtracking: for each candidate, include it (recurse with SAME start index for reuse) or skip to next candidate.

**Algorithm:**
1. backtrack(start, remaining, current):
2. If remaining == 0: add current to result
3. If remaining < 0: return
4. For i = start to N-1:
   - Add candidates[i], recurse(i, remaining-candidates[i]) — SAME i for reuse
   - Remove last (backtrack)

### Time Complexity: O(N^(T/min))
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
target=7: pick 2→pick 2→pick 2→remaining=1, no candidate ≤1 →backtrack
pick 2→pick 2→pick 3→remaining=0→[2,2,3] ✓
```

### Space Complexity: O(T/min) stack

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Try all combinations | O(N^(T/min)) | Varies | Baseline |
| Backtracking with Reuse | O(N^(T/min)) | O(T/min) stack | Optimal |

**Recommended Solution:** Backtracking with Reuse

**Key Insights:**
1. **recurse(i, not i+1):** Same candidate can be reused
2. **Sorted + early termination:** If candidates[i] > remaining → break
3. **FAANG classic:** Foundation for combination problems

<br><br>

---

```code```
