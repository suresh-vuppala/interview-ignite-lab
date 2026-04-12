Compute GCD (Euclidean algorithm) and LCM.

<br>

> **Key insight:** gcd(a,b) = gcd(b, a%b). LCM = a*b / gcd(a,b).

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Euclidean: gcd(a,b) = gcd(b, a%b), base: gcd(a,0)=a

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Euclidean: gcd(a,b) = gcd(b, a%b), base: gcd(a,0)=a`

### Time Complexity: O(log(min(a,b)))
**Why?** Each element/state processed efficiently.

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(log(min(a,b))) | O(1) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
