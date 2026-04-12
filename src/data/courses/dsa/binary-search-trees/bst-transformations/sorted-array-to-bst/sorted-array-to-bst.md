Convert a sorted array to a height-balanced BST.

<br>

> Input: nums = [-10,-3,0,5,9]
> Output: [0,-3,9,-10,null,5] (balanced BST)
> **Key insight:** Middle element becomes root (ensures balance). Left half → left subtree, right half → right subtree. Recursively apply.

<br>

---

## Constraints
- `1 ≤ N ≤ 10⁴`

<br>

---

## Solution: Recursive Mid-Split (Optimal)

**Algorithm:** mid = (left+right)/2. root = nums[mid]. root.left = build(left, mid-1). root.right = build(mid+1, right).

### Time Complexity: O(N)
**Why?** Each element becomes a node exactly once.

### Space Complexity: O(log N) recursion (balanced by construction)

> **Drawback:** None — O(N) is optimal.

> **Key Insight for Improvement:** Choosing the middle element guarantees the tree is height-balanced (difference in subtree heights ≤ 1 at every node).

<br>

---

**Key Insights:**
1. **Middle = root:** Ensures equal-ish splits = balanced
2. **Sorted → BST:** Natural mapping via binary search structure
3. **Foundation for:** Understanding balanced BST construction

<br><br>

---

```code```
