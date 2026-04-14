Minimum days to make M bouquets of K adjacent flowers.

<br>

> bloomDay=[1,10,3,10,2], m=3, k=1 → 3
>
> **Key insight:** Binary search on days. For each candidate day, count adjacent bloomed flowers greedily.

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

## Solution 1: Try all days

**Intuition:**
The most straightforward approach. Linear scan over all possible days.

**Algorithm:**
1. Enumerate all possible candidates
2. For each candidate, verify if it satisfies the condition
3. Track the best valid result
4. Return the optimal answer

### Time Complexity: O(D × N)
**Why?**
Two factors multiply: one from iterating elements, one from the operation per element.
Total = product of both factors.

**Detailed breakdown:**
Depends on both dimensions of the input.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Linear scan over all possible days.

> **Key Insight for Improvement:**
> BS on days: lo=min(bloomDay), hi=max(bloomDay). Count bouquets of K adjacent flowers bloomed by day mid.

<br>

---

## Solution 2: BS on Answer + Adjacent Count (Optimal)

**Intuition:** Binary search on days. For each candidate day, count adjacent bloomed flowers greedily.

**Algorithm:**
1. lo=min(bloom), hi=max(bloom)
2. For each mid: count adjacent groups of K bloomed flowers
3. If bouquets ≥ M → ans=mid, hi=mid-1

### Time Complexity: O(N log D)
**Why?**
Each element/state processed efficiently via the core technique.

**Detailed breakdown:**
Operations scale with input size as described by the complexity.

**Example walkthrough:**
```
[1,10,3,10,2] m=3,k=1 day=3: bloomed=[1,_,3,_,2]→positions 0,2,4→3 bouquets ✓
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Try all days | O(D × N) | Varies | Baseline |
| BS on Answer + Adjacent Count | O(N log D) | O(1) | Optimal approach |

**Recommended Solution:** BS on Answer + Adjacent Count — O(N log D) time.

**Key Insights:**
1. **Adjacent constraint:** Must be K consecutive bloomed flowers
2. **Reset count on gap:** Non-bloomed flower resets adjacent count
3. **Impossible check:** If M*K > N → return -1

<br><br>

---

```code```
