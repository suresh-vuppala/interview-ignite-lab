Find longest word in dictionary where every prefix is also a word in dictionary.

<br>

> words=['w','wo','wor','worl','world'] → 'world'
>
> **Key insight:** Build trie. DFS/BFS: only follow paths where every intermediate node has isEnd=true. Longest such path = answer.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: Sort + check each word's prefixes

### Time Complexity: O(N×L×N)

> **Drawback:**
> Checking each prefix against the dictionary is expensive.

> **Key Insight for Improvement:**
> Trie + DFS: only traverse nodes with isEnd=true (every prefix is a valid word). Track longest valid path.

<br>

---

## Solution 2: Trie + DFS with isEnd Check (Optimal)

**Intuition:** Build trie. DFS/BFS: only follow paths where every intermediate node has isEnd=true. Longest such path = answer.

**Algorithm:**
1. Insert all words into trie
2. DFS from root: only visit children with isEnd=true
3. Track longest path found
4. For ties: lexicographically smallest (DFS in alphabetical order)

### Time Complexity: O(N×L)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
words=['a','app','ap','apple','apply']: Trie path a(end)→p(end)→p(end)→l→e(end),y(end)
DFS: a→ap→app→appl? 'appl' not in dict → stop. apple if 'appl' is end? Check...
```

### Space Complexity: O(N×L)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Sort + check each word's prefixes | O(N×L×N) | Varies | Baseline |
| Trie + DFS with isEnd Check | O(N×L) | O(N×L) | Optimal |

**Recommended Solution:** Trie + DFS with isEnd Check

**Key Insights:**
1. **Every prefix must be a word:** Only follow isEnd nodes
2. **DFS in order:** Lexicographic tiebreaking
3. **BFS alternative:** Process level by level, only extend valid words

<br><br>

---

```code```
