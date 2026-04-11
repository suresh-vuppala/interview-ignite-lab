Find the number of ways to tile a 2×N board using 2×1 dominoes and L-shaped trominoes.

<br>

> Input:
> n = 3

> Output:
> 5

> Explanation:
> Five ways to tile 2×3 board:
> 1. Three horizontal dominoes
> 2. Vertical + two horizontal
> 3. Two horizontal + vertical
> 4. Two trominoes (one up, one down)
> 5. One tromino + one domino
> 
> **Key insight:** Track fully covered columns and partially covered columns separately.

<br>


---

## Constraints

- `0 ≤ n ≤ 10⁴`
- `Values fit in 32-bit integer`
- `DP state space fits in memory`

<br>

---

## All Possible Edge Cases

1. **n = 0 or empty input:** Base case — return 0 or empty
2. **n = 1:** Single element — trivial case
3. **All same elements:** Check if pattern still applies
4. **Maximum constraints:** Verify time complexity handles worst case
5. **Negative values (if applicable):** Affects min/max DP transitions
6. **Result requires modular arithmetic:** Use MOD = 10⁹ + 7 to prevent overflow

<br>

---

## Solution 1: Recursive Approach (Brute Force)

**Intuition:**
At column i, we can have:
- Fully covered: place vertical domino or two horizontal dominoes
- Partially covered: place tromino creating gap for next column

**Recurrence Relation:**
```
full[i] = full[i-1] + full[i-2] + 2*partial[i-1]
partial[i] = full[i-2] + partial[i-1]
Base: full[0]=1, full[1]=1, partial[0]=0, partial[1]=1
```

**Algorithm:**
1. Track two states: fully covered and partially covered
2. Recursively compute both states

### Time Complexity: O(2^n)
**Why exponential?**
- Two recursive calls per state
- Two states to track
- Overlapping subproblems

### Space Complexity: O(n)
- Recursion stack depth

> **Key Insight for Improvement:**
> Overlapping subproblems for both states. Memoize both full[i] and partial[i] to reduce to O(n).

<br>

---

## Solution 2: Memoization (Top-Down DP)

**Intuition:**
Cache results for both fully covered and partially covered states.

**Algorithm:**
1. Create memo for both states
2. Check memo before computing
3. Store and return results

### Time Complexity: O(n)
**Why linear?**
- 2n unique subproblems (n for each state)
- Each computed once
- Total: O(n)

### Space Complexity: O(n)
- Memo tables + recursion stack

> **Key Insight for Improvement:**
> Remove recursion overhead with iterative tabulation.

<br>

---

## Solution 3: Tabulation (Bottom-Up DP)

**DP State:**
```
full[i] = ways to fully cover up to column i
partial[i] = ways to partially cover up to column i
```

**Transition:**
```
full[i] = full[i-1] + full[i-2] + 2*partial[i-1]
partial[i] = full[i-2] + partial[i-1]
```

**Algorithm:**
1. Initialize base cases
2. Fill both arrays iteratively
3. Return full[n]

### Time Complexity: O(n)
- Single loop, constant work per iteration

### Space Complexity: O(n)
- Two arrays of size n

> **Key Insight for Improvement:**
> Only need last 2 values for each state. Use variables instead of arrays.

<br>

---

## Solution 4: Space Optimized

**Intuition:**
Track only necessary previous values for both states.

**Algorithm:**
1. Use variables: full_prev2, full_prev1, partial_prev2, partial_prev1
2. Update in sliding window fashion

### Time Complexity: O(n)
### Space Complexity: O(1)
- Only 4-6 variables

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursive | O(2^n) | O(n) | Baseline |
| Memoization | O(n) | O(n) | Cache both states |
| Tabulation | O(n) | O(n) | Remove recursion |
| Space Optimized | O(n) | O(1) | Variables only |

**Key Pattern:**
- Two-state DP problem
- Each state depends on previous states
- Common in tiling with multiple tile types

> **Final Complexity:** O(n) time, O(1) space

<br>
<br>

---

```code```
