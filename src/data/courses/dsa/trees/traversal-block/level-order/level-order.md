Return the level-order (BFS) traversal of a binary tree — nodes grouped by level.

<br>

> Input: root = [3,9,20,null,null,15,7]
> Output: [[3],[9,20],[15,7]]

> Explanation: Level 0: [3]. Level 1: [9,20]. Level 2: [15,7].
> 
> **Key insight:** BFS with a queue. Process all nodes at current level before moving to the next. Use queue size to determine level boundaries.

<br>

---

## Constraints
- `0 ≤ N ≤ 2000`

<br>

---

## All Possible Edge Cases
1. **Empty tree:** Return []
2. **Single node:** Return [[val]]
3. **Skewed tree:** Each level has exactly one node

<br>

---

## Solution 1: BFS with Queue (Optimal)

**Intuition:** Queue processes nodes in FIFO order. At each level, the queue contains exactly the nodes at that level. Process them all, add their children, move to next level.

**Algorithm:**
1. If root null → return []
2. queue = [root], result = []
3. While queue not empty:
   - levelSize = queue.size()
   - level = []
   - For i = 0 to levelSize-1: dequeue node, add val to level, enqueue children
   - Add level to result

### Time Complexity: O(N)
**Why?** Each node enqueued and dequeued exactly once.

**Detailed breakdown:** N = 2000 → 2000 queue operations

### Space Complexity: O(W) where W = max width
**Why?** Queue holds at most one level's worth of nodes. Max width = N/2 for complete tree.

> **Drawback:** None for level-order. BFS is the natural fit.

> **Key Insight for Improvement:** DFS can also produce level-order using a depth parameter and result[depth] indexing, but BFS is more intuitive.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| BFS Queue | O(N) | O(W) | Natural level-by-level processing |
| DFS + depth | O(N) | O(H) | Alternative using recursion depth |

**Key Insights:**
1. **Level boundaries:** queue.size() at start of loop = number of nodes at current level
2. **Foundation:** Level-order is used in zigzag, right-side view, average of levels, etc.
3. **BFS template:** This exact queue pattern is used in all BFS tree problems

<br><br>

---

```code```
