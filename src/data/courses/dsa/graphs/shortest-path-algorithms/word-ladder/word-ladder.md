Given two words beginWord and endWord, and a dictionary wordList, return the length of shortest transformation sequence from beginWord to endWord, such that:
- Only one letter can be changed at a time
- Each transformed word must exist in wordList
- Return 0 if no transformation sequence exists

<br>

> Input:
> beginWord = "hit", endWord = "cog"
> wordList = ["hot","dot","dog","lot","log","cog"]

> Output:
> 5

> Explanation:
> Shortest transformation: "hit" → "hot" → "dot" → "dog" → "cog" (5 words)
> 
> **Key insight:** Model as graph where words are nodes, edges connect words differing by one letter. Use BFS for shortest path.

<br>

---

## Solution 1: BFS with Neighbor Generation

**Intuition:**
Treat this as shortest path problem in unweighted graph. Each word is a node. Two words are connected if they differ by exactly one letter. Use BFS to find shortest path.

**Algorithm:**
1. Convert wordList to set for O(1) lookup
2. If endWord not in set, return 0
3. Use BFS starting from beginWord
4. For each word, generate all possible one-letter changes
5. If generated word is in wordList, add to queue
6. Track visited words to avoid cycles
7. Return level when endWord is reached

### Time Complexity: O(N × L² × 26)
**Why?**
- N = number of words in wordList
- L = length of each word
- BFS visits each word once: O(N)
- For each word: generate neighbors
  - Try all L positions
  - Try 26 letters at each position
  - Check if word in set: O(L) for string comparison
- Total: N × L × 26 × L = O(N × L² × 26)

**Detailed breakdown:**
- BFS: O(N) words visited
- Per word: L positions × 26 letters = 26L neighbors
- String operations: O(L) per neighbor
- Total: N × 26L × L = O(26NL²)

### Space Complexity: O(N × L)
**Why?**
- Queue: O(N) words
- Visited set: O(N) words
- WordList set: O(N) words
- Each word: O(L) space
- Total: O(N × L)

> **Key Insight for Improvement:**
> Generating neighbors by trying all 26 letters is expensive. Can we preprocess? Yes! Build graph beforehand using pattern matching.

<br>

---

## Solution 2: BFS with Pattern Matching (Preprocessing)

**Intuition:**
Preprocess wordList to group words by patterns. Pattern = word with one letter replaced by '*'. Words sharing a pattern are neighbors. This avoids generating all 26 variations.

**Example:**
```
"hot" → patterns: "*ot", "h*t", "ho*"
"dot" → patterns: "*ot", "d*t", "do*"
"hot" and "dot" share "*ot" → they're neighbors
```

**Algorithm:**
1. Build pattern map: pattern → list of words
2. BFS from beginWord
3. For each word, get all patterns
4. For each pattern, get all neighbor words
5. Add unvisited neighbors to queue
6. Return level when endWord reached

### Time Complexity: O(N × L²)
**Why?**
- Preprocessing: O(N × L²)
  - For each of N words
  - Generate L patterns
  - Each pattern creation: O(L)
- BFS: O(N × L²)
  - Visit N words
  - Each word: L patterns
  - Each pattern: O(L) lookup + neighbors
- Total: O(N × L²)

**Improvement:** From O(N × L² × 26) to O(N × L²)
- Removed factor of 26 (trying all letters)
- Example: L=5, saves 26× operations per word

### Space Complexity: O(N × L²)
**Why?**
- Pattern map: N words × L patterns × L string length
- Queue + visited: O(N × L)
- Total: O(N × L²)

**Trade-off:** More space for faster time

> **Key Insight for Improvement:**
> Single-direction BFS explores many unnecessary paths. Can we search from both ends? Yes! Bidirectional BFS.

<br>

---

## Solution 3: Bidirectional BFS

**Intuition:**
Search from both beginWord and endWord simultaneously. When the two searches meet, we found the shortest path. This dramatically reduces search space.

**Why faster:**
- Single BFS: explores radius R → O(b^R) nodes (b = branching factor)
- Bidirectional: explores radius R/2 from each end → O(2 × b^(R/2)) = O(2 × √(b^R))
- Much smaller search space!

**Algorithm:**
1. Initialize two sets: beginSet = {beginWord}, endSet = {endWord}
2. Track visited words
3. While both sets non-empty:
   - Always expand smaller set (optimization)
   - For each word in current set:
     - Generate neighbors
     - If neighbor in other set: found path, return level
     - If neighbor unvisited: add to next level set
   - Swap sets for next iteration
4. Return 0 if no path found

### Time Complexity: O(N × L²)
**Why?**
- Same asymptotic complexity as Solution 2
- But much better constant factor in practice
- Explores fewer nodes due to meeting in middle

**Practical improvement:**
- Single BFS: might explore entire graph
- Bidirectional: stops when searches meet
- Example: If path length is 10, single BFS explores depth 10, bidirectional explores depth 5 from each end

### Space Complexity: O(N × L)
**Why?**
- Two sets: O(N) words each
- Visited set: O(N)
- Each word: O(L)
- Total: O(N × L)

**Why this is better:**
- Explores exponentially fewer nodes
- Stops as soon as paths meet
- Always expands smaller frontier (optimization)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Feature |
|----------|------|-------|-------------|
| BFS + Neighbor Gen | O(N×L²×26) | O(N×L) | Generate all 26-letter variations |
| BFS + Pattern Match | O(N×L²) | O(N×L²) | Preprocess patterns - avoid 26× factor |
| Bidirectional BFS | O(N×L²) | O(N×L) | Search from both ends - fewer nodes |

**Recommended Solution:** Bidirectional BFS (Solution 3) - O(N×L²) time, O(N×L) space, best practical performance.

**Key Insights:**
1. **Model as graph:** Words = nodes, one-letter difference = edge
2. **BFS for shortest path:** Unweighted graph → BFS finds shortest path
3. **Pattern matching:** Avoid trying all 26 letters → use patterns
4. **Bidirectional search:** Meet in middle → exponentially fewer nodes

<br>
<br>

---

```code```
