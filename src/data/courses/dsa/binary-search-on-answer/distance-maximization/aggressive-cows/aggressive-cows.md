Place C cows in N stalls maximizing the minimum distance between any two cows.

<br>

> stalls=[1,2,4,8,9], cows=3 → 3 (place at 1,4,8→min dist=3)
>
> **Key insight:** Binary search on minimum distance. Greedy: place cows left-to-right, skip stalls too close.

<br>

---

## Constraints
- 2 ≤ N ≤ 10⁵
- 2 ≤ C ≤ N
- 0 ≤ stalls[i] ≤ 10⁹

<br>

---

## All Possible Edge Cases
1. **C = 2:** max distance = last - first stall
2. **C = N:** place in every stall
3. **All stalls equidistant**

<br>

---

## Solution 1: Try all placements

**Intuition:**
The most straightforward approach. Combinatorial — infeasible.

**Algorithm:**
1. Enumerate all possible candidates
2. For each candidate, verify if it satisfies the condition
3. Track the best valid result
4. Return the optimal answer

### Time Complexity: O(C(N,C))
**Why?**
Single pass through the input, doing O(1) work per element.
Total: N elements × O(1) per element = O(N).

**Detailed breakdown:**
For N=100,000: ~100,000 operations — very efficient.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Combinatorial — infeasible.

> **Key Insight for Improvement:**
> BS on min distance: lo=1, hi=max-min. Greedy placement: place cow at first valid stall (≥ last + mid distance).

<br>

---

## Solution 2: BS on Answer + Greedy Placement (Optimal)

**Intuition:** Binary search on minimum distance. Greedy: place cows left-to-right, skip stalls too close.

**Algorithm:**
1. Sort stalls. lo=1, hi=stalls[N-1]-stalls[0]
2. For each mid: greedily place cows with ≥ mid distance
3. If placed ≥ C → ans=mid, lo=mid+1 (try larger)
4. Else → hi=mid-1

### Time Complexity: O(N log D)
**Why?**
Each element/state processed efficiently via the core technique.

**Detailed breakdown:**
Operations scale with input size as described by the complexity.

**Example walkthrough:**
```
stalls=[1,2,4,8,9] C=3 mid=3:
Place at 1. Next ≥ 1+3=4 → place at 4. Next ≥ 4+3=7 → place at 8. Placed 3 ✓
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Try all placements | O(C(N,C)) | Varies | Baseline |
| BS on Answer + Greedy Placement | O(N log D) | O(1) | Optimal approach |

**Recommended Solution:** BS on Answer + Greedy Placement — O(N log D) time.

**Key Insights:**
1. **Maximize minimum:** BS on the minimum distance
2. **Greedy: leftmost valid:** Place each cow at earliest valid stall
3. **Sort stalls first:** Enables greedy left-to-right placement

<br><br>

---

```code```
