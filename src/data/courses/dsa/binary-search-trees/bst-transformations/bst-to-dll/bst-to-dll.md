Convert a BST to a sorted doubly linked list in-place. Left = prev, Right = next.

<br>

> Input: BST [4,2,5,1,3]
> Output: DLL: 1↔2↔3↔4↔5
> **Key insight:** Inorder traversal produces sorted order. Maintain a prev pointer. For each node: node.left = prev, prev.right = node. Track head (first node in inorder).

<br>

---

## Constraints
- `1 ≤ N ≤ 2000`

<br>

---

## Solution 1: Inorder to array, build DLL

**Intuition:**
The most straightforward approach — array intermediate wastes space.

**Algorithm:**
1. Apply the naive/brute approach as described
2. Check all possibilities or use a simpler data structure
3. Return the result

### Time Complexity: O(N) time, O(N) space
**Why?**
The brute approach doesn't exploit the problem's structure efficiently, leading to redundant work.

**Detailed breakdown:**
For typical constraint sizes, this approach may be too slow or use too much space.

### Space Complexity: O(1) or O(N) depending on approach

> **Drawback:**
> Array intermediate wastes space. In-place prev-pointer technique is O(1) extra.

> **Key Insight for Improvement:**
> Use Inorder DFS with Prev Pointer (Optimal) for O(N) time.

<br>

---

## Solution 2: Inorder DFS with Prev Pointer (Optimal)

### Time Complexity: O(N)
### Space Complexity: O(H)

> **Drawback:** None — same technique as Trees module convert-to-dll.

> **Key Insight for Improvement:** Inorder gives sorted order in BST → DLL is naturally sorted. Same prev-pointer technique works for any BT→DLL conversion.

<br>

---

**Key Insights:**
1. **Inorder + prev pointer:** Links nodes in sorted order
2. **Left = prev, Right = next:** Repurpose BST pointers for DLL
3. **Track head:** First node visited in inorder = DLL head

<br><br>

---

```code```
