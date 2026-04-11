Given a list of accounts where each account has a name and list of emails, merge accounts belonging to the same person (connected by shared emails). Use DSU or DFS.

<br>

---

## Constraints

- `1 ≤ accounts.length ≤ 1000`
- `2 ≤ accounts[i].length ≤ 10`
- `1 ≤ accounts[i][j].length ≤ 30`
- `accounts[i][0] is the name`

<br>

---

## All Possible Edge Cases

1. **No shared emails:** Each account stays separate
2. **All same person:** All accounts merge into one
3. **Same name different people:** Names don't determine merge — only shared emails
4. **Single account:** Return as-is
5. **Chain of shared emails:** A shares with B, B shares with C → all merge
6. **Multiple names merge:** Two accounts share email but have different names — shouldn't happen per constraints

<br>

---

```code```
