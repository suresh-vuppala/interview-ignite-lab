Find the Lowest Common Ancestor (LCA) of two nodes p and q in a binary tree.

<br>

> Input: root = [3,5,1,6,2,0,8,null,null,7,4], p=5, q=1
> Output: 3

> Explanation: LCA of 5 and 1 is 3 — the deepest ancestor containing both.
> 
> **Key insight:** If both p and q are in different subtrees of a node → that node is the LCA. If both are in the same subtree → LCA is deeper. Recursive: if current == p or q, return current. If left AND right return non-null → current is LCA.

<br>

---

## Constraints
- `2 ≤ N ≤ 10⁵`, all values unique, p ≠ q, both exist in tree

<br>

---

## Solution 1: Store paths, compare

**Intuition:**
The most straightforward approach — find paths root→p and root→q, compare for last common node.

**Algorithm:**
1. Apply the naive/brute approach as described
2. Check all possibilities or use a simpler data structure
3. Return the result

### Time Complexity: O(N) time, O(N) space
**Why?**
The brute approach doesn't exploit the problem's structure efficiently, leading to redundant work.

**Detailed breakdown:**
For typical constraint sizes, this approach may be too slow or use too much space.

### Space Complexity: O(1) or O(N) depending on approach

> **Drawback:**
> Find paths root→p and root→q, compare for last common node. Uses O(N) space for paths.

> **Key Insight for Improvement:**
> Use Recursive DFS (Optimal) for O(N) time.

<br>

---

## Solution 2: Recursive DFS (Optimal)

**Algorithm:**
1. If root is null or root == p or root == q → return root
2. left = LCA(root.left, p, q)
3. right = LCA(root.right, p, q)
4. If both non-null → root is LCA (p and q in different subtrees)
5. If one is null → return the non-null one (both p,q in that subtree)

### Time Complexity: O(N)
**Why?** Visit each node at most once.

**Detailed breakdown:** N = 100,000 → at most 100,000 operations

### Space Complexity: O(H)

**Example walkthrough:**
```
Tree: [3,5,1,6,2,0,8], p=5, q=1

LCA(3, 5, 1):
  left = LCA(5, 5, 1) → returns 5 (matches p)
  right = LCA(1, 5, 1) → returns 1 (matches q)
  Both non-null → return 3 (LCA!) ✓
```

> **Drawback:** Assumes both nodes exist. If one might not exist, need a modified version with found flags.

> **Key Insight for Improvement:** For BST, LCA is simpler: compare values to determine direction. But for general BT, this DFS approach is optimal.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursive DFS | O(N) | O(H) | Split determines LCA position |

**Key Insights:**
1. **Split point = LCA:** If p and q are in different subtrees, current node is LCA
2. **Three base cases:** null → null, match p → return p, match q → return q
3. **FAANG critical:** Asked at Google, Amazon, Meta very frequently

<br><br>

---

```code```
