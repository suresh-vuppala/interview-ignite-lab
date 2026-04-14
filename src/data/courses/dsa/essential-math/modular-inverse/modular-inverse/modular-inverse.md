Find modular multiplicative inverse of a under mod m.

<br>

> a⁻¹ mod m: a × a⁻¹ ≡ 1 (mod m)
>
> **Key insight:** Fermat's little theorem: if m is prime, a⁻¹ = a^(m-2) mod m. Use fast exponentiation.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: Try all values

**Intuition:**
The most straightforward approach. Linear search for inverse.

**Algorithm:**
1. Enumerate all possible candidates
2. For each candidate, verify if it satisfies the condition
3. Track the best valid result
4. Return the optimal answer

### Time Complexity: O(m)
**Why?**
The approach processes each state/element with the work described by the complexity.
Total operations scale accordingly with input size.

**Detailed breakdown:**
Verify against constraint limits to ensure it passes within time.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Linear search for inverse.

> **Key Insight for Improvement:**
> Fermat's: a^(m-2) mod m via binary exponentiation in O(log m).

<br>

---

## Solution 2: Fermat's + Fast Exponentiation (Optimal)

**Intuition:** Fermat's little theorem: if m is prime, a⁻¹ = a^(m-2) mod m. Use fast exponentiation.

**Algorithm:**
1. Compute a^(m-2) mod m using binary exponentiation
2. Binary exp: result=1, while exp>0: if exp&1 → result×=base; base×=base; exp>>=1
3. All operations mod m

### Time Complexity: O(log m)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
3⁻¹ mod 7: 3^5 mod 7 = 243 mod 7 = 5. Check: 3×5=15≡1(mod 7) ✓
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Try all values | O(m) | Varies | Baseline |
| Fermat's + Fast Exponentiation | O(log m) | O(1) | Optimal |

**Recommended Solution:** Fermat's + Fast Exponentiation

**Key Insights:**
1. **Only works when m is prime:** Fermat's little theorem requirement
2. **Extended GCD alternative:** Works for any coprime a,m
3. **Binary exponentiation:** O(log m) via squaring

<br><br>

---

```code```
