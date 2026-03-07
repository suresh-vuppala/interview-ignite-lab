Generate all possible arrangements of elements in an array.

<br>

> Input:
> nums = [1, 2, 3]

> Output:
> [[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1]]

> Explanation:
> All 6 permutations of [1,2,3]
> 
> **Key insight:** Backtracking with swap - fix each element at current position, recurse for remaining.

<br>

---

## Solution: Backtracking with Swap

**Intuition:**
Build permutations by fixing one element at a time at the current position.
For each position, try every remaining element by swapping.
After exploring, swap back (backtrack) to restore original state.

**Backtracking Template:**
```cpp
void backtrack(position) {
    if (position == end) {
        // Base case: complete permutation
        add current to result
        return
    }
    
    for (each element from position to end) {
        // Choose: swap current with element
        swap(position, element)
        
        // Explore: recurse for next position
        backtrack(position + 1)
        
        // Unchoose: swap back (backtrack)
        swap(position, element)
    }
}
```

**Algorithm:**
1. Start with index = 0
2. For each index from current to end:
   - Swap nums[current] with nums[index]
   - Recursively generate permutations for remaining elements (current+1)
   - Swap back to restore original array (backtrack)
3. Base case: when current == n, add permutation to result

**Example Walkthrough:**
```
nums = [1, 2, 3]

backtrack(0):
  swap(0,0): [1,2,3]
    backtrack(1):
      swap(1,1): [1,2,3]
        backtrack(2):
          swap(2,2): [1,2,3] → add [1,2,3] ✓
      swap(1,2): [1,3,2]
        backtrack(2):
          swap(2,2): [1,3,2] → add [1,3,2] ✓
  
  swap(0,1): [2,1,3]
    backtrack(1):
      swap(1,1): [2,1,3]
        backtrack(2):
          swap(2,2): [2,1,3] → add [2,1,3] ✓
      swap(1,2): [2,3,1]
        backtrack(2):
          swap(2,2): [2,3,1] → add [2,3,1] ✓
  
  swap(0,2): [3,2,1]
    backtrack(1):
      swap(1,1): [3,2,1]
        backtrack(2):
          swap(2,2): [3,2,1] → add [3,2,1] ✓
      swap(1,2): [3,1,2]
        backtrack(2):
          swap(2,2): [3,1,2] → add [3,1,2] ✓

Result: [[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,2,1], [3,1,2]]
```

**Recursion Tree:**
```
                    [1,2,3]
                   /   |   \
            [1,2,3] [2,1,3] [3,2,1]
             /  \     /  \     /  \
      [1,2,3][1,3,2][2,1,3][2,3,1][3,2,1][3,1,2]
```

### Time Complexity: O(N × N!)
**Why?**
- Total permutations: N!
- Each permutation takes O(N) to copy to result
- Total: O(N × N!)

**Detailed breakdown:**
- N choices for position 0
- (N-1) choices for position 1
- (N-2) choices for position 2
- ...
- 1 choice for position N-1
- Total branches: N × (N-1) × (N-2) × ... × 1 = N!
- Each leaf (complete permutation): O(N) to copy
- Total: O(N × N!)

### Space Complexity: O(N)
**Why?**
- Recursion stack depth: O(N) for N positions
- No extra space for tracking (in-place swaps)
- Output space not counted: O(N × N!)
- Total auxiliary space: O(N)

**Why backtracking works:**
- Swapping modifies array in-place
- After exploring with element at position, swap back restores original state
- This allows trying different elements at same position without creating copies

<br>

---

## Alternative: Using Visited Array

**Intuition:**
Build permutation element by element, tracking which elements are used.
Use boolean array to mark visited elements.

**Algorithm:**
```cpp
void backtrack(current_permutation, visited) {
    if (current_permutation.size() == n) {
        add to result
        return
    }
    
    for (i = 0 to n-1) {
        if (visited[i]) continue
        
        // Choose
        current_permutation.add(nums[i])
        visited[i] = true
        
        // Explore
        backtrack(current_permutation, visited)
        
        // Unchoose
        current_permutation.remove_last()
        visited[i] = false
    }
}
```

**Time:** O(N × N!) - same as swap approach
**Space:** O(N) for visited array + O(N) for current permutation = O(N)

**Comparison:**
| Approach | Space | In-place | Code Simplicity |
|----------|-------|----------|-----------------|
| Swap | O(N) | Yes | Simpler |
| Visited | O(N) | No | More intuitive |

<br>

---

## Key Insights

1. **Backtracking Pattern:** Choose → Explore → Unchoose
2. **Swap Technique:** Efficient in-place modification without extra space
3. **Factorial Growth:** N! permutations grow extremely fast (10! = 3,628,800)
4. **Base Case:** When all positions filled, we have complete permutation

**Common Mistakes:**
- Forgetting to swap back (backtrack) - leads to incorrect permutations
- Not copying array when adding to result - all results point to same array
- Trying to optimize beyond O(N × N!) - impossible since we must generate all N! permutations

<br>

---

## Applications

1. **Combinatorial Problems:** Generate all possible arrangements
2. **Scheduling:** All possible task orderings
3. **Cryptography:** Permutation-based encryption
4. **Testing:** Generate all input combinations
5. **Game Theory:** Explore all possible move sequences

<br>
<br>

---

```code```
