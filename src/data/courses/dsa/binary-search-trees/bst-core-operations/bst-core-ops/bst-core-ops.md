Implement BST core operations: search, insert, delete, and find min/max.

<br>

> Input: Insert 5,3,7,2,4. Search 4→true. Delete 3. Min=2, Max=7.
> **Key insight:** BST property: left < root < right. Search/insert follow left/right based on comparison. Delete: 3 cases (leaf, one child, two children — replace with inorder successor).

<br>

---

## Constraints
- Node values are unique integers

<br>

---

## All Possible Edge Cases
1. **Empty tree:** insert creates root
2. **Insert duplicate:** depends on convention (left or skip)
3. **Delete leaf / one child / two children**
4. **Delete root node**
5. **Search for non-existent value**

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
> Use Recursive BST Operations (Optimal) for O(H) per operation time.

<br>

---

## Solution 2: Recursive BST Operations (Optimal)

**Algorithm:**
- Search: if val < root go left, if val > root go right, if equal found
- Insert: recurse to null position, create node
- Delete: leaf→remove, one child→replace, two children→inorder successor

### Time Complexity: O(H) per operation
**Why?** Follow one path from root to target. H = log N (balanced) to N (skewed).

**Detailed breakdown:** Balanced BST with 1M nodes: H ≈ 20 operations

### Space Complexity: O(H) recursion

> **Drawback:** Unbalanced BST degrades to O(N) per operation. Sorted insertions create a chain.

> **Key Insight for Improvement:** Self-balancing BSTs (AVL, Red-Black) guarantee H = O(log N). But basic BST operations are interview fundamentals.

<br>

---

## Complexity Progression Summary

| Operation | Balanced BST | Skewed BST |
|-----------|-------------|------------|
| Search | O(log N) | O(N) |
| Insert | O(log N) | O(N) |
| Delete | O(log N) | O(N) |

**Key Insights:**
1. **BST property enables binary search:** Each comparison eliminates half the tree
2. **Delete with 2 children:** Replace with inorder successor (smallest in right subtree)
3. **Inorder traversal = sorted:** Fundamental BST property

<br><br>

---

```code```
