# Word Break

## Problem Statement

Given a string `s` and a dictionary of strings `wordDict`, return `true` if `s` can be segmented into a space-separated sequence of one or more dictionary words.

**Note:** The same word in the dictionary may be reused multiple times in the segmentation.

**Example 1:**
```
Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
```

Explanation:
> Return true because "leetcode" can be segmented as "leet code".

**Example 2:**
```
Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
```

Explanation:
> Return true because "applepenapple" can be segmented as "apple pen apple".
> Note that you are allowed to reuse a dictionary word.

**Example 3:**
```
Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
```

<br>


---

## Constraints

- `0 ≤ n ≤ 10⁴`
- `Values fit in 32-bit integer`
- `DP state space fits in memory`

<br>

---

## All Possible Edge Cases

1. **n = 0 or empty input:** Base case — return 0 or empty
2. **n = 1:** Single element — trivial case
3. **All same elements:** Check if pattern still applies
4. **Maximum constraints:** Verify time complexity handles worst case
5. **Negative values (if applicable):** Affects min/max DP transitions
6. **Result requires modular arithmetic:** Use MOD = 10⁹ + 7 to prevent overflow

<br>

---

## Solution 1: Recursive Approach (Brute Force)

**Intuition:**
At each position, try all possible words from dictionary that match the prefix starting at current position. If a word matches, recursively check if remaining string can be segmented.

**Recurrence Relation:**
```
f(i) = true                                if i = len(s)
f(i) = OR of f(j) for all j where s[i:j] in wordDict
```

**Algorithm:**
1. Base case: If reached end of string, return true
2. Try all possible end positions j from i+1 to len(s)
3. If s[i:j] is in dictionary and f(j) is true, return true
4. If no valid segmentation found, return false

### Time Complexity: O(2^N)
**Why exponential?**
- At each position, we try all possible word lengths
- Each decision branches into multiple recursive calls
- Total nodes in recursion tree ≈ 2^N
- Example: N=10 → 2^10 = 1,024 calls

**Detailed breakdown:**
- Each position i can be start of 0 to N-i words
- f(5) might be called from f(0), f(1), f(2), f(3), f(4)
- Overlapping subproblems cause exponential redundancy
- No memoization = recompute same positions repeatedly

### Space Complexity: O(N)
**Why?**
- Recursion stack depth = N (worst case)
- No additional data structures
- Maximum N recursive calls active simultaneously

**Problem:** Too slow for strings longer than 15-20 characters.

> **Key Insight for Improvement:**
> We're checking the same position i multiple times. If we cache whether position i can be segmented, we avoid recomputation.

<br>

---

## Solution 2: Memoization (Top-Down DP)

**Intuition:**
Store result for each starting position i in a memo table. Before computing, check if already solved. This eliminates redundant calculations.

**Recurrence Relation:**
```
Same as recursive, but:
if i in memo: return memo[i]
else: compute, store in memo, return
```

**Algorithm:**
1. Create memo dictionary/array
2. Before computing f(i), check memo
3. If found, return cached value
4. Else compute recursively, store result, return

### Time Complexity: O(N²)
**Why quadratic?**
- Total unique positions = N (one per index)
- For each position, we check up to N substrings
- Each substring check: O(1) with hash set
- Total work = N × N × O(1) = O(N²)

**Detailed breakdown:**
- First call to f(i): try all j from i+1 to N → O(N) work
- All future calls to f(i): return memo[i] → O(1)
- Total positions = N
- Total time = N × N = O(N²)

**Improvement:** From O(2^N) to O(N²)
- Example: N=20
- Recursive: 2^20 ≈ 1,048,576 operations
- Memoization: 20×20 = 400 operations

### Space Complexity: O(N)
**Why?**
- Memo table: N entries → O(N)
- Recursion stack: O(N) depth
- Word set: O(M) where M = total characters in dictionary
- Total: O(N) + O(N) + O(M) = O(N + M)

**Breakdown:**
- Memo storage: Each of N positions needs one entry
- Stack space: Maximum N recursive calls active
- Dictionary set: O(M) for fast lookup

> **Key Insight for Improvement:**
> Memoization works but uses recursion. Can we solve iteratively? Yes - tabulation builds solution bottom-up.

<br>

---

## Solution 3: Tabulation (Bottom-Up DP)

**Intuition:**
Define dp[i] = true if s[0:i] can be segmented. Build solution from left to right, checking all possible last words.

**DP State:**
```
dp[i] = true if substring s[0:i] can be segmented into dictionary words
```

**Transition:**
```
dp[i] = true if there exists j < i such that:
  - dp[j] = true (prefix can be segmented)
  - s[j:i] in wordDict (remaining part is a valid word)
```

**Algorithm:**
1. Create dp array of size N+1, initialize all to false
2. Set dp[0] = true (empty string can be segmented)
3. For each i from 1 to N:
   - For each j from 0 to i-1:
     - If dp[j] and s[j:i] in wordDict: dp[i] = true, break
4. Return dp[N]

### Time Complexity: O(N²)
**Why?**
- Outer loop: N iterations
- Inner loop: up to N iterations per outer iteration
- Substring check: O(1) with hash set
- Total: N × N × O(1) = O(N²)

**Detailed breakdown:**
- Initialize array: O(N)
- Fill dp table: 1 + 2 + 3 + ... + N = N(N+1)/2 ≈ O(N²)
- Total: O(N) + O(N²) = O(N²)

**Comparison with Memoization:**
- Same time complexity: O(N²)
- But no recursion overhead (no function call stack)
- Iterative approach typically faster in practice
- Easier to understand and debug

### Space Complexity: O(N)
**Why?**
- DP array: N+1 entries → O(N)
- Word set: O(M) where M = total characters in dictionary
- No recursion stack (iterative)
- Total: O(N + M)

**Breakdown:**
- dp array: N+1 space
- Dictionary set: O(M)
- Auxiliary variables: O(1)
- Total: O(N + M)

> **Key Insight for Improvement:**
> Can we optimize further? BFS approach treats this as a graph problem, potentially with early termination.

<br>

---

## Solution 4: BFS Approach (Alternative)

**Intuition:**
Treat string positions as graph nodes. An edge exists from i to j if s[i:j] is in dictionary. Use BFS to find if we can reach end from start.

**Algorithm:**
1. Create visited set and queue
2. Start BFS from position 0
3. For each position, try all possible next positions
4. If next substring is in dictionary, add to queue
5. If we reach end position, return true
6. If queue empty without reaching end, return false

### Time Complexity: O(N²)
**Why?**
- Each position visited at most once (visited set)
- For each position, check up to N next positions
- Total: N × N = O(N²)

**Detailed breakdown:**
- BFS visits each position once: N positions
- For each position, try N possible next positions
- Substring check: O(1) with hash set
- Total: N × N = O(N²)

**Comparison with Tabulation:**
- Same worst-case time: O(N²)
- But can terminate early if solution found
- Better for cases where solution exists early in string

### Space Complexity: O(N)
**Why?**
- Queue: at most N positions → O(N)
- Visited set: at most N positions → O(N)
- Word set: O(M)
- Total: O(N + M)

**Breakdown:**
- Queue space: O(N)
- Visited set: O(N)
- Dictionary set: O(M)
- Total: O(N + M)

**Why this works:**
- Each position represents a state in graph
- Edge from i to j means s[i:j] is valid word
- BFS finds shortest path (fewest words) if solution exists
- Visited set prevents revisiting same position

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursive | O(2^N) | O(N) | Baseline - too slow |
| Memoization | O(N²) | O(N) | Cache results - exponential to polynomial |
| Tabulation | O(N²) | O(N) | Iterative - no recursion overhead |
| BFS | O(N²) | O(N) | Graph approach - early termination possible |

**Key Insights:**
1. **Recursive → Memoization:** Overlapping subproblems → cache results
2. **Memoization → Tabulation:** Recursion overhead → iterative approach
3. **Tabulation → BFS:** Different perspective → graph traversal

**When to use each:**
- **Memoization:** Natural recursion, easier to implement
- **Tabulation:** Want iterative solution, standard DP approach
- **BFS:** Graph mindset, potential early termination

> **Final Complexity:** O(N²) time, O(N) space

<br>
<br>

---

```code```
