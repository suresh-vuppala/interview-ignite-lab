Design an algorithm to encode a list of strings to a single string and decode it back. Must handle any characters including delimiters.

<br>

> Input: ["hello", "world"] → encode → "5#hello5#world" → decode → ["hello", "world"]

<br>

---

## Constraints

- `0 ≤ strs.length ≤ 200`
- `0 ≤ strs[i].length ≤ 200`
- `strs[i] can contain any character`

<br>

---

## All Possible Edge Cases

1. **Empty list:** Encode to empty, decode back to empty
2. **Empty strings:** ['',''] must be preserved
3. **Strings containing delimiter:** Must use length-prefix

<br>

---

## Solution 1: Delimiter-Based (Fragile)

**Intuition:**
Join strings with a special delimiter. Fails if strings contain the delimiter.

### Time Complexity: O(n)
### Space Complexity: O(n)

> **Problem:** Any chosen delimiter could appear in the strings themselves.

<br>

---

## Solution 2: Length-Prefix Encoding (Robust)

**Intuition:**
Prefix each string with its length and a separator. "5#hello5#world". Since we know the exact length, we can always extract correctly regardless of content.

**Algorithm:**
- **Encode:** For each string s: append len(s) + "#" + s
- **Decode:** Read digits until '#', parse length, extract that many characters

### Time Complexity: O(n) where n = total characters
### Space Complexity: O(1) extra

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Delimiter-Based | O(n) | O(1) | Breaks if strings contain delimiter |
| Length-Prefix | O(n) | O(1) | Handles any character — robust |

**Recommended:** Length-Prefix Encoding — handles all edge cases.

<br>
<br>

---

```code```
