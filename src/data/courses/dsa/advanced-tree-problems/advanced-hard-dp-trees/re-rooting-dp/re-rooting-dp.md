Solve tree DP for all possible roots efficiently in O(N).

<br>

> Compute answer for every possible root without re-running DFS each time
>
> **Key insight:** First DFS: compute answer rooted at node 0. Second DFS: transition answer when moving root from parent to child.

<br>

---

## Constraints
- 1 ≤ N ≤ 10⁵

<br>

---

## All Possible Edge Cases
1. **Star graph (one center, all leaves)
2. **Linear chain: rerooting shifts values
3. **Single node: trivial**

<br>

---

## Solution 1: Run DFS from each node

**Intuition:**
The most straightforward approach. N separate DFS runs.

**Algorithm:**
1. Define recursive function with current state
2. At each step, try all possible choices
3. Recurse on remaining subproblem
4. Base case: return when subproblem is solved

### Time Complexity: O(N²)
**Why?**
Two nested loops each running up to N iterations.
Outer loop: N iterations × Inner loop: up to N iterations = N² total operations.

**Detailed breakdown:**
For N=1,000: ~1 million operations (OK). For N=10,000: ~100 million (borderline TLE).

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> N separate DFS runs.

> **Key Insight for Improvement:**
> Two-pass: (1) root at 0, compute dp values. (2) Re-root: when moving root from u to child v, adjust dp[v] using dp[u] and subtree values.

<br>

---

## Solution 2: Two-Pass Re-Rooting (Optimal)

**Intuition:** First DFS: compute answer rooted at node 0. Second DFS: transition answer when moving root from parent to child.

**Algorithm:**
1. DFS1: root at 0, compute dp_down[v] (answer considering subtree only)
2. DFS2: for each child v of u:
   - dp_up[v] = combine(dp_up[u], dp_down[u] - contribution(v))
   - answer[v] = combine(dp_down[v], dp_up[v])

### Time Complexity: O(N)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
Root at 0: compute subtree answers. Move root to child 1: adjust by removing child's contribution from parent and adding parent's contribution.
```

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Run DFS from each node | O(N²) | Varies | Baseline |
| Two-Pass Re-Rooting | O(N) | O(N) | Optimal |

**Recommended Solution:** Two-Pass Re-Rooting

**Key Insights:**
1. **Two passes:** Down-pass (subtree) + Up-pass (re-root)
2. **Transition formula:** Problem-specific combination/removal
3. **O(N) total:** Each edge traversed twice

<br><br>

---

```code```
