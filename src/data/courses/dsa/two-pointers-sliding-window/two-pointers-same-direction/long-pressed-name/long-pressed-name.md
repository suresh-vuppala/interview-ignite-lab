Your friend is typing their name on a keyboard. Sometimes a key might get long pressed — the character is typed 1 or more extra times. Check if the typed string could be the result of long pressing the name.

<br>

> Input:
> name = "alex", typed = "aaleex"

> Output:
> true

> Explanation:
> Two pointer comparison:
> - i=0('a'), j=0('a'): match, i++, j++
> - i=1('l'), j=1('a'): no match, but typed[1]=='a'==typed[0] (long press), j++
> - i=1('l'), j=2('l'): match, i++, j++
> - i=2('e'), j=3('e'): match, i++, j++
> - i=3('x'), j=4('e'): no match, typed[4]=='e'==typed[3] (long press), j++
> - i=3('x'), j=5('x'): match, i++, j++
> - Both exhausted → true

<br>

---

## Constraints

- `1 ≤ name.length, typed.length ≤ 1000`
- `name and typed consist of only lowercase English letters`

<br>

---

## All Possible Edge Cases

1. **Exact match:** 'alex' vs 'alex' → true
2. **typed shorter than name:** 'alex' vs 'al' → false
3. **Extra character not matching:** 'alex' vs 'alexb' → false
4. **Long press every char:** 'abc' vs 'aabbcc' → true
5. **Wrong character long-pressed:** 'alex' vs 'aaleexa' → false
6. **Empty name:** '' vs '' → true
7. **Single character:** 'a' vs 'aaa' → true
8. **Long press at end only:** 'alex' vs 'alexx' → true
9. **First character mismatch:** 'alex' vs 'blex' → false

<br>

---

## Solution: Two Pointers (Same Direction)

**Intuition:**
Walk through both strings. If characters match, advance both pointers. If they don't match, check if the typed character is a long-press repeat of the previous character — advance only typed pointer. Otherwise, return false.

**Algorithm:**
1. i = 0 (name pointer), j = 0 (typed pointer)
2. While j < typed.length:
   - If i < name.length AND name[i] == typed[j]: i++, j++ (character match)
   - Else if j > 0 AND typed[j] == typed[j-1]: j++ (long press of previous)
   - Else: return false (mismatch)
3. Return i == name.length (all name characters consumed)

<br>

### Time Complexity: O(n + m) — single pass through both strings
### Space Complexity: O(1) — only pointer variables

<br>
<br>

---

```code```
