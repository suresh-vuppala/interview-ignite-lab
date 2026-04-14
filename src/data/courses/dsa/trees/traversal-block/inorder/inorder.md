Return the inorder traversal of a binary tree (Left → Root → Right).

<br>

> Input: root = [1, null, 2, 3]
> Output: [1, 3, 2]

> Explanation: Inorder visits left subtree first, then root, then right subtree. For BST, inorder gives sorted order.
> 
> **Key insight:** Recursive is trivial. Iterative uses a stack: go as far left as possible, process node, then go right. Morris traversal achieves O(1) space using threaded pointers.

<br>

---

## Constraints
- `0 ≤ N ≤ 100`

<br>

---

## All Possible Edge Cases
1. **Empty tree:** Return []
2. **Single node:** Return [val]
3. **Left-skewed:** Processes bottom-up
4. **Right-skewed:** Root first, then right chain

<br>

---

## Solution 1: Recursive

**Intuition:**
The most straightforward approach — try all possibilities and check each one.

**Algorithm:**
1. Define recursive function with current state
2. At each step, try all possible choices
3. Recurse on remaining subproblem
4. Base case: return when subproblem is solved

### Time Complexity: O(N)
**Why?**
Single pass through the input, doing O(1) work per element.
Total: N elements × O(1) per element = O(N).

**Detailed breakdown:**
For N=100,000: ~100,000 operations — very efficient.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Suboptimal time complexity for large inputs. Redundant work is performed.

> **Key Insight for Improvement:**
> Use a more efficient data structure or algorithm to reduce redundant computation.

<br>

---

## Solution 2: Iterative with Stack

**Intuition:** Start at root, push all left descendants. Process top of stack, then move to right child. Repeat.

**Algorithm:**
1. stack = [], current = root
2. While current or stack:
   - While current: push current, go left
   - Pop from stack → process (add to result)
   - current = popped.right

### Time Complexity: O(N)
### Space Complexity: O(H)

**Example walkthrough:**
```
Tree: [1, null, 2, 3]  (1→right→2→left→3)

current=1, push 1 → stack=[1], go left → null
Pop 1 → result=[1], current=2
Push 2 → stack=[2], go left → 3
Push 3 → stack=[2,3], go left → null
Pop 3 → result=[1,3], current=null (3 has no right)
Pop 2 → result=[1,3,2], current=null

Result: [1, 3, 2] ✓
```

> **Drawback:** Still O(H) space for the stack.

> **Key Insight for Improvement:** Morris Traversal: thread the rightmost node of left subtree to current node. Follow threads to return without a stack. O(1) space, O(N) time.

<br>

---

## Solution 3: Morris Traversal (O(1) Space)

**Intuition:** For each node, find its inorder predecessor (rightmost in left subtree). If predecessor's right is null → create thread (point to current), go left. If predecessor's right is current → thread exists, process current, remove thread, go right.

### Time Complexity: O(N) — each edge traversed at most 3 times
### Space Complexity: O(1) — no stack, only pointer manipulation

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursive | O(N) | O(H) | Simple but uses stack |
| Iterative Stack | O(N) | O(H) | Explicit stack, no recursion |
| Morris | O(N) | O(1) | Thread pointers — no extra space |

**Key Insights:**
1. **Inorder on BST = sorted order:** Essential for BST validation
2. **Iterative pattern:** Push lefts, process, go right
3. **Morris:** Temporarily modifies tree (must restore) for O(1) space

<br><br>

---

```code```
