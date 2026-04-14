Construct a binary tree from inorder and preorder traversal arrays.

<br>

> Input: preorder=[3,9,20,15,7], inorder=[9,3,15,20,7]
> Output: tree [3,9,20,null,null,15,7]
> **Key insight:** Preorder's first element = root. Find root in inorder → left of it = left subtree, right = right subtree. Recurse. Use hash map for O(1) root lookup in inorder.

<br>

---

## Constraints
- `1 ≤ N ≤ 3000`, no duplicate values

<br>

---

## Solution 1: Try all possible trees

**Intuition:**
The most straightforward approach — exponential — trying all structures.

**Algorithm:**
1. Apply the naive/brute approach as described
2. Check all possibilities or use a simpler data structure
3. Return the result

### Time Complexity: O(Catalan(N))
**Why?**
The brute approach doesn't exploit the problem's structure efficiently, leading to redundant work.

**Detailed breakdown:**
For typical constraint sizes, this approach may be too slow or use too much space.

### Space Complexity: O(1) or O(N) depending on approach

> **Drawback:**
> Exponential — trying all structures. HashMap + index approach is O(N).

> **Key Insight for Improvement:**
> Use Recursive Split with HashMap (Optimal) for O(N) time.

<br>

---

## Solution 2: Recursive Split with HashMap (Optimal)

**Algorithm:** preorder[0] = root. Find root index in inorder (hash map). Left subtree = inorder[0..rootIdx-1]. Right = inorder[rootIdx+1..end]. Recurse with correct preorder slices.

### Time Complexity: O(N)
**Why?** Each node processed once. Hash map lookup O(1).

**Detailed breakdown:** N = 3000 → 3000 operations

### Space Complexity: O(N) for hash map + O(H) recursion

> **Drawback:** Requires no duplicate values (otherwise root position is ambiguous).

> **Key Insight for Improvement:** Hash map makes root lookup O(1) instead of O(N) linear scan, improving total from O(N²) to O(N).

<br>

---

**Key Insights:**
1. **Preorder gives roots:** First element is always the subtree root
2. **Inorder gives splits:** Root position separates left and right subtrees
3. **Hash map critical:** O(1) lookup vs O(N) scan per recursive call

<br><br>

---

```code```
