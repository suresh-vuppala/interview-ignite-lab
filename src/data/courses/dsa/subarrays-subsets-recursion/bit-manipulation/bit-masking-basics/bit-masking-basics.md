Understand AND, OR, XOR, NOT, left/right shift operations and their properties.

<br>

> 5 & 3 = 1, 5 | 3 = 7, 5 ^ 3 = 6, ~5 = -6, 5<<1 = 10
>
> **Key insight:** AND masks bits, OR sets bits, XOR toggles/finds differences, shift multiplies/divides by 2.

<br>

---

## Constraints
- 0 ≤ N ≤ 2³¹ - 1

<br>

---

## All Possible Edge Cases
1. **N = 0:** all bits zero
2. **N = -1 (signed):** all bits one
3. **Overflow with left shift**

<br>

---

## Solution 1: N/A — foundational

**Intuition:**
The most straightforward approach. N/A — these are primitive operations.

**Algorithm:**
1. Iterate through all possible candidates/states
2. For each candidate, evaluate the required condition
3. Track the best result seen so far
4. Return the optimal answer

### Time Complexity: O(1)
**Why?**
The approach processes each state/element with the work described by the complexity.
Total operations scale accordingly with input size.

**Detailed breakdown:**
Verify against constraint limits to ensure it passes within time.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> N/A — these are primitive operations.

> **Key Insight for Improvement:**
> Master these operations for all bit manipulation problems.

<br>

---

## Solution 2: Bit Operations (Optimal)

**Intuition:** AND masks bits, OR sets bits, XOR toggles/finds differences, shift multiplies/divides by 2.

**Algorithm:**
AND(&): both 1→1. OR(|): either 1→1. XOR(^): different→1. NOT(~): flip all.
Left shift (<<): multiply by 2. Right shift (>>): divide by 2.

### Time Complexity: O(1)
**Why?**
Each element/state processed efficiently via the core technique.

**Detailed breakdown:**
Operations scale with input size as described by the complexity.

**Example walkthrough:**
```
5=101, 3=011: AND=001=1, OR=111=7, XOR=110=6
5<<1=1010=10, 5>>1=10=2
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| N/A — foundational | O(1) | Varies | Baseline |
| Bit Operations | O(1) | O(1) | Optimal approach |

**Recommended Solution:** Bit Operations — O(1) time.

**Key Insights:**
1. **XOR properties:** a^a=0, a^0=a, commutative, associative
2. **AND masking:** n & (1<<k) checks kth bit
3. **Foundation:** Every bit problem uses these operations

<br><br>

---

```code```
