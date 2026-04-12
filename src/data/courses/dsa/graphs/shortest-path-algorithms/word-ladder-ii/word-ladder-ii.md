Find ALL shortest transformation sequences from beginWord to endWord.

<br>

> Input: beginWord="hit", endWord="cog", wordList=["hot","dot","dog","lot","log","cog"]
> Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
> **Key insight:** BFS to find shortest path length and build a parent map. Then DFS/backtrack from endWord using parent map to reconstruct all shortest paths.

<br>

---

## Constraints
- `1 ≤ wordList.length ≤ 5000`

<br>

---

## Solution: BFS (parent map) + DFS (backtrack paths) (Optimal)

**Algorithm:**
1. BFS from beginWord. For each word, track ALL parents (words that led to it at minimum distance).
2. Stop BFS at the level where endWord is found.
3. DFS backtrack from endWord using parent map to reconstruct all paths.

### Time Complexity: O(N × L × 26 + P) where P = total path length output
**Why?** BFS: O(N×L). Path reconstruction: proportional to output size.

### Space Complexity: O(N × L + P)

> **Drawback:** Output can be exponentially large in worst case. But we can't avoid generating it.

> **Key Insight for Improvement:** Track parents only at the SAME BFS level to ensure all paths are shortest. Don't update parents from a deeper level.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| BFS + DFS backtrack | O(N×L + P) | O(N×L + P) |

**Key Insights:**
1. **Parent map, not single parent:** Each word can have MULTIPLE parents (multiple shortest paths)
2. **Level-restricted:** Only add parents from the current BFS level
3. **DFS from endWord:** Backtrack through parent map to build all paths
4. **Hard problem:** Combines BFS + DFS + careful level tracking

<br><br>

---

```code```
