Circular route of N gas stations. gas[i]=fuel, cost[i]=travel cost. Find starting station for full circuit, or -1.

<br>

> gas=[1,2,3,4,5], cost=[3,4,5,1,2] → start=3
>
> **Key insight:** If total gas ≥ total cost, solution exists. Track running surplus — reset starting point whenever surplus goes negative.

<br>

---

## Constraints
- Typical problem constraints apply

<br>

---

## All Possible Edge Cases
1. **Empty input:** Handle gracefully
2. **Single element:** Base case
3. **Large input:** Verify time complexity holds

<br>

---

## Solution 1: Brute Force

### Time Complexity: O(N²)

> **Drawback:**
> Starting from each station and simulating is O(N) per start × N starts.

> **Key Insight for Improvement:**
> Single pass: if total ≥ 0, answer exists. Track local surplus. When it goes negative, next station is the new candidate start.

<br>

---

## Solution 2: Single Pass Surplus Tracking (Optimal)

**Intuition:** If total gas ≥ total cost, solution exists. Track running surplus — reset starting point whenever surplus goes negative.

**Algorithm:**
1. totalSurplus = 0, currentSurplus = 0, start = 0
2. For each station i:
   - totalSurplus += gas[i] - cost[i]
   - currentSurplus += gas[i] - cost[i]
   - If currentSurplus < 0: start = i+1, currentSurplus = 0
3. Return totalSurplus ≥ 0 ? start : -1

### Time Complexity: O(N)
**Why?**
Each element processed at most once through the core data structure/algorithm.

**Detailed breakdown:**
For typical input sizes, operations stay well within time limits.

**Example walkthrough:**
```
gas=[1,2,3,4,5], cost=[3,4,5,1,2]
i=0: surplus=-2<0 → start=1, reset
i=1: surplus=-2<0 → start=2, reset
i=2: surplus=-2<0 → start=3, reset
i=3: surplus=3, i=4: surplus=6
totalSurplus=0 → start=3 ✓
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N²) | Varies | Baseline |
| Single Pass Surplus Tracking | O(N) | O(1) | Single pass: if total ≥ 0, answer exists. Track local surplu |

**Recommended Solution:** Single Pass Surplus Tracking — O(N) time, O(1) space.

**Key Insights:**
1. **If total ≥ 0, solution exists:** Mathematical guarantee
2. **Reset on negative:** All stations before failed start also fail
3. **Unique answer guaranteed:** At most one valid starting station

<br>
<br>

---

```code```
