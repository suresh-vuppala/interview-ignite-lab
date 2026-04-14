Given two binary trees root and subRoot, check if subRoot is a subtree of root.

<br>

> Input: root = [3,4,5,1,2], subRoot = [4,1,2]
> Output: true

> Explanation: The subtree rooted at node 4 in root matches subRoot exactly.
> 
> **Key insight:** For each node in root, check if the subtree rooted there is identical to subRoot. Use the "Same Tree" function as a helper.

<br>

---

## Constraints
- `1 ≤ M, N ≤ 2000`

<br>

---

## Solution 1: Naive / Brute Force Approach

**Intuition:**
Try the most straightforward method without optimization.

**Algorithm:**
1. Apply the direct/naive approach
2. May involve extra space, multiple passes, or higher time complexity
3. Serves as baseline to understand the problem before optimizing

### Time Complexity: Higher than optimal
**Why?**
Does not exploit key structural properties of the problem.

### Space Complexity: May use extra space

> **Drawback:**
> Less efficient approach exists.

> **Key Insight for Improvement:**
> Use DFS + isSameTree Helper (Optimal for interviews) for optimal performance.

<br>

---

## Solution 2: DFS + isSameTree Helper (Optimal for interviews)

**Algorithm:**
1. If root null → return false
2. If isSameTree(root, subRoot) → return true
3. Return isSubtree(root.left, subRoot) OR isSubtree(root.right, subRoot)

### Time Complexity: O(N × M)
**Why?** For each of N nodes in root, isSameTree compares up to M nodes of subRoot.

**Detailed breakdown:** N=M=2000 → worst case 4,000,000 comparisons

### Space Complexity: O(H) recursion

> **Drawback:** O(N×M) worst case. Can be optimized to O(N+M) using serialization + KMP string matching or Merkle hashing.

> **Key Insight for Improvement:** Serialize both trees to strings. Check if subRoot's string appears in root's string using KMP → O(N+M). But DFS approach is cleaner for interviews.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| DFS + isSame | O(N×M) | O(H) | Check at every node |
| Serialization+KMP | O(N+M) | O(N+M) | String matching |

**Key Insights:**
1. **Reuse isSameTree:** Clean decomposition into subproblems
2. **Every node is a candidate root:** Must check all positions
3. **Null handling:** subRoot=null → always true (empty subtree)

<br><br>

---

```code```
