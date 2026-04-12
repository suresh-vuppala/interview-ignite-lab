Determine if a binary tree is a valid BST. Every node must satisfy: left subtree values < node < right subtree values.

<br>

> Input: root = [5,1,4,null,null,3,6]
> Output: false (4 < 5 but 3 is in right subtree of 5)
> **Key insight:** Pass valid range (min, max) down. Each node must be within its range. Left child: range (min, parent). Right child: range (parent, max). Or: inorder traversal must be strictly increasing.

<br>

---

## Constraints
- `1 ≤ N ≤ 10⁴`

<br>

---

## Solution 1: Range Validation (Optimal)

**Algorithm:** isValid(node, min, max). If node.val ≤ min or node.val ≥ max → false. Recurse: left with (min, node.val), right with (node.val, max).

### Time Complexity: O(N)
**Why?** Visit each node once.

**Detailed breakdown:** N = 10,000 → 10,000 comparisons

### Space Complexity: O(H)

> **Drawback:** Must handle INT_MIN/INT_MAX boundaries carefully.

> **Key Insight for Improvement:** Inorder traversal alternative: traverse and check if each value > previous. Simpler to implement, same O(N).

<br>

---

## Solution 2: Inorder Check — Must Be Strictly Increasing

### Time Complexity: O(N)
### Space Complexity: O(H)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Method |
|----------|------|-------|--------|
| Range validation | O(N) | O(H) | Pass (min, max) bounds |
| Inorder check | O(N) | O(H) | Prev value tracking |

**Key Insights:**
1. **Common mistake:** Only checking node > left AND node < right is WRONG — must check entire subtree range
2. **Range narrows:** Each level narrows the valid range
3. **Inorder = sorted:** If inorder traversal is strictly increasing → valid BST
4. **FAANG classic:** Tests understanding of BST invariant

<br><br>

---

```code```
