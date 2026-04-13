Find all unique combinations that sum to target. Each number can be used unlimited times.

<br>

> candidates=[2,3,6,7], target=7 → [[2,2,3],[7]]
>
> **Key insight:** Backtracking: for each candidate, include it (recurse with SAME start index for reuse) or skip to next candidate.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: Try all combinations

### Time Complexity: O(N^(T/min))

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
