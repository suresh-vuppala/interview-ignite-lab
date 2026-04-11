Partition string into substrings such that every substring is a palindrome. Return all possible partitions.

<br>

> Input:
> s = "aab"

> Output:
> [["a","a","b"], ["aa","b"]]

> Explanation:
> Two ways to partition into palindromes:
> - "a" + "a" + "b" (all single chars are palindromes)
> - "aa" + "b" ("aa" is palindrome)
> 
> **Key insight:** Try all possible cuts, check if substring is palindrome, recurse for remaining.

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

## Solution: Backtracking with Palindrome Check

**Intuition:**
At each position, try all possible substrings starting from that position.
If substring is palindrome, add to current partition and recurse for remaining string.
When reach end of string, add current partition to result.

**Algorithm:**
1. Start with index=0, current partition=[]
2. Base case: if index == s.length, add partition to result
3. For each end position from index to s.length-1:
   - Extract substring s[index..end]
   - If substring is palindrome:
     - Add substring to partition
     - Recurse for remaining string (index=end+1)
     - Remove substring (backtrack)

**Palindrome Check:**
```cpp
bool isPalindrome(string s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) return false;
        start++;
        end--;
    }
    return true;
}
```

**Example Walkthrough:**
```
s = "aab"

backtrack(0, []):
  Try substring [0,0]="a": palindrome ✓
    Add "a", partition=["a"]
    backtrack(1, ["a"]):
      Try substring [1,1]="a": palindrome ✓
        Add "a", partition=["a","a"]
        backtrack(2, ["a","a"]):
          Try substring [2,2]="b": palindrome ✓
            Add "b", partition=["a","a","b"]
            backtrack(3, ["a","a","b"]):
              index==3, add ["a","a","b"] ✓
      
      Try substring [1,2]="ab": not palindrome ✗
  
  Try substring [0,1]="aa": palindrome ✓
    Add "aa", partition=["aa"]
    backtrack(2, ["aa"]):
      Try substring [2,2]="b": palindrome ✓
        Add "b", partition=["aa","b"]
        backtrack(3, ["aa","b"]):
          index==3, add ["aa","b"] ✓
  
  Try substring [0,2]="aab": not palindrome ✗

Result: [["a","a","b"], ["aa","b"]]
```

**Recursion Tree:**
```
                    ""
            /               \
          "a"              "aa"
           |                 |
        ["a"]             ["aa"]
           |                 |
       ["a","a"]         ["aa","b"]✓
           |
      ["a","a","b"]✓
```

**Visual Representation:**
```
String: a a b
        ↓ ↓ ↓
Cuts:   | | |  → ["a","a","b"]
        |   |  → ["aa","b"]
        |      → ["aab"] (not palindrome)
```

### Time Complexity: O(N × 2^N)
**Why?**
- At each position, decide where to cut (2 choices per position)
- N positions: 2^N possible partitions
- Each partition: O(N) to check palindromes and copy
- Total: O(N × 2^N)

**Detailed breakdown:**
- Palindrome check: O(N) per substring
- Number of substrings checked: O(2^N)
- Copying result: O(N) per valid partition
- Total: O(N × 2^N)

### Space Complexity: O(N)
**Why?**
- Recursion stack: O(N) maximum depth
- Current partition: O(N) substrings
- Each substring: O(N) characters
- Total: O(N)

<br>

---

## Optimization: Precompute Palindromes (DP)

**Intuition:**
Checking palindrome repeatedly is expensive.
Precompute all palindromic substrings using DP.

**DP Table:**
```cpp
bool dp[n][n];
// dp[i][j] = true if s[i..j] is palindrome

// Fill DP table
for (int len = 1; len <= n; len++) {
    for (int i = 0; i <= n - len; i++) {
        int j = i + len - 1;
        
        if (len == 1) {
            dp[i][j] = true;  // Single char
        } else if (len == 2) {
            dp[i][j] = (s[i] == s[j]);  // Two chars
        } else {
            dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);
        }
    }
}
```

**Optimized Backtracking:**
```cpp
void backtrack(s, index, partition, result, dp) {
    if (index == s.length()) {
        result.add(partition)
        return
    }
    
    for (int end = index; end < s.length(); end++) {
        if (dp[index][end]) {  // O(1) palindrome check
            partition.add(s.substring(index, end+1))
            backtrack(s, end+1, partition, result, dp)
            partition.remove_last()
        }
    }
}
```

**Time:** O(N × 2^N) - same but faster constants
**Space:** O(N²) for DP table + O(N) for recursion = O(N²)

<br>

---

## Key Insights

1. **All Cuts:** Try every possible way to partition string
2. **Palindrome Check:** Essential constraint for valid partition
3. **Backtracking:** Add substring → Recurse → Remove substring
4. **DP Optimization:** Precompute palindromes for O(1) lookup

**Common Mistakes:**
- Not checking if substring is palindrome before recursing
- Forgetting to backtrack (remove last substring)
- Wrong palindrome check implementation
- Not handling empty string edge case

<br>

---

## Example: Longer String

```
s = "aabb"

Valid partitions:
["a","a","b","b"]
["a","a","bb"]
["aa","b","b"]
["aa","bb"]

Invalid (not all palindromes):
["aab","b"]  - "aab" not palindrome
["a","abb"]  - "abb" not palindrome
```

<br>

---

## Edge Cases

1. **Empty string:** "" → [[]]
2. **Single character:** "a" → [["a"]]
3. **All same characters:** "aaa" → [["a","a","a"], ["a","aa"], ["aa","a"], ["aaa"]]
4. **No palindrome substrings > 1:** "abc" → [["a","b","c"]]
5. **Entire string palindrome:** "aba" → [["a","b","a"], ["aba"]]

<br>

---

## Comparison: With vs Without DP

| Aspect | Without DP | With DP |
|--------|------------|---------|
| Preprocessing | None | O(N²) |
| Palindrome Check | O(N) | O(1) |
| Total Time | O(N × 2^N) | O(N × 2^N) |
| Space | O(N) | O(N²) |
| Best For | Small strings | Large strings |

<br>

---

## Related Problems

**1. Palindrome Partitioning II:**
Find minimum cuts needed.
Use DP instead of backtracking.
**Time:** O(N²)

**2. Palindrome Partitioning III:**
Partition into K palindromic substrings.
Use DP with K dimension.
**Time:** O(N² × K)

**3. Palindrome Partitioning IV:**
Check if can partition into K palindromes.
Use DP with boolean result.
**Time:** O(N² × K)

<br>

---

## Applications

1. **Text Processing:** Breaking text into meaningful palindromic chunks
2. **DNA Sequencing:** Finding palindromic sequences
3. **String Compression:** Palindrome-based encoding
4. **Pattern Recognition:** Identifying symmetric patterns
5. **Puzzle Games:** Word games with palindrome constraints

<br>
<br>

---

```code```
