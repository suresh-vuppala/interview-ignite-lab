Schedule jobs with deadlines and profits to maximize total profit. Each job takes 1 unit of time.

<br>

> jobs=[(1,4,20),(2,1,10),(3,1,40),(4,1,30)], deadlines → max profit=60
>
> **Key insight:** Sort by profit descending. For each job, find the latest available slot before its deadline.

<br>

---

## Constraints
- Typical problem constraints apply

<br>

---

## All Possible Edge Cases
1. **Empty input:** Handle gracefully
2. **Single element:** Base case
3. **Large input:** Verify time complexity holds

<br>

---

## Solution 1: Brute Force

**Intuition:**
The most straightforward approach. Factorial permutations — completely infeasible.

**Algorithm:**
1. For each element i (outer loop):
   - For each element j (inner loop):
     - Check if the pair/condition is satisfied
2. Return the best result found

### Time Complexity: O(N!)
**Why?**
Generating all permutations requires N! arrangements.
Each permutation requires O(N) work to construct and verify.

**Detailed breakdown:**
For N=10: ~3.6 million. For N=12: ~479 million. For N=15: ~1.3 trillion — infeasible.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Factorial permutations — completely infeasible.

> **Key Insight for Improvement:**
> Greedy: highest profit first. For each job, find latest available time slot ≤ deadline. This maximizes profit.

<br>

---

## Solution 2: Sort by Profit + Greedy Slot Assignment (Optimal)

**Intuition:** Sort by profit descending. For each job, find the latest available slot before its deadline.

**Algorithm:**
1. Sort jobs by profit descending
2. Create slots array of size maxDeadline (all free)
3. For each job: find latest free slot ≤ deadline
   - If found: assign job, mark slot used, add profit
   - If not: skip job
4. Return total profit

### Time Complexity: O(N² or N log N with DSU)
**Why?**
Each element processed at most once through the core data structure/algorithm.

**Detailed breakdown:**
For typical input sizes, operations stay well within time limits.

**Example walkthrough:**
```
Jobs sorted by profit: (40,d=1),(30,d=1),(20,d=4),(10,d=1)
Slot 1: assign job(40). Slot 1 taken.
Job(30,d=1): slot 1 taken → skip
Job(20,d=4): slot 4 free → assign. Profit=40+20=60 ✓
```

### Space Complexity: O(maxDeadline)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N!) | Varies | Baseline |
| Sort by Profit + Greedy Slot Assignment | O(N² or N log N with DSU) | O(maxDeadline) | Greedy: highest profit first. For each job, find latest avai |

**Recommended Solution:** Sort by Profit + Greedy Slot Assignment — O(N² or N log N with DSU) time, O(maxDeadline) space.

**Key Insights:**
1. **Highest profit first:** Greedy ensures most valuable jobs considered first
2. **Latest slot:** Leaves earlier slots open for shorter-deadline jobs
3. **DSU optimization:** O(log N) slot finding instead of O(N) scan

<br>
<br>

---

```code```
