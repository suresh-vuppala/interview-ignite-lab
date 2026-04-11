Given a string s and integer k, find the longest substring where you can replace at most k characters to make all characters the same.

<br>

> Input:
> s = "AABABBA", k = 1

> Output:
> 4

> Explanation:
> Replace one B in "AABA" → "AAAA" (length 4). Or replace A in "ABBA" → "BBBB" (length 4).
> 
> **Key insight:** Window length - count of most frequent char = chars that need replacing. If this > k, window is invalid → shrink left. Track the max frequency seen so far.

<br>



---

## Constraints

- `1 ≤ s.length ≤ 10⁵`
- `0 ≤ k ≤ s.length`
- `s consists of uppercase English letters`

<br>

---

## All Possible Edge Cases

1. **k = 0:** Longest run of same character
2. **k ≥ n:** Entire string (replace everything)
3. **All same chars:** Entire string regardless of k
4. **Alternating:** "ABABAB" with k=1 → longest = 3

<br>

---

## Solution 1: Brute Force — Check All Substrings

### Time Complexity: O(N² × 26)

> **Drawback:**
> Checking each substring independently. We're not reusing frequency information from overlapping windows.

> **Key Insight for Improvement:**
> Sliding window: windowLen - maxFreqInWindow = replacements needed. If > k → shrink left. The key insight is we DON'T need to update maxFreq when shrinking — we only care about finding LONGER valid windows, and those need a HIGHER maxFreq.

<br>

---

## Solution 2: Sliding Window + Max Frequency (Optimal)

**Intuition:**
Track character frequencies in the window. The number of characters to replace = windowLen - maxFreq. If this exceeds k, shrink left. We never decrease maxFreq because we're looking for the longest window — only a larger maxFreq can give a longer valid window.

**Algorithm:**
1. left = 0, maxFreq = 0, maxLen = 0, freq[26] = {}
2. For right = 0 to n-1:
   - freq[s[right]]++
   - maxFreq = max(maxFreq, freq[s[right]])
   - If (right - left + 1) - maxFreq > k → shrink: freq[s[left]]--, left++
   - maxLen = max(maxLen, right - left + 1)

### Time Complexity: O(N)
**Why?**
- Single pass: N iterations
- Each iteration: O(1) operations

**Detailed breakdown:**
- N = 100,000 → 100,000 iterations

**Example walkthrough:**
```
s = "AABABBA", k = 1

right=0('A'): freq={A:1}, maxF=1, window=1, replace=1-1=0≤1 ✓ len=1
right=1('A'): freq={A:2}, maxF=2, window=2, replace=2-2=0≤1 ✓ len=2
right=2('B'): freq={A:2,B:1}, maxF=2, window=3, replace=3-2=1≤1 ✓ len=3
right=3('A'): freq={A:3,B:1}, maxF=3, window=4, replace=4-3=1≤1 ✓ len=4
right=4('B'): freq={A:3,B:2}, maxF=3, window=5, replace=5-3=2>1 → shrink
  remove 'A': freq={A:2,B:2}, left=1, window=4, replace=4-3=1≤1
right=5('B'): freq={A:2,B:3}, maxF=3, window=5, replace=5-3=2>1 → shrink
  remove 'A': freq={A:1,B:3}, left=2, window=4
right=6('A'): freq={A:2,B:3}, window=5, replace=5-3=2>1 → shrink
  remove 'B': freq={A:2,B:2}, left=3, window=4

maxLen = 4 ✓
```

### Space Complexity: O(1) — 26-element frequency array

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N²×26) | O(1) | Check all substrings |
| Sliding Window | O(N) | O(1) | Expand/shrink with maxFreq trick |

**Recommended Solution:** Sliding Window (Solution 2) — O(N) time, O(1) space.

**Key Insights:**
1. **Replacements needed = windowLen - maxFreq** — the key formula
2. **maxFreq never decreases:** We only care about finding LONGER windows
3. **Shrink by 1:** When invalid, shrink left by exactly 1 — window size stays same or grows


<br>
<br>

---

```code```
