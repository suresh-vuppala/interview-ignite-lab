Sprague-Grundy theorem for solving combinatorial games.

<br>

> Compute Grundy number for game states to determine winner
>
> **Key insight:** G(state) = mex({G(next_state) for all reachable next states}). mex = minimum excludant (smallest non-negative integer not in set). XOR Grundy numbers for combined games.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: Minimax on full game tree

### Time Complexity: Exponential

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
