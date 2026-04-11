Find the length of the longest common subsequence between two strings. A subsequence is a sequence that appears in the same relative order but not necessarily contiguous.

<br>

> Input:
> text1 = "abcde", text2 = "ace"

> Output:
> 3

> Explanation:
> Longest common subsequence: "ace"
> - 'a' appears in both at positions 0
> - 'c' appears in both (text1[2], text2[1])
> - 'e' appears in both (text1[4], text2[2])
> Length: 3
> 
> **Key insight:** If characters match, add 1 to LCS of remaining strings.

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

## Solution 1: Memoization (Top-Down DP)

**Recurrence Relation:**
```
if text1[i] == text2[j]:
    lcs(i, j) = 1 + lcs(i+1, j+1)
else:
    lcs(i, j) = max(lcs(i+1, j), lcs(i, j+1))
Base: lcs(m, *) = 0, lcs(*, n) = 0
```

**Algorithm:**
1. Compare characters at positions i, j
2. If match: 1 + recurse on both remaining
3. If no match: max of (skip i) or (skip j)
4. Store in memo[i][j]

**Key insight:** Match extends LCS, no match tries both options.



<br>

### Time Complexity: O(m × n)
- m × n subproblems
- Each computed once

### Space Complexity: O(m × n)
- Memo table: O(m × n)
- Recursion stack: O(m + n)

<br>

---

## Solution 2: Tabulation (Bottom-Up DP)

**DP State:**
```
dp[i][j] = LCS length of text1[0..i-1] and text2[0..j-1]
```

**Transition:**
```
if text1[i-1] == text2[j-1]:
    dp[i][j] = 1 + dp[i-1][j-1]
else:
    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
```

**Algorithm:**
1. Create (m+1) × (n+1) dp table
2. Initialize first row and column to 0
3. Fill table using transition
4. Return dp[m][n]



<br>

### Time Complexity: O(m × n)
- Nested loops: m × n iterations

### Space Complexity: O(m × n)
- DP table: O(m × n)

**Space Optimization: O(min(m, n))**
- Only need previous row
- Use 1D array of size min(m, n)

<br>

---

## Comparison

| Approach | Time | Space | Pros | Cons |
|----------|------|-------|------|------|
| Memoization | O(m×n) | O(m×n) | Natural recursion | Stack overhead |
| Tabulation | O(m×n) | O(m×n) | Iterative | Must solve all |
| Optimized | O(m×n) | O(min(m,n)) | Space efficient | Can't reconstruct |

**Applications:**
- Diff tools (git diff)
- DNA sequence alignment
- File comparison
- Plagiarism detection

> **Time Complexity:** O(m × n)
> **Space Complexity:** O(m × n) or O(min(m,n)) optimized

<br>
<br>

---

---

```code```
