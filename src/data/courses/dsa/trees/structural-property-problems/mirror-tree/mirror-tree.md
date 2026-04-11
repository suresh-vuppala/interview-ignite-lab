Convert a binary tree to its mirror (same as invert tree). Swap left and right children at every node.

<br>

> Input: root = [1,2,3]
> Output: [1,3,2]

> Explanation: Every node's left and right children are swapped.
> 
> **Key insight:** Same as Invert Tree. Recursively swap left and right at every node.

<br>

---

## Constraints
- `0 ≤ N ≤ 100`

<br>

---

## Solution: Recursive Swap (Optimal)

**Algorithm:** If root null → return. Swap left and right. Recurse on both.

### Time Complexity: O(N)
### Space Complexity: O(H)

> **Drawback:** None — O(N) is optimal.

> **Key Insight for Improvement:** This is identical to "Invert Binary Tree." Same solution, different name.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Recursive Swap | O(N) | O(H) |

**Key Insights:**
1. **Same as Invert Tree:** Swap children at every node
2. **Mirror = Invert:** Tree becomes its own reflection

<br><br>

---

```code```
