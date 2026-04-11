Find if pattern exists in text using various string matching algorithms.

<br>

> Input:
> text = "hello world", pattern = "world"

> Output:
> 6 (index where pattern starts)

> Explanation:
> Pattern "world" found at index 6 in text
> 
> Multiple algorithms with different trade-offs:
> - Naive: Simple but O(N×M)
> - KMP: Optimal O(N+M) with preprocessing
> - Rabin-Karp: O(N+M) average with hashing
> 
> **Key insight:** Preprocessing pattern enables linear-time matching.

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

## Solution 1: Naive Approach

**Intuition:**
Check pattern at every position in text by comparing character by character.

**Algorithm:**
1. For each position i in text (0 to N-M):
   - Compare text[i..i+M-1] with pattern[0..M-1]
   - If all characters match, return i
2. Return -1 if no match found

**Example:**
```
text = "ABABCABAB"
pattern = "ABAB"

i=0: ABAB vs ABAB ✓ → Match at index 0
```

### Time Complexity: O(N×M)
**Why?**
- Outer loop: N-M+1 positions ≈ O(N)
- Inner loop: M character comparisons per position
- Total: O(N) × O(M) = O(N×M)

**Detailed breakdown:**
- Best case: O(N) when first character never matches
- Worst case: O(N×M) when pattern almost matches everywhere
- Example: text="AAAAAAB", pattern="AAAB" → many failed comparisons

### Space Complexity: O(1)
**Why?**
- Only use index variables
- No additional data structures

**Problem:** Inefficient for large texts - rechecks characters unnecessarily.

> **Key Insight for Improvement:**
> When mismatch occurs, we restart from next position. But pattern structure can tell us how far to skip! KMP uses this insight.

<br>

---

## Solution 2: KMP (Knuth-Morris-Pratt)

**Intuition:**
When mismatch occurs, use pattern's internal structure to avoid rechecking matched characters. Build LPS (Longest Proper Prefix which is also Suffix) array to know how much to skip.

**LPS Array Construction:**
```
pattern = "ABABC"
lps     = [0,0,1,2,0]

Meaning: lps[i] = length of longest proper prefix of pattern[0..i]
         that is also a suffix

For "ABAB":
- lps[0] = 0 (no proper prefix)
- lps[1] = 0 ("AB" has no matching prefix-suffix)
- lps[2] = 1 ("ABA" → "A" matches)
- lps[3] = 2 ("ABAB" → "AB" matches)
```

**Algorithm:**
1. **Build LPS array:**
   - len = 0, i = 1
   - While i < M:
     - If pattern[i] == pattern[len]: lps[i] = ++len, i++
     - Else if len > 0: len = lps[len-1]
     - Else: lps[i] = 0, i++

2. **Search using LPS:**
   - i = 0 (text index), j = 0 (pattern index)
   - While i < N:
     - If text[i] == pattern[j]: i++, j++
     - If j == M: return i-M (match found)
     - Else if i < N and mismatch:
       - If j > 0: j = lps[j-1] (skip using LPS)
       - Else: i++

**Example:**
```
text    = "ABABDABACDABABCABAB"
pattern = "ABABC"
lps     = [0,0,1,2,0]

Step-by-step:
i=0-3: Match "ABAB"
i=4: Mismatch at 'D' vs 'C'
     Use lps[3]=2 → continue from pattern[2]
     Don't restart text from i=1!
```

### Time Complexity: O(N+M)
**Why?**
- Build LPS: O(M) - each character processed once
- Search: O(N) - text pointer never backtracks
- Total: O(M) + O(N) = O(N+M)

**Detailed breakdown:**
- LPS construction: M iterations, each O(1) amortized
- Search phase: N iterations, j only moves forward (amortized)
- No character in text is compared more than twice

**Improvement:** From O(N×M) to O(N+M)
- Example: N=1,000,000, M=1,000
- Naive: 1,000,000 × 1,000 = 1,000,000,000 operations
- KMP: 1,000,000 + 1,000 = 1,001,000 operations (1000× faster!)

### Space Complexity: O(M)
**Why?**
- LPS array: M entries → O(M)
- Few variables: O(1)
- Total: O(M)

> **Key Insight for Improvement:**
> KMP guarantees O(N+M) but needs O(M) space. Can we achieve similar average performance with O(1) space? Yes - Rabin-Karp uses hashing!

<br>

---

## Solution 3: Rabin-Karp (Rolling Hash)

**Intuition:**
Compute hash of pattern and hash of each text window. Compare hashes first (O(1)), only do string comparison on hash collision. Use rolling hash to update window hash in O(1).

**Hash Function:**
```cpp
hash(s) = (s[0]×d^(M-1) + s[1]×d^(M-2) + ... + s[M-1]×d^0) % MOD

where:
d = base (usually 256 for ASCII)
MOD = large prime (e.g., 10^9+7)
```

**Rolling Hash Update:**
```
Remove leftmost character:
hash = (hash - text[i]×d^(M-1)) % MOD

Shift left:
hash = hash × d

Add new rightmost character:
hash = (hash + text[i+M]) % MOD

All in O(1)!
```

**Algorithm:**
1. Compute pattern hash: O(M)
2. Compute first window hash: O(M)
3. For each position i (0 to N-M):
   - If window_hash == pattern_hash:
     - Verify with string comparison (avoid false positives)
     - If match: return i
   - Roll hash to next window: O(1)
4. Return -1 if no match

**Example:**
```
text = "ABCABC", pattern = "ABC"
d = 256, MOD = 101

pattern_hash = (65×256^2 + 66×256 + 67) % 101 = 4

Window 0 ("ABC"): hash = 4 ✓ → Verify → Match!
```

### Time Complexity: O(N+M) average, O(N×M) worst
**Why average O(N+M)?**
- Compute pattern hash: O(M)
- Compute first window hash: O(M)
- Slide through N-M+1 windows: O(N)
  - Each hash comparison: O(1)
  - String verification: O(M) only on hash match
  - With good hash, collisions rare → O(N) total
- Total: O(M) + O(N) = O(N+M)

**Why worst O(N×M)?**
- If hash collisions frequent (bad hash function)
- Every window triggers O(M) string verification
- Total: O(N) × O(M) = O(N×M)

**Detailed breakdown:**
- Best case: O(N+M) with no collisions
- Average case: O(N+M) with rare collisions
- Worst case: O(N×M) with many collisions
- Example: All same characters → many hash collisions

### Space Complexity: O(1)
**Why?**
- Store pattern hash, window hash, d^(M-1): O(1)
- No arrays or additional structures
- Total: O(1)

**Advantage over KMP:**
- O(1) space vs O(M) space
- Easy to extend to multiple patterns (compute multiple hashes)
- Simple implementation

<br>

---

## Comparison

| Algorithm | Time | Space | Best For |
|-----------|------|-------|----------|
| Naive | O(N×M) | O(1) | Small inputs, simple implementation |
| KMP | O(N+M) | O(M) | Guaranteed linear time |
| Rabin-Karp | O(N+M) avg | O(1) | Multiple patterns, space-constrained |

**When to use each:**
- **Naive:** Small texts, simple code, no preprocessing needed
- **KMP:** Need guaranteed O(N+M), single pattern, space available
- **Rabin-Karp:** Multiple patterns, O(1) space needed, average case acceptable

<br>

---

## Applications

1. **Text Editors:** Find/replace functionality (KMP for single pattern)
2. **DNA Sequencing:** Pattern matching in genomes (Rabin-Karp for multiple patterns)
3. **Plagiarism Detection:** Find copied text (Rabin-Karp for document fingerprinting)
4. **Network Security:** Intrusion detection patterns (KMP for guaranteed performance)
5. **Search Engines:** Query matching in documents (Rabin-Karp for multiple queries)

<br>
<br>

---

```code```
