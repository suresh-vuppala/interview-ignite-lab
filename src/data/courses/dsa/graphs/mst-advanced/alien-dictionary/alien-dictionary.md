Derive character ordering from a sorted alien dictionary using topological sort.

<br>

---

## Solution 1: Build Graph + Topological Sort (BFS/DFS)

**Algorithm:**
1. Compare adjacent words to find ordering constraints (first differing char)
2. Build directed graph of character ordering
3. Topological sort gives the alien alphabet order
4. If cycle → invalid → return ""

**Edge case:** If word1 is prefix of word2 but longer → invalid.

### Time: O(C) where C = total characters
### Space: O(1) — at most 26 nodes

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Graph + Topo Sort | O(C) | O(1) | Extract ordering from adjacent words |

<br>
<br>

---

```code```
