Find the maximum depth (height) of a binary tree. Height = number of nodes along the longest root-to-leaf path.

<br>

> Input: root = [3,9,20,null,null,15,7]
> Output: 3

> Explanation: Longest path: 3→20→15 (or 3→20→7). Height = 3 nodes.
> 
> **Key insight:** height(node) = 1 + max(height(left), height(right)). Base case: null node has height 0.

<br>

---

## Constraints
- `0 ≤ number of nodes ≤ 10⁴`

<br>

---

## All Possible Edge Cases
1. **Empty tree:** Return 0
2. **Single node:** Return 1
3. **Skewed (all left):** Height = N
4. **Perfect tree:** Height = log₂(N+1)

<br>

---

## Solution 1: Recursive DFS (Optimal)

**Intuition:** Height of tree = 1 + max(height of left subtree, height of right subtree). Naturally recursive.

**Algorithm:**
1. If root is null → return 0
2. leftHeight = height(root.left)
3. rightHeight = height(root.right)
4. Return 1 + max(leftHeight, rightHeight)

### Time Complexity: O(N)
**Why?** Visit every node exactly once.

**Detailed breakdown:** N = 10,000 → 10,000 recursive calls

### Space Complexity: O(H)
**Why?** Recursion stack depth = height H. Balanced: O(log N). Skewed: O(N).

> **Drawback:**
> Recursive — uses O(H) stack space. For very deep trees, may cause stack overflow.

> **Key Insight for Improvement:**
> Iterative BFS (level-order) counts levels. Each level processed = one increment. Uses O(W) space where W = max width (typically O(N) worst case but no recursion stack risk).

<br>

---

## Solution 2: Iterative BFS — Count Levels

**Algorithm:**
1. If root null → return 0
2. queue = [root], depth = 0
3. While queue not empty:
   - Process all nodes at current level
   - Add their children to queue
   - depth++
4. Return depth

### Time Complexity: O(N)
### Space Complexity: O(W) where W = maximum width

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursive DFS | O(N) | O(H) | Natural recursion |
| Iterative BFS | O(N) | O(W) | No recursion stack risk |

**Key Insights:**
1. **Recursive formula:** height = 1 + max(leftHeight, rightHeight)
2. **Base case:** null → 0 (or null → -1 if measuring edges instead of nodes)
3. **Foundation:** Height calculation is used in balanced check, diameter, and many other tree problems

<br><br>

---

```code```
