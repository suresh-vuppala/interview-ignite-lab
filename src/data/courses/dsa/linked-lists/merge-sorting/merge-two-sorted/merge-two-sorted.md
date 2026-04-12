Merge two sorted linked lists into one sorted list.

<br>

> Input: l1 = [1,2,4], l2 = [1,3,4]
> Output: [1,1,2,3,4,4]
> **Key insight:** Two pointers on both lists. Compare heads, append smaller to result. When one exhausts, append the remainder of the other.

<br>

---

## Constraints
- `0 ≤ N, M ≤ 50`

<br>

---

## Solution: Merge with Dummy Node (Optimal)

**Algorithm:** Dummy node. Compare l1.val vs l2.val. Append smaller. Advance that pointer. After loop, append remaining.

### Time Complexity: O(N + M)
**Why?** Each node processed exactly once.

### Space Complexity: O(1) — reuse existing nodes

> **Drawback:** None — O(N+M) is optimal.

> **Key Insight for Improvement:** Foundation for merge-k-sorted (merge pairs iteratively or use heap) and merge sort on linked list.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Iterative merge | O(N+M) | O(1) |
| Recursive | O(N+M) | O(N+M) stack |

**Key Insights:**
1. **Dummy node:** Avoids special case for first element
2. **Append remainder:** When one list exhausts, tail.next = other list
3. **Stable sort property:** Equal elements maintain original order

<br><br>

---

```code```
