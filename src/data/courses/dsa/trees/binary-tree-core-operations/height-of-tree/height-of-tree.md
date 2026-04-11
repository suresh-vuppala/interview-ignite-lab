Find the height of a binary tree (edges on longest root-to-leaf path).

<br>

> Input: [3,9,20,null,null,15,7]
> Output: 2

<br>

---

## Constraints

- `0 ≤ n ≤ 10⁴`

<br>

---

## Solution 1: DFS Recursive

**Intuition:** Height = 1 + max(height(left), height(right)). Base case: null → -1 (or 0 depending on convention).

### Time: O(n) | Space: O(h) recursion

<br>

---

## Solution 2: BFS Level Count

**Intuition:** Level order traversal, count number of levels. Height = levels - 1.

### Time: O(n) | Space: O(n)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| DFS | O(n) | O(h) | Natural recursion |
| BFS | O(n) | O(n) | Count levels iteratively |

<br>
<br>

---

```code```
