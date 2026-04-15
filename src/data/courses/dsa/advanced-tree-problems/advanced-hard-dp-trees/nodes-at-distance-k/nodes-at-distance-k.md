Find all nodes at distance K from a target node in a binary tree.

<br>

> root=[3,5,1,6,2,0,8,null,null,7,4], target=5, K=2 → [7,4,1]
>
> **Key insight:** Convert tree to graph (add parent pointers). BFS from target for K levels.

<br>

---

## Constraints
- 1 ≤ N ≤ 500
- 0 ≤ K ≤ 1000

<br>

---

## All Possible Edge Cases
1. **K = 0: only the target node
2. **K exceeds tree depth: empty result
3. **Target is root: only downward nodes
4. **Target is leaf: must go upward through parent**

<br>

---

## Solution 1: DFS from every node checking distance

**Intuition:**
The most straightforward approach. Checking from every node is quadratic.

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
> Checking from every node is quadratic.

> **Key Insight for Improvement:**
> Parent map + BFS: build parent pointers, then BFS from target K levels in all directions (children + parent).

<br>

---

## Solution 2: Parent Map + BFS (Optimal)

**Intuition:** Convert tree to graph (add parent pointers). BFS from target for K levels.

**Algorithm:**
1. DFS to build parent map: parent[child] = parent_node
2. BFS from target node, K levels
3. Track visited to avoid revisiting
4. All nodes at level K = answer

### Time Complexity: O(N)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
Target=5, K=2: BFS level 0=[5], level 1=[6,2,3(parent)], level 2=[7,4,1] ✓
```

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| DFS from every node checking distance | O(N²) | Varies | Baseline |
| Parent Map + BFS | O(N) | O(N) | Optimal |

**Recommended Solution:** Parent Map + BFS

**Key Insights:**
1. **Parent map:** Enables upward traversal in tree
2. **BFS K levels:** Distance = BFS level
3. **Visited set:** Prevents going back to already-explored nodes

<br><br>

---

```code```
