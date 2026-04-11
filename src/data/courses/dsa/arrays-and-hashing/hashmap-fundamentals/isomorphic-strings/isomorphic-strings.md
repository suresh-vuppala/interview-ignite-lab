Given two strings s and t, determine if they are isomorphic. Two strings are isomorphic if characters in s can be replaced to get t, preserving order. No two characters may map to the same character, and a character must map to itself consistently.

<br>

---

## Constraints

- `1 ≤ s.length ≤ 5 × 10⁴`
- `t.length == s.length`
- `s and t consist of any valid ASCII character`

<br>

---

## All Possible Edge Cases

1. **Same string:** 'abc' → 'abc' — always isomorphic
2. **Different lengths:** Immediately false
3. **Single char each:** Always isomorphic
4. **Repeated mapping:** 'egg' → 'add' — e→a, g→d consistent
5. **Conflicting mapping:** 'foo' → 'bar' — o maps to both a and r → false
6. **Reverse mapping conflict:** 'badc' → 'baba' — both d and c map to a → false
7. **Empty strings:** '' and '' → true

<br>

---

```code```
