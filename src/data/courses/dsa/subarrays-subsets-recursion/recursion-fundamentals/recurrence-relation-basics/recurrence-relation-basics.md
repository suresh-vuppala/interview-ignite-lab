Solve recurrence relations using Master Theorem and substitution.

<br>

> T(N)=2T(N/2)+N → O(N log N) by Master Theorem
>
> **Key insight:** Master Theorem: T(N)=aT(N/b)+O(N^d). Compare log_b(a) with d. If equal: O(N^d log N).

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: Trial and error

**Intuition:**
The most straightforward approach. Guessing complexity without proof.

**Algorithm:**
1. Iterate through all possible candidates/states
2. For each candidate, evaluate the required condition
3. Track the best result seen so far
4. Return the optimal answer

### Time Complexity: Imprecise
**Why?**
The approach processes each state/element with the work described by the complexity.
Total operations scale accordingly with input size.

**Detailed breakdown:**
Verify against constraint limits to ensure it passes within time.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Guessing complexity without proof.

> **Key Insight for Improvement:**
> Master Theorem gives direct answer for divide-and-conquer recurrences.

<br>

---

## Solution 2: Master Theorem (Optimal)

**Intuition:** Master Theorem: T(N)=aT(N/b)+O(N^d). Compare log_b(a) with d. If equal: O(N^d log N).

**Algorithm:**
T(N)=aT(N/b)+O(N^d):
Case 1: log_b(a) > d → O(N^(log_b a))
Case 2: log_b(a) = d → O(N^d log N)
Case 3: log_b(a) < d → O(N^d)

### Time Complexity: Varies
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
Merge sort: T(N)=2T(N/2)+O(N) → a=2,b=2,d=1, log_2(2)=1=d → Case 2: O(N log N)
```

### Space Complexity: Varies

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Trial and error | Imprecise | Varies | Baseline |
| Master Theorem | Varies | Varies | Optimal |

**Recommended Solution:** Master Theorem

**Key Insights:**
1. **Three cases:** Compare log_b(a) with d
2. **Common results:** Binary search O(log N), merge sort O(N log N)
3. **Not all recurrences fit:** Some need Akra-Bazzi or substitution

<br><br>

---

```code```
