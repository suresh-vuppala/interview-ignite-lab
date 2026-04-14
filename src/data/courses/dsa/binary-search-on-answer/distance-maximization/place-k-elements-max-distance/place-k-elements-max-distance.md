Place K elements maximizing minimum distance. Generic version of aggressive cows.

<br>

> Positions array, K elements → maximize minimum gap
>
> **Key insight:** Same BS-on-answer + greedy placement pattern.

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

## Solution 1: Brute force all placements

**Intuition:**
The most straightforward approach. Combinatorial.

**Algorithm:**
1. For each element i (outer loop):
   - For each element j (inner loop):
     - Check if the pair/condition is satisfied
2. Return the best result found

### Time Complexity: O(C(N,K))
**Why?**
Single pass through the input, doing O(1) work per element.
Total: N elements × O(1) per element = O(N).

**Detailed breakdown:**
For N=100,000: ~100,000 operations — very efficient.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Combinatorial.

> **Key Insight for Improvement:**
> BS on min distance + greedy sequential placement.

<br>

---

## Solution 2: BS on Answer (Optimal)

**Intuition:** Same BS-on-answer + greedy placement pattern.

**Algorithm:**
Same as aggressive cows / magnetic force

### Time Complexity: O(N log D)
**Why?**
Each element/state processed efficiently via the core technique.

**Detailed breakdown:**
Operations scale with input size as described by the complexity.

**Example walkthrough:**
```
Same pattern as aggressive cows
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute force all placements | O(C(N,K)) | Varies | Baseline |
| BS on Answer | O(N log D) | O(1) | Optimal approach |

**Recommended Solution:** BS on Answer — O(N log D) time.

**Key Insights:**
1. **Family of problems:** Aggressive cows = magnetic force = place K elements
2. **All use:** Sort + BS on min distance + greedy placement check

<br><br>

---

```code```
