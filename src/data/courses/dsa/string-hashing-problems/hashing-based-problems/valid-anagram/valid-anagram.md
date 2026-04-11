Given two strings s and t, return true if t is an anagram of s.

<br>

> Input: s = "anagram", t = "nagaram" → Output: true
> Input: s = "rat", t = "car" → Output: false

<br>

---

## Constraints

- `1 ≤ s.length, t.length ≤ 5 × 10⁴`
- Lowercase English letters only

<br>

---

## All Possible Edge Cases

1. **Different lengths:** Immediately false
2. **Same string:** Always true
3. **Single character:** Direct compare

<br>

---

## Solution 1: Sort Both Strings

**Intuition:**
If two strings are anagrams, sorting them produces the same string.

**Algorithm:**
1. If lengths differ → false
2. Sort both strings
3. Compare character by character

### Time Complexity: O(n log n)
### Space Complexity: O(n)

```code```

> **Key Insight for Improvement:**
>
> **Drawback of current approach:** Sorting takes O(n log n) time and requires O(n) space for the sorted copies. We're rearranging entire strings when we only need to verify character frequencies match.
>
> **Insight:** Use a frequency count array of size 26. Increment for s, decrement for t. If all counts are 0, it's an anagram — O(n) time, O(1) space.

<br>

---

## Solution 2: Frequency Count Array (Optimal)

**Intuition:**
Count frequency of each character in s. Decrement for each character in t. If all counts are zero → anagram.

**Algorithm:**
1. If lengths differ → false
2. Create int[26] array
3. For each char in s: freq[c-'a']++
4. For each char in t: freq[c-'a']--
5. All zeros → true

### Time Complexity: O(n)
### Space Complexity: O(1) — fixed 26-element array

```code```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Sort | O(n log n) | O(n) | Sorted anagrams are identical |
| Frequency Count | O(n) | O(1) | Count in fixed-size array |

<br>
<br>
