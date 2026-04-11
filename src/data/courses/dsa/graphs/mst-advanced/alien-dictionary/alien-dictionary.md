Given a sorted dictionary of an alien language, derive the order of characters in that language using topological sort.

<br>

---

## Constraints

- `1 ≤ words.length ≤ 100`
- `1 ≤ words[i].length ≤ 100`
- `words[i] consists of lowercase English letters`

<br>

---

## All Possible Edge Cases

1. **Single word:** Any order of its characters
2. **Invalid ordering:** 'abc' before 'ab' → impossible, return ''
3. **Cycle detected:** Return '' — no valid ordering
4. **All same first letter:** Compare second characters
5. **Independent characters:** Multiple valid orderings

<br>

---

```code```
