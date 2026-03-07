Find all unique combinations that sum to target. Each number used at most once. Array may contain duplicates.

<br>

> Input:
> candidates = [10,1,2,7,6,1,5], target = 8

> Output:
> [[1,1,6], [1,2,5], [1,7], [2,6]]

> Explanation:
> Each element used at most once
> Input has duplicate 1s, but output combinations are unique
> 
> **Key insight:** Sort + skip duplicates at same level to avoid duplicate combinations.

<br>

---

## Solution: Backtracking with Duplicate Skipping

**Intuition:**
Similar to Combination Sum, but:
1. Each element used at most once (increment index after including)
2. Skip duplicate elements at same recursion level to avoid duplicate combinations

**Key Differences from Combination Sum:**
- Increment index after including element (no reuse)
- Sort array and skip duplicates: `if (i > index && candidates[i] == candidates[i-1]) continue`

**Why Skip Duplicates:**
```
candidates = [1, 1, 2], target = 3

Without skipping:
  Use 1₁: [1₁]
    Use 1₂: [1₁,1₂]
      Use 2: [1₁,1₂,2] → sum=4 > 3
    Use 2: [1₁,2] → sum=3 ✓
  
  Use 1₂: [1₂]  ← This creates duplicate!
    Use 2: [1₂,2] → sum=3 ✓ (duplicate of [1₁,2])

With skipping:
  Use 1₁: [1₁]
    Use 1₂: [1₁,1₂]
      Use 2: [1₁,1₂,2] → sum=4 > 3
    Use 2: [1₁,2] → sum=3 ✓
  
  Skip 1₂ (duplicate at same level)
  Use 2: [2] → sum=2 < 3

Result: [[1,2]] (no duplicates)
```

**Algorithm:**
1. Sort candidates to group duplicates
2. Start with index=0, current=[], sum=0
3. Base cases:
   - If sum == target: add combination to result
   - If sum > target: return (prune)
4. For each candidate from current index:
   - Skip if duplicate of previous at same level
   - Include candidate in combination
   - Recurse with index+1 (no reuse)
   - Remove candidate (backtrack)

**Example Walkthrough:**
```
candidates = [1,1,2,5,6,7,10], target = 8 (sorted)

backtrack(0, [], 0):
  Include 1₁: [1], sum=1
    backtrack(1, [1], 1):
      Include 1₂: [1,1], sum=2
        backtrack(2, [1,1], 2):
          Include 2: [1,1,2], sum=4
            backtrack(3, [1,1,2], 4):
              Include 5: [1,1,2,5], sum=9 > 8 → prune
              Skip 6,7,10 (all > remaining)
          Include 5: [1,1,5], sum=7
            backtrack(4, [1,1,5], 7):
              Include 6: [1,1,5,6], sum=13 > 8 → prune
              Skip 7,10
          Include 6: [1,1,6], sum=8 → add [1,1,6] ✓
          Include 7: [1,1,7], sum=9 > 8 → prune
          Include 10: [1,1,10], sum=12 > 8 → prune
      
      Skip 1₂ at this level (duplicate)
      Include 2: [1,2], sum=3
        backtrack(3, [1,2], 3):
          Include 5: [1,2,5], sum=8 → add [1,2,5] ✓
          Include 6: [1,2,6], sum=9 > 8 → prune
          Skip 7,10
      Include 5: [1,5], sum=6
        backtrack(4, [1,5], 6):
          Include 6: [1,5,6], sum=12 > 8 → prune
          Skip 7,10
      Include 6: [1,6], sum=7
        backtrack(5, [1,6], 7):
          Include 7: [1,6,7], sum=14 > 8 → prune
          Skip 10
      Include 7: [1,7], sum=8 → add [1,7] ✓
      Include 10: [1,10], sum=11 > 8 → prune
  
  Skip 1₂ at root level (duplicate)
  Include 2: [2], sum=2
    backtrack(3, [2], 2):
      Include 5: [2,5], sum=7
        backtrack(4, [2,5], 7):
          Include 6: [2,5,6], sum=13 > 8 → prune
          Skip 7,10
      Include 6: [2,6], sum=8 → add [2,6] ✓
      Include 7: [2,7], sum=9 > 8 → prune
      Include 10: [2,10], sum=12 > 8 → prune
  
  Include 5: [5], sum=5
    backtrack(4, [5], 5):
      Include 6: [5,6], sum=11 > 8 → prune
      Skip 7,10
  
  Include 6: [6], sum=6
    backtrack(5, [6], 6):
      Include 7: [6,7], sum=13 > 8 → prune
      Skip 10
  
  Include 7: [7], sum=7
    backtrack(6, [7], 7):
      Include 10: [7,10], sum=17 > 8 → prune
  
  Include 10: [10], sum=10 > 8 → prune

Result: [[1,1,6], [1,2,5], [1,7], [2,6]]
```

**Skip Condition Explained:**
```cpp
for (int i = index; i < candidates.size(); i++) {
    // Skip duplicates at same recursion level
    if (i > index && candidates[i] == candidates[i-1]) {
        continue;
    }
    // ... rest of backtracking
}

Why "i > index"?
- i == index: First element at this level, always use
- i > index: Not first element, check if duplicate of previous
```

### Time Complexity: O(2^N)
**Why?**
- Each element: include or exclude (2 choices)
- N elements: 2^N subsets
- Pruning and duplicate skipping reduce actual complexity
- Sorting: O(N log N) (negligible)

**Detailed breakdown:**
- Worst case (all unique, small target): explore most subsets
- Best case (large candidates, small target): heavy pruning
- Average: significantly less than 2^N due to pruning

### Space Complexity: O(N)
**Why?**
- Recursion stack: O(N) maximum depth
- Current combination: O(N)
- Sorting: O(1) if in-place
- Total: O(N)

<br>

---

## Key Insights

1. **Sort First:** Groups duplicates for easy detection
2. **Skip Condition:** `i > index && candidates[i] == candidates[i-1]`
3. **No Reuse:** Increment index after including element
4. **Pruning:** Stop when sum > target

**Common Mistakes:**
- Not sorting array first (can't detect duplicates)
- Wrong skip condition (missing `i > index` check)
- Allowing reuse (not incrementing index)
- Not pruning when sum exceeds target

<br>

---

## Comparison with Related Problems

| Problem | Reuse | Duplicates | Skip Logic |
|---------|-------|------------|------------|
| Combination Sum | Yes | No input dups | None |
| Combination Sum II | No | Yes input dups | Skip at same level |
| Subsets II | No | Yes input dups | Skip at same level |
| Permutations II | No | Yes input dups | Skip with visited check |

<br>

---

## Why Sorting is Essential

**Without sorting:**
```
candidates = [1, 2, 1], target = 3

Can't easily detect duplicates:
[1₁, 2] and [1₂, 2] both generated
No simple way to skip without sorting
```

**With sorting:**
```
candidates = [1, 1, 2], target = 3

Duplicates adjacent:
[1₁, 2] generated
[1₂, 2] skipped (duplicate at same level)
Clear rule: skip if same as previous at same level
```

<br>

---

## Edge Cases

1. **All duplicates:** [1,1,1,1], target=2 → [[1,1]]
2. **No solution:** Return []
3. **Single element:** [5], target=5 → [[5]]
4. **Target = 0:** [[]]
5. **All candidates > target:** []

<br>

---

## Optimization: Early Termination

```cpp
void backtrack(candidates, target, index, current, result) {
    if (target == 0) {
        result.add(current)
        return
    }
    
    for (i = index to candidates.size()-1) {
        // Skip duplicates
        if (i > index && candidates[i] == candidates[i-1]) continue
        
        // Early termination (candidates sorted)
        if (candidates[i] > target) break
        
        current.add(candidates[i])
        backtrack(candidates, target - candidates[i], i+1, current, result)
        current.remove_last()
    }
}
```

<br>

---

## Applications

1. **Coin Change:** Making exact change with limited coins
2. **Subset Sum:** Finding subsets with specific sum
3. **Knapsack:** 0/1 knapsack with duplicate items
4. **Resource Allocation:** Limited resources with duplicates
5. **Puzzle Solving:** Combinations with constraints

<br>
<br>

---

```code```
