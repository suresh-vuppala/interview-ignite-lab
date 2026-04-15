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

## All Possible Edge Cases
1. **Empty tree**
2. **Single node (already mirror)**
3. **Verify children swapped at every level**

<br>

---

## Solution 1: Brute Force / Naive Approach

**Intuition:**
The most straightforward approach — straightforward but suboptimal.

**Algorithm:**
1. Apply the naive/brute approach as described
2. Check all possibilities or use a simpler data structure
3. Return the result

### Time Complexity: O(N²) or higher
**Why?**
The brute approach doesn't exploit the problem's structure efficiently, leading to redundant work.

**Detailed breakdown:**
For typical constraint sizes, this approach may be too slow or use too much space.

### Space Complexity: O(1) or O(N) depending on approach

> **Drawback:**
> Straightforward but suboptimal. Does redundant work that can be avoided with a better algorithm or data structure.

> **Key Insight for Improvement:**
> Use Recursive Swap (Optimal) for O(N) time.

<br>

---

## Solution 2: Recursive Swap (Optimal)

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
