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

## Solution: Recursive with Upper Bound (Optimal)

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
