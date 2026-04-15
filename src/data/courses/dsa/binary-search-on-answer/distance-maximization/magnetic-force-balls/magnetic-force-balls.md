Place M balls maximizing minimum magnetic force (distance). Same as aggressive cows.

<br>

> positions=[1,2,3,4,7], m=3 → 3
>
> **Key insight:** Identical to aggressive cows. Binary search on minimum distance, greedy placement.

<br>

---

## Constraints
- 2 ≤ N ≤ 10⁵
- 2 ≤ M ≤ N
- 1 ≤ positions[i] ≤ 10⁹

<br>

---

## All Possible Edge Cases
1. **Same as aggressive cows**

<br>

---

## Solution 1: Same as aggressive cows

**Intuition:**
The most straightforward approach. Same combinatorial explosion.

**Algorithm:**
1. Iterate through all possible candidates/states
2. For each candidate, evaluate the required condition
3. Track the best result seen so far
4. Return the optimal answer

### Time Complexity: O(C(N,M))
**Why?**
Single pass through the input, doing O(1) work per element.
Total: N elements × O(1) per element = O(N).

**Detailed breakdown:**
For N=100,000: ~100,000 operations — very efficient.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Same combinatorial explosion.

> **Key Insight for Improvement:**
> Same BS + greedy pattern.

<br>

---

## Solution 2: BS on Min Distance (Optimal)

**Intuition:** Identical to aggressive cows. Binary search on minimum distance, greedy placement.

**Algorithm:**
Same algorithm as aggressive cows

### Time Complexity: O(N log D)
**Why?**
Each element/state processed efficiently via the core technique.

**Detailed breakdown:**
Operations scale with input size as described by the complexity.

**Example walkthrough:**
```
Same as aggressive cows with different variable names
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Same as aggressive cows | O(C(N,M)) | Varies | Baseline |
| BS on Min Distance | O(N log D) | O(1) | Optimal approach |

**Recommended Solution:** BS on Min Distance — O(N log D) time.

**Key Insights:**
1. **Identical to aggressive cows:** Same algorithm, LeetCode 1552
2. **Sort + BS + greedy:** The universal maximize-minimum pattern

<br><br>

---

```code```
