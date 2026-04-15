Generate all subsequences using recursion (include/exclude pattern).

<br>

> nums=[1,2,3] → [[],[1],[2],[3],[1,2],[1,3],[2,3],[1,2,3]]
>
> **Key insight:** For each element: include it in current subsequence or exclude it. Recurse on remaining.

<br>

---

## Constraints
- 0 ≤ N ≤ 20

<br>

---

## All Possible Edge Cases
1. **Empty input: 1 subsequence (empty)
2. **2^N total subsequences
3. **Order preserved from original**

<br>

---

## Solution 1: Same recursive approach

**Intuition:**
The most straightforward approach. 2^N subsequences exist — must generate all.

**Algorithm:**
1. Define recursive function with current state
2. At each step, try all possible choices
3. Recurse on remaining subproblem
4. Base case: return when subproblem is solved

### Time Complexity: O(N×2^N)
**Why?**
Each element has multiple choices (include/exclude, take/skip), leading to exponential branching.
For N elements, the total states explored grow as 2^N or worse.

**Detailed breakdown:**
For N=20: ~1 million states. For N=30: ~1 billion states — too slow.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> 2^N subsequences exist — must generate all.

> **Key Insight for Improvement:**
> Include/exclude recursion: at each element, branch into two choices.

<br>

---

## Solution 2: Include/Exclude Recursion (Optimal)

**Intuition:** For each element: include it in current subsequence or exclude it. Recurse on remaining.

**Algorithm:**
1. backtrack(index, current):
2. If index == N: add current to result
3. Include: current.add(nums[index]) → backtrack(index+1, current) → remove last
4. Exclude: backtrack(index+1, current)

### Time Complexity: O(N × 2^N)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
[1,2,3]: include 1→include 2→include 3→[1,2,3]. Backtrack: exclude 3→[1,2]...
```

### Space Complexity: O(N) stack

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Same recursive approach | O(N×2^N) | Varies | Baseline |
| Include/Exclude Recursion | O(N × 2^N) | O(N) stack | Optimal |

**Recommended Solution:** Include/Exclude Recursion

**Key Insights:**
1. **2^N total:** Each element has 2 choices
2. **Subsequences maintain order:** Unlike subsets (which are same elements unordered)
3. **Same as power set generation**

<br><br>

---

```code```
