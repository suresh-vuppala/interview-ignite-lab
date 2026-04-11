Encode a list of strings to a single string and decode it back. Must handle any characters.

<br>

> ["hello","world"] → encode → "5#hello5#world" → decode → ["hello","world"]

<br>

---

## Constraints

- Strings can contain ANY character

<br>

---

## Solution 1: Length-Prefix Encoding (Optimal)

**Intuition:** Prefix each string with its length and '#'. Since we know exact length, extraction is unambiguous regardless of content.

### Time: O(n) | Space: O(1) extra

```code```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Delimiter (fragile) | O(n) | O(1) | Breaks if strings contain delimiter |
| Length-Prefix | O(n) | O(1) | Handles any character — robust |

<br>
<br>
