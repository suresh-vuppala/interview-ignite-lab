You are given a 0-indexed string array words.

Let's define a boolean function isPrefixAndSuffix that takes two strings, str1 and str2:

isPrefixAndSuffix(str1, str2) returns true if str1 is both a prefix and a suffix of str2, and false otherwise.

For example, isPrefixAndSuffix("aba", "ababa") is true because "aba" is a prefix of "ababa" and also a suffix, but isPrefixAndSuffix("abc", "abcd") is false.

Return an integer denoting the number of index pairs (i, j) such that i < j, and isPrefixAndSuffix(words[i], words[j]) is true.

<br>

**Example 1:**
```
Input: words = ["a","aba","ababa","aa"]
Output: 4
Explanation: 
i = 0 and j = 1 because isPrefixAndSuffix("a", "aba") is true.
i = 0 and j = 2 because isPrefixAndSuffix("a", "ababa") is true.
i = 0 and j = 3 because isPrefixAndSuffix("a", "aa") is true.
i = 1 and j = 2 because isPrefixAndSuffix("aba", "ababa") is true.
```

**Example 2:**
```
Input: words = ["pa","papa","ma","mama"]
Output: 2
Explanation:
i = 0 and j = 1 because isPrefixAndSuffix("pa", "papa") is true.
i = 2 and j = 3 because isPrefixAndSuffix("ma", "mama") is true.
```

**Example 3:**
```
Input: words = ["abab","ab"]
Output: 0
Explanation: The only valid index pair is i = 0 and j = 1, and isPrefixAndSuffix("abab", "ab") is false.
```

<br>

---

## Constraints
- 1 <= words.length <= 10^5
- 1 <= words[i].length <= 10^5
- words[i] consists only of lowercase English letters
- The sum of the lengths of all words[i] does not exceed 5 * 10^5

<br>

---

## All Possible Edge Cases
1. **No valid pairs: 0
2. **Word is both prefix and suffix of another
3. **i < j ordering constraint**

<br>

---

## Solution 1: Brute Force - Check All Pairs

**Intuition:**
For each pair (i,j) where i < j, check if words[i] is both a prefix AND suffix of words[j]. Use built-in string methods.

**Algorithm:**
1. For each word i from 0 to n-1:
   - For each word j from i+1 to n-1:
     - If len(words[i]) > len(words[j]), skip
     - Check if words[j].startsWith(words[i]) AND words[j].endsWith(words[i])
     - If both true, increment count
2. Return count

**Example walkthrough:**
```
words = ["a", "aba", "ababa", "aa"]

Pair (0,1): "a" vs "aba"
  - "aba".startsWith("a") = true
  - "aba".endsWith("a") = true
  - Count = 1

Pair (0,2): "a" vs "ababa"
  - "ababa".startsWith("a") = true
  - "ababa".endsWith("a") = true
  - Count = 2

Pair (0,3): "a" vs "aa"
  - "aa".startsWith("a") = true
  - "aa".endsWith("a") = true
  - Count = 3

Pair (1,2): "aba" vs "ababa"
  - "ababa".startsWith("aba") = true
  - "ababa".endsWith("aba") = true
  - Count = 4

Result: 4
```

### Time Complexity: O(N² × L)
**Why?**
- Outer loop: N iterations
- Inner loop: up to N iterations
- Each check: O(L) for prefix and suffix comparison
- Total: N × N × L = O(N² × L)

**Detailed breakdown:**
For N=1,000, L=100: ~10 million operations (acceptable). For N=10,000: ~1 billion (TLE).

### Space Complexity: O(1)
**Why?**
Only using counter variable, no auxiliary data structures.

> **Drawback:**
> Checking every pair is inefficient. Each string comparison takes O(L) time, and we do N² comparisons.

> **Key Insight for Improvement:**
> Instead of checking pairs, we can use two separate Tries: one for prefixes (normal) and one for suffixes (reversed). For each word, query both tries to find matches.

<br>

---

## Solution 2: Double Trie (Prefix Trie + Suffix Trie)

**Intuition:**
Build two tries: one for normal strings (prefix matching) and one for reversed strings (suffix matching). For each word, find all shorter words that match as prefix in Trie1 AND as suffix in Trie2.

**Algorithm:**
1. Build Prefix Trie: Insert all words normally
2. Build Suffix Trie: Insert all words reversed
3. For each word:
   - Query Prefix Trie to get all words that are prefixes of current word
   - Query Suffix Trie (with reversed word) to get all words that are suffixes
   - Find intersection of both sets (words that are both prefix AND suffix)
   - Add count to result

**Example walkthrough:**
```
words = ["a", "aba", "ababa"]

Prefix Trie:           Suffix Trie (reversed):
    root                   root
     |                      |
     a                      a
    / \                    / |
   b   (end)              b  (end)
   |                      |
   a                      a
   |                      |
  (end)                  (end)
   |
   b
   |
   a
   |
  (end)

For "ababa":
  - Prefix matches: ["a", "aba", "ababa"]
  - Suffix matches (reverse "ababa"): ["a", "aba", "ababa"]
  - Intersection (excluding self): ["a", "aba"]
  - Count += 2
```

### Time Complexity: O(N × L²)
**Why?**
- Building both tries: O(N × L)
- For each word (N words):
  - Query prefix trie: O(L) to traverse, but collecting all matches can be O(L) per match
  - Query suffix trie: O(L)
  - Finding intersection: O(number of matches)
- Worst case: O(N × L²) when many words share prefixes/suffixes

### Space Complexity: O(N × L)
**Why?**
Two tries storing all words: 2 × O(N × L) = O(N × L)

> **Drawback:**
> Maintaining two separate tries is complex. Need to query both tries for each word and find intersection. Also, collecting all matching words from trie requires additional traversal.

> **Key Insight for Improvement:**
> Combine both prefix and suffix information into a single trie structure. Store both forward and backward traversal in one unified structure to avoid separate queries and intersection logic.

<br>

---

## Solution 3: Combined Trie (Optimal)

**Intuition:**
Build a single trie where each node stores both the character and tracks words that have this prefix-suffix property. For each word, insert it with metadata about its position, then query for matches efficiently.

**Alternative approach:** Use a trie of pairs (prefix_char, suffix_char) to simultaneously match both ends.

**Algorithm:**
1. Create a trie where each node represents (prefix_char, suffix_char) pairs
2. For each word, insert path representing simultaneous traversal from start and end
3. For each word, query the trie to count how many shorter words match both prefix and suffix

**Example walkthrough:**
```
words = ["a", "aba", "ababa"]

Combined Trie (char pairs):
For "a": (a,a)
For "aba": (a,a) -> (b,b) -> (a,a)
For "ababa": (a,a) -> (b,b) -> (a,a) -> (b,b) -> (a,a)

When processing "ababa":
  - Traverse: (a,a) [found "a"] -> (b,b) -> (a,a) [found "aba"]
  - Count = 2
```

**Simplified approach using hash map:**
```
For each word j:
  For each shorter word i:
    If word[i] is prefix AND suffix of word[j]:
      count++

Optimize with trie:
  - Store all words in trie with their indices
  - For each word, check prefix matches in trie
  - For each prefix match, verify suffix condition
```

### Time Complexity: O(N × L² × 26) ≈ O(N × L²)
**Why?**
- Insert all words: O(N × L)
- For each word (N words):
  - Query trie with simultaneous prefix-suffix matching: O(L)
  - At each level, may need to check multiple branches: O(26) in worst case
  - Total per word: O(L × 26) ≈ O(L)
- Overall: O(N × L)

However, in practice with verification: O(N × L²) due to string comparisons.

### Space Complexity: O(N × L × 26)
**Why?**
Trie with pair nodes can have up to 26×26 children per node in worst case, but typically much less. Effective space: O(N × L).

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N² × L) | O(1) | Baseline - check all pairs |
| Double Trie | O(N × L²) | O(N × L) | Separate prefix/suffix tries reduce comparisons |
| Combined Trie | O(N × L²) | O(N × L) | Single unified structure, cleaner logic |

**Recommended Solution:** Combined Trie (for large N) or Brute Force (for small N < 1000)

**Key Insights:**
1. **Prefix + suffix check:** Both conditions must hold simultaneously - a word must match at both ends
2. **Trie optimization:** Tries can efficiently find all words with a given prefix, reducing redundant comparisons
3. **Combined structure:** Merging prefix and suffix checking into one structure simplifies logic and reduces overhead

<br><br>

---

```code```
