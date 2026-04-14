Compute combinations nCr and permutations nPr.

<br>

> C(5,2)=10, P(5,2)=20
>
> **Key insight:** nCr = n!/(r!×(n-r)!). Pascal's triangle: C(n,r)=C(n-1,r-1)+C(n-1,r). nPr = n!/(n-r)!.

<br>

---

## Constraints
- 0 ≤ R ≤ N ≤ 10⁶

<br>

---

## Solution 1: Direct factorial

**Intuition:**
The most straightforward approach. Factorials grow fast — overflow even for moderate N.

**Algorithm:**
1. Iterate through all possible candidates/states
2. For each candidate, evaluate the required condition
3. Track the best result seen so far
4. Return the optimal answer

### Time Complexity: O(N) but overflow risk
**Why?**
Single pass through the input, doing O(1) work per element.
Total: N elements × O(1) per element = O(N).

**Detailed breakdown:**
For N=100,000: ~100,000 operations — very efficient.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Factorials grow fast — overflow even for moderate N.

> **Key Insight for Improvement:**
> Multiplicative formula with modular inverse, or Pascal's triangle for exact values.

<br>

---

## Solution 2: Pascal's Triangle / Multiplicative (Optimal)

**Intuition:** nCr = n!/(r!×(n-r)!). Pascal's triangle: C(n,r)=C(n-1,r-1)+C(n-1,r). nPr = n!/(n-r)!.

**Algorithm:**
C(n,r) = (n × (n-1) × ... × (n-r+1)) / (r × (r-1) × ... × 1)
With mod: multiply then apply modular inverse for division

### Time Complexity: O(R) or O(N²) for Pascal's
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
C(5,2) = (5×4)/(2×1) = 10
P(5,2) = 5×4 = 20
```

### Space Complexity: O(1) or O(N²)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Direct factorial | O(N) but overflow risk | Varies | Baseline |
| Pascal's Triangle / Multiplicative | O(R) or O(N²) for Pascal's | O(1) or O(N²) | Optimal |

**Recommended Solution:** Pascal's Triangle / Multiplicative

**Key Insights:**
1. **Pascal's triangle:** No division needed, exact integers
2. **Multiplicative + mod inverse:** For large N with mod
3. **Lucas' theorem:** For very large N with prime mod

<br><br>

---

```code```
