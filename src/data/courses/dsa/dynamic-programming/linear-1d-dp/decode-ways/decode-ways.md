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

## Constraints

- `0 ≤ n ≤ 10⁴`
- `Values fit in 32-bit integer`
- `DP state space fits in memory`

<br>

---

## All Possible Edge Cases

1. **n = 0 or empty input:** Base case — return 0 or empty
2. **n = 1:** Single element — trivial case
3. **All same elements:** Check if pattern still applies
4. **Maximum constraints:** Verify time complexity handles worst case
5. **Negative values (if applicable):** Affects min/max DP transitions
6. **Result requires modular arithmetic:** Use MOD = 10⁹ + 7 to prevent overflow

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
