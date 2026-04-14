Invert a binary tree (mirror it). Swap every left and right child.

<br>

> Input: root = [4,2,7,1,3,6,9]
> Output: [4,7,2,9,6,3,1]

> Explanation: Every node's left and right children are swapped. The tree is mirrored.
> 
> **Key insight:** Recursively swap left and right children at every node. Base case: null node → return null.

<br>

---

## Constraints
- `0 ≤ N ≤ 100`

<br>

---

## Solution 1: BFS level-order swap

**Intuition:**
The most straightforward approach — both bfs and recursive dfs work.

**Algorithm:**
1. Apply the naive/brute approach as described
2. Check all possibilities or use a simpler data structure
3. Return the result

### Time Complexity: O(N)
**Why?**
The brute approach doesn't exploit the problem's structure efficiently, leading to redundant work.

**Detailed breakdown:**
For typical constraint sizes, this approach may be too slow or use too much space.

### Space Complexity: O(1) or O(N) depending on approach

> **Drawback:**
> Both BFS and recursive DFS work. Recursive is more elegant.

> **Key Insight for Improvement:**
> Use Recursive Swap (Optimal) for O(N) time.

<br>

---

## Solution 2: Recursive Swap (Optimal)

**Algorithm:**
1. If root null → return null
2. Swap root.left and root.right
3. Recursively invert left subtree
4. Recursively invert right subtree
5. Return root

### Time Complexity: O(N)
**Why?** Visit every node once, O(1) swap each.

**Detailed breakdown:** N = 100 → 100 operations

### Space Complexity: O(H)

> **Drawback:** Recursive. Iterative BFS/DFS alternative possible.

> **Key Insight for Improvement:** Already optimal. The "Homebrew incident" made this problem famous — elegant 4-line solution.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Recursive | O(N) | O(H) |
| Iterative BFS | O(N) | O(W) |

**Key Insights:**
1. **Swap at every level:** Not just leaves — every node's children swap
2. **Order doesn't matter:** Can swap before or after recursing (pre/post-order both work)
3. **Inverting twice = original:** Involution property

<br><br>

---

```code```
