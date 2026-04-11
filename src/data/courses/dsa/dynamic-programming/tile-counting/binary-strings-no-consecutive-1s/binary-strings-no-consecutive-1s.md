Count binary strings of length n with no consecutive 1s.

<br>

> Input:
> n = 3

> Output:
> 5

> Explanation:
> Valid strings: 000, 001, 010, 100, 101
> Invalid: 011, 110, 111 (have consecutive 1s)
> 
> **Key insight:** Track strings ending in 0 and strings ending in 1 separately.

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
At position i:
- If previous bit is 0: can place 0 or 1
- If previous bit is 1: can only place 0

**Recurrence Relation:**
```
end0[i] = end0[i-1] + end1[i-1]  (can append 0 after 0 or 1)
end1[i] = end0[i-1]              (can append 1 only after 0)
Total = end0[n] + end1[n]
Base: end0[1]=1, end1[1]=1
```

**Algorithm:**
1. Track two states: ending in 0 and ending in 1
2. Recursively compute both

### Time Complexity: O(2^n)
**Why exponential?**
- Two recursive calls per state
- Overlapping subproblems
- No memoization

### Space Complexity: O(n)
- Recursion stack

> **Key Insight for Improvement:**
> Overlapping subproblems for both states. Memoize to reduce to O(n).

<br>

---

## Solution 2: Memoization (Top-Down DP)

**Intuition:**
Cache results for strings ending in 0 and ending in 1.

**Algorithm:**
1. Create memo for both states
2. Check memo before computing
3. Store and return

### Time Complexity: O(n)
- 2n unique subproblems
- Each computed once

### Space Complexity: O(n)
- Memo + recursion stack

> **Key Insight for Improvement:**
> Remove recursion with iterative approach.

<br>

---

## Solution 3: Tabulation (Bottom-Up DP)

**DP State:**
```
end0[i] = count of valid strings of length i ending in 0
end1[i] = count of valid strings of length i ending in 1
```

**Transition:**
```
end0[i] = end0[i-1] + end1[i-1]
end1[i] = end0[i-1]
```

**Algorithm:**
1. Initialize: end0[1]=1, end1[1]=1
2. For i from 2 to n: apply transitions
3. Return end0[n] + end1[n]

### Time Complexity: O(n)
- Single loop

### Space Complexity: O(n)
- Two arrays

> **Key Insight for Improvement:**
> Only need previous values. Use variables for O(1) space.

<br>

---

## Solution 4: Space Optimized

**Intuition:**
Track only last values for both states.

**Algorithm:**
1. Use variables: prev_end0, prev_end1
2. Update in each iteration

### Time Complexity: O(n)
### Space Complexity: O(1)
- Only 4 variables

**Pattern Recognition:**
- This follows Fibonacci: total[i] = total[i-1] + total[i-2]
- Proof: end0[i] + end1[i] = (end0[i-1] + end1[i-1]) + end0[i-1]
                            = total[i-1] + end0[i-1]
                            = total[i-1] + total[i-2]

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
- Two-state DP (ending in 0 vs 1)
- Reduces to Fibonacci pattern
- Common in constraint-based counting

> **Final Complexity:** O(n) time, O(1) space

<br>
<br>

---

```code```
