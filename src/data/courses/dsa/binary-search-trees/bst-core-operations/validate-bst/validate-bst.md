Determine if a binary tree is a valid Binary Search Tree (BST). A valid BST satisfies: for every node, all values in left subtree < node value < all values in right subtree.

<br>

> Input:
> Tree structure:
>     2
>    / \
>   1   3

> Output:
> true

> Explanation:
> - Node 2: left child (1) < 2 < right child (3) ✓
> - Node 1: leaf node, valid ✓
> - Node 3: leaf node, valid ✓
> Valid BST

<br>

> Input:
> Tree structure:
>     5
>    / \
>   1   4
>      / \
>     3   6

> Output:
> false

> Explanation:
> - Node 5: left child (1) < 5, but right child (4) < 5 ✗
> - Node 4 should be > 5 to be in right subtree
> - Even though 4 > 1 and 4's children are valid, 4 < 5 violates BST property
> Invalid BST

<br>


---

## Constraints

- `1 ≤ n ≤ 10⁴`
- `-2³¹ ≤ Node.val ≤ 2³¹ - 1`

<br>

---

## All Possible Edge Cases

1. **Single node:** Always valid BST
2. **All left:** Valid if descending
3. **Equal values:** Not valid BST (strict inequality)
4. **INT_MIN/INT_MAX values:** Watch for boundary overflow in comparisons
5. **Valid but not balanced:** Still a valid BST

<br>

---

## Solution: Range Validation (Min-Max Approach)

Use recursive DFS with valid range tracking:
1. Each node must be within valid range [min, max]
2. Left subtree: range becomes [min, node.val)
3. Right subtree: range becomes (node.val, max]
4. Start with range [-∞, +∞] for root

**Key insight:** Not enough to check immediate children; must validate entire subtree ranges.



<br>

### Time Complexity Analysis

**DFS Traversal: O(n)**
- Visit each node exactly once
- At each node:
  - Compare value with min/max bounds: O(1)
  - Recursive call to left child: T(n/2)
  - Recursive call to right child: T(n/2)
- Total: T(n) = T(n/2) + T(n/2) + O(1) = O(n)

**Why must visit all nodes?**
- Cannot determine validity without checking every node
- One invalid node anywhere makes entire tree invalid
- Must validate all subtree ranges

**Space Complexity: O(h)**
- Recursion stack depth = height of tree
- Best case (balanced): O(log n)
- Worst case (skewed): O(n)
- Only stores min/max bounds per recursive call

**Alternative: Inorder Traversal**
- Inorder of valid BST is sorted array
- Traverse and check if strictly increasing
- Same O(n) time, O(h) space
- Less intuitive but also correct

**Common mistake:**
- Only checking node.left < node < node.right is WRONG
- Must ensure ALL left descendants < node < ALL right descendants
- Example: Node 5 with left=1, right=4 where 4 has left=3, right=6
  - 1 < 5 < 4? No! But 3 < 4 < 6? Yes!
  - Still invalid because 4 < 5 (right child must be > parent)

> **Time Complexity:** O(n) - visit each node once to validate
> **Space Complexity:** O(h) - recursion stack for tree height

<br>
<br>

---

---

```code```
