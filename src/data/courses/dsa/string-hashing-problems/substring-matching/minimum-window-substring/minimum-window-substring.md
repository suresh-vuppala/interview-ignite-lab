Given strings s and t, find the minimum window in s that contains all characters of t (including duplicates). If no such window exists, return "".

<br>

> Input:
> s = "ADOBECODEBANC", t = "ABC"

> Output:
> "BANC"

> Explanation:
> The smallest window containing A, B, and C is "BANC" (indices 9-12).
> 
> **Key insight:** Expand right to include all required chars. Once valid, shrink from left to find the minimum. Track "formed" count — how many unique chars in t have their required frequency met.

<br>



---

## Constraints

- `1 ≤ s.length, t.length ≤ 10⁵`
- `s and t consist of uppercase and lowercase English letters`

<br>

---

## All Possible Edge Cases

1. **t longer than s:** Impossible → return ""
2. **t == s:** Return s
3. **Single char t:** Find first occurrence
4. **Duplicate chars in t:** "AAB" — need 2 A's and 1 B

<br>

---

## Solution 1: Brute Force — Check All Substrings

**Intuition:**
For each possible window [i..j], check if it contains all characters of t.

### Time Complexity: O(N² × M)
**Why?**
- O(N²) substrings × O(M) to verify each

**Detailed breakdown:**
- N = 100,000 → 10¹⁰ × M — far too slow

### Space Complexity: O(M)

> **Drawback:**
> Checking every substring from scratch. Once a window contains all required chars, shrinking from the left is the only way to minimize — no need to restart from scratch.

> **Key Insight for Improvement:**
> Expand right to make window valid (contains all of t). Then shrink from left to minimize. Track "formed" — number of unique chars meeting their required count. When formed == required → valid window → try to shrink.

<br>

---

## Solution 2: Sliding Window + Frequency Tracking (Optimal)

**Intuition:**
Two pointers. Expand right until window contains all of t. Then shrink from left to minimize. Track with two maps: tFreq (required) and wFreq (current window). "formed" counts how many unique chars meet their target.

**Algorithm:**
1. Build tFreq from t. required = number of unique chars in t
2. left = 0, formed = 0, wFreq = {}
3. For right = 0 to |s|-1:
   - wFreq[s[right]]++
   - If wFreq[s[right]] == tFreq[s[right]] → formed++ (this char fully met)
   - While formed == required (window is valid):
     - Update min window if smaller
     - wFreq[s[left]]--
     - If wFreq[s[left]] < tFreq[s[left]] → formed-- (no longer met)
     - left++
4. Return min window

### Time Complexity: O(N + M)
**Why?**
- Right pointer: N iterations
- Left pointer: moves at most N times total across all iterations
- Total: 2N + M (for building tFreq) = O(N + M)

**Detailed breakdown:**
- N = 100,000 → at most 200,000 map operations
- Compared to brute: 10¹⁰ → 200,000 (50,000,000× faster!)

**Example walkthrough:**
```
s = "ADOBECODEBANC", t = "ABC"
tFreq: {A:1, B:1, C:1}, required=3

right=0('A'): wFreq={A:1}, formed=1 (A met)
right=1('D'): formed=1
right=2('O'): formed=1
right=3('B'): wFreq={A:1,B:1}, formed=2 (B met)
right=4('E'): formed=2
right=5('C'): wFreq={A:1,B:1,C:1}, formed=3 ★ VALID
  → window="ADOBEC" len=6, shrink:
  → remove 'A': wFreq={A:0}, formed=2 → stop, left=1
right=6..9: expand to get valid again
right=10('A'): formed=3 ★ window="CODEBA"→shrink...
...eventually: window="BANC" len=4 → minimum ✓
```

### Space Complexity: O(|s| + |t|)
**Why?**
- Two frequency maps bounded by character set

<br>

---

## Solution 3: Binary Search on Length + Sliding Window

**Intuition:**
Binary search on the window length. For each candidate length, check if any window of that length contains all characters of t using sliding window.

**Algorithm:**
1. Binary search on length: low = |t|, high = |s|
2. For each mid (candidate length):
   - Use sliding window to check if any window of length mid contains all chars of t
   - If yes, try smaller length (high = mid - 1)
   - If no, try larger length (low = mid + 1)
3. Return the minimum valid length window

**Check Function (canFindWindow):**
- Use sliding window of fixed size = mid
- Track frequency of characters in current window
- Check if window satisfies all requirements of t

### Time Complexity: O(N × log N)
**Why?**
- Binary search: O(log N) iterations
- Each iteration: O(N) to check all windows of length mid
- Total: O(N × log N)

**Detailed breakdown:**
- N = 100,000 → log(100,000) ≈ 17
- Total operations: 100,000 × 17 = 1,700,000
- Slower than sliding window O(N) but demonstrates binary search thinking

### Space Complexity: O(|s| + |t|)
**Why?**
- Frequency maps for checking

**When to use this approach:**
- Interview variation: "Find if window of length K exists"
- Demonstrates binary search on answer pattern
- Good for follow-up discussions

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N²×M) | O(M) | Check all substrings |
| Sliding Window | O(N+M) | O(N+M) | Expand/shrink with formed tracking |
| Binary Search | O(N×log N) | O(N+M) | Binary search on window length |

**Recommended Solution:** Sliding Window (Solution 2) — O(N+M) time.

**Key Insights:**
1. **Formed counter:** Tracks how many unique chars are fully satisfied — avoids checking entire map
2. **Expand then shrink:** Expand right until valid, shrink left to minimize
3. **Binary search variation:** Useful for "check if window of length K exists" problems
4. **FAANG favorite:** Tests both sliding window mechanics AND frequency tracking


<br>
<br>

---

```code```
