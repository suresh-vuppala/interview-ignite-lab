Rob maximum from binary tree — can't rob adjacent (parent-child) nodes.

<br>

---

## Solution 1: Recursion — Try rob/skip each node O(2^n)
## Solution 2: DFS returning (rob, skip) pair

At each node: rob = node.val + left.skip + right.skip. skip = max(left.rob, left.skip) + max(right.rob, right.skip).

### Time: O(n) | Space: O(h)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursion | O(2^n) | O(n) | Exponential choices |
| DFS (rob, skip) | O(n) | O(h) | Return pair eliminates recomputation |

<br>
<br>

---

```code```
