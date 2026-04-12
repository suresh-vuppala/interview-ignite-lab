Count the number of longest increasing subsequences.

<br>

> **Key insight:** Track both length dp[i] and count cnt[i]. When dp[j]+1 == dp[i]: cnt[i] += cnt[j]. When dp[j]+1 > dp[i]: cnt[i] = cnt[j].

<br>

---

## Constraints
- Typical DP constraints

<br>

---

## Solution 1: Recursion

> **Drawback:** Overlapping subproblems.

> **Key Insight for Improvement:** Recurrence: `dp[i]=max len ending at i, cnt[i]=count of LIS ending at i`

<br>

---

## Solution 2: DP — Bottom-up

**Recurrence:** `dp[i]=max len ending at i, cnt[i]=count of LIS ending at i`

### Time Complexity: O(N²)
**Why?** Each state computed once.

### Space Complexity: O(N)

**Example walkthrough:**
```
nums=[1,3,5,4,7] → LIS length=4, count=2 ([1,3,5,7] and [1,3,4,7])
```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Recursion | Exponential | O(N) stack |
| DP | O(N²) | O(N) |

**Key Insights:**
1. Identify states, transitions, base cases
2. Space optimization when possible


<br><br>

---

```code```
