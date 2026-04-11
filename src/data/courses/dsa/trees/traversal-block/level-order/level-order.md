Level order traversal — visit nodes level by level using BFS.

<br>

> Input: [3,9,20,null,null,15,7]
> Output: [[3],[9,20],[15,7]]

<br>

---

## Constraints

- `0 ≤ n ≤ 2000`

<br>

---

## Solution 1: BFS with Queue (Standard)

**Intuition:** Use queue. Process one level at a time by tracking queue size at each level.

**Algorithm:**
1. Queue starts with root
2. While queue not empty:
   - levelSize = queue.size()
   - Process levelSize nodes, adding their children
   - Collect level values into a list

### Time: O(n) | Space: O(n) — queue holds up to n/2 nodes at widest level

<br>

---

## Solution 2: DFS with Level Tracking

**Intuition:** DFS with depth parameter. Append node value to result[depth].

### Time: O(n) | Space: O(h) recursion

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| BFS Queue | O(n) | O(n) | Natural level-by-level |
| DFS + Level | O(n) | O(h) | Less space for narrow trees |

<br>
<br>

---

```code```
