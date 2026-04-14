Find the size of the largest BST subtree within a binary tree.

<br>

> Binary tree with some BST subtrees → size of largest
>
> **Key insight:** Postorder: each node returns (isBST, size, min, max). If both children are BSTs and values in range → current subtree is BST.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: Check every subtree

**Intuition:**
The most straightforward approach. Checking each subtree from scratch is quadratic.

**Algorithm:**
1. Enumerate all possible candidates
2. For each candidate, verify if it satisfies the condition
3. Track the best valid result
4. Return the optimal answer

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
> Checking each subtree from scratch is quadratic.

> **Key Insight for Improvement:**
> Postorder DFS: merge bottom-up. Each node reports its BST status and range. O(N) total.

<br>

---

## Solution 2: Postorder BST Validation (Optimal)

**Intuition:** Postorder: each node returns (isBST, size, min, max). If both children are BSTs and values in range → current subtree is BST.

**Algorithm:**
1. DFS returns (isBST, size, min, max)
2. Leaf: (true, 1, val, val)
3. Node: if left.isBST and right.isBST and left.max < val < right.min:
   → (true, left.size+right.size+1, left.min, right.max)
4. Track global max size

### Time Complexity: O(N)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
Check each subtree bottom-up. Merge BST properties upward.
```

### Space Complexity: O(H)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Check every subtree | O(N²) | Varies | Baseline |
| Postorder BST Validation | O(N) | O(H) | Optimal |

**Recommended Solution:** Postorder BST Validation

**Key Insights:**
1. **Bottom-up merging:** Each node checked once
2. **Four values:** isBST, size, min, max propagated upward
3. **O(N) vs O(N²):** Postorder avoids redundant checks

<br><br>

---

```code```
