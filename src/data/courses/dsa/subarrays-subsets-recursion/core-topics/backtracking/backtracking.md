Master backtracking - a systematic way to explore all possible solutions.

<br>

> **Backtracking Definition:**
> Algorithmic technique that incrementally builds candidates and abandons them ("backtracks") when they cannot lead to valid solutions.

> **Key Components:**
> 1. Choice: What options do we have?
> 2. Constraint: What rules must we follow?
> 3. Goal: When have we found a solution?
> 
> **Key insight:** Try all possibilities, undo bad choices, and continue exploring.

<br>

---

## What is Backtracking?

**Intuition:**
Backtracking is like exploring a maze:
- Try a path
- If it leads to dead end, go back and try another path
- Continue until you find the exit or exhaust all paths

**Core Idea:**
```
1. Make a choice
2. Explore consequences
3. If it doesn't work, undo the choice (backtrack)
4. Try next choice
```

**Example - Finding Path in Maze:**
```
Start → Try Right → Dead End → Backtrack
     → Try Down → Dead End → Backtrack  
     → Try Left → Success!
```

<br>

---

## Backtracking vs Other Techniques

| Technique | Approach | When to Use |
|-----------|----------|-------------|
| **Backtracking** | Try all, undo bad choices | Find all/any solutions |
| **Greedy** | Make locally optimal choice | Optimization with greedy property |
| **Dynamic Programming** | Store subproblem results | Overlapping subproblems |
| **Brute Force** | Try everything, no pruning | Small input, simple logic |

**Key Difference:** Backtracking prunes search space by abandoning invalid paths early.

<br>

---

## Backtracking Template

**General Structure:**
```cpp
void backtrack(state, choices, result) {
    // Base case: found solution
    if (isGoal(state)) {
        result.add(state);
        return;
    }
    
    // Try each choice
    for (choice in choices) {
        // 1. Make choice
        if (isValid(choice, state)) {
            makeChoice(choice, state);
            
            // 2. Explore
            backtrack(newState, newChoices, result);
            
            // 3. Undo choice (backtrack)
            undoChoice(choice, state);
        }
    }
}
```

**Three Key Steps:**
1. **Choose:** Add element to current solution
2. **Explore:** Recursively solve remaining problem
3. **Unchoose:** Remove element (backtrack)

<br>

---

## Example: Generate All Subsets

**Problem:** Generate all subsets of [1, 2, 3]

**Solution:**
```cpp
void generateSubsets(vector<int>& nums, int index, 
                     vector<int>& current, vector<vector<int>>& result) {
    // Base case: processed all elements
    if (index == nums.size()) {
        result.push_back(current);
        return;
    }
    
    // Choice 1: Exclude current element
    generateSubsets(nums, index + 1, current, result);
    
    // Choice 2: Include current element
    current.push_back(nums[index]);  // Choose
    generateSubsets(nums, index + 1, current, result);  // Explore
    current.pop_back();  // Unchoose (backtrack)
}
```

**Execution Tree:**
```
                        []
                    /        \
              []              [1]
            /    \          /    \
        []      [2]      [1]    [1,2]
       / \      / \      / \     / \
     [] [3]  [2][2,3] [1][1,3][1,2][1,2,3]
```

**Result:** [], [3], [2], [2,3], [1], [1,3], [1,2], [1,2,3]

<br>

---

## When to Use Backtracking

**Perfect For:**
1. **Combinatorial Problems:** Permutations, combinations, subsets
2. **Constraint Satisfaction:** N-Queens, Sudoku, graph coloring
3. **Path Finding:** Maze, word search, knight's tour
4. **Optimization:** Find all solutions, then pick best

**Characteristics:**
- Multiple choices at each step
- Constraints that eliminate invalid paths
- Need all solutions or any valid solution
- No overlapping subproblems (else use DP)

<br>

---

## Optimization Techniques

### 1. Pruning
Eliminate branches that cannot lead to solution.

```cpp
if (!isValid(choice)) {
    continue;  // Skip this branch entirely
}
```

**Example - N-Queens:**
```cpp
// Don't try placing queen if column/diagonal already attacked
if (isUnderAttack(row, col)) {
    continue;  // Prune this branch
}
```

### 2. Early Termination
Stop when first solution found (if only one needed).

```cpp
if (found) return true;  // Stop searching
```

### 3. Constraint Propagation
Use constraints to reduce choices.

```cpp
// Sudoku: If cell can only be one value, fill it immediately
if (possibleValues.size() == 1) {
    fillCell(possibleValues[0]);
}
```

### 4. Ordering Heuristics
Try most constrained choices first.

```cpp
// Try values that eliminate most options for other cells
sort(choices, mostConstrainingFirst);
```

<br>

---

## Common Backtracking Patterns

### Pattern 1: Permutations
**Goal:** Arrange elements in all possible orders

```cpp
void permute(vector<int>& nums, int start, vector<vector<int>>& result) {
    if (start == nums.size()) {
        result.push_back(nums);
        return;
    }
    for (int i = start; i < nums.size(); i++) {
        swap(nums[start], nums[i]);  // Choose
        permute(nums, start + 1, result);  // Explore
        swap(nums[start], nums[i]);  // Unchoose
    }
}
```

### Pattern 2: Combinations
**Goal:** Select K elements from N

```cpp
void combine(int n, int k, int start, 
             vector<int>& current, vector<vector<int>>& result) {
    if (current.size() == k) {
        result.push_back(current);
        return;
    }
    for (int i = start; i <= n; i++) {
        current.push_back(i);  // Choose
        combine(n, k, i + 1, current, result);  // Explore
        current.pop_back();  // Unchoose
    }
}
```

### Pattern 3: Subset Sum
**Goal:** Find subsets that sum to target

```cpp
void subsetSum(vector<int>& nums, int index, int target,
               vector<int>& current, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(current);
        return;
    }
    if (index == nums.size() || target < 0) return;
    
    // Include current element
    current.push_back(nums[index]);
    subsetSum(nums, index + 1, target - nums[index], current, result);
    current.pop_back();
    
    // Exclude current element
    subsetSum(nums, index + 1, target, current, result);
}
```

<br>

---

## Time & Space Complexity

### Time Complexity
**Worst Case:** O(b^d)
- b = branching factor (choices per step)
- d = depth of recursion tree

**Examples:**
- Permutations: O(N!) - N choices, then N-1, then N-2...
- Subsets: O(2^N) - 2 choices (include/exclude) per element
- N-Queens: O(N!) - but pruning reduces significantly

### Space Complexity
**Call Stack:** O(d) where d = maximum depth
**Additional:** O(solution size) for storing current solution

<br>

---

## Backtracking vs Recursion

**All Backtracking uses Recursion, but not all Recursion is Backtracking.**

| Aspect | Recursion | Backtracking |
|--------|-----------|-------------|
| Purpose | Solve problem recursively | Explore all possibilities |
| Undo | Not required | Must undo choices |
| Example | Factorial, Fibonacci | Permutations, N-Queens |
| Pattern | Divide & conquer | Try & undo |

<br>

---

## Common Pitfalls

### 1. Forgetting to Backtrack
```cpp
// WRONG
current.push_back(choice);
backtrack(...);
// Missing: current.pop_back();
```

### 2. Modifying Shared State
```cpp
// WRONG - modifies original array
void backtrack(vector<int>& nums) {
    nums.push_back(x);  // Affects all recursive calls!
}

// CORRECT - use local copy or undo
void backtrack(vector<int> nums) {  // Pass by value
    nums.push_back(x);
}
```

### 3. Not Checking Constraints
```cpp
// WRONG - tries invalid choices
for (choice in choices) {
    backtrack(choice);  // No validation!
}

// CORRECT
for (choice in choices) {
    if (isValid(choice)) {
        backtrack(choice);
    }
}
```

<br>

---

## Classic Backtracking Problems

1. **Permutations:** Generate all arrangements
2. **Combinations:** Select K from N elements
3. **Subsets:** Generate all subsets (power set)
4. **N-Queens:** Place N queens on N×N board
5. **Sudoku Solver:** Fill 9×9 grid with constraints
6. **Word Search:** Find word in 2D grid
7. **Palindrome Partitioning:** Split string into palindromes
8. **Combination Sum:** Find combinations that sum to target
9. **Rat in Maze:** Find path from start to end
10. **Knight's Tour:** Visit all squares on chessboard

<br>

---

## Applications

1. **Puzzle Solving:** Sudoku, crosswords, logic puzzles
2. **Game AI:** Chess, checkers (with minimax)
3. **Scheduling:** Task assignment, timetabling
4. **Resource Allocation:** Bin packing, job scheduling
5. **Constraint Satisfaction:** Map coloring, circuit design
6. **Combinatorial Optimization:** Traveling salesman (small instances)

<br>
<br>

---



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
