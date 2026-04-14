Reverse all 32 bits of an unsigned integer.

<br>

> n=43261596 → 964176192
>
> **Key insight:** Extract LSB, build result from MSB. Shift result left, OR with extracted bit. Repeat 32 times.

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

## Solution 1: Convert to string, reverse

**Intuition:**
The most straightforward approach. String conversion overhead.

**Algorithm:**
1. Iterate through all possible candidates/states
2. For each candidate, evaluate the required condition
3. Track the best result seen so far
4. Return the optimal answer

### Time Complexity: O(32)
**Why?**
The approach processes each state/element with the work described by the complexity.
Total operations scale accordingly with input size.

**Detailed breakdown:**
Verify against constraint limits to ensure it passes within time.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> String conversion overhead.

> **Key Insight for Improvement:**
> Bit-by-bit: extract rightmost bit of n, shift result left and OR. Shift n right.

<br>

---

## Solution 2: Bit-by-Bit Reversal (Optimal)

**Intuition:** Extract LSB, build result from MSB. Shift result left, OR with extracted bit. Repeat 32 times.

**Algorithm:**
1. result = 0
2. For 32 iterations:
   - result = (result << 1) | (n & 1)
   - n >>= 1
3. Return result

### Time Complexity: O(32) = O(1)
**Why?**
Each element/state processed efficiently via the core technique.

**Detailed breakdown:**
Operations scale with input size as described by the complexity.

**Example walkthrough:**
```
n=1011: iter1: result=1, n=101
iter2: result=11, n=10
iter3: result=110, n=1
iter4: result=1101 → reversed!
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Convert to string, reverse | O(32) | Varies | Baseline |
| Bit-by-Bit Reversal | O(32) = O(1) | O(1) | Optimal approach |

**Recommended Solution:** Bit-by-Bit Reversal — O(32) = O(1) time.

**Key Insights:**
1. **Extract LSB:** n & 1 gets rightmost bit
2. **Build from left:** result << 1 shifts, OR appends new bit
3. **32 iterations:** Fixed — always process all bits

<br><br>

---

```code```
