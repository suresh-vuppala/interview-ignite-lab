Construct a BST from a given preorder traversal.

<br>

> Input: preorder = [8,5,1,7,10,12]
> Output: BST with root=8, left subtree [5,1,7], right subtree [10,12]
> **Key insight:** First element = root. Use upper bound to determine which elements go left vs right. Recursive: build(preorder, bound). If next element > bound → return null (belongs to parent's right).

<br>

---

## Constraints
- `1 ≤ N ≤ 10⁴`

<br>

---

## Solution 1: Insert elements one by one into BST

**Intuition:**
The most straightforward approach — sequential insertion is o(n²) for sorted input.

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
> Sequential insertion is O(N²) for sorted input. Bound-based recursion is O(N).

> **Key Insight for Improvement:**
> Use Recursive with Upper Bound (Optimal) for O(N) time.

<br>

---

## Solution 2: Recursive with Upper Bound (Optimal)

**Algorithm:** Maintain index i. build(bound): if i >= n or preorder[i] > bound → null. Create node with preorder[i++]. Left = build(node.val). Right = build(bound).

### Time Complexity: O(N)
**Why?** Each element processed exactly once (index advances monotonically).

### Space Complexity: O(H)

> **Drawback:** None — O(N) is optimal.

> **Key Insight for Improvement:** The upper bound trick elegantly splits left/right without searching. preorder[i] > bound means this element belongs to an ancestor's right subtree.

<br>

---

**Key Insights:**
1. **Preorder: root comes first:** Process root, then left subtree, then right
2. **Upper bound determines split:** Left children must be < root, right children must be < ancestor's bound
3. **O(N) vs O(N²):** Bound approach avoids scanning for split point each time

<br><br>

---

```code```
