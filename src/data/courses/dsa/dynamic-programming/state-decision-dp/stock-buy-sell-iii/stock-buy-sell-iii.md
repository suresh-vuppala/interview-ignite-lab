At most 2 transactions. Maximize profit.

<br>

> **Key insight:** Track buy1, profit1, buy2, profit2 in one pass. buy2 considers profit1 as discount.

<br>

---

## Constraints
- Typical DP constraints

<br>

---

## Solution 1: Recursion

**Intuition:**
The most straightforward approach — try all possibilities and check each one.

**Algorithm:**
1. Define recursive function with current state
2. At each step, try all possible choices
3. Recurse on remaining subproblem
4. Base case: return when subproblem is solved

### Time Complexity: O(N²)
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

## Solution 2: DP — Bottom-up

**Recurrence:** `State machine / track approach`

### Time Complexity: O(N)
**Why?** Each state computed once.

### Space Complexity: O(1) or O(K)

**Example walkthrough:**
```
Single pass through prices/values tracking states
```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Recursion | Exponential | O(N) stack |
| DP | O(N) | O(1) or O(K) |

**Key Insights:**
1. Identify states, transitions, base cases
2. Space optimization when possible


<br><br>

---

```code```
