Check if a number N is prime.

<br>

> N=17 → true, N=15 → false
>
> **Key insight:** Check divisibility from 2 to √N. If any divides N, not prime.

<br>

---

## Constraints
- 1 ≤ N ≤ 10⁹

<br>

---

## All Possible Edge Cases
1. **N = 0 or 1:** NOT prime
2. **N = 2:** smallest and only even prime
3. **Even N > 2:** NOT prime
4. **Large prime near 10⁹**

<br>

---

## Solution 1: Check all 2 to N-1

**Intuition:**
The most straightforward approach. Checking all numbers is overkill.

**Algorithm:**
1. Enumerate all possible candidates
2. For each candidate, verify if it satisfies the condition
3. Track the best valid result
4. Return the optimal answer

### Time Complexity: O(N)
**Why?**
Single pass through the input, doing O(1) work per element.
Total: N elements × O(1) per element = O(N).

**Detailed breakdown:**
For N=100,000: ~100,000 operations — very efficient.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Checking all numbers is overkill.

> **Key Insight for Improvement:**
> Only check up to √N: if N has a factor > √N, the paired factor is < √N.

<br>

---

## Solution 2: Square Root Check (Optimal)

**Intuition:** Check divisibility from 2 to √N. If any divides N, not prime.

**Algorithm:**
1. If N ≤ 1: not prime
2. If N ≤ 3: prime
3. If N%2==0 or N%3==0: not prime
4. For i=5 to √N, step 6: if N%i==0 or N%(i+2)==0: not prime

### Time Complexity: O(√N)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
17: not div by 2,3. Check 5: 5²=25>17→stop. Prime ✓
15: div by 3→not prime ✓
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Check all 2 to N-1 | O(N) | Varies | Baseline |
| Square Root Check | O(√N) | O(1) | Optimal |

**Recommended Solution:** Square Root Check

**Key Insights:**
1. **6k±1 optimization:** All primes > 3 are of form 6k±1
2. **√N bound:** If no factor ≤ √N, N is prime
3. **Skip even numbers:** After checking 2, only check odds

<br><br>

---

```code```
