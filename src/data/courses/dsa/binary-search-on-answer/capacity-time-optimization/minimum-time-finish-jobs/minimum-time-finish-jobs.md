Minimize maximum working time distributing jobs to workers.

<br>

> jobs=[3,2,3], K=3 → 3 (one job each)
>
> **Key insight:** Binary search on max time + backtracking feasibility check.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## All Possible Edge Cases
1. **Empty/single element input**
2. **Boundary values** (min/max of range)
3. **All elements same / sorted / reverse sorted**

<br>

---

## Solution 1: Try all assignments

**Intuition:**
The most straightforward approach. Exponential — assigning N jobs to K workers.

**Algorithm:**
1. Enumerate all possible candidates
2. For each candidate, verify if it satisfies the condition
3. Track the best valid result
4. Return the optimal answer

### Time Complexity: O(K^N)
**Why?**
Single pass through the input, doing O(1) work per element.
Total: N elements × O(1) per element = O(N).

**Detailed breakdown:**
For N=100,000: ~100,000 operations — very efficient.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Exponential — assigning N jobs to K workers.

> **Key Insight for Improvement:**
> BS on max time: check if jobs can be assigned so no worker exceeds limit. Backtracking for exact check.

<br>

---

## Solution 2: BS on Answer + Backtracking (Optimal)

**Intuition:** Binary search on max time + backtracking feasibility check.

**Algorithm:**
1. lo=max(jobs), hi=sum(jobs)
2. Binary search: canFinish(mid, K) → backtracking assignment
3. Sort jobs descending for better pruning

### Time Complexity: O(N log S × K^N worst)
**Why?**
Each element/state processed efficiently via the core technique.

**Detailed breakdown:**
Operations scale with input size as described by the complexity.

**Example walkthrough:**
```
jobs=[3,2,3] K=3 mid=3: assign [3],[2],[3] → all ≤ 3 → feasible
```

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Try all assignments | O(K^N) | Varies | Baseline |
| BS on Answer + Backtracking | O(N log S × K^N worst) | O(N) | Optimal approach |

**Recommended Solution:** BS on Answer + Backtracking — O(N log S × K^N worst) time.

**Key Insights:**
1. **Backtracking check:** Not always greedy — may need exact search
2. **Sort descending:** Large jobs first prunes search space
3. **Harder variant:** Unlike greedy-checkable problems

<br><br>

---

```code```
