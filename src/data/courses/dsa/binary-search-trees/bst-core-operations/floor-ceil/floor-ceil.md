Find the floor (largest value ≤ key) and ceil (smallest value ≥ key) in a BST.

<br>

> Input: BST = [8,4,12,2,6,10,14], key=5
> Output: floor=4, ceil=6
> **Key insight:** BST search-like traversal. For floor: if node.val ≤ key → candidate, go right for better. For ceil: if node.val ≥ key → candidate, go left for better.

<br>

---

## Constraints
- `1 ≤ N ≤ 10⁵`

<br>

---

## Solution 1: Inorder traversal to sorted array, binary search

**Intuition:**
The most straightforward approach — full inorder wastes time.

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
> Full inorder wastes time. BST property enables O(H) direct search.

> **Key Insight for Improvement:**
> Use BST Traversal (Optimal) for O(H) time.

<br>

---

## Solution 2: BST Traversal (Optimal)

**Algorithm:**
- Floor: if node.val == key → return. If node.val < key → update floor, go right. If node.val > key → go left.
- Ceil: mirror of floor.

### Time Complexity: O(H)
**Why?** Follow one path down the tree.

**Detailed breakdown:** Balanced BST, N=100,000 → H ≈ 17 comparisons

### Space Complexity: O(1) iterative

> **Drawback:** None — O(H) is optimal for BST.

> **Key Insight for Improvement:** Floor and ceil are used in many interval/range problems. TreeMap in Java provides these as built-in operations.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| BST traversal | O(H) | O(1) |

**Key Insights:**
1. **Floor: go right when smaller:** Smaller value is a candidate, but bigger might exist in right subtree
2. **Ceil: go left when bigger:** Bigger value is a candidate, but smaller might exist in left subtree
3. **Key not in tree:** Floor and ceil may be different nodes

<br><br>

---

```code```
