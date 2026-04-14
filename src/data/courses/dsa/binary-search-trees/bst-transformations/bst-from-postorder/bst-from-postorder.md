Construct a BST from a given postorder traversal.

<br>

> Input: postorder = [1,7,5,12,10,8]
> Output: BST with root=8
> **Key insight:** Mirror of preorder construction. Process from RIGHT to LEFT (root is last element). Use LOWER bound. Build right subtree first, then left.

<br>

---

## Constraints
- `1 ≤ N ≤ 10⁴`

<br>

---

## Solution 1: Insert elements one by one

**Intuition:**
The most straightforward approach — same as preorder — sequential insertion can be o(n²).

**Algorithm:**
1. Apply the naive/brute approach as described
2. Check all possibilities or use a simpler data structure
3. Return the result

### Time Complexity: O(N²) worst case
**Why?**
The brute approach doesn't exploit the problem's structure efficiently, leading to redundant work.

**Detailed breakdown:**
For typical constraint sizes, this approach may be too slow or use too much space.

### Space Complexity: O(1) or O(N) depending on approach

> **Drawback:**
> Same as preorder — sequential insertion can be O(N²). Reverse bound approach is O(N).

> **Key Insight for Improvement:**
> Use Reverse Iteration with Lower Bound (Optimal) for O(N) time.

<br>

---

## Solution 2: Reverse Iteration with Lower Bound (Optimal)

**Algorithm:** Start from last element (root). build(lower_bound): if idx < 0 or postorder[idx] < bound → null. Create node. Right = build(node.val). Left = build(bound).

### Time Complexity: O(N)
### Space Complexity: O(H)

> **Drawback:** None.

> **Key Insight for Improvement:** Postorder = Left, Right, Root. Reverse = Root, Right, Left. So process from right: root first, then right subtree, then left — mirror of preorder approach.

<br>

---

**Key Insights:**
1. **Reverse postorder = Root, Right, Left:** Mirror of preorder
2. **Lower bound (not upper):** Because we process right subtree first
3. **Same O(N) technique:** Bound-based splitting

<br><br>

---

```code```
