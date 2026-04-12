Serialize a binary tree to a string representation.

<br>

> Input: root = [1,2,3,null,null,4,5]
> Output: "1,2,3,null,null,4,5"
> **Key insight:** BFS level-order serialization including nulls. Or preorder DFS with null markers. Must include nulls to preserve structure.

<br>

---

## Constraints
- `0 ≤ N ≤ 10⁴`

<br>

---

## Solution: BFS Serialization (Optimal)

### Time Complexity: O(N)
### Space Complexity: O(N)

> **Drawback:** None.

> **Key Insight for Improvement:** Must include null markers — without them, tree structure is ambiguous. Preorder + null markers uniquely determines a tree.

<br>

---

**Key Insights:**
1. **Include nulls:** "1,2,3,null,null,4,5" — nulls mark missing children
2. **BFS = level-order format:** Same as LeetCode representation
3. **Paired with deserialize:** Must use same format for both

<br><br>

---

```code```
