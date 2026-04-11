Find all unique combinations of candidates that sum to target. Same number can be used unlimited times.

<br>

> Input:
> candidates = [2, 3, 6, 7], target = 7

> Output:
> [[2,2,3], [7]]

> Explanation:
> 2+2+3 = 7 and 7 = 7
> Same number can be reused multiple times
> 
> **Key insight:** Backtracking with index - can reuse current element or move to next.

<br>


---

## Constraints

- `0 ≤ n ≤ 20 (for exponential solutions)`
- `n ≤ 10⁵ for polynomial solutions`
- `Values may include duplicates`

<br>

---

## All Possible Edge Cases

1. **Empty input:** Return [] or [[]]
2. **Single element:** One subset or one subarray
3. **All duplicates:** Must skip to avoid duplicate results
4. **n at maximum:** Verify 2ⁿ doesn't exceed time/memory limits
5. **Negative numbers:** Affects sum-based problems

<br>

---

## Solution: Backtracking with Reuse

**Intuition:**
Build combinations element by element.
At each step, either include current candidate (can reuse) or skip to next.
Stop when sum equals target (success) or exceeds target (prune).

**Key Difference from Subsets:**
- Can reuse same element multiple times
- Don't increment index when including element
- Only increment when skipping to next element

**Algorithm:**
1. Sort candidates (optional, helps with pruning)
2. Start with index=0, current combination=[], current sum=0
3. Base cases:
   - If sum == target: add combination to result
   - If sum > target: return (prune)
4. For each candidate from current index:
   - Include candidate in combination
   - Recurse with same index (allow reuse)
   - Remove candidate (backtrack)

**Example Walkthrough:**
```
candidates = [2, 3, 6, 7], target = 7

backtrack(0, [], 0):
  Include 2: [2], sum=2
    backtrack(0, [2], 2):
      Include 2: [2,2], sum=4
        backtrack(0, [2,2], 4):
          Include 2: [2,2,2], sum=6
            backtrack(0, [2,2,2], 6):
              Include 2: [2,2,2,2], sum=8 > 7 → prune
              Skip to 3: [2,2,2,3], sum=9 > 7 → prune
              Skip to 6: [2,2,2,6], sum=12 > 7 → prune
              Skip to 7: [2,2,2,7], sum=13 > 7 → prune
          Skip to 3: [2,2,3], sum=7 → add [2,2,3] ✓
          Skip to 6: [2,2,6], sum=10 > 7 → prune
          Skip to 7: [2,2,7], sum=11 > 7 → prune
      Skip to 3: [2,3], sum=5
        backtrack(1, [2,3], 5):
          Include 3: [2,3,3], sum=8 > 7 → prune
          Skip to 6: [2,3,6], sum=11 > 7 → prune
          Skip to 7: [2,3,7], sum=12 > 7 → prune
      Skip to 6: [2,6], sum=8 > 7 → prune
      Skip to 7: [2,7], sum=9 > 7 → prune
  
  Skip to 3: [3], sum=3
    backtrack(1, [3], 3):
      Include 3: [3,3], sum=6
        backtrack(1, [3,3], 6):
          Include 3: [3,3,3], sum=9 > 7 → prune
          Skip to 6: [3,3,6], sum=12 > 7 → prune
          Skip to 7: [3,3,7], sum=13 > 7 → prune
      Skip to 6: [3,6], sum=9 > 7 → prune
      Skip to 7: [3,7], sum=10 > 7 → prune
  
  Skip to 6: [6], sum=6
    backtrack(2, [6], 6):
      Include 6: [6,6], sum=12 > 7 → prune
      Skip to 7: [6,7], sum=13 > 7 → prune
  
  Skip to 7: [7], sum=7 → add [7] ✓

Result: [[2,2,3], [7]]
```

**Recursion Tree:**
```
                    []
        /      /      |      \
      [2]    [3]    [6]    [7]✓
      / \     / \     |
   [2,2] [2,3][3,3][3,6]
    / \    |
[2,2,2][2,2,3]✓
   |
[2,2,2,2]
```

### Time Complexity: O(N^(T/M))
**Why?**
- N = number of candidates
- T = target value
- M = minimum candidate value
- Maximum depth: T/M (using smallest candidate repeatedly)
- Each level: up to N choices
- Total: N^(T/M)

**Detailed breakdown:**
- Example: candidates=[2,3], target=8
- Max depth: 8/2 = 4
- Branches: 2^4 = 16 paths explored
- Actual: pruning reduces significantly

### Space Complexity: O(T/M)
**Why?**
- Recursion stack depth: T/M (maximum combination length)
- Current combination: O(T/M)
- Total: O(T/M)

<br>

---

## Optimization: Early Pruning with Sorting

**Approach:**
Sort candidates in ascending order.
If current candidate exceeds remaining target, skip all larger candidates.

```cpp
void backtrack(candidates, target, index, current, result) {
    if (target == 0) {
        result.add(current)
        return
    }
    
    for (i = index to candidates.size()-1) {
        if (candidates[i] > target) break  // Prune: all larger will exceed
        
        current.add(candidates[i])
        backtrack(candidates, target - candidates[i], i, current, result)
        current.remove_last()
    }
}
```

**Benefit:** Stops early when candidates too large, avoiding unnecessary recursion.

<br>

---

## Key Insights

1. **Reuse Allowed:** Don't increment index when including element
2. **Pruning:** Stop when sum > target (no point continuing)
3. **Sorting Helps:** Early termination when candidate too large
4. **No Duplicates:** Each combination unique due to index progression

**Common Mistakes:**
- Incrementing index when including element (prevents reuse)
- Not pruning when sum > target (TLE)
- Forgetting to backtrack (remove last element)
- Not handling edge cases (empty candidates, target=0)

<br>

---

## Comparison with Similar Problems

| Problem | Reuse | Duplicates in Input | Key Difference |
|---------|-------|---------------------|----------------|
| Combination Sum | Yes | No | Can reuse, no dups |
| Combination Sum II | No | Yes | No reuse, skip dups |
| Subsets | No | No | All subsets, no target |
| Permutations | Yes | No | Order matters |

<br>

---

## Edge Cases

1. **target = 0:** Return [[]]
2. **No solution:** Return []
3. **Single element equals target:** Return [[element]]
4. **All candidates > target:** Return []
5. **Candidates with 1:** Many combinations possible

<br>

---

## Variations

**1. Count Combinations Only:**
Don't store combinations, just count.
**Space:** O(T/M) instead of O(N × T/M)

**2. Minimum Coins:**
Find combination with fewest elements.
Use BFS or DP instead.

**3. With Limits:**
Each candidate can be used at most K times.
Track usage count.

<br>

---

## Applications

1. **Coin Change:** Making change with unlimited coins
2. **Knapsack:** Unbounded knapsack variant
3. **Resource Allocation:** Unlimited resource types
4. **Recipe Generation:** Combining ingredients
5. **Music Composition:** Notes forming melodies

<br>
<br>

---

```code```
