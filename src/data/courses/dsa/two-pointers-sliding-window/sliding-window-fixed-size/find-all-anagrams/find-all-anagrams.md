Given a string s and a pattern p, find all starting indices of p's anagrams in s. An anagram is a rearrangement of letters.

<br>

> Input:
> s = "cbaebabacd", p = "abc"

> Output:
> [0, 6]

> Explanation:
> Anagrams of "abc" are "abc", "acb", "bac", "bca", "cab", "cba"
> - Index 0: "cba" is an anagram of "abc"
> - Index 6: "bac" is an anagram of "abc"
> 
> **Key insight:** Use frequency map and sliding window to match character counts.

<br>

---

## Solution 1: Brute Force with Sorting

**Intuition:**
For each window of size len(p), sort it and compare with sorted p.

**Algorithm:**
1. Sort pattern p
2. For each window of size len(p) in s:
   - Sort window
   - If sorted window == sorted p, add index

### Time Complexity: O(n×k log k)
**Why?**
- n-k+1 windows (n = len(s), k = len(p))
- Each window: sort k characters → O(k log k)
- Total: O((n-k)×k log k) ≈ O(n×k log k)

### Space Complexity: O(k)
**Why?**
- Sorting requires O(k) space
- Storing sorted pattern: O(k)

**Problem:** Sorting each window is expensive.

> **Key Insight for Improvement:**
> Instead of sorting, use frequency maps. Two strings are anagrams if they have same character frequencies.

<br>

---

## Solution 2: Sliding Window with Frequency Map

**Intuition:**
Maintain frequency map of current window. Compare with pattern's frequency map.

**Algorithm:**
1. Create frequency map for pattern
2. Create frequency map for first window
3. Compare maps, add index if match
4. Slide window: decrement left char, increment right char
5. Compare and add if match

### Time Complexity: O(n×26) = O(n)
**Why?**
- Build pattern map: O(k)
- Process each character once: O(n)
- Map comparison: O(26) for lowercase letters
- Total: O(n) since 26 is constant

**Improvement:**
- Before: O(n×k log k)
- After: O(n)
- Example: n=10000, k=100
  - Brute: ~6,000,000 operations
  - Optimized: ~10,000 operations (600× faster!)

### Space Complexity: O(1)
**Why?**
- Two frequency maps of size 26 (constant)
- Total: O(26) = O(1)

> **Key Insight for Improvement:**
> Instead of comparing entire maps, track count of matching characters. Only update when frequencies change.

<br>

---

## Solution 3: Optimized Sliding Window with Match Count

**Intuition:**
Track how many characters have matching frequencies. When match count equals 26, we have an anagram.

**Algorithm:**
1. Build frequency maps for pattern and first window
2. Count initial matches
3. Slide window:
   - Update match count when adding/removing characters
   - If matches == 26, add index

### Time Complexity: O(n)
**Why?**
- Single pass through string
- Constant time per character
- No map comparisons needed

### Space Complexity: O(1)
**Why?**
- Two arrays of size 26
- Constant space

<br>

---

## Complexity Summary

| Solution | Time | Space | Notes |
|----------|------|-------|-------|
| Brute Force | O(n×k log k) | O(k) | Sorts each window |
| Frequency Map | O(n) | O(1) | Compares maps each slide |
| Match Count | O(n) | O(1) | Optimal - tracks matches |

> **Recommended Solution:** Match Count - O(n) time, O(1) space

<br>
<br>

---

```code```
