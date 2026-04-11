Given a binary tree and two node values x and y, determine if the two nodes are cousins. Two nodes are cousins if they are at the same depth but have different parents.

<br>

> Input:
> root = [1,2,3,4], x = 4, y = 3

> Output:
> false

> Explanation:
> Node 4 is at depth 2 with parent 2.
> Node 3 is at depth 1 with parent 1.
> Different depths → not cousins.
> 
> **Key insight:** Track both depth and parent for each node. Cousins have same depth but different parents.

<br>


---

## Constraints

- `2 ≤ n ≤ 100`
- `All values unique`

<br>

---

## All Possible Edge Cases

1. **Same parent:** Not cousins (siblings)
2. **Different depth:** Not cousins
3. **Same depth, different parents:** Cousins!
4. **Root's children:** Not cousins of anyone except each other's subtrees

<br>

---

## Solution 1: DFS with Parent and Depth Tracking

**Intuition:**
Use DFS to find both nodes, tracking their depth and parent. Then check if they have same depth but different parents.

**Algorithm:**
1. Create helper function to find node info (depth, parent)
2. DFS from root, tracking current depth and parent
3. When node found, return (depth, parent)
4. Compare results: same depth AND different parents

### Time Complexity: O(N)
**Why?**
- Visit each node once in worst case
- N = number of nodes
- Early termination when both nodes found

**Detailed breakdown:**
- DFS traversal: O(N)
- Each node visited at most once
- Example: Tree with 1000 nodes → 1000 visits

### Space Complexity: O(H)
**Why?**
- Recursion stack depth = tree height
- H = height of tree
- Worst case (skewed): O(N)
- Best case (balanced): O(log N)

> **Key Insight for Improvement:**
> We're doing two separate DFS calls. Can we find both nodes in one pass? Yes! Track both nodes simultaneously.

<br>

---

## Solution 2: Single DFS Pass

**Intuition:**
Find both nodes in a single DFS traversal. Store depth and parent for each node as we find them.

**Algorithm:**
1. Initialize variables for x and y info
2. Single DFS traversal:
   - Track current depth and parent
   - When x found, store its depth and parent
   - When y found, store its depth and parent
   - Early return if both found
3. Check: same depth AND different parents

### Time Complexity: O(N)
**Why?**
- Single DFS traversal
- Visit nodes until both found
- Average case: better than Solution 1 (early termination)

**Improvement:** Same worst case, better average case
- Solution 1: Always two passes
- Solution 2: One pass with early termination

### Space Complexity: O(H)
**Why?**
- Recursion stack: O(H)
- Few variables: O(1)
- Total: O(H)

> **Key Insight for Improvement:**
> DFS uses recursion stack. Can we use iteration? Yes! BFS with level-order traversal naturally tracks depth.

<br>

---

## Solution 3: BFS (Level Order Traversal)

**Intuition:**
Use BFS to traverse level by level. At each level, track parent of each node. If both nodes found at same level with different parents, they're cousins.

**Algorithm:**
1. BFS with queue, process level by level
2. For each level:
   - Track parent of each child
   - Check if x or y found
   - If both found at same level with different parents: return true
   - If only one found: return false (different depths)
3. Return false if not found

### Time Complexity: O(N)
**Why?**
- BFS visits each node once
- Process nodes level by level
- Early termination when both found or one found alone

**Detailed breakdown:**
- Queue operations: O(1) per node
- Total nodes: N
- Total: O(N)

### Space Complexity: O(W)
**Why?**
- Queue stores nodes at current level
- W = maximum width of tree
- Worst case (complete tree): O(N/2) = O(N)
- Best case (skewed): O(1)

**Why BFS is natural:**
- Processes level by level
- Easy to check same depth
- No recursion stack needed

<br>

---

## Solution 4: Optimized Single Pass DFS

**Intuition:**
Combine depth and parent checking in single recursive call. Return early when we know the answer.

**Algorithm:**
1. Recursive function returns (found_x, found_y, are_cousins)
2. At each node:
   - Check if children are x and y (same parent → not cousins)
   - Recursively check left and right subtrees
   - Combine results from both subtrees
3. Return final result

### Time Complexity: O(N)
**Why?**
- Single DFS traversal
- Each node visited once
- Early termination possible

### Space Complexity: O(H)
**Why?**
- Recursion stack: O(H)
- Constant extra space
- Total: O(H)

**Why this is elegant:**
- Single pass
- Early termination
- Clean logic

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Feature |
|----------|------|-------|-------------|
| DFS (Two Pass) | O(N) | O(H) | Find each node separately |
| DFS (Single Pass) | O(N) | O(H) | Find both in one traversal |
| BFS (Level Order) | O(N) | O(W) | Natural level tracking |
| Optimized DFS | O(N) | O(H) | Early termination + clean logic |

**Recommended Solution:** BFS (Solution 3) - O(N) time, O(W) space, most intuitive for level-based problems.

**Key Insights:**
1. **Cousins definition:** Same depth + different parents
2. **DFS approach:** Track depth and parent during traversal
3. **BFS approach:** Process level by level, natural for depth checking
4. **Early termination:** Stop when both nodes found or one found alone

**Edge cases:**
- One or both nodes don't exist → false
- Nodes are siblings (same parent) → false
- Root node → cannot be cousin (no parent)

<br>
<br>

---

```code```
