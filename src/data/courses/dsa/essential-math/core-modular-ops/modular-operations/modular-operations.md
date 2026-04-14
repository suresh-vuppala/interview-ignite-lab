Modular arithmetic: addition, subtraction, multiplication.

<br>

> (a+b)%m, (a-b+m)%m, (a*b)%m
>
> **Key insight:** Distribute mod over +, -, ×. Subtraction: add m before mod to handle negatives.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: Direct computation

**Intuition:**
The most straightforward approach. Large numbers can overflow before taking mod.

**Algorithm:**
1. Iterate through all possible candidates/states
2. For each candidate, evaluate the required condition
3. Track the best result seen so far
4. Return the optimal answer

### Time Complexity: Overflow risk
**Why?**
The approach processes each state/element with the work described by the complexity.
Total operations scale accordingly with input size.

**Detailed breakdown:**
Verify against constraint limits to ensure it passes within time.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Large numbers can overflow before taking mod.

> **Key Insight for Improvement:**
> Apply mod at each step to prevent overflow.

<br>

---

## Solution 2: Modular Properties (Optimal)

**Intuition:** Distribute mod over +, -, ×. Subtraction: add m before mod to handle negatives.

**Algorithm:**
(a+b)%m = ((a%m)+(b%m))%m
(a-b)%m = ((a%m)-(b%m)+m)%m
(a*b)%m = ((a%m)*(b%m))%m

### Time Complexity: O(1)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
(7+5)%3 = ((7%3)+(5%3))%3 = (1+2)%3 = 0 ✓
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Direct computation | Overflow risk | Varies | Baseline |
| Modular Properties | O(1) | O(1) | Optimal |

**Recommended Solution:** Modular Properties

**Key Insights:**
1. **Distribute mod:** Apply to each operand first
2. **Add m for subtraction:** Prevents negative results
3. **Overflow prevention:** Mod after each multiplication

<br><br>

---

```code```
