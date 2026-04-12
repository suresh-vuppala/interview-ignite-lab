Find the kth smallest and kth largest element in a BST.

<br>

> Input: BST = [3,1,4,null,2], k=1
> Output: kth smallest=1, kth largest=4
> **Key insight:** Inorder traversal gives sorted order. Kth smallest = kth element in inorder. Kth largest = kth element in reverse inorder (right→root→left).

<br>

---

## Constraints
- `1 ≤ k ≤ N ≤ 10⁴`

<br>

---

## Solution 1: Inorder to Array — O(N) time, O(N) space

> **Drawback:** Collects ALL elements even though we only need k.

> **Key Insight for Improvement:** Inorder traversal with counter — stop as soon as k elements visited. O(H + k) time, O(H) space.

<br>

---

## Solution 2: Inorder with Early Termination (Optimal)

**Algorithm:** Inorder DFS with a counter. Decrement k at each node visit. When k == 0 → found the kth smallest.

### Time Complexity: O(H + k)
**Why?** Traverse H nodes to reach leftmost, then visit k nodes.

**Detailed breakdown:** H=20, k=5 → 25 operations (not full N traversal!)

### Space Complexity: O(H)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Full inorder | O(N) | O(N) | Collect all, index k |
| Early termination | O(H+k) | O(H) | Stop after k visits |

**Key Insights:**
1. **Inorder = sorted:** BST's defining useful property
2. **Early stop saves time:** Don't traverse entire tree for small k
3. **Kth largest = reverse inorder:** Right→Root→Left traversal

<br><br>

---

```code```
