Implement core binary tree operations: insert a node, search for a value, and delete a node.

<br>

> Input: Insert 5, 3, 7, 1, 4. Search 4. Delete 3.
> Output: Search=true. After delete: tree restructured.

> Explanation: Build BST by insertion rules. Search traverses left/right. Delete handles 3 cases: leaf, one child, two children.
> 
> **Key insight:** Insert/Search follow BST property (left < root < right). Delete with two children: replace with inorder successor (smallest in right subtree), then delete the successor.

<br>

---

## Constraints
- Nodes contain integer values

<br>

---

## All Possible Edge Cases
1. **Empty tree:** Insert creates root
2. **Delete leaf:** Simply remove
3. **Delete node with one child:** Replace with child
4. **Delete node with two children:** Replace with inorder successor

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
> Self-balancing BSTs (AVL, Red-Black) guarantee O(log N) height. But understanding the basic BST operations is essential before learning balanced variants.

<br>

---

## Solution 2: Recursive BST Operations (Optimal)

**Insert:** Compare with root → go left or right recursively. Create node at null position.

**Search:** Compare → go left or right. Return true if found, false at null.

**Delete (3 cases):**
1. Leaf → return null
2. One child → return that child
3. Two children → find inorder successor, copy value, delete successor

### Time Complexity: O(H) per operation
**Why?**
- H = height of tree
- Balanced tree: H = log N → O(log N)
- Skewed tree: H = N → O(N)

**Detailed breakdown:**
- Balanced BST with 1,000,000 nodes: H ≈ 20 → 20 comparisons per operation
- Skewed (linked list): 1,000,000 comparisons — need self-balancing BST

### Space Complexity: O(H) for recursion stack

> **Drawback:**
> Regular BST can degrade to O(N) if insertions are sorted. Height becomes N instead of log N.

> **Key Insight for Improvement:**
> Self-balancing BSTs (AVL, Red-Black) guarantee O(log N) height. But understanding the basic BST operations is essential before learning balanced variants.

<br>

---

## Complexity Progression Summary

| Operation | Balanced | Skewed |
|-----------|----------|--------|
| Insert | O(log N) | O(N) |
| Search | O(log N) | O(N) |
| Delete | O(log N) | O(N) |

**Key Insights:**
1. **BST property:** Left < Root < Right — enables binary search
2. **Delete with 2 children:** Inorder successor preserves BST property
3. **Height matters:** All ops are O(H) — motivation for balanced trees

<br><br>

---

```code```
