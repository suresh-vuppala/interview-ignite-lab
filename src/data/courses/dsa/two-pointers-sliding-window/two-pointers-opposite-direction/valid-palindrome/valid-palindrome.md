Given a string, determine if it's a palindrome considering only alphanumeric characters and ignoring case.

<br>

> Input: "A man, a plan, a canal: Panama"
> Output: true

<br>

---

## Constraints

- `1 ≤ s.length ≤ 2 × 10⁵`
- `s consists of printable ASCII characters`

<br>

---

## All Possible Edge Cases

1. **Empty string:** True
2. **Single character:** True
3. **All non-alphanumeric:** ",.!!" → true (empty after filtering)
4. **Mixed case:** "Aa" → true
5. **Numbers:** "0P" → false

<br>

---

## Solution 1: Filter + Reverse

**Intuition:** Clean the string (lowercase, alphanumeric only), then compare with its reverse.

### Time Complexity: O(n)
### Space Complexity: O(n) — cleaned string

<br>

---

## Solution 2: Two Pointers (Optimal)

**Intuition:**
Pointers at both ends, skip non-alphanumeric, compare lowercase characters.

**Algorithm:**
1. left = 0, right = n-1
2. While left < right:
   - Skip non-alphanumeric from left
   - Skip non-alphanumeric from right
   - If toLower(s[left]) != toLower(s[right]) → false
   - left++, right--
3. Return true

### Time Complexity: O(n)
### Space Complexity: O(1) — no extra string

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Filter + Reverse | O(n) | O(n) | Build clean string |
| Two Pointers | O(n) | O(1) | Compare in-place, skip junk |

<br>
<br>

---

```code```
