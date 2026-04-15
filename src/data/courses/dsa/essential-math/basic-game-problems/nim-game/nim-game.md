Game theory: player taking last stone wins. Can take 1-3 stones per turn.

<br>

> n=4 → first player loses (whatever they take, opponent can complete to 4)
>
> **Key insight:** If N % 4 == 0, current player loses. Otherwise wins by taking N%4 stones.

<br>

---

## Constraints
- 1 ≤ N ≤ 2³¹ - 1

<br>

---

## Solution 1: Minimax simulation

**Intuition:**
The most straightforward approach. Exponential game tree.

**Algorithm:**
1. Iterate through all possible candidates/states
2. For each candidate, evaluate the required condition
3. Track the best result seen so far
4. Return the optimal answer

### Time Complexity: O(2^N)
**Why?**
Each element has multiple choices (include/exclude, take/skip), leading to exponential branching.
For N elements, the total states explored grow as 2^N or worse.

**Detailed breakdown:**
For N=20: ~1 million states. For N=30: ~1 billion states — too slow.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Exponential game tree.

> **Key Insight for Improvement:**
> Mathematical: N%4==0 → losing position. Take N%4 stones to leave multiple of 4 for opponent.

<br>

---

## Solution 2: Modular Analysis (Optimal)

**Intuition:** If N % 4 == 0, current player loses. Otherwise wins by taking N%4 stones.

**Algorithm:**
If n % 4 == 0: lose (opponent can always respond to maintain multiple of 4)
Else: win (take n%4 stones, leaving multiple of 4 for opponent)

### Time Complexity: O(1)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
n=5: take 1→leave 4 (opponent loses). n=4: any move leaves 1,2,3 → opponent wins.
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Minimax simulation | O(2^N) | Varies | Baseline |
| Modular Analysis | O(1) | O(1) | Optimal |

**Recommended Solution:** Modular Analysis

**Key Insights:**
1. **Key insight:** 4 is the losing number — can't take 4, any 1-3 leaves opponent in winning position
2. **Generalization:** For max take k, losing if N%(k+1)==0
3. **Sprague-Grundy:** Generalizes to any impartial game

<br><br>

---

```code```
