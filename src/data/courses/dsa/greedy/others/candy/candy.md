There are n children standing in a line with ratings. Give candies such that: each child gets ≥ 1 candy, and children with higher rating than neighbors get more. Find minimum total candies.

<br>

---

## Constraints

- `1 ≤ n ≤ 2 × 10⁴`
- `0 ≤ ratings[i] ≤ 2 × 10⁴`

<br>

---

## All Possible Edge Cases

1. **All same ratings:** Everyone gets 1 candy → answer = n
2. **Strictly increasing:** 1,2,3,...,n → answer = n(n+1)/2
3. **Strictly decreasing:** n,n-1,...,1 → answer = n(n+1)/2
4. **V-shape:** Valley gets 1, both sides increase
5. **Peak:** Higher of left and right requirement
6. **Single child:** Gets 1 candy
7. **Two children:** Compare and assign 1 and 2
8. **Zigzag ratings:** Alternating high-low

<br>

---

```code```
