Count islands in a grid (connected groups of '1's).

<br>

> Input: [["1","1","0"],["1","1","0"],["0","0","1"]]
> Output: 2

<br>

---

## Constraints

- `1 ≤ m, n ≤ 300`

<br>

---

## Solution 1: DFS Flood Fill

For each unvisited '1', DFS to mark entire island. Increment count.

### Time: O(m × n) | Space: O(m × n) recursion stack worst case

<br>

---

## Solution 2: BFS Flood Fill

Same but use queue for BFS instead of recursion.

### Time: O(m × n) | Space: O(min(m, n)) queue size

<br>

---

## Solution 3: Union-Find

Treat each '1' cell as a node. Union adjacent '1' cells. Count distinct components.

### Time: O(m × n × α(m×n)) | Space: O(m × n)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| DFS | O(m×n) | O(m×n) | Recursive flood fill |
| BFS | O(m×n) | O(min(m,n)) | Better space for wide grids |
| Union-Find | O(m×n) | O(m×n) | No recursion, good for streaming |

<br>
<br>

---

```code```
