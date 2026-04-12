Construct a binary tree from level-order traversal (with nulls marking missing children).

<br>

> Input: [3,9,20,null,null,15,7]
> Output: tree with root=3
> **Key insight:** BFS construction. Queue of parent nodes. For each parent, next two values are left and right children. Null means no child.

<br>

---

## Constraints
- `0 ≤ N ≤ 10⁴`

<br>

---

## Solution: BFS Queue Construction (Optimal)

### Time Complexity: O(N)
### Space Complexity: O(N)

> **Drawback:** None.

> **Key Insight for Improvement:** This is how LeetCode represents trees. Understanding this construction is essential for testing/debugging tree solutions.

<br>

---

**Key Insights:**
1. **Queue-based:** Process parents in order, assign children from array
2. **Null = no child:** Skip and move to next value
3. **LeetCode format:** Standard tree serialization

<br><br>

---

```code```
