A node X is good if in the path from root to X there are no nodes with value greater than X. Return the number of good nodes in the binary tree.

<br>

---

## Constraints

- `1 ≤ n ≤ 10⁵`
- `-10⁴ ≤ Node.val ≤ 10⁴`

<br>

---

## All Possible Edge Cases

1. **Single node:** Root is always good → return 1
2. **All same values:** Every node is good
3. **Strictly decreasing path:** Only root is good
4. **Strictly increasing path:** Every node is good
5. **Negative values:** Good if ≥ max on path from root
6. **Skewed tree:** Linear chain comparison

<br>

---

```code```
