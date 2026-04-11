Given two strings s and t, return true if t is an anagram of s, and false otherwise. An anagram uses the same characters with the same frequencies.

<br>

> Input: s = "anagram", t = "nagaram"
> Output: true

> Input: s = "rat", t = "car"
> Output: false

<br>

---

## Constraints

- `1 ≤ s.length, t.length ≤ 5 × 10⁴`
- `s and t consist of lowercase English letters`

<br>

---

## All Possible Edge Cases

1. **Different lengths:** Immediately false
2. **Same string:** Always true
3. **Single character each:** Compare directly
4. **All same character:** 'aaa' vs 'aaa' → true
5. **Unicode follow-up:** Use hash map instead of array[26]

<br>

---

## Solution 1: Sort Both Strings

**Intuition:**
If two strings are anagrams, sorting both produces the same string.

**Algorithm:**
1. If lengths differ → return false
2. Sort both strings
3. Compare character by character

### Time Complexity: O(n log n)
### Space Complexity: O(n) for sorted copies

> **Key Insight for Improvement:** Instead of sorting, count character frequencies — O(n).

<br>

---

## Solution 2: Frequency Count (Array)

**Intuition:**
Count frequency of each character in s. Decrement for each character in t. If all counts are 0, it's an anagram.

**Algorithm:**
1. If lengths differ → return false
2. Create int[26] frequency array
3. For each char in s: freq[c - 'a']++
4. For each char in t: freq[c - 'a']--
5. If all freq values are 0 → return true

### Time Complexity: O(n)
### Space Complexity: O(1) — fixed 26-element array

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Sort | O(n log n) | O(n) | Sorted anagrams are identical |
| Frequency Count | O(n) | O(1) | Count chars in fixed array |

**Recommended:** Frequency Count — O(n) time, O(1) space.

<br>
<br>

---

```code```
