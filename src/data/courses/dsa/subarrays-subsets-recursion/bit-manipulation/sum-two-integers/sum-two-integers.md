Calculate the sum of two integers without using the + or - operators. Use bitwise XOR for addition without carry, AND + left shift for carry, and repeat until carry is zero.

<br>

---

## Constraints

- `-1000 ≤ a, b ≤ 1000`
- `Cannot use + or - operators`

<br>

---

## All Possible Edge Cases

1. **Both positive:** Standard case
2. **Both negative:** Two's complement addition
3. **One zero:** a + 0 = a
4. **Both zero:** 0 + 0 = 0
5. **Opposite signs:** 5 + (-3) = 2
6. **Carry propagation:** 7 + 1 = 8 (carry ripples through bits)
7. **Negative result:** 1 + (-3) = -2

<br>

---

```code```
