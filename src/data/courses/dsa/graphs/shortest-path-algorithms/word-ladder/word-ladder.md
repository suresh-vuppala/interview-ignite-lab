Given beginWord, endWord, and a word list, find the shortest transformation sequence length where each step changes exactly one letter and the intermediate word must be in the word list.

<br>

> Input: beginWord="hit", endWord="cog", wordList=["hot","dot","dog","lot","log","cog"]
> Output: 5 (hit→hot→dot→dog→cog)
> **Key insight:** Model as unweighted graph: words are nodes, edges connect words differing by one letter. BFS from beginWord gives shortest path.

<br>

---

## Constraints
- `1 ≤ beginWord.length ≤ 10`, `1 ≤ wordList.length ≤ 5000`

<br>

---

## Solution 1: BFS + Check All Pairs

**Intuition:**
The most straightforward approach — try all possibilities and check each one.

**Algorithm:**
1. For each element i (outer loop):
   - For each element j (inner loop):
     - Check if the pair/condition is satisfied
2. Return the best result found

### Time Complexity: O(N² × L) — compare all word pairs
**Why?**
Two nested loops each running up to N iterations.
Outer loop: N iterations × Inner loop: up to N iterations = N² total operations.

**Detailed breakdown:**
For N=1,000: ~1 million operations (OK). For N=10,000: ~100 million (borderline TLE).

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Suboptimal time complexity for large inputs. Redundant work is performed.

> **Key Insight for Improvement:**
> Use a more efficient data structure or algorithm to reduce redundant computation.

<br>

---

## Solution 2: BFS + Generate Variants (Optimal)

**Algorithm:**
1. Put wordList in a set for O(1) lookup
2. BFS from beginWord. For each word, try all 26 substitutions at each position.
3. If variant is in set → enqueue, remove from set (visited). Level count = steps.

### Time Complexity: O(N × L × 26) = O(N × L)
**Why?** Each word dequeued once. Per word: L positions × 26 letters = O(L) work.

**Detailed breakdown:** N=5000, L=10 → 5000 × 260 = 1,300,000 operations

### Space Complexity: O(N × L)

> **Drawback:** None for single shortest path length.

> **Key Insight for Improvement:** Bidirectional BFS: search from both beginWord and endWord simultaneously. They meet in the middle → reduces search space from O(26^D) to O(2×26^(D/2)).

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| BFS + All Pairs | O(N²×L) | O(N×L) | Compare all word pairs |
| BFS + Variants | O(N×L) | O(N×L) | Generate 26L variants per word |

**Key Insights:**
1. **Implicit graph:** Don't build adjacency list — generate neighbors on-the-fly during BFS
2. **Remove from set = visited:** Prevents revisiting without separate visited array
3. **BFS = shortest path:** Unweighted graph → BFS level = minimum transformations
4. **FAANG critical:** Top-10 graph problem at Google, Amazon

<br><br>

---

```code```
