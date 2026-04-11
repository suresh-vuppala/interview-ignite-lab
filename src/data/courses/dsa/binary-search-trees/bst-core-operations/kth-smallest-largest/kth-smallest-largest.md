Find the kth smallest (or kth largest) element in a Binary Search Tree.

<br>

> Input:
> BST structure:
>     5
>    / \
>   3   6
>  / \
> 2   4
>/
>1
> 
> k = 3

> Output:
> 3

> Explanation:
> Inorder traversal (sorted): [1, 2, 3, 4, 5, 6]
> 3rd smallest element = 3
> 
> Inorder process:
> 1. Visit left subtree: 1, 2
> 2. Visit root of left subtree: 3 (this is 3rd element)
> 3. Stop when k elements visited

<br>

> Input:
> Same BST, k = 2 (for kth largest)

> Output:
> 5

> Explanation:
> Reverse inorder (descending): [6, 5, 4, 3, 2, 1]
> 2nd largest element = 5

<br>


---

## Constraints

- `1 ≤ k ≤ n ≤ 10⁴`

<br>

---

## All Possible Edge Cases

1. **k = 1:** Leftmost node (smallest)
2. **k = n:** Rightmost node (largest)
3. **k = n/2:** Middle element — median
4. **Single node, k=1:** Return that node
5. **Skewed BST:** k steps from one end

<br>

---

## Solution #1: Inorder Traversal for Kth Smallest

Use inorder traversal (Left-Root-Right) which visits BST nodes in ascending order:
1. Perform inorder traversal
2. Count nodes visited
3. Return kth node encountered
4. Can optimize by stopping after k nodes

**Key insight:** Inorder traversal of BST produces sorted sequence.

```code```

<br>

### Time Complexity Analysis

**Inorder Traversal: O(h + k)**
- Must traverse to kth smallest element
- In best case: k elements near root, O(k)
- In worst case: k = n, traverse all nodes, O(n)
- Average case: O(h + k) where h = height to reach kth element

**Why not always O(n)?**
- Can stop after finding kth element
- Don't need to visit remaining n-k nodes
- Early termination optimization

**Space Complexity: O(h)**
- Recursion stack depth = height
- Best case (balanced): O(log n)
- Worst case (skewed): O(n)
- Iterative approach: O(h) for explicit stack

<br>
<br>

---

## Solution #2: Reverse Inorder for Kth Largest

Use reverse inorder traversal (Right-Root-Left) for descending order:
1. Visit right subtree first
2. Process root
3. Visit left subtree
4. Count nodes, return kth node

**Key insight:** Reverse inorder visits nodes in descending order.

```code```

<br>

### Time Complexity Analysis

**Reverse Inorder: O(h + k)**
- Same as kth smallest but traverse right first
- Must reach kth largest element
- Can stop after k nodes visited

**Optimization with Augmented BST:**
- Store subtree size at each node: O(n) space
- Find kth element in O(h) time
- Useful when multiple queries needed
- Trade-off: O(n) space for O(h) query time

**Comparison:**
- Kth smallest: Inorder (Left-Root-Right)
- Kth largest: Reverse inorder (Right-Root-Left)
- Both: O(h + k) time, O(h) space
- Can convert: kth largest = (n - k + 1)th smallest

> **Time Complexity:** O(h + k) - traverse to kth element
> - Best case: O(k) when k is small
> - Worst case: O(n) when k = n
> 
> **Space Complexity:** O(h) - recursion stack for tree height

<br>
<br>

---
