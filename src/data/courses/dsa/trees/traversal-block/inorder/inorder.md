Perform inorder traversal of a binary tree. Inorder visits nodes in Left-Root-Right order. For BSTs, this produces sorted output.

<br>

> Input:
> Tree structure:
>       1
>      / \
>     2   3
>    / \
>   4   5

> Output:
> [4, 2, 5, 1, 3]

> Explanation:
> Inorder traversal (Left-Root-Right):
> 1. Visit left subtree of 1 → go to node 2
> 2. Visit left subtree of 2 → go to node 4
> 3. Node 4 is leaf, print 4
> 4. Back to node 2, print 2
> 5. Visit right subtree of 2 → go to node 5
> 6. Node 5 is leaf, print 5
> 7. Back to node 1, print 1
> 8. Visit right subtree of 1 → go to node 3
> 9. Node 3 is leaf, print 3
> 
> Result: [4, 2, 5, 1, 3]

<br>


---

## Constraints

- `0 ≤ n ≤ 100`
- `-100 ≤ Node.val ≤ 100`

<br>

---

## All Possible Edge Cases

1. **Empty tree:** Return []
2. **Single node:** Return [val]
3. **Left-skewed tree:** Acts like descending list
4. **Right-skewed tree:** Acts like ascending list
5. **Complete binary tree:** Standard traversal

<br>

---

## Solution #1: Recursive Inorder

Recursive approach follows natural definition:
1. Recursively traverse left subtree
2. Process current node (print/store value)
3. Recursively traverse right subtree

```code```

<br>

### Time Complexity Analysis (Recursive)

**Visit Each Node Once: O(n)**
- Each node is visited exactly once
- At each node: O(1) work (print/store value)
- Total: n × O(1) = O(n)

**Recursion Tree:**
- Each node makes 2 recursive calls (left, right)
- Total function calls = n (one per node)
- Work per call = O(1)

> **Time Complexity:** O(n) - visit each node once
> **Space Complexity:** O(h) - recursion stack depth, where h = height
> - Best case (balanced): O(log n)
> - Worst case (skewed): O(n)

<br>
<br>

---

## Solution #2: Iterative Inorder (Using Stack)

Iterative approach simulates recursion using explicit stack:
1. Push all left nodes to stack
2. Pop node, process it
3. Move to right child, repeat

**Algorithm:**
- Start from root, go left as far as possible (push to stack)
- Pop from stack, process node
- Move to right child, repeat process

```code```

<br>

### Time Complexity Analysis (Iterative)

**Stack Operations: O(n)**
- Each node pushed to stack exactly once: n pushes
- Each node popped from stack exactly once: n pops
- Total operations: 2n = O(n)

**Why O(n)?**
- Every node is processed exactly once
- Stack operations are O(1) each
- No node is revisited

**Space Complexity: O(h)**
- Stack holds nodes along path from root to current
- Maximum stack size = height of tree
- Best case (balanced): O(log n)
- Worst case (left-skewed): O(n)

**Comparison:**
- Recursive: Cleaner code, implicit stack
- Iterative: Explicit control, same complexity
- Both: O(n) time, O(h) space

> **Time Complexity:** O(n) - each node pushed and popped once
> **Space Complexity:** O(h) - explicit stack for tree height

<br>
<br>

---
