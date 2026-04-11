Given a string s, rearrange the characters so that no two adjacent characters are the same. Return any valid arrangement or empty string if impossible.

<br>

---

## Constraints

- `1 ≤ s.length ≤ 500`
- `s consists of lowercase English letters`

<br>

---

## All Possible Edge Cases

1. **Impossible case:** 'aaa' — one char freq > (n+1)/2 → return ''
2. **Single character:** 'a' → 'a'
3. **Two characters equal freq:** 'aabb' → 'abab'
4. **Already valid:** 'abc' → 'abc'
5. **All same except one:** 'aaab' → 'abaa' is invalid, return ''

<br>

---

```code```
