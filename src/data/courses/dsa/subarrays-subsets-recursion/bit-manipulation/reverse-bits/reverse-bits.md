Reverse the bits of a given 32-bit unsigned integer. For example, input 43261596 (00000010100101000001111010011100) returns 964176192 (00111001011110000010100101000000).

<br>

---

## Constraints

- `Input is a 32-bit unsigned integer`

<br>

---

## All Possible Edge Cases

1. **All zeros:** 0 → 0
2. **All ones:** 4294967295 → 4294967295
3. **Power of two:** Only one bit set — moves to mirror position
4. **Palindrome bit pattern:** Reverse equals original
5. **Single trailing bit:** Becomes leading bit after reversal
6. **Alternating bits:** Pattern reverses but looks similar

<br>

---

```code```
