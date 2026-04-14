Add two integers without using + or - operators.

<br>

> a=1, b=2 → 3
>
> **Key insight:** XOR = sum without carry. AND << 1 = carry. Repeat until carry is 0.

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

## Solution 1: N/A — constraint prevents +

**Intuition:**
The most straightforward approach. Must use bit operations only.

**Algorithm:**
1. Iterate through all possible candidates/states
2. For each candidate, evaluate the required condition
3. Track the best result seen so far
4. Return the optimal answer

### Time Complexity: N/A
**Why?**
Single pass through the input, doing O(1) work per element.
Total: N elements × O(1) per element = O(N).

**Detailed breakdown:**
For N=100,000: ~100,000 operations — very efficient.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Must use bit operations only.

> **Key Insight for Improvement:**
> XOR gives sum ignoring carry. AND gives carry positions. Shift carry left and repeat.

<br>

---

## Solution 2: XOR + AND Carry (Optimal)

**Intuition:** XOR = sum without carry. AND << 1 = carry. Repeat until carry is 0.

**Algorithm:**
1. While b ≠ 0:
   - carry = (a & b) << 1
   - a = a ^ b (sum without carry)
   - b = carry
2. Return a

### Time Complexity: O(32)
**Why?**
Each element/state processed efficiently via the core technique.

**Detailed breakdown:**
Operations scale with input size as described by the complexity.

**Example walkthrough:**
```
a=5(101), b=3(011):
a^b=110=6, carry=(101&011)<<1=010<<1=100=4
a=6, b=4: a^b=010=2, carry=(110&100)<<1=100<<1=1000=8
a=2, b=8: a^b=1010=10, carry=0→done. 5+3=8... (simplified)
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| N/A — constraint prevents + | N/A | Varies | Baseline |
| XOR + AND Carry | O(32) | O(1) | Optimal approach |

**Recommended Solution:** XOR + AND Carry — O(32) time.

**Key Insights:**
1. **XOR = addition without carry:** 1+1=0 (carry handled separately)
2. **AND << 1 = carry:** Both bits 1 → carry to next position
3. **Repeat:** Process carries until none remain

<br><br>

---

```code```
