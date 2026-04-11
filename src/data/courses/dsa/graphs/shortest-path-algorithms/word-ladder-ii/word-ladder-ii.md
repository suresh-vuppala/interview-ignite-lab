Given two words beginWord and endWord, and a dictionary wordList, return all shortest transformation sequences from beginWord to endWord, such that:
- Only one letter can be changed at a time
- Each transformed word must exist in wordList
- Return empty list if no transformation sequence exists

<br>

> Input:
> beginWord = "hit", endWord = "cog"
> wordList = ["hot","dot","dog","lot","log","cog"]

> Output:
> [["hit","hot","dot","dog","cog"], ["hit","hot","lot","log","cog"]]

> Explanation:
> Two shortest paths of length 5 exist.
> 
> **Key insight:** Use BFS to find shortest distance, then DFS/backtracking to construct all paths at that distance.

<br>


---

## Constraints

- `1 ≤ beginWord.length ≤ 5`
- `endWord.length == beginWord.length`
- `1 ≤ wordList.length ≤ 500`

<br>

---

## All Possible Edge Cases

1. **No path exists:** Return []
2. **Multiple shortest paths:** Return all of them
3. **Single step transformation:** Return [[begin, end]]
4. **endWord not in wordList:** Return []
5. **Very long paths:** Memory for storing all paths

<br>

---

## Solution 1: BFS + DFS (Two-Pass)

**Intuition:**
First use BFS to find shortest distance and build parent relationships. Then use DFS to backtrack from endWord to beginWord, constructing all shortest paths.

**Algorithm:**
1. **BFS Phase:** Build graph of parent relationships
   - For each word at level L, track all parents at level L-1
   - Stop BFS when endWord is reached
2. **DFS Phase:** Backtrack from endWord
   - Recursively visit all parents
   - Build paths in reverse
   - Reverse paths before returning

### Time Complexity: O(N × L² + P × L)
**Why?**
- BFS: O(N × L²) to build parent graph
  - N words, L² for neighbor generation
- DFS: O(P × L) to construct paths
  - P = number of shortest paths
  - L = path length
- Total: O(N × L² + P × L)

**Detailed breakdown:**
- BFS explores all words: O(N)
- Per word: generate neighbors O(L²)
- DFS constructs P paths, each length L
- In worst case, P can be exponential

### Space Complexity: O(N × L + P × L)
**Why?**
- Parent map: O(N × L) - stores parent lists
- Queue: O(N) words
- Result paths: O(P × L)
- Recursion stack: O(L)
- Total: O(N × L + P × L)

> **Key Insight for Improvement:**
> Two-pass approach (BFS then DFS) works but requires storing all parent relationships. Can we do it in one pass? Yes, but two-pass is clearer and efficient enough.

<br>

---

## Solution 2: BFS with Level-by-Level Processing

**Intuition:**
Process BFS level by level. At each level, track which words can reach endWord. Build paths incrementally as we go.

**Algorithm:**
1. Initialize paths with [beginWord]
2. For each level:
   - For each path in current level:
     - Generate neighbors of last word
     - Extend path with each valid neighbor
   - If endWord found at this level, collect all paths
   - Remove used words from wordList
3. Return collected paths

### Time Complexity: O(N × L² + P × L)
**Why?**
- Same as Solution 1
- BFS: O(N × L²)
- Path construction: O(P × L)
- Total: O(N × L² + P × L)

### Space Complexity: O(P × L)
**Why?**
- Stores all paths as they're built
- P paths, each length L
- More space-efficient than storing parent map

**Trade-off:**
- Solution 1: Clearer separation (BFS then DFS)
- Solution 2: Builds paths incrementally
- Both have similar complexity

<br>

---

## Solution 3: Bidirectional BFS + DFS

**Intuition:**
Use bidirectional BFS to find meeting point faster, then construct paths from both directions.

**Algorithm:**
1. **Bidirectional BFS:**
   - Search from both beginWord and endWord
   - Build parent maps from both directions
   - Stop when searches meet
2. **Path Construction:**
   - DFS from beginWord to meeting point
   - DFS from endWord to meeting point
   - Combine paths from both directions

### Time Complexity: O(N × L² + P × L)
**Why?**
- Bidirectional BFS: O(N × L²)
  - Explores fewer nodes in practice
  - Same worst-case complexity
- Path construction: O(P × L)
- Total: O(N × L² + P × L)

**Practical improvement:**
- Explores significantly fewer nodes
- Faster in practice due to meeting in middle
- More complex implementation

### Space Complexity: O(N × L + P × L)
**Why?**
- Two parent maps: O(N × L)
- Result paths: O(P × L)
- Total: O(N × L + P × L)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Feature |
|----------|------|-------|-------------|
| BFS + DFS | O(N×L² + P×L) | O(N×L + P×L) | Clear two-phase approach |
| BFS Level-by-Level | O(N×L² + P×L) | O(P×L) | Build paths incrementally |
| Bidirectional BFS + DFS | O(N×L² + P×L) | O(N×L + P×L) | Faster in practice |

**Recommended Solution:** BFS + DFS (Solution 1) - clearest approach, efficient, easy to understand.

**Key Insights:**
1. **BFS for shortest distance:** Find level where endWord appears
2. **Track parents:** Store all possible parents at each level
3. **DFS for path construction:** Backtrack through parents to build all paths
4. **Stop at first occurrence:** Don't explore beyond level where endWord found

**Difference from Word Ladder I:**
- Word Ladder I: Return length (single BFS)
- Word Ladder II: Return all paths (BFS + DFS)
- Much harder due to exponential number of paths

<br>
<br>

---

```code```
