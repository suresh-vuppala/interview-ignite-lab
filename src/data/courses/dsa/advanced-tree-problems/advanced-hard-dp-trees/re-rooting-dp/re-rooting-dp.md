Calculate sum of distances from each node to all other nodes in a tree.

<br>

> Input:
> n = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
> Tree:
>     0
>    / \
>   1   2
>      /|\
>     3 4 5

> Output:
> [8,12,6,10,10,10]

> Explanation:
> From node 0: distances = [0,1,1,2,2,2] → sum = 8
> From node 2: distances = [1,2,0,1,1,1] → sum = 6
> 
> **Key insight:** Compute for root, then re-root to get all answers in O(N).

<br>


---

## Constraints

- `1 ≤ n ≤ 10⁵`
- `-10⁵ ≤ Node.val ≤ 10⁵`

<br>

---

## All Possible Edge Cases

1. **Empty tree:** Return null or 0
2. **Single node:** Trivial case
3. **Skewed tree:** Degenerates to linked list behavior
4. **Balanced tree:** Optimal case for most tree algorithms
5. **Large tree:** Must be O(n) or O(n log n)

<br>

---

## Solution: Two-Pass Re-rooting DP

**Intuition:**
Computing from scratch for each node = O(N²).
Instead:
1. Compute answer for root (node 0)
2. Re-root: when moving root from parent to child, update answer in O(1)

**Key formula:**
```
ans[child] = ans[parent] - count[child] + (n - count[child])
```
- Subtract count[child]: nodes in child's subtree get 1 closer
- Add (n - count[child]): nodes outside get 1 farther

**Algorithm:**
1. DFS1: Compute count[node] and ans[0] (root)
2. DFS2: Re-root from parent to each child



<br>

### Time Complexity: O(N)
**Why linear?**
- DFS1: Visit all nodes once → O(N)
- DFS2: Visit all nodes once → O(N)
- Total: O(N) + O(N) = O(N)

**Detailed breakdown:**
- First DFS (bottom-up):
  - Compute subtree sizes: O(N)
  - Compute ans[root]: O(N)
- Second DFS (top-down):
  - Re-root to each child: O(1) per edge
  - N-1 edges: O(N)

**Why not O(N²)?**
- Naive: BFS/DFS from each node
- Optimized: Compute once, re-root in O(1)

### Space Complexity: O(N)
**Why?**
- Graph adjacency list: O(N)
- count array: O(N)
- ans array: O(N)
- Recursion stack: O(H) ≤ O(N)
- Total: O(N)

**Re-rooting technique:**
- Compute for one root: O(N)
- Transition to neighbors: O(1) each
- Total for all nodes: O(N)

**Applications:**
- Tree DP problems
- Subtree queries
- Distance calculations

> **Time Complexity:** O(N)
> **Space Complexity:** O(N)

<br>
<br>

---

---

```code```
