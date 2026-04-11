Given a string with '(', ')' and '*' where '*' can be '(', ')' or empty, determine if the string is valid. Use greedy with min/max open count range.

<br>

---

## Constraints

- `1 ≤ s.length ≤ 100`
- `s consists of '(', ')' and '*' only`

<br>

---

## All Possible Edge Cases

1. **No stars:** Standard valid parentheses check
2. **All stars:** Always valid (all can be empty)
3. **Star as open:** '*(' — star becomes empty or '(' 
4. **Star as close:** '*)' — star becomes ')'
5. **Empty string:** Valid
6. **Single star:** Valid (* can be empty)
7. **Unbalanceable:** ')(' — no star placement can fix
8. **Stars at end:** '((**' — stars become '))'

<br>

---

```code```
