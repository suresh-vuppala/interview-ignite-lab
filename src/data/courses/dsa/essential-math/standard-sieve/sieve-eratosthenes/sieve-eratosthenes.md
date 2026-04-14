Find all primes up to N using the Sieve of Eratosthenes.

<br>

> N=20 → [2,3,5,7,11,13,17,19]
>
> **Key insight:** Mark multiples of each prime starting from p². All unmarked numbers are prime.

<br>

---

## Constraints
- 2 ≤ N ≤ 10⁷

<br>

---

## Solution 1: Check each number individually

**Intuition:**
The most straightforward approach. Individual primality tests are slower combined.

**Algorithm:**
1. Enumerate all possible candidates
2. For each candidate, verify if it satisfies the condition
3. Track the best valid result
4. Return the optimal answer

### Time Complexity: O(N√N)
**Why?**
Single pass through the input, doing O(1) work per element.
Total: N elements × O(1) per element = O(N).

**Detailed breakdown:**
For N=100,000: ~100,000 operations — very efficient.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Individual primality tests are slower combined.

> **Key Insight for Improvement:**
> Sieve: mark multiples starting from p² (smaller multiples already marked by smaller primes).

<br>

---

## Solution 2: Sieve of Eratosthenes (Optimal)

**Intuition:** Mark multiples of each prime starting from p². All unmarked numbers are prime.

**Algorithm:**
1. Create boolean array is_prime[0..N] = true
2. is_prime[0]=is_prime[1]=false
3. For p=2 to √N: if is_prime[p]:
   - Mark p², p²+p, p²+2p, ... as false
4. Collect all true indices

### Time Complexity: O(N log log N)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
Mark multiples of 2: 4,6,8,10...
Mark multiples of 3: 9,12,15...
Mark multiples of 5: 25... (>20 so skip)
Primes: [2,3,5,7,11,13,17,19]
```

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Check each number individually | O(N√N) | Varies | Baseline |
| Sieve of Eratosthenes | O(N log log N) | O(N) | Optimal |

**Recommended Solution:** Sieve of Eratosthenes

**Key Insights:**
1. **Start from p²:** Smaller multiples already marked by smaller primes
2. **O(N log log N):** Nearly linear — very efficient
3. **Foundation:** Prime factorization, Euler's totient, number theory

<br><br>

---

```code```
