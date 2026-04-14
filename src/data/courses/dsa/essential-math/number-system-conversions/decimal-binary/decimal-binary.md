Convert between decimal and binary representations.

<br>

> 13 → '1101', '1101' → 13
>
> **Key insight:** Decimal→Binary: repeatedly divide by 2, collect remainders. Binary→Decimal: positional value sum.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: N/A — direct conversion

**Intuition:**
The most straightforward approach. Already efficient.

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
> Already efficient.

> **Key Insight for Improvement:**
> Standard conversion algorithms.

<br>

---

## Solution 2: Division/Multiplication (Optimal)

**Intuition:** Decimal→Binary: repeatedly divide by 2, collect remainders. Binary→Decimal: positional value sum.

**Algorithm:**
Dec→Bin: while n>0: bits.append(n%2), n=n//2, reverse
Bin→Dec: for each bit: result = result*2 + bit

### Time Complexity: O(log N)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
13: 13%2=1, 6%2=0, 3%2=1, 1%2=1 → reverse: 1101
1101: 1×8+1×4+0×2+1×1=13
```

### Space Complexity: O(log N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| N/A — direct conversion | O(log N) | Varies | Baseline |
| Division/Multiplication | O(log N) | O(log N) | Optimal |

**Recommended Solution:** Division/Multiplication

**Key Insights:**
1. **%2 gives LSB:** Build binary right-to-left, reverse at end
2. **×2 + bit:** Horner's method for binary→decimal
3. **Foundation:** Understanding bit manipulation

<br><br>

---

```code```
