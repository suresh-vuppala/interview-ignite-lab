Check if subRoot is a subtree of root.

<br>

---

## Solution 1: DFS + Compare at Each Node

For each node in root, check if subtree rooted there equals subRoot (using identical tree check).

### Time: O(m × n) — compare at each node
### Space: O(h)

<br>

---

## Solution 2: Serialize + String Matching

Serialize both trees, check if subRoot's serialization is a substring of root's.

### Time: O(m + n)
### Space: O(m + n)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| DFS + Compare | O(m×n) | O(h) | Compare at every node |
| Serialize | O(m+n) | O(m+n) | Substring matching |

<br>
<br>

---

```code```
