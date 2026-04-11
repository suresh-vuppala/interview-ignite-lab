Check if a typed string could be the result of long pressing keys while typing a name.

<br>

> Input: name = "alex", typed = "aaleex"
> Output: true (a long-pressed, e long-pressed)

<br>

---

## Constraints

- `1 ≤ name.length, typed.length ≤ 1000`
- `Lowercase English letters only`

<br>

---

## All Possible Edge Cases

1. **Identical strings:** true
2. **Extra characters at end:** "alex" vs "alexxx" → true only if last char matches
3. **Missing character:** "alex" vs "ale" → false
4. **Wrong character:** "alex" vs "alxe" → false

<br>

---

## Solution 1: Two Pointers

**Intuition:**
Use pointer i for name, j for typed. If chars match, advance both. If typed[j] matches typed[j-1] (long press), advance j only. Otherwise, mismatch → false.

**Algorithm:**
1. i = 0, j = 0
2. While j < typed.length:
   - If i < name.length AND name[i] == typed[j] → i++, j++
   - Else if j > 0 AND typed[j] == typed[j-1] → j++ (long press)
   - Else → return false
3. Return i == name.length

### Time Complexity: O(n + m)
### Space Complexity: O(1)

<br>

---

## Solution 2: Group Comparison

**Intuition:**
Group consecutive identical characters in both strings. Compare groups: same character, and typed group size ≥ name group size.

### Time Complexity: O(n + m)
### Space Complexity: O(n + m) for groups

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Two Pointers | O(n+m) | O(1) | Direct character-by-character matching |
| Group Comparison | O(n+m) | O(n+m) | Compare run-length groups |

**Recommended:** Two Pointers — simpler, O(1) space.

<br>
<br>

---

```code```
