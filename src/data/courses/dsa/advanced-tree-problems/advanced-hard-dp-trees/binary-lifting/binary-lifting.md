Find the kth ancestor of a node in a tree using binary lifting technique.

<br>

> Input:
> n = 7, parent = [-1,0,0,1,1,2,2]
> Tree structure:
>       0
>      / \
>     1   2
>    / \ / \
>   3  4 5  6
> 
> Query: getKthAncestor(3, 1) → 1
> Query: getKthAncestor(5, 2) → 0
> Query: getKthAncestor(6, 3) → -1

> Output:
> 1, 0, -1

> Explanation:
> Node 3's 1st ancestor = 1
> Node 5's 2nd ancestor = 0 (5→2→0)
> Node 6's 3rd ancestor = -1 (doesn't exist)
> 
> **Key insight:** Precompute 2^j jumps for O(log N) queries.

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

## Solution: Binary Lifting with Sparse Table

**Intuition:**
Instead of jumping 1 step at a time (O(K) per query), precompute jumps of powers of 2.
- up[node][j] = 2^j-th ancestor of node
- Any k can be represented as sum of powers of 2
- Query in O(log K) by binary decomposition

**Preprocessing:**
```
up[node][0] = parent[node]
up[node][j] = up[up[node][j-1]][j-1]  // Jump 2^j = two jumps of 2^(j-1)
```

**Query:**
```
For each bit i in k:
  if bit i is set: node = up[node][i]
```

```code```

<br>

### Time Complexity: O(N log N) preprocess, O(log N) query
**Why?**
- Preprocess: Fill up[N][LOG] table
  - N nodes × LOG levels = O(N log N)
- Query: Check LOG bits of k
  - Each bit: O(1) lookup
  - Total: O(log N)

**Detailed breakdown:**
- Build sparse table:
  - First level (j=0): O(N)
  - Each level j: O(N) using previous level
  - LOG levels: O(N log N)
- Query k-th ancestor:
  - Binary representation of k: log K bits
  - Each bit: table lookup O(1)
  - Total: O(log K) ≈ O(log N)

### Space Complexity: O(N log N)
**Why?**
- Sparse table: up[N][LOG]
- N nodes × LOG levels
- LOG ≈ 20 for N ≤ 10^6

**Why binary lifting?**
- Naive: Jump 1 step k times → O(K) per query
- Binary lifting: Jump by powers of 2 → O(log K)
- Massive speedup for large k

**Applications:**
- LCA (Lowest Common Ancestor)
- Tree path queries
- Competitive programming

> **Time Complexity:** O(N log N) preprocess, O(log N) query
> **Space Complexity:** O(N log N)

<br>
<br>

---
