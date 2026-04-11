Find the left view of a binary tree. Left view contains the first node visible at each level when viewing the tree from the left side.

<br>

> Input:
> Tree structure:
>       1
>      / \
>     2   3
>    / \ / \
>   4  5 6  7
>  /
> 8

> Output:
> [1, 2, 4, 8]

> Explanation:
> Level-wise left view:
> - Level 0: First node = 1
> - Level 1: First node = 2 (leftmost at this level)
> - Level 2: First node = 4 (leftmost at this level)
> - Level 3: First node = 8 (leftmost at this level)
> 
> When viewing from left side, we see: 1, 2, 4, 8

<br>


---

## Constraints

- `0 ≤ n ≤ 10⁵`

<br>

---

## All Possible Edge Cases

1. **Empty tree:** Return []
2. **Right-skewed tree:** Only root visible
3. **Left-skewed tree:** All nodes visible
4. **Complete tree:** One node per level

<br>

---

## Solution #1: Level Order Traversal (BFS)

Use level-order traversal and pick first node at each level:
1. Use queue for BFS
2. Process nodes level by level
3. First node at each level is part of left view
4. Add to result



<br>

### Time Complexity Analysis (BFS)

**Level Order Traversal: O(n)**
- Visit each node exactly once
- Queue operations:
  - Each node enqueued once: n enqueues
  - Each node dequeued once: n dequeues
  - Each operation is O(1)
- Total: 2n operations = O(n)

**Space Complexity: O(w)**
- Queue holds nodes at current level
- Maximum width w = max nodes at any level
- Best case (skewed): O(1)
- Worst case (complete tree): O(n/2) = O(n)
- Average case: O(w) where w is width

<br>
<br>

---

## Solution #2: Recursive DFS (Pre-order)

Use DFS with level tracking:
1. Traverse tree in pre-order (Root-Left-Right)
2. Track current level
3. If visiting level for first time, add node to result
4. Recurse left first (ensures leftmost node seen first)

**Key insight:** Pre-order with left-first traversal ensures leftmost node at each level is visited first.



<br>

### Time Complexity Analysis (DFS)

**DFS Traversal: O(n)**
- Visit each node exactly once
- At each node:
  - Check if level visited: O(1)
  - Add to result if first at level: O(1)
  - Recursive calls: T(left) + T(right)
- Total: n × O(1) = O(n)

**Space Complexity: O(h)**
- Recursion stack depth = height
- Result array: O(h) for h levels
- Total: O(h) + O(h) = O(h)
- Best case (balanced): O(log n)
- Worst case (skewed): O(n)

**Comparison:**
- BFS: O(n) time, O(w) space - better for wide trees
- DFS: O(n) time, O(h) space - better for tall trees
- Both correct, choose based on tree shape

**Why pre-order?**
- Process root before children
- Visit left before right
- Ensures leftmost node at each level seen first
- Inorder or postorder won't guarantee this

> **Time Complexity:** O(n) - visit each node once
> **Space Complexity:** 
> - BFS: O(w) where w = maximum width
> - DFS: O(h) where h = height

<br>
<br>

---

---

```code```
