## Overview
Understand Grundy numbers (Sprague-Grundy theorem) for solving impartial games.

## Topics Covered
1. **Grundy Number Definition**: MEX of reachable states
2. **Calculate Grundy**: For game positions
3. **Combine Games**: XOR of Grundy numbers

## Approach
### Grundy Number
- Grundy(position) = MEX({Grundy(next_positions)})
- MEX = Minimum Excludant (smallest non-negative integer not in set)
- Time: Depends on game complexity

### Winning Strategy
- Grundy = 0: Losing position
- Grundy ≠ 0: Winning position

## Complexity Analysis
### Time: O(states * transitions)

## Code


---

## Constraints

- `1 ≤ n ≤ 10⁹ (for number theory problems)`
- `Results may need modular arithmetic`

<br>

---

## All Possible Edge Cases

1. **n = 0:** Check base case definition
2. **n = 1:** Smallest valid input
3. **Prime number input:** Special behavior in factorization/sieve
4. **Power of 2:** Special case in many algorithms
5. **Very large n:** Needs O(√n) or O(log n) algorithm
6. **n = 0 or 1 in GCD:** GCD(a,0) = a, GCD(1,b) = 1

<br>

---

```code```
