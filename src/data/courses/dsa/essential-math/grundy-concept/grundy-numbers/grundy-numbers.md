Sprague-Grundy theorem for solving combinatorial games.

<br>

> Compute Grundy number for game states to determine winner
>
> **Key insight:** G(state) = mex({G(next_state) for all reachable next states}). mex = minimum excludant (smallest non-negative integer not in set). XOR Grundy numbers for combined games.

<br>

---

## Constraints
- Game-theory specific constraints

<br>

---

## Solution 1: Minimax on full game tree

**Intuition:**
The most straightforward approach. Full tree exploration.

**Algorithm:**
1. Iterate through all possible candidates/states
2. For each candidate, evaluate the required condition
3. Track the best result seen so far
4. Return the optimal answer

### Time Complexity: Exponential
**Why?**
Each element has multiple choices (include/exclude, take/skip), leading to exponential branching.
For N elements, the total states explored grow as 2^N or worse.

**Detailed breakdown:**
For N=20: ~1 million states. For N=30: ~1 billion states — too slow.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Full tree exploration.

> **Key Insight for Improvement:**
> Grundy numbers + XOR: compute G for each subgame, XOR all. If XOR > 0, first player wins.

<br>

---

## Solution 2: Sprague-Grundy + XOR (Optimal)

**Intuition:** G(state) = mex({G(next_state) for all reachable next states}). mex = minimum excludant (smallest non-negative integer not in set). XOR Grundy numbers for combined games.

**Algorithm:**
1. G(terminal) = 0
2. G(state) = mex({G(next) for all next states})
3. Combined game: G = G₁ ⊕ G₂ ⊕ ... (XOR)
4. G > 0 → first player wins, G = 0 → loses

### Time Complexity: O(states × moves)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
Nim with piles [3,4,5]: G=3⊕4⊕5=2≠0 → first player wins
```

### Space Complexity: O(states)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Minimax on full game tree | Exponential | Varies | Baseline |
| Sprague-Grundy + XOR | O(states × moves) | O(states) | Optimal |

**Recommended Solution:** Sprague-Grundy + XOR

**Key Insights:**
1. **mex:** Smallest missing non-negative integer in successor Grundy set
2. **XOR for combinations:** Independent subgames combine with XOR
3. **Nim-value:** Every impartial game is equivalent to a Nim pile

<br><br>

---

```code```
