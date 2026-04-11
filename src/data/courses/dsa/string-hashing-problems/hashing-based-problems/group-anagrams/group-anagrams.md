Group strings that are anagrams of each other into lists.

<br>

> Input:
> strs = ["eat","tea","tan","ate","nat","bat"]

> Output:
> [["bat"],["nat","tan"],["ate","eat","tea"]]

> Explanation:
> "eat", "tea", "ate" are anagrams (same letters, different order)
> "tan", "nat" are anagrams
> "bat" stands alone
> 
> **Key insight:** Anagrams have identical character frequencies - use sorted string or character count as hash key.

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

## Solution 1: Sorting as Hash Key

**Intuition:**
Anagrams contain the same characters, just in different order.
If we sort each string, all anagrams will produce the same sorted result.
Use the sorted string as a hash map key to group anagrams together.

**Algorithm:**
1. Create hash map: sorted_string → list of original strings
2. For each string in input:
   - Sort the string to get the key
   - Add original string to the list for this key
3. Return all values (lists) from hash map

**Example:**
```cpp
strs = ["eat", "tea", "tan", "ate", "nat", "bat"]

Process each string:
"eat" → sort → "aet" → groups["aet"] = ["eat"]
"tea" → sort → "aet" → groups["aet"] = ["eat", "tea"]
"tan" → sort → "ant" → groups["ant"] = ["tan"]
"ate" → sort → "aet" → groups["aet"] = ["eat", "tea", "ate"]
"nat" → sort → "ant" → groups["ant"] = ["tan", "nat"]
"bat" → sort → "abt" → groups["abt"] = ["bat"]

Result: [["eat","tea","ate"], ["tan","nat"], ["bat"]]
```

### Time Complexity: O(N × K log K)
**Why?**
- N = number of strings
- K = maximum length of a string
- For each of N strings:
  - Sort the string: O(K log K)
  - Hash map insert/lookup: O(1) average
- Total: N × O(K log K) = O(N × K log K)

**Detailed breakdown:**
- Iterate through N strings: N iterations
- Sort each string of length K: O(K log K) per string
- Hash map operations (insert, lookup): O(1) average
- Total: N × K log K

### Space Complexity: O(N × K)
**Why?**
- Store all N strings in result: O(N × K) total characters
- Hash map keys (sorted strings): O(N) keys, each up to K length
- Hash map values (lists): O(N) total strings
- Total: O(N × K)

**Detailed breakdown:**
- Result lists contain all N strings: O(N × K)
- Hash map with N entries: O(N)
- Each key is a sorted string: up to O(K) per key
- Total space: O(N × K)

> **Key Insight for Improvement:**
> Sorting takes O(K log K) per string. Can we identify anagrams faster? Yes - use character frequency counting for O(K) per string!

<br>

---

## Solution 2: Character Count as Hash Key (Optimal)

**Intuition:**
Instead of sorting, count the frequency of each character.
Anagrams have identical character frequencies.
Convert the frequency count to a string/tuple and use as hash key.

**Algorithm:**
1. Create hash map: count_key → list of original strings
2. For each string:
   - Count character frequencies (26-element array for lowercase letters)
   - Convert count array to string/tuple as key
   - Add original string to list for this key
3. Return all values from hash map

**Example:**
```cpp
strs = ["eat", "tea", "tan"]

Process each string:
"eat" → count: [1,0,0,0,1,0,...,1,0,...] (a=1,e=1,t=1)
       → key: "#1#0#0#0#1#...#1#..." 
       → groups[key] = ["eat"]

"tea" → count: [1,0,0,0,1,0,...,1,0,...] (a=1,e=1,t=1)
       → key: "#1#0#0#0#1#...#1#..." (same as "eat"!)
       → groups[key] = ["eat", "tea"]

"tan" → count: [1,0,0,0,0,0,...,1,0,...] (a=1,n=1,t=1)
       → key: "#1#0#0#0#0#...#1#..." (different)
       → groups[key] = ["tan"]

Result: [["eat","tea"], ["tan"]]
```

**Key Representation:**
Convert count array to string: "#1#0#0#0#1#..." (delimiter prevents ambiguity)
Alternatively, use tuple in Python: (1,0,0,0,1,...)

### Time Complexity: O(N × K)
**Why?**
- N = number of strings
- K = maximum length of a string
- For each of N strings:
  - Count characters: O(K) to scan string
  - Build key from count: O(26) = O(1) for lowercase letters
  - Hash map operations: O(1) average
- Total: N × O(K) = O(N × K)

**Detailed breakdown:**
- Iterate through N strings: N iterations
- For each string:
  - Scan K characters: O(K)
  - Build count array: O(26) = O(1)
  - Convert to key: O(26) = O(1)
  - Hash operations: O(1)
- Total: N × K

### Space Complexity: O(N × K)
**Why?**
- Store all N strings in result: O(N × K)
- Hash map keys: O(N) keys, each O(26) = O(1) size
- Count array per iteration: O(26) = O(1)
- Total: O(N × K)

**Detailed breakdown:**
- Result contains all strings: O(N × K)
- Hash map with N entries: O(N)
- Each key is fixed size (26 chars): O(1) per key
- Temporary count array: O(26) = O(1)
- Total space: O(N × K)

**Improvement:** From O(N × K log K) to O(N × K)
- Example: N=1000 strings, K=100 characters
- Sorting: 1000 × 100 × log(100) ≈ 664,000 operations
- Counting: 1000 × 100 = 100,000 operations (6.6× faster!)

**Why this is optimal:**
- Must read all N × K characters at least once: Ω(N × K)
- Our solution does exactly this with O(1) work per character
- Cannot do better than O(N × K) for this problem

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Technique |
|----------|------|-------|---------------|
| Sorting as Key | O(N × K log K) | O(N × K) | Sort each string for canonical form |
| Character Count | O(N × K) | O(N × K) | Count frequencies for O(K) comparison |

**Key Insights:**
1. **Sorting → Counting:** Avoid O(K log K) sorting by using O(K) character counting
2. **Hash Map Grouping:** Use canonical representation (sorted or count) as key
3. **Character Count Key:** Convert frequency array to string/tuple for hashing

**When to use each:**
- **Sorting:** Simple implementation, good for small K (K < 20)
- **Character Count:** Optimal for larger K, best asymptotic complexity

> **Final Complexity:** O(N × K) time, O(N × K) space

<br>

---

## Applications

1. **Text Analysis:** Find words with same letter composition
2. **Word Games:** Scrabble/anagram solvers and validators
3. **Data Deduplication:** Group similar strings by character content
4. **Spell Checkers:** Suggest anagrams as corrections
5. **Cryptography:** Analyze character frequency patterns

<br>
<br>

---

```code```
