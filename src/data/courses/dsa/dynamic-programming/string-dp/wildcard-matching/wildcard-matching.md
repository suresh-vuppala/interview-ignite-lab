Given a string s and a pattern p with '?' (matches single char) and '*' (matches any sequence including empty), determine if the pattern matches the entire string.

<br>

---

## Constraints

- `0 ≤ s.length, p.length ≤ 2000`
- `s contains only lowercase English letters`
- `p contains lowercase letters, '?' and '*'`

<br>

---

## All Possible Edge Cases

1. **Empty pattern:** Only matches empty string
2. **Pattern is all '*':** Matches any string
3. **No wildcards:** Exact string match
4. **'?' only:** Each '?' must match exactly one char
5. **Consecutive '*':** Same as single '*'
6. **Empty string with '*' pattern:** '*' matches empty

<br>

---

```code```
