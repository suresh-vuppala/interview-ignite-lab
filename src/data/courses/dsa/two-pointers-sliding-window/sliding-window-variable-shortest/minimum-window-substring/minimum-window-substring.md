Given two strings s and t, find the minimum window substring in s that contains all characters of t (including duplicates). Return empty string if no such window exists.

<br>

> Input:
> s = "ADOBECODEBANC", t = "ABC"

> Output:
> "BANC"

> Explanation:
> The minimum window substring "BANC" contains all characters from t
> Other valid windows: "ADOBEC", "ODEBANC" (but longer)
> 
> **Key insight:** Use sliding window with frequency maps. Expand right to include characters, shrink left while window is valid.

<br>

---

## Solution 1: Brute Force

**Intuition:**
Check all possible substrings. For each substring, verify if it contains all characters of t.

**Algorithm:**
1. For each starting position i
2. For each ending position j ≥ i
3. Check if substring s[i:j+1] contains all chars of t
4. Update minimum if valid

### Time Complexity: O(n²×m)
**Why?**
- Two nested loops: O(n²) substrings
- Checking each substring: O(n+m) to verify
- Total: O(n²×(n+m)) ≈ O(n³) worst case

### Space Complexity: O(m)
**Why?**
- Frequency maps for t and current window
- Size proportional to character set

**Problem:** Checking all substrings is extremely inefficient.

> **Key Insight for Improvement:**
> Use sliding window with two frequency maps. Track how many characters match. Expand right to match more, shrink left to minimize.

<br>

---

## Solution 2: Sliding Window with Frequency Maps

**Intuition:**
Maintain frequency maps for t and current window. Track count of matched characters. When all matched, try shrinking from left.

**Algorithm:**
1. Build frequency map for t
2. Use two pointers and window frequency map
3. Expand right, update window map
4. When window contains all chars of t:
   - Update minimum window
   - Shrink from left while still valid
5. Return minimum window

### Time Complexity: O(n+m)
**Why?**
- Build t frequency map: O(m)
- Right pointer moves n times: O(n)
- Left pointer moves at most n times: O(n)
- Each character processed at most twice
- Total: O(n+m)

**Improvement:**
- Before: O(n³)
- After: O(n+m)
- Example: n=10000, m=100
  - Brute: ~1,000,000,000,000 operations
  - Sliding: ~10,100 operations (100 million× faster!)

### Space Complexity: O(m+k)
**Why?**
- Frequency map for t: O(m)
- Frequency map for window: O(k) where k = unique chars
- Total: O(m+k)

> **Key Insight for Improvement:**
> Instead of comparing entire maps, track count of characters that have matching frequencies. Only update when frequencies change.

<br>

---

## Solution 3: Optimized Sliding Window with Match Count

**Intuition:**
Track how many unique characters from t have been fully matched in current window. When matched count equals required count, window is valid.

**Algorithm:**
1. Build frequency map for t, count required unique chars
2. Track matched count as we expand window
3. When matched == required:
   - Try shrinking from left
   - Update minimum window
4. Return minimum window

### Time Complexity: O(n+m)
**Why?**
- Same as Solution 2
- But avoids map comparisons
- More efficient in practice

### Space Complexity: O(m+k)
**Why?**
- Same as Solution 2
- Two frequency maps

<br>

---

## Complexity Summary

| Solution | Time | Space | Notes |
|----------|------|-------|-------|
| Brute Force | O(n³) | O(m) | Checks all substrings |
| Sliding Window | O(n+m) | O(m+k) | Compares maps |
| Optimized Window | O(n+m) | O(m+k) | Optimal - tracks match count |

> **Recommended Solution:** Optimized Sliding Window - O(n+m) time, O(m+k) space

<br>
<br>

---

```code```
