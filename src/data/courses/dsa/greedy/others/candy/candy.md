Distribute minimum candies: each child gets ≥1, higher-rated child gets more than neighbors.

<br>

> ratings=[1,0,2] → 5 (candies=[2,1,2])
>
> **Key insight:** Two passes: left-to-right ensures right neighbor constraint. Right-to-left ensures left neighbor constraint. Take max.

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

### Time Complexity: O(N × max_rating)

> **Drawback:**
> Trying all valid distributions is infeasible.

> **Key Insight for Improvement:**
> Two passes: L→R: if rating[i] > rating[i-1] → candy[i] = candy[i-1]+1. R→L: if rating[i] > rating[i+1] → candy[i] = max(candy[i], candy[i+1]+1).

<br>

---

## Solution 2: Two-Pass Greedy (Optimal)

**Intuition:** Two passes: left-to-right ensures right neighbor constraint. Right-to-left ensures left neighbor constraint. Take max.

**Algorithm:**
1. candies = [1] * N
2. Left→Right: if ratings[i] > ratings[i-1]: candies[i] = candies[i-1]+1
3. Right→Left: if ratings[i] > ratings[i+1]: candies[i] = max(candies[i], candies[i+1]+1)
4. Return sum(candies)

### Time Complexity: O(N)
**Why?**
Each element processed at most once through the core data structure/algorithm.

**Detailed breakdown:**
For typical input sizes, operations stay well within time limits.

**Example walkthrough:**
```
ratings=[1,0,2]
L→R: [1,1,2] (0 not > 1, 2 > 0)
R→L: [2,1,2] (1 > 0 → max(1,1+1)=2)
Sum: 2+1+2=5 ✓
```

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N × max_rating) | Varies | Baseline |
| Two-Pass Greedy | O(N) | O(N) | Two passes: L→R: if rating[i] > rating[i-1] → candy[i] = can |

**Recommended Solution:** Two-Pass Greedy — O(N) time, O(N) space.

**Key Insights:**
1. **Two passes handle both directions:** L→R for left neighbor, R→L for right
2. **Take max:** Satisfies both constraints simultaneously
3. **Start with 1:** Everyone gets at least one candy

<br>
<br>

---

```code```
