Compute GCD using Euclidean algorithm and LCM from GCD.

<br>

> gcd(12,8)=4, lcm(12,8)=24
>
> **Key insight:** Euclidean: gcd(a,b) = gcd(b, a%b), base: gcd(a,0)=a. LCM = a×b/gcd(a,b).

<br>

---

## Constraints
- 1 ≤ a, b ≤ 10⁹

<br>

---

## Solution 1: Trial division

**Intuition:**
The most straightforward approach. Checking all divisors up to min.

**Algorithm:**
1. Iterate through all possible candidates/states
2. For each candidate, evaluate the required condition
3. Track the best result seen so far
4. Return the optimal answer

### Time Complexity: O(min(a,b))
**Why?**
The approach processes each state/element with the work described by the complexity.
Total operations scale accordingly with input size.

**Detailed breakdown:**
Verify against constraint limits to ensure it passes within time.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Checking all divisors up to min.

> **Key Insight for Improvement:**
> Euclidean algorithm: repeated modulo until 0. O(log(min(a,b))).

<br>

---

## Solution 2: Euclidean Algorithm (Optimal)

**Intuition:** Euclidean: gcd(a,b) = gcd(b, a%b), base: gcd(a,0)=a. LCM = a×b/gcd(a,b).

**Algorithm:**
gcd(a,b): if b==0 return a, else return gcd(b, a%b)
lcm(a,b) = a / gcd(a,b) * b (divide first to avoid overflow)

### Time Complexity: O(log(min(a,b)))
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
gcd(48,18): gcd(18,48%18)=gcd(18,12)=gcd(12,6)=gcd(6,0)=6
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Trial division | O(min(a,b)) | Varies | Baseline |
| Euclidean Algorithm | O(log(min(a,b))) | O(1) | Optimal |

**Recommended Solution:** Euclidean Algorithm

**Key Insights:**
1. **a%b shrinks rapidly:** Logarithmic convergence
2. **LCM overflow prevention:** Divide before multiply
3. **Extended GCD:** Also finds x,y where ax+by=gcd(a,b)

<br><br>

---

```code```
