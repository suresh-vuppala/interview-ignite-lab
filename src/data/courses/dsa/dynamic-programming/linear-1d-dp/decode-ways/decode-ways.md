A message containing letters A-Z is encoded as "1"=A, "2"=B, ..., "26"=Z. Count ways to decode a string.

<br>

> Input:
> s = "226"

> Output:
> 3

> Explanation:
> "226" can be decoded as:
> 1. "BZ" (2, 26)
> 2. "VF" (22, 6)
> 3. "BBF" (2, 2, 6)
> 
> **Key insight:** At each position, decode 1 digit or 2 digits if valid.

<br>

---

## Solution 1: Memoization (Top-Down DP)

**Recurrence:**
```
ways(i) = ways(i-1) [if s[i] valid] + ways(i-2) [if s[i-1:i+1] valid]
```

```code```

### Time: O(n) | Space: O(n)

---

## Solution 2: Tabulation (Bottom-Up DP)

**DP State:**
```
dp[i] = ways to decode s[0..i-1]
dp[i] = dp[i-1] [1 digit] + dp[i-2] [2 digits]
```

```code```

### Time: O(n) | Space: O(1) optimized

---
