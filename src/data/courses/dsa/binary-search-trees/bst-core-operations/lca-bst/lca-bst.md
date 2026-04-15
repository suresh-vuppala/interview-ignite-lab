Find the Lowest Common Ancestor of two nodes in a BST. Exploit BST property for O(H) solution.

<br>

> Input: root = [6,2,8,0,4,7,9,null,null,3,5], p=2, q=8
> Output: 6
> **Key insight:** BST property: if both p,q < node → LCA is in left. If both > node → LCA is in right. If split (one left, one right) → current node is LCA.

<br>

---

## Constraints
- All values unique, p ≠ q, both exist

<br>

---

## All Possible Edge Cases
1. **One node is ancestor of other**
2. **Both nodes are same**
3. **Nodes in different subtrees of root → LCA = root
4. **One or both nodes not in BST**

<br>

---

## Solution 1: General BT LCA (ignore BST property)

**Intuition:**
The most straightforward approach — general lca doesn't use bst ordering.

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
> General LCA doesn't use BST ordering. BST property gives O(H) single-path descent.

> **Key Insight for Improvement:**
> Use BST-Guided Search (Optimal) for O(H) time.

<br>

---

## Solution 2: BST-Guided Search (Optimal)

**Algorithm:** Start at root. If both p,q < root → go left. If both > root → go right. Otherwise → root is LCA (split point).

### Time Complexity: O(H)
**Why?** Follow ONE path down — no branching. Much better than O(N) general BT LCA.

**Detailed breakdown:** Balanced BST, N=100,000 → H ≈ 17 comparisons

### Space Complexity: O(1) iterative

> **Drawback:** None — O(H) is optimal for BST LCA.

> **Key Insight for Improvement:** General BT LCA is O(N) because no ordering info. BST's ordering makes it O(H). Always clarify: "Is this a BST?" in interviews.

<br>

---

## Complexity Progression Summary

| Tree Type | LCA Time | Method |
|-----------|----------|--------|
| General BT | O(N) | Recursive split check |
| BST | O(H) | Value-guided descent |

**Key Insights:**
1. **Split point = LCA:** When p and q are on different sides
2. **No recursion needed:** Iterative O(1) space
3. **Simpler than BT LCA:** No need to search both subtrees

<br><br>

---

```code```
