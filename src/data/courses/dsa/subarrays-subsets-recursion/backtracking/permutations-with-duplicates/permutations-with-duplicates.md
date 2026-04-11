Generate all unique permutations when array contains duplicate elements.

<br>

> Input:
> nums = [1, 1, 2]

> Output:
> [[1,1,2], [1,2,1], [2,1,1]]

> Explanation:
> Only 3 unique permutations (not 6) because of duplicate 1s
> 
> **Key insight:** Sort array + skip duplicates at same recursion level to avoid duplicate permutations.

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

## Solution: Backtracking with Duplicate Skipping

**Intuition:**
Similar to regular permutations, but skip duplicate elements at same position.
Sort array first to group duplicates together.
Use visited array to track which elements are used.

**Key Difference from Regular Permutations:**
```cpp
// Skip if:
// 1. Current element already used
// 2. Current element == previous element AND previous not used
if (visited[i] || (i > 0 && nums[i] == nums[i-1] && !visited[i-1])) {
    continue
}
```

**Why this works:**
- Sorting groups duplicates: [1, 1, 2]
- For duplicates at same level, only use first occurrence
- If nums[i] == nums[i-1] and i-1 not used, skip i (prevents duplicate permutations)

**Algorithm:**
1. Sort array to group duplicates
2. Use visited array to track used elements
3. For each position:
   - Try each unused element
   - Skip if duplicate of previous unused element
   - Recursively build remaining permutation
   - Backtrack by unmarking visited

**Example Walkthrough:**
```
nums = [1, 1, 2] (sorted)
visited = [false, false, false]

Level 0 (position 0):
  Try nums[0]=1: visited=[T,F,F], current=[1]
    Level 1:
      Skip nums[0]=1 (visited)
      Try nums[1]=1: visited=[T,T,F], current=[1,1]
        Level 2:
          Skip nums[0]=1, nums[1]=1 (visited)
          Try nums[2]=2: visited=[T,T,T], current=[1,1,2] → add ✓
      Try nums[2]=2: visited=[T,F,T], current=[1,2]
        Level 2:
          Skip nums[0]=1 (visited)
          Try nums[1]=1: visited=[T,T,T], current=[1,2,1] → add ✓
  
  Skip nums[1]=1 (duplicate of nums[0] and nums[0] not visited)
  
  Try nums[2]=2: visited=[F,F,T], current=[2]
    Level 1:
      Try nums[0]=1: visited=[T,F,T], current=[2,1]
        Level 2:
          Skip nums[0]=1 (visited)
          Try nums[1]=1: visited=[T,T,T], current=[2,1,1] → add ✓
      Skip nums[1]=1 (duplicate of nums[0] and nums[0] not visited)

Result: [[1,1,2], [1,2,1], [2,1,1]]
```

**Visual Explanation of Duplicate Skipping:**
```
At position 0:
[1₁, 1₂, 2]
 ↑   ↑
 use skip (duplicate, 1₁ not used yet)

Why skip 1₂?
- If we use 1₂ first, we get same permutations as using 1₁ first
- To avoid duplicates, always use leftmost duplicate first
```

### Time Complexity: O(N × N!)
**Why?**
- Worst case (all unique): N! permutations
- Best case (all same): 1 permutation
- Average: N!/k₁!×k₂!×...×kₘ! where kᵢ = count of element i
- Each permutation: O(N) to copy
- Sorting: O(N log N) (negligible compared to N!)
- Total: O(N × N!)

**Detailed breakdown:**
- For [1,1,2]: 3!/2! = 3 permutations
- For [1,1,1]: 3!/3! = 1 permutation
- For [1,2,3]: 3!/1!×1!×1! = 6 permutations

### Space Complexity: O(N)
**Why?**
- Visited array: O(N)
- Recursion stack: O(N)
- Current permutation: O(N)
- Total: O(N)

<br>

---

## Why Sorting is Necessary

**Without sorting:**
```
nums = [1, 2, 1]

Can't easily detect duplicates:
- At position 0, try 1 (index 0)
- At position 0, try 1 (index 2) → duplicate permutation!
- No easy way to skip without sorting
```

**With sorting:**
```
nums = [1, 1, 2]

Duplicates adjacent:
- At position 0, try 1 (index 0)
- At position 0, skip 1 (index 1) if index 0 not used
- Clear rule: use leftmost duplicate first
```

<br>

---

## Alternative: Using Set (Less Efficient)

**Approach:**
Generate all permutations (including duplicates), store in set to remove duplicates.

**Time:** O(N × N!) to generate + O(N × N!) for set operations = O(N × N!)
**Space:** O(N × N!) for set storage

**Why not recommended:**
- Generates many duplicate permutations unnecessarily
- High memory usage for set
- Slower due to set operations
- Optimal approach (skip duplicates) is better

<br>

---

## Key Insights

1. **Sort First:** Groups duplicates for easy detection
2. **Skip Condition:** `nums[i] == nums[i-1] && !visited[i-1]`
3. **Leftmost Rule:** Always use leftmost duplicate first at each level
4. **Visited Array:** Essential for tracking which elements used

**Common Mistakes:**
- Forgetting to sort array first
- Wrong skip condition (missing !visited[i-1] check)
- Using swap approach (doesn't work well with duplicates)
- Not understanding why skip condition prevents duplicates

<br>

---

## Comparison with Regular Permutations

| Aspect | Regular | With Duplicates |
|--------|---------|-----------------|
| Preprocessing | None | Sort array |
| Tracking | Swap or visited | Visited only |
| Skip logic | None | Skip duplicate at same level |
| Permutations | N! | N!/k₁!×k₂!×...×kₘ! |
| Complexity | O(N × N!) | O(N × N!) |

<br>

---

## Applications

1. **Anagram Generation:** All unique arrangements of letters
2. **Scheduling with Constraints:** Tasks with identical durations
3. **Combinatorial Optimization:** Unique configurations
4. **String Permutations:** Words with repeated characters
5. **Resource Allocation:** Identical resources to different slots

<br>
<br>

---

```code```
