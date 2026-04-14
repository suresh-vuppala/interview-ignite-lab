Find minimum ship capacity to ship all packages within D days.

<br>

> weights=[1,2,3,4,5,6,7,8,9,10], D=5 → 15
>
> **Key insight:** Binary search on capacity. Greedy: load packages sequentially, start new day when exceeding capacity.

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

## Solution 1: Try all capacities

**Intuition:**
The most straightforward approach. Linear search over all possible capacities.

**Algorithm:**
1. Enumerate all possible candidates
2. For each candidate, verify if it satisfies the condition
3. Track the best valid result
4. Return the optimal answer

### Time Complexity: O(max_cap × N)
**Why?**
Two factors multiply: one from iterating elements, one from the operation per element.
Total = product of both factors.

**Detailed breakdown:**
Depends on both dimensions of the input.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Linear search over all possible capacities.

> **Key Insight for Improvement:**
> BS on capacity: lo=max(weights), hi=sum(weights). Greedy day counting.

<br>

---

## Solution 2: BS on Answer + Greedy (Optimal)

**Intuition:** Binary search on capacity. Greedy: load packages sequentially, start new day when exceeding capacity.

**Algorithm:**
1. lo=max(weights), hi=sum(weights)
2. Binary search: count days needed with capacity mid
3. If days ≤ D → ans=mid, hi=mid-1

### Time Complexity: O(N log S)
**Why?**
Each element/state processed efficiently via the core technique.

**Detailed breakdown:**
Operations scale with input size as described by the complexity.

**Example walkthrough:**
```
weights=[1..10] D=5: lo=10, hi=55
mid=15: [1,2,3,4,5]=15, [6,7]=13, [8]=8, [9]=9, [10]=10 → 5 days → ans=15 ✓
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Try all capacities | O(max_cap × N) | Varies | Baseline |
| BS on Answer + Greedy | O(N log S) | O(1) | Optimal approach |

**Recommended Solution:** BS on Answer + Greedy — O(N log S) time.

**Key Insights:**
1. **Same pattern:** Minimize capacity (=maximum) with day limit
2. **lo=max(weights):** Must fit largest single package
3. **Greedy loading:** Fill each day until capacity exceeded

<br><br>

---

```code```
