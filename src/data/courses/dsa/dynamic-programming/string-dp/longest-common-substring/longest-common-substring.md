Find the length of the longest common substring between two strings.

<br>

> Input: s1 = "abcde", s2 = "abfce"
> Output: 2 ("ab")

> **Key insight:** Unlike subsequence, substring must be contiguous. Track matching suffix lengths.

<br>

---

## Constraints

- `1 ≤ s1.length, s2.length ≤ 1000`

<br>

---

## All Possible Edge Cases

1. **No common substring:** Return 0
2. **One is substring of other:** Return shorter length
3. **Identical strings:** Return length
4. **Single character match:** Return 1

<br>

---

## Solution 1: Check All Substrings

**Intuition:** For each substring of s1, check if it exists in s2.

### Time Complexity: O(n² × m) — generate substrings × search
### Space Complexity: O(1)

<br>

---

## Solution 2: DP (Optimal)

**Intuition:**
dp[i][j] = length of longest common substring ENDING at s1[i-1] and s2[j-1].

**Transition:**
- If s1[i-1] == s2[j-1]: dp[i][j] = dp[i-1][j-1] + 1
- Else: dp[i][j] = 0 (substring must be contiguous — reset)

Track global maximum across all dp[i][j].

### Time Complexity: O(n × m)
### Space Complexity: O(n × m) → O(m) with 1D array

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| All Substrings | O(n²m) | O(1) | Check each substring |
| DP | O(nm) | O(m) | Track contiguous matching suffixes |

**Recommended:** DP — O(nm) time, O(m) space.

**Key difference from LCS (subsequence):** When characters don't match, reset to 0 (not carry forward).

<br>
<br>

---

```code```
