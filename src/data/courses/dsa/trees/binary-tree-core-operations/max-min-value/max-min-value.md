Find the maximum and minimum values in a binary tree.

<br>

> Input: root = [4, 2, 6, 1, 3, 5, 7]
> Output: max=7, min=1

> Explanation: Traverse all nodes, track maximum and minimum values seen.
> 
> **Key insight:** Simple DFS/BFS traversal. For BST: min = leftmost node, max = rightmost node (O(H)). For general BT: must visit all nodes (O(N)).

<br>

---

## Constraints
- `1 ≤ N ≤ 10⁴`

<br>

---

## Solution 1: DFS — Visit All Nodes (General BT)

**Algorithm:** Recursively compare root value with max/min of left and right subtrees.

### Time Complexity: O(N)
**Why?** Must visit every node — any could be max or min.

**Detailed breakdown:** N = 10,000 → 10,000 comparisons

### Space Complexity: O(H)

> **Drawback:** Visits all N nodes even for BST where we could exploit sorted structure.

> **Key Insight for Improvement:** For BST: min is the leftmost node (keep going left). Max is the rightmost (keep going right). O(H) instead of O(N). But for general BT, O(N) is unavoidable.

<br>

---

## Solution 2: BST Optimization — O(H)

**Algorithm:**
- Min: follow left pointers until null. Last non-null = min.
- Max: follow right pointers until null. Last non-null = max.

### Time Complexity: O(H)
### Space Complexity: O(1) iterative

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Applies to |
|----------|------|-------|-----------|
| DFS all nodes | O(N) | O(H) | Any binary tree |
| Follow edges | O(H) | O(1) | BST only |

**Key Insights:**
1. **General BT:** Must check every node — O(N)
2. **BST:** Sorted structure → min at leftmost, max at rightmost — O(H)
3. **Always clarify:** "Is this a BST?" before choosing approach

<br><br>

---

```code```
