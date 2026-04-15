Implement Morris Inorder Traversal — O(1) space inorder traversal without recursion or stack.

<br>

> Input: root = [1,2,3,4,5]
> Output: [4,2,5,1,3]

> Explanation: Standard inorder but using threaded pointers instead of a stack. Temporarily creates right pointers from inorder predecessor back to current node.
> 
> **Key insight:** For each node with a left child, find its inorder predecessor (rightmost in left subtree). If predecessor's right is null → create thread, go left. If predecessor's right points to current → remove thread, process current, go right.

<br>

---

## Constraints
- `0 ≤ N ≤ 10⁵`

<br>

---

## All Possible Edge Cases
1. **Empty tree**
2. **Right-skewed (no left children):** no threading needed
3. **Left-skewed: maximum threading**
4. **Tree must be fully restored after traversal**

<br>

---

## Solution 1: Standard recursive/iterative with stack

**Intuition:**
The most straightforward approach — stack uses o(h) space.

**Algorithm:**
1. Apply the naive/brute approach as described
2. Check all possibilities or use a simpler data structure
3. Return the result

### Time Complexity: O(N) time, O(H) space
**Why?**
The brute approach doesn't exploit the problem's structure efficiently, leading to redundant work.

**Detailed breakdown:**
For typical constraint sizes, this approach may be too slow or use too much space.

### Space Complexity: O(1) or O(N) depending on approach

> **Drawback:**
> Stack uses O(H) space. Morris threading achieves O(1) space traversal.

> **Key Insight for Improvement:**
> Use Morris Inorder (Optimal Space) for O(N) time.

<br>

---

## Solution 2: Morris Inorder (Optimal Space)

**Algorithm:**
1. current = root
2. While current:
   - If no left child → process current, go right
   - Else find predecessor (rightmost in left subtree):
     - If predecessor.right == null → create thread, go left
     - If predecessor.right == current → remove thread, process, go right

### Time Complexity: O(N)
**Why?** Each edge traversed at most 3 times (once normally, once to find predecessor, once to remove thread).

**Detailed breakdown:** N = 100,000 → at most 300,000 pointer traversals

### Space Complexity: O(1)
**Why?** No stack, no recursion. Only pointer manipulation.

> **Drawback:** Temporarily modifies the tree structure. Must restore all threads.

> **Key Insight for Improvement:** This IS the optimal O(1) space solution. The tree is fully restored after traversal.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursive | O(N) | O(H) | Implicit stack |
| Iterative Stack | O(N) | O(H) | Explicit stack |
| Morris | O(N) | O(1) | Threaded pointers — no stack at all |

**Key Insights:**
1. **Thread = temporary shortcut:** Predecessor's right points back to current for "return"
2. **Two visits per node:** First visit creates thread (go left), second removes thread (process)
3. **Tree fully restored:** All temporary threads are removed during second visit

<br><br>

---

```code```
