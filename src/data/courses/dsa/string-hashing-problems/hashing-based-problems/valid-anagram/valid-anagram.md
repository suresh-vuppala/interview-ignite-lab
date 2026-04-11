Given two strings s and t, return true if t is an anagram of s, and false otherwise. An anagram uses the same characters with the same frequencies.

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
5. **One character off:** 'rat' vs 'car' → false
6. **Empty strings:** Both empty → true
7. **Unicode follow-up:** Use hash map instead of array[26]

<br>

---

```code```
