Design an algorithm to encode a list of strings to a single string and decode it back. The encoded string must handle any characters including delimiters. Use length-prefix encoding: '4#word5#hello'.

<br>

---

## Constraints

- `0 ≤ strs.length ≤ 200`
- `0 ≤ strs[i].length ≤ 200`
- `strs[i] can contain any character including delimiters`

<br>

---

## All Possible Edge Cases

1. **Empty list:** Encode to empty, decode back to empty
2. **Empty strings in list:** ['',''] must be preserved
3. **Strings containing delimiter:** Must use length-prefix, not just delimiter
4. **Single string:** Encode and decode back
5. **Special characters:** Strings with #, :, newlines, etc.
6. **Very long string:** Length prefix handles it

<br>

---

```code```
