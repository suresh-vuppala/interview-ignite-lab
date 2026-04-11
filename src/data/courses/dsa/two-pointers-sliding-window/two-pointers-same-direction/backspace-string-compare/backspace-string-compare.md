Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

<br>

> Input:
> s = "ab#c", t = "ad#c"

> Output:
> true

> Explanation:
> s: type 'a' → "a", type 'b' → "ab", backspace → "a", type 'c' → "ac"
> t: type 'a' → "a", type 'd' → "ad", backspace → "a", type 'c' → "ac"
> Both result in "ac" → true
> 
> **Key insight:** Process from the END. Count backspaces and skip characters accordingly. O(1) space.

<br>

> Input:
> s = "ab##", t = "c#d#"

> Output:
> true

> Explanation:
> s: "ab##" → "" (both characters deleted)
> t: "c#d#" → "" (both characters deleted)
> Both empty → true

<br>

---

## Constraints

- `1 ≤ s.length, t.length ≤ 200`
- `s and t only contain lowercase letters and '#' characters`

<br>

---

## All Possible Edge Cases

1. **No backspaces:** 'abc' vs 'abc' → true
2. **Backspace on empty:** '#a' — backspace at start has no effect, result is 'a'
3. **All backspaces:** '###' → empty string
4. **Multiple consecutive backspaces:** 'abc###' → empty string
5. **Both empty after processing:** 'a#' vs 'b#' → true (both empty)
6. **Different lengths, same result:** 'ab##c' vs 'c' → true
7. **Backspace deletes previous backspace result:** 'ab#c' = 'ac', not 'abc'
8. **Single character each:** 'a' vs 'a' → true, 'a' vs 'b' → false

<br>

---

## Solution: Two Pointers from End (O(1) Space)

**Intuition:**
Process both strings from the end. When we encounter '#', count backspaces and skip that many characters. Compare the next valid characters from both strings.

**Algorithm:**
1. Start i = end of s, j = end of t
2. Loop while i >= 0 or j >= 0:
   - Find next valid char in s: count '#' and skip accordingly
   - Find next valid char in t: count '#' and skip accordingly
   - If both valid: compare characters, return false if different
   - If one valid and one exhausted: return false
   - Move both pointers left
3. Return true

<br>

### Time Complexity: O(n + m)
**Why?**
- Each character in both strings processed at most twice (once for counting, once for comparing)

### Space Complexity: O(1)
**Why?**
- Only pointer and counter variables
- No extra strings built

<br>
<br>

---

```code```
