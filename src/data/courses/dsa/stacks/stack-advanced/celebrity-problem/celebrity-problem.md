In a party of N people, find the celebrity. A celebrity is known by everyone but knows nobody. Given a knows(a, b) function.

<br>

> Input: N=4, knows matrix: person 2 is known by all, knows nobody
> Output: 2

> Explanation: Person 2 is the celebrity — everyone knows them, they know nobody.
> 
> **Key insight:** Use a stack to eliminate non-celebrities. If A knows B, A is not celebrity. If A doesn't know B, B is not celebrity. Each comparison eliminates one person. N-1 comparisons → one candidate left → verify.

<br>

---

## Constraints
- `2 ≤ N ≤ 100`
- At most one celebrity exists

<br>

---

## All Possible Edge Cases
1. **No celebrity exists: return -1
2. **First person is celebrity
3. **Last person is celebrity
4. **Everyone knows everyone: no celebrity**

<br>

---

## Solution 1: Brute Force — Check All

**Intuition:**
The most straightforward approach — try all possibilities and check each one.

**Algorithm:**
1. For each element i (outer loop):
   - For each element j (inner loop):
     - Check if the pair/condition is satisfied
2. Return the best result found

### Time Complexity: O(N²) — check each person against all others
**Why?**
Two nested loops each running up to N iterations.
Outer loop: N iterations × Inner loop: up to N iterations = N² total operations.

**Detailed breakdown:**
For N=1,000: ~1 million operations (OK). For N=10,000: ~100 million (borderline TLE).

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Suboptimal time complexity for large inputs. Redundant work is performed.

> **Key Insight for Improvement:**
> Use a more efficient data structure or algorithm to reduce redundant computation.

<br>

---

## Solution 2: Stack Elimination + Verify (Optimal)

**Algorithm:**
1. Push all N people onto stack
2. While stack has > 1 person: pop A and B. If knows(A,B) → push B (A eliminated). Else → push A.
3. Candidate = last remaining. Verify: everyone knows candidate AND candidate knows nobody.

### Time Complexity: O(N)
**Why?** N-1 elimination comparisons + 2(N-1) verification comparisons = O(N).

**Detailed breakdown:** N = 100 → ~300 knows() calls

### Space Complexity: O(N) for initial stack

> **Drawback:** Uses O(N) space for the stack.

> **Key Insight for Improvement:** Two-pointer approach achieves the same O(N) with O(1) space: start with candidate=0, scan 1..N-1, eliminate using same logic.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N²) | O(1) | Check all pairs |
| Stack Elimination | O(N) | O(N) | Each comparison eliminates one |

**Key Insights:**
1. **Elimination:** Each knows() call eliminates exactly one candidate
2. **N-1 comparisons → 1 candidate:** Then verify in O(N)
3. **Two-pointer alternative:** O(1) space version uses same elimination logic

<br><br>

---

```code```
