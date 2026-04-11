## Overview
BFS traversal visiting nodes level-by-level (breadth-first).

## Problem Statement
Perform level order traversal returning list of lists (each inner list is one level).

## Approach
- Use queue: enqueue root, process level by level
- For each level, process all current nodes
- Add their children to queue

## Complexity Analysis
- **Time**: O(n)
- **Space**: O(w) where w = max width

## Code



---

## Constraints

- `0 ≤ n ≤ 2000`
- `-1000 ≤ Node.val ≤ 1000`

<br>

---

## All Possible Edge Cases

1. **Empty tree:** Return []
2. **Single node:** Return [[val]]
3. **Complete binary tree:** Each level fully populated
4. **Skewed tree:** One node per level
5. **Single level:** Only root

<br>

---

```code```
