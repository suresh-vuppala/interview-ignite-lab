## Overview
Understand basic game theory concepts including Nim game and stone-taking games.

## Topics Covered
1. **Nim Game**: XOR-based winning strategy
2. **Take 1 or 2 Stones**: Dynamic programming approach
3. **Winning/Losing Positions**: Game state analysis

## Approach
### Nim Game
- XOR all pile sizes
- If XOR = 0, losing position; else winning
- Time: O(n)

### Take 1 or 2 Stones
- Losing positions: multiples of 3
- Time: O(1)

## Complexity Analysis
### Time: O(n) for Nim, O(1) for simple games

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
