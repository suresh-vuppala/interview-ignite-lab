Check if a number is a power of 2.

<br>

> n=16 → true, n=18 → false
>
> **Key insight:** Power of 2 has exactly one set bit. n > 0 && (n & (n-1)) == 0.

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

## Solution 1: Divide by 2 repeatedly

### Time Complexity: O(log N)

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
