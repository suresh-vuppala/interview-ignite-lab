Common mathematical patterns in competitive programming.

<br>

> Fibonacci, Catalan, fast exponentiation, modular arithmetic
>
> **Key insight:** Pattern recognition + mathematical formulas for efficient solutions.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: Ad-hoc computation

### Time Complexity: Varies

> **Drawback:**
> Without knowing patterns, each problem is solved from scratch.

> **Key Insight for Improvement:**
> Learn common sequences: Fibonacci O(N), Catalan O(N), fast exp O(log N), etc.

<br>

---

## Solution 2: Pattern Library (Optimal)

**Intuition:** Pattern recognition + mathematical formulas for efficient solutions.

**Algorithm:**
Fibonacci: F(n)=F(n-1)+F(n-2)
Catalan: C(n)=C(2n,n)/(n+1) — counts BSTs, parenthesizations, etc.
Fast exp: a^n in O(log n) via squaring
Euler's totient: count of coprime numbers < N

### Time Complexity: Varies
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
Catalan(3)=5: 5 different BSTs with 3 nodes
Fast exp: 2^10 = (2^5)^2 = ((2^2)^2×2)^2
```

### Space Complexity: Varies

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Ad-hoc computation | Varies | Varies | Baseline |
| Pattern Library | Varies | Varies | Optimal |

**Recommended Solution:** Pattern Library

**Key Insights:**
1. **Catalan numbers:** BSTs, valid parentheses, polygon triangulations
2. **Fast exponentiation:** Binary method for O(log N) power
3. **Inclusion-exclusion:** Count by adding/subtracting overlaps

<br><br>

---

```code```
