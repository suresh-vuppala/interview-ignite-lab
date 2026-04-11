Count the number of leaf nodes and internal nodes in a binary tree. A leaf has no children. An internal node has at least one child.

<br>

> Input: root = [1, 2, 3, 4, 5, null, 6]
> Output: Leaves=3 (4,5,6), Internal=3 (1,2,3)

> Explanation: Nodes 4, 5, 6 have no children (leaves). Nodes 1, 2, 3 have at least one child (internal).
> 
> **Key insight:** Traverse the tree. For each node: if both children null → leaf. Otherwise → internal. Simple DFS or BFS.

<br>

---

## Constraints
- `0 ≤ N ≤ 10⁴`

<br>

---

## Solution: DFS Count (Optimal)

**Algorithm:**
1. If root null → return (0, 0)
2. If both children null → leaf! return (1, 0)
3. Else → internal. Recurse on children, add counts.

### Time Complexity: O(N)
**Why?** Visit every node once.

**Detailed breakdown:** N = 10,000 → 10,000 operations

### Space Complexity: O(H) recursion stack

> **Drawback:** Recursion uses O(H) stack. Iterative BFS alternative avoids this.

> **Key Insight for Improvement:** Both DFS and BFS are O(N) time. DFS is simpler for this problem. Note: leaves + internal = total nodes (always).

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| DFS | O(N) | O(H) |
| BFS | O(N) | O(W) |

**Key Insights:**
1. **Leaf definition:** node.left == null AND node.right == null
2. **leaves + internal = N:** Always true for any tree
3. **Full binary tree:** Every internal node has exactly 2 children → leaves = internal + 1

<br><br>

---

```code```
