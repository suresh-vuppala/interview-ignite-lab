Check whether a binary tree is a mirror of itself (symmetric around its center).

<br>

> Input: root = [1,2,2,3,4,4,3]
> Output: true

> Explanation: Left subtree mirrors right subtree: 2↔2, 3↔3, 4↔4.
> 
> **Key insight:** A tree is symmetric if its left subtree is a mirror of its right subtree. Recursively check: left.val == right.val AND left.left mirrors right.right AND left.right mirrors right.left.

<br>

---

## Constraints
- `1 ≤ N ≤ 1000`

<br>

---

## All Possible Edge Cases
1. **Single node:** symmetric
2. **Left subtree ≠ mirror of right
3. **Null tree:** symmetric
4. **Values match but structure doesn't mirror**

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
> Use Recursive Mirror Check (Optimal) for optimal performance.

<br>

---

## Solution 2: Recursive Mirror Check (Optimal)

**Algorithm:**
1. isMirror(left, right):
   - Both null → true
   - One null → false
   - Values differ → false
   - Return isMirror(left.left, right.right) AND isMirror(left.right, right.left)
2. Return isMirror(root.left, root.right)

### Time Complexity: O(N)
**Why?** Each node visited once.

**Detailed breakdown:** N = 1000 → 1000 comparisons

### Space Complexity: O(H)

> **Drawback:** Recursive. Iterative BFS alternative processes pairs level by level.

> **Key Insight for Improvement:** Iterative: use queue of pairs (left, right). Enqueue (left.left, right.right) and (left.right, right.left). Same O(N) but no recursion stack risk.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursive | O(N) | O(H) | Mirror comparison |
| Iterative BFS | O(N) | O(W) | Queue of pairs |

**Key Insights:**
1. **Mirror comparison:** Compare outer children and inner children
2. **Symmetric ≠ Identical:** Symmetric checks mirror, identical checks exact match
3. **Cross-comparison:** left.left↔right.right and left.right↔right.left

<br><br>

---

```code```
