Schedule tasks with cooldown period n. Find minimum intervals to complete all tasks.

<br>

> tasks=['A','A','A','B','B','B'], n=2 → 8 (A_B_A_B_A_B→AB_AB_AB→8)
>
> **Key insight:** Most frequent task determines the frame. Formula: max(len, (maxFreq-1)×(n+1) + countOfMaxFreq).

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
The most straightforward approach. Simulation is slow for large inputs.

**Algorithm:**
1. For each element i (outer loop):
   - For each element j (inner loop):
     - Check if the pair/condition is satisfied
2. Return the best result found

### Time Complexity: O(N × maxFreq)
**Why?**
Two factors multiply: one from iterating elements, one from the operation per element.
Total = product of both factors.

**Detailed breakdown:**
Depends on both dimensions of the input.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Simulation is slow for large inputs.

> **Key Insight for Improvement:**
> Formula: idle slots are created by most frequent task. Other tasks fill idle slots. Answer = max(N, (maxFreq-1)×(n+1)+countMax).

<br>

---

## Solution 2: Frequency Formula (Optimal)

**Intuition:** Most frequent task determines the frame. Formula: max(len, (maxFreq-1)×(n+1) + countOfMaxFreq).

**Algorithm:**
1. Count task frequencies
2. maxFreq = highest frequency, countMax = how many tasks have maxFreq
3. partitions = maxFreq - 1
4. emptySlots = partitions × (n - countMax + 1)
5. availableTasks = len(tasks) - maxFreq × countMax
6. idles = max(0, emptySlots - availableTasks)
7. Answer = len(tasks) + idles

### Time Complexity: O(N)
**Why?**
Each element processed at most once through the core data structure/algorithm.

**Detailed breakdown:**
For typical input sizes, operations stay well within time limits.

**Example walkthrough:**
```
tasks=[A:3,B:3], n=2
maxFreq=3, countMax=2, partitions=2
Frame: AB_AB_AB → length = (3-1)×(2+1)+2 = 8
Answer: max(6, 8) = 8 ✓
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N × maxFreq) | Varies | Baseline |
| Frequency Formula | O(N) | O(1) | Formula: idle slots are created by most frequent task. Other |

**Recommended Solution:** Frequency Formula — O(N) time, O(1) space.

**Key Insights:**
1. **Frame concept:** (maxFreq-1) gaps of size (n+1), plus final group of countMax
2. **Formula covers all:** max(N, formula) handles both idle and no-idle cases
3. **Greedy: fill gaps with other tasks:** Reduces idles

<br>
<br>

---

```code```
