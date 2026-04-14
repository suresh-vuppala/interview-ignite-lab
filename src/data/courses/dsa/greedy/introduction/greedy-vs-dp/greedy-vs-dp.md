Understand when to use greedy vs dynamic programming.

<br>

> N/A — conceptual
>
> **Key insight:** Greedy works when local optimal = global optimal (greedy choice property + optimal substructure). DP when overlapping subproblems exist.

<br>

---

## Constraints
- Conceptual — no specific constraints apply

<br>

---

## All Possible Edge Cases
1. **N/A — conceptual comparison**

<br>

---

## Solution 1: Brute Force

**Intuition:**
The most straightforward approach. Not always clear which approach to use.

**Algorithm:**
1. For each element i (outer loop):
   - For each element j (inner loop):
     - Check if the pair/condition is satisfied
2. Return the best result found

### Time Complexity: O(varies)
**Why?**
The approach processes each state/element with the work described by the complexity.
Total operations scale accordingly with input size.

**Detailed breakdown:**
Verify against constraint limits to ensure it passes within time.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Not always clear which approach to use.

> **Key Insight for Improvement:**
> Greedy choice property: prove that choosing the locally best option never prevents reaching global optimum. If it can't be proven, use DP.

<br>

---

## Solution 2: Analysis Framework (Optimal)

**Intuition:** Greedy works when local optimal = global optimal (greedy choice property + optimal substructure). DP when overlapping subproblems exist.

**Algorithm:**
1. Check greedy choice property: does local optimal lead to global optimal?
2. Check optimal substructure: does optimal solution contain optimal sub-solutions?
3. If both → greedy works. If overlapping subproblems → DP.
4. Greedy examples: activity selection, Huffman coding. DP: knapsack, LCS.

### Time Complexity: O(varies)
**Why?**
Each element processed at most once through the core data structure/algorithm.

**Detailed breakdown:**
For typical input sizes, operations stay well within time limits.

**Example walkthrough:**
```
Activity Selection: greedy works (earliest end time)
0/1 Knapsack: greedy fails (must use DP)
Fractional Knapsack: greedy works (best ratio first)
```

### Space Complexity: O(varies)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(varies) | Varies | Baseline |
| Analysis Framework | O(varies) | O(varies) | Greedy choice property: prove that choosing the locally best |

**Recommended Solution:** Analysis Framework — O(varies) time, O(varies) space.

**Key Insights:**
1. **Greedy = no backtracking:** Once a choice is made, it's final
2. **DP = explore all:** Considers all subproblems, memoizes results
3. **Proof needed:** Greedy requires proving optimality — DP just works

<br>
<br>

---

```code```
