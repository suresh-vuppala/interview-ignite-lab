Given a string s and an integer k, find the length of the longest substring that contains at most k distinct characters.

<br>

---

## Constraints

- `1 ≤ s.length ≤ 5 × 10⁴`
- `0 ≤ k ≤ 50`
- `s consists of lowercase English letters`

<br>

---

## All Possible Edge Cases

1. **k = 0:** Return 0 (no characters allowed)
2. **k ≥ 26:** Return full string length
3. **All same characters:** Return string length for any k ≥ 1
4. **k = 1:** Longest run of same character
5. **Empty string:** Return 0

<br>

---

```code```
