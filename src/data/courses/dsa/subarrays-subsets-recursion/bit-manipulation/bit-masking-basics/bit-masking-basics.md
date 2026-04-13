Understand AND, OR, XOR, NOT, left/right shift operations and their properties.

<br>

> 5 & 3 = 1, 5 | 3 = 7, 5 ^ 3 = 6, ~5 = -6, 5<<1 = 10
>
> **Key insight:** AND masks bits, OR sets bits, XOR toggles/finds differences, shift multiplies/divides by 2.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## All Possible Edge Cases
1. **Empty/single element input**
2. **Boundary values** (min/max of range)
3. **All elements same / sorted / reverse sorted**

<br>

---

## Solution 1: N/A — foundational

### Time Complexity: O(1)

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
