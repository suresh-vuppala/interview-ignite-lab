Merge accounts that share at least one email. Each account has a name and list of emails.

<br>

> Input: accounts=[["John","john@mail","john_neo@mail"],["John","john@mail","john00@mail"],["Mary","mary@mail"],["John","johnnybravo@mail"]]
> Output: [["John","john00@mail","john@mail","john_neo@mail"],["Mary","mary@mail"],["John","johnnybravo@mail"]]
> **Key insight:** Union-Find on emails. For each account, union all emails together. Same-name check not needed — shared email = same person.

<br>

---

## Constraints
- `1 ≤ accounts.length ≤ 1000`

<br>

---

## Solution: DSU on Emails (Optimal)

**Algorithm:**
1. Map each email to an integer ID. Union all emails within same account.
2. Group emails by root. Attach account name. Sort emails.

### Time Complexity: O(N × K × α) where K = emails per account
### Space Complexity: O(N × K)

> **Drawback:** None.

> **Key Insight for Improvement:** Key insight: union first email with all others in same account. Don't union all pairs — just chain through first email.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| DSU on emails | O(NK·α) | O(NK) |

**Key Insights:**
1. **Emails as nodes:** Union emails, not accounts
2. **Shared email = same person:** Even if names are different (though problem guarantees same name)
3. **Chain union:** Union email[0] with email[1], email[0] with email[2], etc.

<br><br>

---

```code```
