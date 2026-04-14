Minimum eating speed K to finish all banana piles in H hours.

<br>

> piles=[3,6,7,11], H=8 → 4
>
> **Key insight:** Binary search on speed. At speed K: hours = sum(ceil(pile/K)). If hours ≤ H → feasible.

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

## Solution 1: Try all speeds 1..max

**Intuition:**
The most straightforward approach. Linear search over all speeds.

**Algorithm:**
1. Enumerate all possible candidates
2. For each candidate, verify if it satisfies the condition
3. Track the best valid result
4. Return the optimal answer

### Time Complexity: O(max × N)
**Why?**
Two factors multiply: one from iterating elements, one from the operation per element.
Total = product of both factors.

**Detailed breakdown:**
Depends on both dimensions of the input.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Linear search over all speeds.

> **Key Insight for Improvement:**
> BS on speed: lo=1, hi=max(piles). Time = sum(ceil(pile/K)). If ≤ H → try slower.

<br>

---

## Solution 2: BS on Answer (Optimal)

**Intuition:** Binary search on speed. At speed K: hours = sum(ceil(pile/K)). If hours ≤ H → feasible.

**Algorithm:**
1. lo=1, hi=max(piles)
2. hours(K) = sum(ceil(pile/K) for pile in piles)
3. If hours ≤ H → ans=K, hi=K-1
4. Else → lo=K+1

### Time Complexity: O(N log M)
**Why?**
Each element/state processed efficiently via the core technique.

**Detailed breakdown:**
Operations scale with input size as described by the complexity.

**Example walkthrough:**
```
piles=[3,6,7,11] H=8 K=4:
ceil(3/4)+ceil(6/4)+ceil(7/4)+ceil(11/4)=1+2+2+3=8 ≤ 8 → ans=4 ✓
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Try all speeds 1..max | O(max × N) | Varies | Baseline |
| BS on Answer | O(N log M) | O(1) | Optimal approach |

**Recommended Solution:** BS on Answer — O(N log M) time.

**Key Insights:**
1. **Ceiling division:** (pile+K-1)/K or ceil(pile/K)
2. **lo=1:** Minimum possible speed
3. **LeetCode 875:** Classic BS-on-answer

<br><br>

---

```code```
