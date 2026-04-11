Given a string s, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

<br>

> Input:
> s = "A man, a plan, a canal: Panama"

> Output:
> true

> Explanation:
> After removing non-alphanumeric and lowering case: "amanaplanacanalpanama" — reads the same forwards and backwards.
> 
> **Key insight:** Two pointers from both ends. Skip non-alphanumeric characters. Compare in-place without building a cleaned string.

<br>



---

## Constraints

- `1 ≤ s.length ≤ 2 × 10⁵`
- `s consists of printable ASCII characters`

<br>

---

## All Possible Edge Cases

1. **Empty or single char:** Always palindrome
2. **All non-alphanumeric:** "!@#$" → empty → palindrome
3. **Numeric palindrome:** "0P0" → "0p0" → palindrome
4. **Case sensitivity:** "Aa" → "aa" → palindrome

<br>

---

## Solution 1: Filter + Reverse — Build Clean String

**Intuition:**
Build a new string with only lowercase alphanumeric characters. Compare with its reverse.

**Algorithm:**
1. Build clean string: for each char, if alphanumeric → append tolower
2. Compare clean with reversed clean
3. Equal → palindrome

### Time Complexity: O(N)
**Why?**
- Building clean string: O(N)
- Reversing: O(N)
- Comparing: O(N)
- Total: O(N)

**Detailed breakdown:**
- String length 200,000 → ~600,000 operations (build + reverse + compare)

### Space Complexity: O(N)
**Why?**
- Clean string stores up to N characters
- Reversed copy: another O(N)

> **Drawback:**
> Creates two extra strings (cleaned + reversed) — O(N) extra space. We're materializing the cleaned string when we don't need to.

> **Key Insight for Improvement:**
> Two pointers from both ends of the ORIGINAL string. Skip non-alphanumeric characters with while loops. Compare lowercase characters in-place. No extra string needed — O(1) space.

<br>

---

## Solution 2: Two Pointers In-Place (Optimal)

**Intuition:**
Left pointer starts at beginning, right at end. Both skip non-alphanumeric characters. Compare lowercase characters. Any mismatch → not palindrome.

**Algorithm:**
1. left = 0, right = n-1
2. While left < right:
   - While left < right and !isAlphanumeric(s[left]) → left++
   - While left < right and !isAlphanumeric(s[right]) → right--
   - If toLower(s[left]) ≠ toLower(s[right]) → return false
   - left++, right--
3. Return true

### Time Complexity: O(N)
**Why?**
- Each character visited at most twice (once by each pointer)
- Total: 2N = O(N)

**Detailed breakdown:**
- String length 200,000 → at most 400,000 operations
- Same time as Solution 1 but O(1) space

**Example walkthrough:**
```
s = "A man, a plan, a canal: Panama"

left=0('A'), right=29('a') → 'a'=='a' ✓ → left=1, right=28
left=1(' '), skip → left=2('m')
right=28('m') → 'm'=='m' ✓
... continues matching all alphanumeric pairs ...
All match → true ✓
```

### Space Complexity: O(1)
**Why?**
- Only two pointer variables
- No extra strings created

**Why this is optimal:**
- Must examine each character: O(N) minimum
- O(1) space — purely in-place comparison

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Filter + Reverse | O(N) | O(N) | Build clean string |
| Two Pointers | O(N) | O(1) | Compare in-place, skip junk |

**Recommended Solution:** Two Pointers (Solution 2) — O(N) time, O(1) space.

**Key Insights:**
1. **Skip non-alphanumeric:** While loops advance past junk characters
2. **Case-insensitive:** Compare tolower versions
3. **In-place:** No need to build a cleaned string at all


<br>
<br>

---

```code```
