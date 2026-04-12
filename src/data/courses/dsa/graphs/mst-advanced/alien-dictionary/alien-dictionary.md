Given a sorted list of words in an alien language, derive the order of characters. Return the order as a string, or "" if invalid.

<br>

> Input: words = ["wrt","wrf","er","ett","rftt"]
> Output: "wertf"
> **Key insight:** Compare adjacent words to extract ordering rules (edges in a directed graph). Then topological sort the character graph. Invalid if cycle exists or if a word is a prefix of the previous.

<br>

---

## Constraints
- `1 ≤ words.length ≤ 100`

<br>

---

## Solution: Build Graph from Adjacent Words + Topo Sort (Optimal)

**Algorithm:**
1. Compare each pair of adjacent words. Find first differing character → edge from char1 to char2.
2. Build directed graph of character ordering.
3. Topological sort (Kahn's). If cycle → invalid (""). If not all chars → invalid.

### Time Complexity: O(C) where C = total characters across all words
**Why?** Building graph: compare adjacent words, total character comparisons ≤ C. Topo sort: O(V+E) where V = unique chars, E = edges.

### Space Complexity: O(V + E)

> **Drawback:** None.

> **Key Insight for Improvement:** Edge case: if word[i] is a prefix of word[i-1] but longer → invalid ordering (e.g., "abc" before "ab").

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Compare Adjacent + Topo Sort | O(C) | O(1) (26 chars max) |

**Key Insights:**
1. **Adjacent comparison:** Only adjacent words give ordering info
2. **First difference = one edge:** Compare char by char, first mismatch = ordering constraint
3. **Prefix check:** "abc" before "ab" is INVALID — longer word can't come first
4. **FAANG favorite:** Google/Meta interview classic

<br><br>

---

```code```
