Given n nodes labeled 0 to n-1 and a list of undirected edges, determine if these edges form a valid tree. A valid tree has n-1 edges, is connected, and has no cycles.

<br>

---

## Constraints

- `1 ≤ n ≤ 2000`
- `0 ≤ edges.length ≤ 5000`
- `0 ≤ ai, bi < n`
- `ai ≠ bi`
- `No duplicate edges`

<br>

---

## All Possible Edge Cases

1. **No edges, n=1:** Valid tree (single node)
2. **No edges, n>1:** Not valid (disconnected)
3. **n-1 edges, connected:** Valid tree
4. **n-1 edges, disconnected:** Not valid (has cycle in one component)
5. **n edges:** Has a cycle — not a tree
6. **Extra edge creating cycle:** Exactly n edges → one cycle

<br>

---

```code```
