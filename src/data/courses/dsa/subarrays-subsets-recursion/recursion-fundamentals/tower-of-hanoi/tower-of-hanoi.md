Move N disks from source to destination using auxiliary peg. Only smaller disk can go on larger.

<br>

> N=3 → 7 moves
>
> **Key insight:** Recursive: move N-1 disks to aux, move Nth disk to dest, move N-1 from aux to dest. T(N) = 2T(N-1)+1 = 2^N-1 moves.

<br>

---

## Constraints
- 1 ≤ N ≤ 20

<br>

---

## Solution 1: N/A — recursive is optimal

**Intuition:**
The most straightforward approach. Cannot do better — 2^N-1 moves is proven minimum.

**Algorithm:**
1. Define recursive function with current state
2. At each step, try all possible choices
3. Recurse on remaining subproblem
4. Base case: return when subproblem is solved

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
> Cannot do better — 2^N-1 moves is proven minimum.

> **Key Insight for Improvement:**
> Recursive solution IS optimal. Classic divide-and-conquer.

<br>

---

## Solution 2: Recursive (Optimal)

**Intuition:** Recursive: move N-1 disks to aux, move Nth disk to dest, move N-1 from aux to dest. T(N) = 2T(N-1)+1 = 2^N-1 moves.

**Algorithm:**
1. hanoi(N, source, dest, aux):
2. If N==1: move disk from source to dest
3. hanoi(N-1, source, aux, dest) — move N-1 to aux
4. Move disk N from source to dest
5. hanoi(N-1, aux, dest, source) — move N-1 to dest

### Time Complexity: O(2^N)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
N=3: move 2 disks A→B, move disk3 A→C, move 2 disks B→C
= 3+1+3 = 7 moves
```

### Space Complexity: O(N) stack

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| N/A — recursive is optimal | O(2^N) | Varies | Baseline |
| Recursive | O(2^N) | O(N) stack | Optimal |

**Recommended Solution:** Recursive

**Key Insights:**
1. **2^N-1 moves:** Proven optimal — can't do fewer
2. **Divide and conquer:** Break into moving N-1 disks
3. **Classic recursion:** First problem in many CS courses

<br><br>

---

```code```
