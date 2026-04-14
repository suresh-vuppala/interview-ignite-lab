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

## Solution 1: Brute Force / Naive Approach

**Intuition:**
The most straightforward approach — straightforward but suboptimal.

**Algorithm:**
1. Apply the naive/brute approach as described
2. Check all possibilities or use a simpler data structure
3. Return the result

### Time Complexity: O(N²) or higher
**Why?**
The brute approach doesn't exploit the problem's structure efficiently, leading to redundant work.

**Detailed breakdown:**
For typical constraint sizes, this approach may be too slow or use too much space.

### Space Complexity: O(1) or O(N) depending on approach

> **Drawback:**
> Straightforward but suboptimal. Does redundant work that can be avoided with a better algorithm or data structure.

> **Key Insight for Improvement:**
> Use DSU on Emails (Optimal) for O(N × K × α) where K = emails per account time.

<br>

---

## Solution 2: DSU on Emails (Optimal)

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
