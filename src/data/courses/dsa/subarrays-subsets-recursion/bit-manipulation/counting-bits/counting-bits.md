Given an integer n, return an array ans of length n+1 such that ans[i] is the number of 1's in the binary representation of i (0 ≤ i ≤ n). Solve in O(n) time using DP relationship: bits[i] = bits[i >> 1] + (i & 1).

<br>

---

## Constraints

- `0 ≤ n ≤ 10⁵`

<br>

---

## All Possible Edge Cases

1. **n = 0:** Return [0]
2. **n = 1:** Return [0, 1]
3. **n = 2:** Return [0, 1, 1]
4. **Power of two:** Has exactly 1 set bit
5. **Large n:** Use DP: ans[i] = ans[i >> 1] + (i & 1) for O(n)
6. **n = 5:** Return [0, 1, 1, 2, 1, 2]

<br>

---

```code```
