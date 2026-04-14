Visualize recursion as a tree to analyze time complexity.

<br>

> fib(4) → tree with duplicate subtrees showing overlapping subproblems
>
> **Key insight:** Each function call = node. Branches = recursive calls. Total nodes = time complexity. Height = space complexity (stack).

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: N/A — conceptual

**Intuition:**
The most straightforward approach. N/A — analysis technique.

**Algorithm:**
1. Iterate through all possible candidates/states
2. For each candidate, evaluate the required condition
3. Track the best result seen so far
4. Return the optimal answer

### Time Complexity: N/A
**Why?**
Single pass through the input, doing O(1) work per element.
Total: N elements × O(1) per element = O(N).

**Detailed breakdown:**
For N=100,000: ~100,000 operations — very efficient.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> N/A — analysis technique.

> **Key Insight for Improvement:**
> Draw recursion tree: count nodes for time, height for space. Identify overlapping subproblems for DP.

<br>

---

## Solution 2: Recursion Tree Analysis (Optimal)

**Intuition:** Each function call = node. Branches = recursive calls. Total nodes = time complexity. Height = space complexity (stack).

**Algorithm:**
1. Root = initial call
2. Children = recursive subcalls
3. Total nodes = total function calls = time complexity
4. Height = max recursion depth = space complexity
5. Repeated subtrees = overlapping subproblems → use DP

### Time Complexity: Varies
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
fib(4): calls fib(3),fib(2). fib(3) calls fib(2),fib(1).
fib(2) computed twice → overlapping subproblem
Total nodes ≈ 2^N → O(2^N) time
```

### Space Complexity: O(depth)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| N/A — conceptual | N/A | Varies | Baseline |
| Recursion Tree Analysis | Varies | O(depth) | Optimal |

**Recommended Solution:** Recursion Tree Analysis

**Key Insights:**
1. **Nodes = time:** Count total function calls
2. **Height = space:** Maximum stack depth
3. **Repeated subtrees = DP opportunity**

<br><br>

---

```code```
