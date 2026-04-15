Add a row of nodes with a given value at a given depth in a binary tree.

<br>

> Input: root = [4,2,6,3,1,5], val = 1, depth = 2
> Output: [4,1,1,2,null,null,6,3,1,5]
> **Key insight:** Find all nodes at depth-1 using BFS or DFS. Insert new nodes between them and their children.

<br>

---

## Constraints
- `1 ≤ N ≤ 10⁴`, `1 ≤ depth ≤ N + 1`

<br>

---

## All Possible Edge Cases
1. **Depth = 1: new root with old tree as left child**
2. **Depth = max_depth + 1: add at leaf level
3. **Single node tree**

<br>

---

## Solution 1: Brute Force / Naive Approach

**Intuition:**
The most straightforward approach — straightforward but suboptimal.

**Algorithm:**
1. Apply the naive/brute approach as described
2. Check all possibilities or use a simpler data structure
3. Return the result

### Time Complexity: O(N²) or higher
**Why?**
The brute approach doesn't exploit the problem's structure efficiently, leading to redundant work.

**Detailed breakdown:**
For typical constraint sizes, this approach may be too slow or use too much space.

### Space Complexity: O(1) or O(N) depending on approach

> **Drawback:**
> Straightforward but suboptimal. Does redundant work that can be avoided with a better algorithm or data structure.

> **Key Insight for Improvement:**
> Use BFS to Depth-1, Insert (Optimal) for O(N) time.

<br>

---

## Solution 2: BFS to Depth-1, Insert (Optimal)

**Algorithm:**
1. If depth == 1: new root with val, old root as left child
2. BFS to level (depth-2). For each node at that level: create new left node (old left becomes its left), create new right node (old right becomes its right).

### Time Complexity: O(N)
### Space Complexity: O(W)

> **Drawback:** None.

> **Key Insight for Improvement:** DFS recursive approach: at depth-1, insert new nodes. Pass depth counter down.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| BFS/DFS | O(N) | O(W) or O(H) |

**Key Insights:**
1. **Insert = rewire:** New node takes the old child as ITS child
2. **Depth 1 special case:** New node becomes root
3. **Both children get new nodes:** Left and right independently

<br><br>

---

```code```
