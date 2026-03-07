Given a string s and an integer k, you can replace at most k characters. Find the length of the longest substring containing the same letter after replacements.

<br>

> Input:
> s = "AABABBA", k = 1

> Output:
> 4

> Explanation:
> Replace one 'A' in "AABA" to get "AAAA" (length 4)
> Or replace one 'B' in "ABBB" to get "BBBB" (length 4)
> 
> **Key insight:** In a valid window, (window_size - max_frequency) ≤ k means we can replace remaining characters.

<br>

---

## Solution 1: Brute Force

**Intuition:**
Check all possible substrings. For each substring, count the most frequent character. If remaining characters ≤ k, it's valid.

**Algorithm:**
1. For each starting position i
2. For each ending position j ≥ i
3. Count character frequencies in substring
4. If (length - max_freq) ≤ k, update max length

### Time Complexity: O(n²×26) = O(n²)
**Why?**
- Two nested loops: O(n²) substrings
- For each substring: count frequencies O(26) = O(1)
- Total: O(n²)

### Space Complexity: O(1)
**Why?**
- Frequency array of size 26 (constant)
- No additional structures

**Problem:** Checking all substrings is inefficient.

> **Key Insight for Improvement:**
> Use sliding window. Expand right while valid, shrink left when invalid. Track max frequency to determine validity.

<br>

---

## Solution 2: Sliding Window with Frequency Map

**Intuition:**
Maintain a window with character frequencies. Window is valid if (window_size - max_frequency) ≤ k. Expand right, shrink left when invalid.

**Algorithm:**
1. Use two pointers: left and right
2. Expand right, update frequency
3. While (window_size - max_freq) > k:
   - Shrink from left
4. Update max length

### Time Complexity: O(n×26) = O(n)
**Why?**
- Right pointer moves n times: O(n)
- Left pointer moves at most n times total: O(n)
- Finding max frequency: O(26) per iteration
- Total: O(n×26) = O(n)

**Improvement:**
- Before: O(n²)
- After: O(n)
- Example: n=1000
  - Brute: 1,000,000 operations
  - Sliding: ~26,000 operations (40× faster!)

### Space Complexity: O(1)
**Why?**
- Frequency map of size 26
- Constant space

> **Key Insight for Improvement:**
> We don't need to recalculate max frequency every time. Track it incrementally and only update when adding characters.

<br>

---

## Solution 3: Optimized Sliding Window

**Intuition:**
Instead of finding max frequency each time, track it as we go. We only care if current frequency becomes new maximum.

**Algorithm:**
1. Track max_freq as we add characters
2. When adding character, update max_freq if needed
3. If window invalid, shrink left
4. Max length = max(max_length, right - left + 1)

### Time Complexity: O(n)
**Why?**
- Single pass with two pointers
- No inner loop to find max frequency
- Constant work per character
- Total: O(n)

**Improvement:**
- Before: O(n×26)
- After: O(n)
- Removes constant factor of 26

### Space Complexity: O(1)
**Why?**
- Frequency array of size 26
- Few variables

<br>

---

## Complexity Summary

| Solution | Time | Space | Notes |
|----------|------|-------|-------|
| Brute Force | O(n²) | O(1) | Checks all substrings |
| Sliding Window | O(n×26) | O(1) | Recalculates max freq |
| Optimized Window | O(n) | O(1) | Optimal - tracks max freq |

> **Recommended Solution:** Optimized Sliding Window - O(n) time, O(1) space

<br>
<br>

---

```code```
