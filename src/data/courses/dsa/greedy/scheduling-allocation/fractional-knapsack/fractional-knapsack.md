Maximize value with weight capacity W. Items can be taken fractionally.

<br>

> items=[(60,10),(100,20),(120,30)], W=50 → 240
>
> **Key insight:** Sort by value/weight ratio descending. Take items greedily. Take fraction of last item if needed.

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

**Intuition:**
The most straightforward approach. 0/1 combinations don't apply — fractional changes the game.

**Algorithm:**
1. For each element i (outer loop):
   - For each element j (inner loop):
     - Check if the pair/condition is satisfied
2. Return the best result found

### Time Complexity: O(2^N)
**Why?**
Each element has multiple choices (include/exclude, take/skip), leading to exponential branching.
For N elements, the total states explored grow as 2^N or worse.

**Detailed breakdown:**
For N=20: ~1 million states. For N=30: ~1 billion states — too slow.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> 0/1 combinations don't apply — fractional changes the game.

> **Key Insight for Improvement:**
> Greedy by value/weight ratio: take highest ratio items first. Fraction of last item fills remaining capacity.

<br>

---

## Solution 2: Sort by Value/Weight Ratio (Optimal)

**Intuition:** Sort by value/weight ratio descending. Take items greedily. Take fraction of last item if needed.

**Algorithm:**
1. Compute ratio = value/weight for each item
2. Sort by ratio descending
3. For each item: if fits → take entirely. If not → take fraction.
4. Total value = sum of taken values

### Time Complexity: O(N log N)
**Why?**
Each element processed at most once through the core data structure/algorithm.

**Detailed breakdown:**
For typical input sizes, operations stay well within time limits.

**Example walkthrough:**
```
Items by ratio: (60/10=6.0), (100/20=5.0), (120/30=4.0)
Take item1 fully: 10kg, val=60, remaining=40
Take item2 fully: 20kg, val=100, remaining=20
Take 20/30 of item3: val=120×(20/30)=80
Total: 60+100+80=240 ✓
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(2^N) | Varies | Baseline |
| Sort by Value/Weight Ratio | O(N log N) | O(1) | Greedy by value/weight ratio: take highest ratio items first |

**Recommended Solution:** Sort by Value/Weight Ratio — O(N log N) time, O(1) space.

**Key Insights:**
1. **Fractional = greedy works:** Unlike 0/1 knapsack which needs DP
2. **Ratio is the key:** Higher ratio = more value per unit weight
3. **Greedy proof:** Taking any other order wastes capacity on lower-value items

<br>
<br>

---

```code```
