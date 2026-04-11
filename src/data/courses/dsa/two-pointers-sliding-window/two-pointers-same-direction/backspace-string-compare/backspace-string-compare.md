Given two strings with '#' as backspace, check if they are equal after processing.

<br>

> Input: s = "ab#c", t = "ad#c"
> Output: true (both become "ac")

<br>

---

## Constraints

- `1 ≤ s.length, t.length ≤ 200`
- `s and t contain lowercase letters and '#'`

<br>

---

## All Possible Edge Cases

1. **No backspaces:** Direct comparison
2. **Backspace on empty:** '#a' → 'a' (backspace has no effect)
3. **All backspaces:** "###" → ""
4. **Multiple consecutive backspaces:** "abc###" → ""

<br>

---

## Solution 1: Build String with Stack

**Intuition:**
Process each string: push non-'#' chars onto stack, pop on '#'. Compare final stacks.

### Time Complexity: O(n + m)
### Space Complexity: O(n + m)

<br>

---

## Solution 2: Two Pointers from End (Optimal)

**Intuition:**
Process both strings from right to left. Count '#' characters to know how many to skip. Compare characters after skipping.

**Algorithm:**
1. i = len(s)-1, j = len(t)-1
2. While i ≥ 0 or j ≥ 0:
   - Count and skip backspaced chars in s (advance i)
   - Count and skip backspaced chars in t (advance j)
   - Compare s[i] and t[j]
   - If mismatch → false

### Time Complexity: O(n + m)
### Space Complexity: O(1) — no extra data structures

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Stack | O(n+m) | O(n+m) | Build processed strings |
| Two Pointers RTL | O(n+m) | O(1) | Process from right, skip in-place |

<br>
<br>

---

```code```
