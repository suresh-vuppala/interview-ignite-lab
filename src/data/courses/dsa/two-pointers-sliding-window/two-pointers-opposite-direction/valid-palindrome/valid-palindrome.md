Given a string s, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

<br>

> Input:
> s = "A man, a plan, a canal: Panama"

> Output:
> true

> Explanation:
> After removing non-alphanumeric and lowercasing: "amanaplanacanalpanama"
> 
> Two pointer process:
> - left=0 ('a'), right=19 ('a'): match ✓, move inward
> - left=1 ('m'), right=18 ('m'): match ✓, move inward
> - ... all characters match
> - Pointers meet → palindrome confirmed
> 
> **Key insight:** Skip non-alphanumeric characters, compare case-insensitively.

<br>

> Input:
> s = "race a car"

> Output:
> false

> Explanation:
> After filtering: "raceacar"
> - left=0 ('r'), right=7 ('r'): match ✓
> - left=1 ('a'), right=6 ('a'): match ✓
> - left=2 ('c'), right=5 ('c'): match ✓
> - left=3 ('e'), right=4 ('a'): mismatch ✗ → not a palindrome

<br>

---

## Constraints

- `1 ≤ s.length ≤ 2 × 10⁵`
- `s consists of printable ASCII characters`

<br>

---

## All Possible Edge Cases

1. **Empty string or single char:** Always a palindrome
2. **Only non-alphanumeric characters:** '!!!@@@' → true (empty after filtering)
3. **Case sensitivity:** 'Aa' → true (case-insensitive comparison)
4. **All spaces:** '     ' → true
5. **Numbers in string:** '0P' → false (0 and P are not equal)
6. **Palindrome with mixed punctuation:** 'A man, a plan, a canal: Panama' → true
7. **Two characters, not palindrome:** 'ab' → false
8. **String with only numbers:** '12321' → true

<br>

---

## Solution: Two Pointers (Opposite Direction)

**Intuition:**
Place two pointers at the start and end. Skip non-alphanumeric characters. Compare characters case-insensitively. Move inward.

**Algorithm:**
1. Initialize left = 0, right = s.length - 1
2. While left < right:
   - Skip left forward past non-alphanumeric characters
   - Skip right backward past non-alphanumeric characters
   - If left >= right: break (all compared)
   - Compare toLower(s[left]) vs toLower(s[right])
   - If not equal: return false
   - Move both pointers inward
3. Return true

<br>

### Time Complexity: O(n)
**Why?**
- Each pointer moves at most n positions total
- Each character visited at most once
- tolower and isalnum are O(1) operations

### Space Complexity: O(1)
**Why?**
- Only two pointer variables
- No extra string created (in-place comparison)
- Constant space regardless of input size

<br>
<br>

---

```code```
