Find the longest substring that appears in both strings.

<br>

> Input:
> s1 = "abcde", s2 = "xbcdy"

> Output:
> "bcd" (length 3)

> Explanation:
> Common substrings: "b", "bc", "bcd", "c", "cd", "d"
> Longest is "bcd" with length 3
> 
> **Key insight:** Binary search on length + rolling hash enables efficient verification.

<br>


---

## Constraints

- `1 ≤ s.length ≤ 10⁵`
- `s consists of lowercase English letters (typically)`
- `Hash collisions must be handled`

<br>

---

## All Possible Edge Cases

1. **Empty string:** Return '' or 0
2. **Single character:** Trivial case
3. **All same characters:** Hash/pattern matching is straightforward
4. **No match found:** Return -1 or empty
5. **Multiple matches:** Return all or first depending on problem
6. **Very long string:** Need efficient O(n) algorithm

<br>

---

## Solution 1: Brute Force (Check All Substrings)

**Intuition:**
Generate all substrings of s1, check if each exists in s2.
Track maximum length found.

**Algorithm:**
1. For each starting position i in s1 (0 to n-1):
   - For each ending position j (i to n-1):
     - Extract substring s1[i..j]
     - Check if it exists in s2 using substring search
     - Update max length if found
2. Return max length

**Example:**
```
s1 = "abc", s2 = "bcd"

Check all substrings of s1:
"a" → not in s2
"ab" → not in s2
"abc" → not in s2
"b" → in s2 ✓ (length 1)
"bc" → in s2 ✓ (length 2)
"c" → in s2 ✓ (length 1)

Max = 2 ("bc")
```

### Time Complexity: O(N² × M)
**Why?**
- Generate all substrings of s1: O(N²) substrings
- For each substring, search in s2: O(M) per search
- Total: O(N²) × O(M) = O(N² × M)

**Detailed breakdown:**
- Outer loop (start): N iterations
- Inner loop (end): N iterations on average
- Substring search in s2: O(M) for each
- Total: N × N × M = O(N² × M)

### Space Complexity: O(N)
**Why?**
- Store current substring: O(N) in worst case
- Few variables: O(1)
- Total: O(N)

**Problem:** Too slow for large strings - generates and checks too many substrings.

> **Key Insight for Improvement:**
> We're checking substrings in arbitrary order. Can we be smarter? Yes - binary search on the answer (length) and use hashing for fast verification!

<br>

---

## Solution 2: Binary Search + Brute Force Verification

**Intuition:**
If a common substring of length K exists, then common substrings of all lengths < K also exist.
This monotonic property allows binary search on the answer.

**Algorithm:**
1. Binary search on length L from 0 to min(n, m):
   - Generate all substrings of length L from s1
   - For each, check if it exists in s2
   - If any match found: try larger L (left = mid + 1)
   - If no match: try smaller L (right = mid - 1)
2. Return maximum L where match was found

**Example:**
```
s1 = "abcde", s2 = "xbcdy"
min(5, 5) = 5

Binary search:
L=2 (mid of 0-5): Check "ab","bc","cd","de" in s2
  "bc" found ✓ → try larger (left=3)
L=4 (mid of 3-5): Check "abcd","bcde" in s2
  None found ✗ → try smaller (right=3)
L=3 (mid of 3-3): Check "abc","bcd","cde" in s2
  "bcd" found ✓ → answer is 3
```

### Time Complexity: O(N² × M × log(min(N,M)))
**Why?**
- Binary search: O(log(min(N,M))) iterations
- Each iteration: check all substrings of length L
  - Generate N-L+1 ≈ O(N) substrings
  - Search each in s2: O(M) per search
  - Total per iteration: O(N × M)
- Total: O(log(min(N,M))) × O(N × M) = O(N × M × log(min(N,M)))

**Detailed breakdown:**
- Binary search levels: log(min(N,M))
- At each level, check O(N) substrings
- Each substring search in s2: O(M)
- Total: log(min(N,M)) × N × M

### Space Complexity: O(L)
**Why?**
- Store current substring of length L: O(L)
- Binary search variables: O(1)
- Total: O(L) ≤ O(min(N,M))

**Improvement:** From O(N² × M) to O(N × M × log(min(N,M)))
- Example: N=1000, M=1000
- Brute force: 1000² × 1000 = 1,000,000,000 operations
- Binary search: 1000 × 1000 × log(1000) ≈ 10,000,000 operations (100× faster!)

> **Key Insight for Improvement:**
> Substring search in s2 takes O(M) time. Can we make it faster? Yes - use rolling hash for O(1) average-case substring comparison!

<br>

---

## Solution 3: Binary Search + Rolling Hash (Optimal)

**Intuition:**
Combine binary search on length with rolling hash for O(1) substring comparison.
Hash all substrings of length L in both strings, check for common hashes.

**Rolling Hash Formula:**
```cpp
hash(s[i..i+L-1]) = (s[i]×d^(L-1) + s[i+1]×d^(L-2) + ... + s[i+L-1]×d^0) % MOD

Rolling update:
hash_new = (hash_old - s[i]×d^(L-1)) × d + s[i+L]
```

**Algorithm:**
1. Binary search on length L from 0 to min(n, m):
   - **Hash all substrings of length L in s1:**
     - Compute first hash
     - Roll through s1, store all hashes in set
   - **Hash all substrings of length L in s2:**
     - Compute first hash
     - Roll through s2, check if hash exists in s1's set
   - If match found: try larger L
   - If no match: try smaller L
2. Return maximum L where match was found

**Example:**
```
s1 = "abcde", s2 = "xbcdy"
d = 256, MOD = 10^9+7

L=3:
s1 hashes: {hash("abc"), hash("bcd"), hash("cde")}
s2 hashes: {hash("xbc"), hash("bcd"), hash("cdy")}
Common: hash("bcd") ✓ → try L=4

L=4:
s1 hashes: {hash("abcd"), hash("bcde")}
s2 hashes: {hash("xbcd"), hash("bcdy")}
No common hash ✗ → answer is 3
```

### Time Complexity: O((N+M) × log(min(N,M)))
**Why?**
- Binary search: O(log(min(N,M))) iterations
- Each iteration at length L:
  - Hash all substrings in s1: O(N) with rolling hash
  - Hash all substrings in s2: O(M) with rolling hash
  - Hash lookup: O(1) average per substring
  - Total per iteration: O(N + M)
- Total: O(log(min(N,M))) × O(N + M) = O((N+M) × log(min(N,M)))

**Detailed breakdown:**
- Binary search levels: log(min(N,M))
- At each level:
  - Compute N-L+1 hashes for s1: O(N) with rolling
  - Compute M-L+1 hashes for s2: O(M) with rolling
  - Set operations: O(1) average per hash
- Total: log(min(N,M)) × (N + M)

### Space Complexity: O(N)
**Why?**
- Hash set for s1 substrings: O(N) hashes
- Rolling hash variables: O(1)
- Total: O(N)

**Improvement:** From O(N × M × log(min(N,M))) to O((N+M) × log(min(N,M)))
- Example: N=10000, M=10000
- Binary + Brute: 10000 × 10000 × log(10000) ≈ 1,300,000,000 operations
- Binary + Hash: (10000 + 10000) × log(10000) ≈ 260,000 operations (5000× faster!)

**Why this is optimal:**
- Binary search: O(log(min(N,M))) is optimal for searching answer space
- Rolling hash: O(N+M) per iteration is optimal for checking all substrings
- Cannot do better than O((N+M) × log(min(N,M))) for this approach

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N² × M) | O(N) | Baseline - check all substrings |
| Binary + Brute | O(N × M × log(min(N,M))) | O(L) | Binary search on answer |
| Binary + Hash | O((N+M) × log(min(N,M))) | O(N) | Rolling hash for O(1) comparison |

**Key Insights:**
1. **Brute Force → Binary Search:** Monotonic property → search answer space
2. **Binary + Brute → Binary + Hash:** Expensive substring search → O(1) hash comparison
3. **Rolling Hash:** Enables O(1) substring hash update instead of O(L) recomputation

**When to use each:**
- **Brute Force:** Very small strings (N, M < 100), simple implementation
- **Binary + Brute:** Medium strings, want better than brute force
- **Binary + Hash:** Large strings (N, M > 1000), optimal performance

> **Final Complexity:** O((N+M) × log(min(N,M))) time, O(N) space

<br>

---

## Applications

1. **Diff Tools:** Find common code blocks between file versions
2. **Bioinformatics:** DNA/protein sequence alignment and similarity
3. **Plagiarism Detection:** Find copied passages in documents
4. **Data Deduplication:** Identify duplicate content blocks
5. **Version Control:** Detect common chunks in file diffs

<br>
<br>

---

```code```
