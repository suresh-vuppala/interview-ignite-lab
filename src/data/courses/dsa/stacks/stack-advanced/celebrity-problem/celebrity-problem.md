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

## Solution 1: Brute Force — Check All

### Time Complexity: O(N²) — check each person against all others

> **Drawback:** Checking all N² pairs. Each comparison eliminates exactly one person — we should need only N-1 comparisons to find the candidate.

> **Key Insight for Improvement:** Push all people on stack. Pop two, compare: if A knows B, A is eliminated. If not, B is eliminated. Push the survivor. After N-1 rounds, one candidate remains. Verify in O(N).

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
