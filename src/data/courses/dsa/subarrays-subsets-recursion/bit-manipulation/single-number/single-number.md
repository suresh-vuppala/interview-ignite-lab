Every element appears twice except one. Find the single one.

<br>

> nums=[2,2,1] → 1
>
> **Key insight:** XOR all elements. Pairs cancel (a^a=0). Single number remains (0^a=a).

<br>

---

## Constraints
- 1 ≤ N ≤ 3 × 10⁴
- Every element appears twice except one

<br>

---

## All Possible Edge Cases
1. **Single element array**
2. **Single number is 0**
3. **Negative numbers**

<br>

---

## Solution 1: Hash set tracking

**Intuition:**
The most straightforward approach. Extra space for the set.

**Algorithm:**
1. Initialize a hash set/map for tracking
2. Iterate through each element
3. Check against the hash set/map for the required condition
4. Update the hash set/map with the current element

### Time Complexity: O(N) time, O(N) space
**Why?**
Single pass through the input, doing O(1) work per element.
Total: N elements × O(1) per element = O(N).

**Detailed breakdown:**
For N=100,000: ~100,000 operations — very efficient.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Extra space for the set.

> **Key Insight for Improvement:**
> XOR all: a^a=0 cancels pairs. 0^single=single remains. O(1) space.

<br>

---

## Solution 2: XOR All Elements (Optimal)

**Intuition:** XOR all elements. Pairs cancel (a^a=0). Single number remains (0^a=a).

**Algorithm:**
result = 0. For each num: result ^= num. Return result.

### Time Complexity: O(N)
**Why?**
Each element/state processed efficiently via the core technique.

**Detailed breakdown:**
Operations scale with input size as described by the complexity.

**Example walkthrough:**
```
[2,2,1]: 0^2=2, 2^2=0, 0^1=1 → single=1 ✓
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Hash set tracking | O(N) time, O(N) space | Varies | Baseline |
| XOR All Elements | O(N) | O(1) | Optimal approach |

**Recommended Solution:** XOR All Elements — O(N) time.

**Key Insights:**
1. **XOR properties:** a^a=0, a^0=a, commutative
2. **Pairs cancel perfectly:** Only unpaired element survives
3. **FAANG classic:** Elegant O(1) space solution

<br><br>

---

```code```
