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

## Solution 1: Recursive preorder to string

**Intuition:**
The most straightforward approach — both bfs and dfs serialization work.

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
> Both BFS and DFS serialization work. BFS level-order is more standard.

> **Key Insight for Improvement:**
> Use BFS Serialization (Optimal) for O(N) time.

<br>

---

## Solution 2: BFS Serialization (Optimal)

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
