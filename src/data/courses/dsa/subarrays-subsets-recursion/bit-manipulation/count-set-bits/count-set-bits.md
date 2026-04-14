Count the number of 1-bits (set bits) in an integer.

<br>

> n=11 (1011) → 3
>
> **Key insight:** Brian Kernighan's trick: n & (n-1) clears the lowest set bit. Count iterations until n=0.

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

## Solution 1: Check each of 32 bits

**Intuition:**
The most straightforward approach. Always checks all 32 bits even if few are set.

**Algorithm:**
1. Enumerate all possible candidates
2. For each candidate, verify if it satisfies the condition
3. Track the best valid result
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
> Always checks all 32 bits even if few are set.

> **Key Insight for Improvement:**
> Brian Kernighan's: n = n & (n-1) removes exactly one set bit per step. Loop count = set bits.

<br>

---

## Solution 2: Brian Kernighan's Algorithm (Optimal)

**Intuition:** Brian Kernighan's trick: n & (n-1) clears the lowest set bit. Count iterations until n=0.

**Algorithm:**
1. count = 0
2. While n > 0: n = n & (n-1), count++
3. Return count

### Time Complexity: O(set bits)
**Why?**
Each element/state processed efficiently via the core technique.

**Detailed breakdown:**
Operations scale with input size as described by the complexity.

**Example walkthrough:**
```
n=11(1011): 1011&1010=1010(count=1), 1010&1001=1000(count=2), 1000&0111=0(count=3)
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Check each of 32 bits | O(32) | Varies | Baseline |
| Brian Kernighan's Algorithm | O(set bits) | O(1) | Optimal approach |

**Recommended Solution:** Brian Kernighan's Algorithm — O(set bits) time.

**Key Insights:**
1. **n & (n-1):** Clears lowest set bit — elegant trick
2. **O(set bits):** Only loops for actual 1-bits, not all 32
3. **Also called:** popcount, Hamming weight

<br><br>

---

```code```
