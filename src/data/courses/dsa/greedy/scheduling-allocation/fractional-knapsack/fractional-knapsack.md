Given weights and values of n items, put items in a knapsack of capacity W to get maximum total value. You can break items (take fractions).

<br>

---

## Constraints

- `1 ≤ n ≤ 10⁵`
- `1 ≤ W ≤ 10⁹`
- `1 ≤ value[i], weight[i] ≤ 10⁴`

<br>

---

## All Possible Edge Cases

1. **All items fit:** Total weight ≤ W → take everything
2. **Single item:** Take min(weight, W) fraction
3. **All same value/weight ratio:** Take in any order until full
4. **W = 0:** Can't take anything → return 0
5. **Item weight > W:** Take fraction of it

<br>

---

```code```
