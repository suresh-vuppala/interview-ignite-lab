Find the length of the longest substring with at most k distinct characters.

<br>

> Input: s = "eceba", k = 2
> Output: 3 ("ece")

<br>

---

## Constraints

- `1 ≤ s.length ≤ 5 × 10⁴`
- `0 ≤ k ≤ 50`

<br>

---

## All Possible Edge Cases

1. **k = 0:** Return 0
2. **k ≥ 26:** Return full length
3. **All same characters:** Return length
4. **k = 1:** Longest run of same char

<br>

---

## Solution 1: Brute Force

**Intuition:** Check all substrings, count distinct characters.

### Time Complexity: O(n²)
### Space Complexity: O(1)

<br>

---

## Solution 2: Sliding Window + Hash Map (Optimal)

**Intuition:**
Expand window by adding characters. When distinct count exceeds k, shrink from left until we're back to k distinct.

**Algorithm:**
1. left = 0, maxLen = 0, freq = {}
2. For right = 0 to n-1:
   - freq[s[right]]++
   - While distinct count > k:
     - freq[s[left]]--; if 0, remove; left++
   - maxLen = max(maxLen, right - left + 1)

### Time Complexity: O(n) — each char added/removed once
### Space Complexity: O(k) — at most k entries in map

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(n²) | O(1) | Check all substrings |
| Sliding Window | O(n) | O(k) | Shrink when distinct > k |

<br>
<br>

---

```code```
