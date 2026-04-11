Given strings s and p, find all start indices of p's anagrams in s.

<br>

> Input:
> s = "cbaebabacd", p = "abc"

> Output:
> [0, 6]

> Explanation:
> Substring starting at 0: "cba" — anagram of "abc". Starting at 6: "bac" — anagram of "abc".
> 
> **Key insight:** Fixed-size window of |p|. Maintain character frequency counts. Slide: decrement leaving char, increment entering char. If window freq matches p's freq → anagram found.

<br>



---

## Constraints

- `1 ≤ s.length, p.length ≤ 3 × 10⁴`
- `Lowercase English letters only`

<br>

---

## All Possible Edge Cases

1. **p longer than s:** No anagrams possible → []
2. **s == p:** Return [0]
3. **All same characters:** "aaaa", p="aa" → [0,1,2]
4. **No match:** Disjoint character sets

<br>

---

## Solution 1: Brute Force — Rebuild Frequency per Window

**Intuition:**
For each window of size |p| in s, count character frequencies and compare with p's frequencies.

### Time Complexity: O(N × M)
**Why?**
- (N-M+1) windows × M to count each

**Detailed breakdown:**
- N=30,000, M=100 → 3,000,000 operations

### Space Complexity: O(1) — fixed 26-element arrays

> **Drawback:**
> Rebuilding the frequency count from scratch for every window. Adjacent windows differ by only 2 characters (one leaves, one enters).

> **Key Insight for Improvement:**
> Maintain a sliding frequency count. When sliding: decrement freq of leaving char, increment freq of entering char. Compare arrays in O(26)=O(1) per slide. Total: O(N).

<br>

---

## Solution 2: Sliding Window + Frequency Match (Optimal)

**Intuition:**
Maintain window frequency array. Slide by updating 2 characters. Compare with p's frequency after each slide.

**Algorithm:**
1. Build pFreq[26] from p
2. Build wFreq[26] from first |p| chars of s
3. If wFreq == pFreq → add index 0
4. For i = |p| to |s|-1:
   - wFreq[s[i]]++ (entering)
   - wFreq[s[i-|p|]]-- (leaving)
   - If wFreq == pFreq → add index (i-|p|+1)

### Time Complexity: O(N)
**Why?**
- Single pass: N iterations
- Frequency update: O(1) per slide
- Frequency comparison: O(26) = O(1) per slide
- Total: O(N × 26) = O(N)

**Detailed breakdown:**
- N = 30,000 → 30,000 slides × O(1) each
- Compared to brute: 3,000,000 → 30,000 (100× faster!)

**Example walkthrough:**
```
s = "cbaebabacd", p = "abc"
pFreq: a=1, b=1, c=1

Window "cba": wFreq: a=1, b=1, c=1 == pFreq → index 0 ✓
Slide to "bae": wFreq: a=1, b=1, e=1 ≠ pFreq
Slide to "aeb": wFreq: a=1, b=1, e=1 ≠ pFreq
... (skip non-matching windows) ...
Slide to "bac": wFreq: a=1, b=1, c=1 == pFreq → index 6 ✓

Result: [0, 6] ✓
```

### Space Complexity: O(1)
**Why?**
- Two fixed-size arrays of 26 elements

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(N×M) | O(1) | Rebuild freq per window |
| Sliding Frequency | O(N) | O(1) | Update 2 chars per slide, O(1) compare |

**Recommended Solution:** Sliding Frequency (Solution 2) — O(N) time, O(1) space.

**Key Insights:**
1. **Fixed-size window:** Window size = |p|, slides one position at a time
2. **O(1) comparison:** 26-element array comparison is constant time
3. **Optimization:** Track "matches" count instead of full array comparison for O(1) amortized


<br>
<br>

---

```code```
