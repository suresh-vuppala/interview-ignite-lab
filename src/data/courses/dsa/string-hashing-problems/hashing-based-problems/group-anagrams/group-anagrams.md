Given an array of strings, group the anagrams together. Two strings are anagrams if they contain the same characters with the same frequencies.

<br>

> Input:
> strs = ["eat","tea","tan","ate","nat","bat"]

> Output:
> [["eat","tea","ate"], ["tan","nat"], ["bat"]]

> Explanation:
> "eat", "tea", "ate" all have characters {a,e,t}. "tan", "nat" have {a,n,t}. "bat" has {a,b,t}.
> 
> **Key insight:** Two strings are anagrams if and only if they produce the same key when sorted OR have the same character frequency count.

<br>



---

## Constraints

- `1 ≤ strs.length ≤ 10⁴`
- `0 ≤ strs[i].length ≤ 100`
- `strs[i] consists of lowercase English letters`

<br>

---

## All Possible Edge Cases

1. **Single string:** One group with one element
2. **All same string:** ["a","a","a"] → one group
3. **No anagrams:** Each string is its own group
4. **Empty strings:** ["",""] → one group (both empty)
5. **Single character strings:** ["a","b","a"] → [["a","a"],["b"]]

<br>

---

## Solution 1: Sort Each String as Key

**Intuition:**
Anagrams produce the same sorted string. Use the sorted version as a hash map key to group them.

**Algorithm:**
1. Create hash map: sorted_string → list of original strings
2. For each string in input:
   - Sort the string → key
   - Append original string to map[key]
3. Return all map values

### Time Complexity: O(N × K log K)
**Why?**
- N strings, each of average length K
- Sorting each string: O(K log K)
- Hash map insert: O(K) for string hashing
- Total: N × (K log K + K) = O(N × K log K)

**Detailed breakdown:**
- N=10,000 strings, K=100 avg length
- Sorting per string: ~664 comparisons
- Total: 10,000 × 664 = ~6.6 million operations

### Space Complexity: O(N × K)
**Why?**
- Hash map stores all N strings plus sorted keys

> **Drawback:**
> Sorting each string takes O(K log K). For long strings, this adds up. We're doing more work than needed — we only need to identify that two strings have the same character composition.

> **Key Insight for Improvement:**
> Instead of sorting, count character frequencies. Use the frequency count as the hash key. Counting is O(K) vs sorting's O(K log K). For 26 lowercase letters, the key is a fixed-size tuple.

<br>

---

## Solution 2: Character Frequency Count as Key (Optimal)

**Intuition:**
Count the frequency of each character in the string. Use this frequency vector as the hash map key. Two anagrams always produce the same frequency vector.

**Algorithm:**
1. Create hash map: frequency_key → list of strings
2. For each string:
   - Count character frequencies → int[26]
   - Convert to string key: "2#1#0#...#0#" (counts separated by #)
   - Append string to map[key]
3. Return all map values

### Time Complexity: O(N × K)
**Why?**
- Counting frequencies: O(K) per string
- Building key: O(26) = O(1) per string
- Total: N × (K + 26) = O(N × K)

**Detailed breakdown:**
- N=10,000, K=100 → 10,000 × 100 = 1,000,000 operations
- Compared to sort approach: 6,600,000 → 1,000,000 (6.6× faster!)

**Example walkthrough:**
```
strs = ["eat", "tea", "ate"]

"eat" → freq: a=1,e=1,t=1 → key="1#0#0#0#1#...#1#0#..."
"tea" → freq: a=1,e=1,t=1 → key="1#0#0#0#1#...#1#0#..." (same!)
"ate" → freq: a=1,e=1,t=1 → key="1#0#0#0#1#...#1#0#..." (same!)

All three share the same key → grouped together ✓
```

### Space Complexity: O(N × K)
**Why?**
- Same storage as Solution 1

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Sort as Key | O(N × K log K) | O(N × K) | Sorted anagram = same string |
| Frequency Key | O(N × K) | O(N × K) | Count chars instead of sorting |

**Recommended Solution:** Frequency Count Key (Solution 2) — O(N × K) time.

**Key Insights:**
1. **Sort → Frequency:** Counting is O(K) vs sorting O(K log K)
2. **Key encoding:** Convert int[26] to string for hashable key
3. **Fixed alphabet:** 26 lowercase letters → O(1) key construction


<br>
<br>

---

```code```
