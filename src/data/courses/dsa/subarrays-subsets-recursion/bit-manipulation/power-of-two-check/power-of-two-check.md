Check if a number is a power of 2.

<br>

> n=16 → true, n=18 → false
>
> **Key insight:** Power of 2 has exactly one set bit. n > 0 && (n & (n-1)) == 0.

<br>

---

## Constraints
- -2³¹ ≤ N ≤ 2³¹ - 1

<br>

---

## All Possible Edge Cases
1. **N = 0:** NOT power of 2
2. **N negative:** NOT power of 2
3. **N = 1:** IS power of 2

<br>

---

## Solution 1: Divide by 2 repeatedly

**Intuition:**
The most straightforward approach. Multiple divisions.

**Algorithm:**
1. Iterate through all possible candidates/states
2. For each candidate, evaluate the required condition
3. Track the best result seen so far
4. Return the optimal answer

### Time Complexity: O(log N)
**Why?**
Single pass through the input, doing O(1) work per element.
Total: N elements × O(1) per element = O(N).

**Detailed breakdown:**
For N=100,000: ~100,000 operations — very efficient.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Multiple divisions.

> **Key Insight for Improvement:**
> Single operation: n & (n-1) removes the only set bit → result 0 if power of 2.

<br>

---

## Solution 2: Bit Trick (Optimal)

**Intuition:** Power of 2 has exactly one set bit. n > 0 && (n & (n-1)) == 0.

**Algorithm:**
n > 0 && (n & (n-1)) == 0

### Time Complexity: O(1)
**Why?**
Each element/state processed efficiently via the core technique.

**Detailed breakdown:**
Operations scale with input size as described by the complexity.

**Example walkthrough:**
```
16=10000: 10000 & 01111 = 0 → true ✓
18=10010: 10010 & 10001 = 10000 ≠ 0 → false ✓
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Divide by 2 repeatedly | O(log N) | Varies | Baseline |
| Bit Trick | O(1) | O(1) | Optimal approach |

**Recommended Solution:** Bit Trick — O(1) time.

**Key Insights:**
1. **One set bit = power of 2:** Binary: 1, 10, 100, 1000...
2. **n & (n-1) == 0:** Removes the single bit, leaving 0
3. **Check n > 0:** 0 is not a power of 2

<br><br>

---

```code```
