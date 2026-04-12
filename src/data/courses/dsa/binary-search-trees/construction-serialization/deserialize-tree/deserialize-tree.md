Deserialize a string back to a binary tree.

<br>

> Input: "1,2,3,null,null,4,5"
> Output: tree [1,2,3,null,null,4,5]
> **Key insight:** Reverse of serialization. BFS: parse values, use queue of parents. Each parent gets next two values as children.

<br>

---

## Constraints
- `0 ≤ N ≤ 10⁴`

<br>

---

## Solution: BFS Deserialization (Optimal)

### Time Complexity: O(N)
### Space Complexity: O(N)

> **Drawback:** None.

> **Key Insight for Improvement:** Must match serialization format exactly. BFS serialize → BFS deserialize. Preorder serialize → preorder deserialize.

<br>

---

**Key Insights:**
1. **Queue mirrors serialization:** Parents processed in same order
2. **Two values per parent:** Left child, then right child
3. **"null" = no child:** Skip node creation

<br><br>

---

```code```
