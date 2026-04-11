Given two strings s and t, return true if t is an anagram of s, and false otherwise. An anagram uses the exact same characters the exact same number of times.

<br>

> Input:
> s = "anagram", t = "nagaram"

> Output:
> true

> Explanation:
> Both strings contain: a×3, n×1, g×1, r×1, m×1. Same character frequencies → anagram.
> 
> **Key insight:** Two strings are anagrams if and only if they have identical character frequency distributions.

<br>



---

## Constraints

- `1 ≤ s.length, t.length ≤ 5 × 10⁴`
- `s and t consist of lowercase English letters`

<br>

---

## All Possible Edge Cases

1. **Different lengths:** Immediately false — anagrams must have same length
2. **Same string:** Always true
3. **Single character:** Direct comparison
4. **All same characters:** "aaa" vs "aaa" → true
5. **One character different frequency:** "aaab" vs "aaba" → true, "aaab" vs "aabb" → false

<br>

---

## Solution 1: Sort Both Strings

**Intuition:**
If two strings are anagrams, sorting both produces identical strings. "anagram" → "aaagmnr", "nagaram" → "aaagmnr".

**Algorithm:**
1. If lengths differ → return false
2. Sort both strings
3. Compare sorted versions character by character
4. If identical → true, else false

### Time Complexity: O(N log N)
**Why?**
- Sorting each string: O(N log N)
- Comparison: O(N)
- Total: O(N log N) dominated by sorting

**Detailed breakdown:**
- String length 100 → ~664 operations (sort) + 100 (compare) ≈ 764
- String length 50,000 → ~780,482 operations
- At max constraint: ~780K operations — fast enough but not optimal

### Space Complexity: O(N)
**Why?**
- Creating sorted copies of both strings
- Some sort algorithms need O(N) auxiliary space

> **Drawback:**
> Sorting takes O(N log N) time and O(N) space for copies. We're rearranging entire strings when we only need to verify that character frequencies match. Sorting does far more work than needed.

> **Key Insight for Improvement:**
> Since we only have 26 lowercase letters, use a fixed-size frequency count array. Increment for characters in s, decrement for characters in t. If all counts are zero → anagram. O(N) time, O(1) space.

<br>

---

## Solution 2: Frequency Count Array (Optimal)

**Intuition:**
Count the frequency of each character in s. Subtract the frequency of each character in t. If all counts reach zero, the strings are anagrams.

**Algorithm:**
1. If lengths differ → return false
2. Create int[26] frequency array (initialized to 0)
3. For each character c in s: freq[c - 'a']++
4. For each character c in t: freq[c - 'a']--
5. Check all 26 entries: if any ≠ 0 → return false
6. All zero → return true

### Time Complexity: O(N)
**Why?**
- Two passes through strings: O(N) each
- Final check: O(26) = O(1)
- Total: O(N)

**Detailed breakdown:**
- String length 100 → 200 operations (two passes) + 26 (check) = 226
- String length 50,000 → 100,026 operations
- Compared to sort: 780,482 → 100,026 (7.8× faster!)

**Example walkthrough:**
```
s = "anagram", t = "nagaram"

After processing s: a=3, n=1, g=1, r=1, m=1
After processing t: a=3-3=0, n=1-1=0, g=1-1=0, r=1-1=0, m=1-1=0
All zeros → true ✓
```

### Space Complexity: O(1)
**Why?**
- Fixed array of 26 integers — does not grow with input size
- 26 × 4 bytes = 104 bytes total

**Why this is optimal:**
- Must read every character at least once: O(N) minimum
- O(1) space with fixed alphabet size

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Sort | O(N log N) | O(N) | Sorted anagrams are identical |
| Frequency Count | O(N) | O(1) | Count in fixed 26-element array |

**Recommended Solution:** Frequency Count (Solution 2) — O(N) time, O(1) space.

**Key Insights:**
1. **Sort → Frequency:** We don't need sorted order, just frequency match — O(N log N) → O(N)
2. **Fixed alphabet trick:** 26 lowercase letters → constant-size array → O(1) space
3. **Follow-up:** For Unicode characters, use a hash map instead of array


<br>
<br>

---

```code```
