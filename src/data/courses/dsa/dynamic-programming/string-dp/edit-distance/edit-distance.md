# Edit Distance

## Problem Statement

Given two strings `word1` and `word2`, return the minimum number of operations required to convert `word1` to `word2`.

You have the following three operations permitted on a word:
- Insert a character
- Delete a character
- Replace a character

**Example 1:**
```
Input: word1 = "horse", word2 = "ros"
Output: 3
```

Explanation:
> horse → rorse (replace 'h' with 'r')
> rorse → rose (remove 'r')
> rose → ros (remove 'e')

**Example 2:**
```
Input: word1 = "intention", word2 = "execution"
Output: 5
```

Explanation:
> intention → inention (remove 't')
> inention → enention (replace 'i' with 'e')
> enention → exention (replace 'n' with 'x')
> exention → exection (replace 'n' with 'c')
> exection → execution (insert 'u')

<br>

---

## Solution 1: Recursive Approach (Brute Force)

**Intuition:**
At each position (i,j) in word1 and word2, we have three choices if characters don't match: insert, delete, or replace. If characters match, no operation needed. Recursively try all possibilities and take minimum.

**Recurrence Relation:**
```
f(i,j) = j                                    if i = 0 (insert j characters)
f(i,j) = i                                    if j = 0 (delete i characters)
f(i,j) = f(i-1,j-1)                          if word1[i-1] = word2[j-1]
f(i,j) = 1 + min(f(i-1,j), f(i,j-1), f(i-1,j-1))  otherwise
         (delete)    (insert)   (replace)
```

**Algorithm:**
1. Base case: If word1 empty, insert all of word2 (return j)
2. Base case: If word2 empty, delete all of word1 (return i)
3. If characters match, move both pointers
4. Else try all three operations, take minimum + 1

### Time Complexity: O(3^(M+N))
**Why exponential?**
- At each position, we make up to 3 recursive calls
- Maximum depth = M+N (length of both strings)
- Total nodes ≈ 3^(M+N)
- Example: M=5, N=5 → 3^10 ≈ 59,000 calls

**Detailed breakdown:**
- Each state (i,j) computed multiple times
- f(2,2) might be called from f(3,2), f(2,3), and f(3,3)
- Overlapping subproblems cause exponential redundancy
- No memoization = recompute same states repeatedly

### Space Complexity: O(M+N)
**Why?**
- Recursion stack depth = M+N (worst case path)
- No additional data structures
- Maximum M+N recursive calls active simultaneously

**Problem:** Too slow for strings longer than 10-15 characters.

> **Key Insight for Improvement:**
> We're solving the same (i,j) subproblems repeatedly. If we cache results in a memo table, we can reduce time from exponential to polynomial.

<br>

---

## Solution 2: Memoization (Top-Down DP)

**Intuition:**
Store result of each (i,j) state in a memo table. Before computing, check if already solved. This eliminates redundant calculations.

**Recurrence Relation:**
```
Same as recursive, but:
if (i,j) in memo: return memo[i,j]
else: compute, store in memo, return
```

**Algorithm:**
1. Create 2D memo dictionary/array
2. Before computing f(i,j), check memo
3. If found, return cached value
4. Else compute recursively, store result, return

### Time Complexity: O(M×N)
**Why polynomial?**
- Total unique states = M×N (one per (i,j) pair)
- Each state computed exactly once
- Subsequent lookups are O(1)
- Total work = M×N × O(1) = O(M×N)

**Detailed breakdown:**
- First call to f(i,j): compute and cache → O(1) work
- All future calls to f(i,j): return memo[i,j] → O(1)
- Total states = M×N
- Total time = M×N × O(1) = O(M×N)

**Improvement:** From O(3^(M+N)) to O(M×N)
- Example: M=10, N=10
- Recursive: 3^20 ≈ 3,486,784,401 operations
- Memoization: 10×10 = 100 operations

### Space Complexity: O(M×N)
**Why?**
- Memo table: M×N entries → O(M×N)
- Recursion stack: O(M+N) depth
- Total: O(M×N) + O(M+N) = O(M×N) (dominant term)

**Breakdown:**
- Memo storage: Each of M×N states needs one entry
- Stack space: Maximum M+N recursive calls active
- Since M×N > M+N, space is O(M×N)

> **Key Insight for Improvement:**
> Memoization works but uses recursion (stack overhead). Can we solve iteratively? Yes - tabulation builds solution bottom-up without recursion.

<br>

---

## Solution 3: Tabulation (Bottom-Up DP)

**Intuition:**
Build solution iteratively from base cases. Fill dp table where dp[i][j] = minimum operations to convert word1[0..i-1] to word2[0..j-1].

**DP State:**
```
dp[i][j] = minimum edit distance between word1[0..i-1] and word2[0..j-1]
```

**Transition:**
```
dp[i][j] = j                                    if i = 0
dp[i][j] = i                                    if j = 0
dp[i][j] = dp[i-1][j-1]                        if word1[i-1] = word2[j-1]
dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])  otherwise
```

**Algorithm:**
1. Create dp table (M+1)×(N+1)
2. Initialize first row: dp[0][j] = j (insert j characters)
3. Initialize first column: dp[i][0] = i (delete i characters)
4. Fill table row by row:
   - If characters match: dp[i][j] = dp[i-1][j-1]
   - Else: dp[i][j] = 1 + min(delete, insert, replace)
5. Return dp[M][N]

### Time Complexity: O(M×N)
**Why?**
- Nested loops: outer M iterations, inner N iterations
- Each cell computed once: O(1) work
- Total: M × N × O(1) = O(M×N)

**Detailed breakdown:**
- Initialize first row: O(N)
- Initialize first column: O(M)
- Fill remaining cells: M×N
- Total: O(M) + O(N) + O(M×N) = O(M×N)

**Comparison with Memoization:**
- Same time complexity: O(M×N)
- But no recursion overhead (no function call stack)
- Iterative approach typically 2-3× faster in practice

### Space Complexity: O(M×N)
**Why?**
- DP table: (M+1)×(N+1) entries → O(M×N)
- No recursion stack (iterative)
- Total: O(M×N)

**Breakdown:**
- dp array: (M+1) rows × (N+1) columns ≈ M×N space
- Auxiliary variables: O(1)
- Total: O(M×N)

> **Key Insight for Improvement:**
> Notice dp[i][j] only depends on dp[i-1][j], dp[i][j-1], and dp[i-1][j-1]. We don't need the entire table - just the previous row! This leads to space optimization.

<br>

---

## Solution 4: Space Optimized (One Row)

**Intuition:**
Use two arrays: prev (previous row) and curr (current row). When computing row i, we only need row i-1. After processing, curr becomes prev for next iteration.

**Algorithm:**
1. Create array prev[N+1], initialize with [0,1,2,...,N]
2. For each row i from 1 to M:
   - Create array curr[N+1], set curr[0] = i
   - For each column j from 1 to N:
     - If word1[i-1] = word2[j-1]: curr[j] = prev[j-1]
     - Else: curr[j] = 1 + min(prev[j], curr[j-1], prev[j-1])
   - prev = curr
3. Return prev[N]

### Time Complexity: O(M×N)
**Why unchanged?**
- Same iteration pattern
- Each cell still processed once
- Space optimization doesn't affect time

### Space Complexity: O(N)
**Why optimal?**
- Two arrays of size N+1: prev and curr → O(2N) = O(N)
- Few variables: O(1)
- Total: O(N)

**Improvement:**
- Before (tabulation): O(M×N)
- After (1D): O(N)
- Example: M=1000, N=1000
  - Before: 1,000,000 space units
  - After: 2,000 space units (500× reduction!)

**Why this works:**
- When computing curr[j], we need:
  - prev[j] (cell above) - not yet overwritten
  - curr[j-1] (cell to left) - already computed
  - prev[j-1] (diagonal) - not yet overwritten
- All required values available when processing left-to-right

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursive | O(3^(M+N)) | O(M+N) | Baseline - too slow |
| Memoization | O(M×N) | O(M×N) | Cache results - exponential to polynomial |
| Tabulation | O(M×N) | O(M×N) | Remove recursion - same complexity, faster |
| Space Optimized | O(M×N) | O(N) | Keep only previous row - space reduced |

**Key Insights:**
1. **Recursive → Memoization:** Overlapping subproblems → cache results
2. **Memoization → Tabulation:** Recursion overhead → iterative approach
3. **Tabulation → Space Optimized:** Only need previous row → two arrays suffice

**When to use each:**
- **Memoization:** Natural recursion, easier to implement
- **Tabulation:** Want iterative solution, slightly faster
- **Space Optimized:** Memory constrained, optimal solution

> **Final Complexity:** O(M×N) time, O(N) space

<br>
<br>

---

```code```
