Implement regular expression matching with '.' (matches any single character) and '*' (matches zero or more of the preceding element).

<br>

---

## Constraints

- `1 ≤ s.length ≤ 20`
- `1 ≤ p.length ≤ 20`
- `s contains only lowercase letters`
- `p contains lowercase letters, '.', and '*'`

<br>

---

## All Possible Edge Cases

1. **No special chars:** Exact match required
2. **'.*' pattern:** Matches any string
3. **'a*' matches empty:** Star means zero or more of preceding
4. **Consecutive star patterns:** 'a*b*c' — each star group independent
5. **'.' matches any single char:** 'a.b' matches 'aXb'
6. **Pattern longer than string:** Can still match if stars consume to zero

<br>

---

```code```
