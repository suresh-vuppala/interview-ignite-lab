Design an algorithm to encode a list of strings to a single string and decode it back. The encoding must handle any possible characters in the strings (including delimiters).

<br>

> Input:
> ["hello","world"]

> Output (encoded):
> "5#hello5#world"

> Output (decoded):
> ["hello","world"]

> Explanation:
> Each string is prefixed with its length and a '#' separator. Since we know the exact length, we can extract strings unambiguously regardless of their content.
> 
> **Key insight:** Length-prefix encoding is delimiter-independent — it works for any character set.

<br>



---

## Constraints

- `0 ≤ strs.length ≤ 200`
- `0 ≤ strs[i].length ≤ 200`
- `strs[i] can contain any 256 valid ASCII characters`

<br>

---

## All Possible Edge Cases

1. **Empty list:** [] → "" → []
2. **Empty strings:** ["",""] → "0#0#" → ["",""]
3. **Strings containing #:** ["a#b"] → "3#a#b" — handled correctly by length prefix
4. **Strings containing digits:** ["123"] → "3#123" — length prefix disambiguates
5. **Single string:** ["hello"] → "5#hello"

<br>

---

## Solution 1: Length-Prefix Encoding (Optimal)

**Intuition:**
Prefix each string with its length followed by a '#' delimiter. To decode, read the length, skip past '#', then extract exactly that many characters.

**Algorithm (Encode):**
1. For each string s: append len(s) + "#" + s
2. Return concatenated result

**Algorithm (Decode):**
1. Initialize i = 0, result = []
2. While i < encoded.length:
   - Find '#' starting from i → position j
   - length = parseInt(encoded[i..j-1])
   - Extract string: encoded[j+1..j+length]
   - Advance i = j + 1 + length
3. Return result

### Time Complexity: O(N)
**Why?**
- N = total characters across all strings
- Encode: one pass to build result string
- Decode: one pass to extract strings
- Total: O(N)

**Detailed breakdown:**
- 200 strings × 200 chars = 40,000 total characters
- Encode: 40,000 char appends + 200 length prefixes
- Decode: 40,000 char reads

**Example walkthrough:**
```
Encode: ["hello", "world"]
  "hello" → "5#hello"
  "world" → "5#world"
  Result: "5#hello5#world"

Decode: "5#hello5#world"
  i=0: find '#' at j=1, length=5, extract "hello", i=7
  i=7: find '#' at j=8, length=5, extract "world", i=14
  Result: ["hello", "world"] ✓

Edge case: ["a#b", "c"]
  Encode: "3#a#b1#c"
  Decode: length=3 → extract "a#b" (includes the #!), then length=1 → "c" ✓
```

### Space Complexity: O(1) extra
**Why?**
- Only index variables for decoding
- Output strings are required

**Why this is robust:**
- Length prefix makes it immune to any character in the strings
- Even "#", digits, or empty strings are handled correctly

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Delimiter (fragile) | O(N) | O(1) | Breaks if strings contain the delimiter |
| Length-Prefix | O(N) | O(1) | Handles ANY character — robust |

**Recommended Solution:** Length-Prefix Encoding — O(N) time, O(1) extra space.

**Key Insights:**
1. **Length prefix > delimiter:** Length tells us exactly how many chars to read — no ambiguity
2. **Any character safe:** Even strings containing "#" or digits work correctly
3. **Format:** "len#string" — the # is just a separator between length digits and string content


<br>
<br>

---

```code```
