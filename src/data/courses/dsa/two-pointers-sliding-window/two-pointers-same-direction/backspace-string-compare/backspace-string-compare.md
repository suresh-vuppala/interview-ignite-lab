Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

<br>

> Input:
> s = "ab#c", t = "ad#c"

> Output:
> true

> Explanation:
> s: type 'a', type 'b', backspace (remove 'b'), type 'c' → "ac"
> t: type 'a', type 'd', backspace (remove 'd'), type 'c' → "ac"
> Both result in "ac" → equal.
> 
> **Key insight:** Process from RIGHT to LEFT. Count '#' to know how many characters to skip. Compare final characters without building strings.

<br>



---

## Constraints

- `1 ≤ s.length, t.length ≤ 200`
- `s and t only contain lowercase letters and '#'`

<br>

---

## All Possible Edge Cases

1. **No backspaces:** Direct comparison
2. **All backspaces:** "###" → empty string
3. **Backspace on empty:** "#a#" → "a" (first # has no effect)
4. **Multiple consecutive backspaces:** "abc###" → ""

<br>

---

## Solution 1: Stack — Build Processed Strings

**Intuition:**
Use a stack to simulate typing. Push letters, pop on '#'. Convert to string and compare.

**Algorithm:**
1. Process s: for each char, if '#' → pop (if stack not empty), else push
2. Process t: same way
3. Compare resulting strings

### Time Complexity: O(N + M)
**Why?**
- Process each string: O(N) and O(M)
- Comparison: O(min(N, M))

**Detailed breakdown:**
- s.length=200, t.length=200 → ~600 operations

### Space Complexity: O(N + M)
**Why?**
- Two stacks/strings storing processed results

> **Drawback:**
> Uses O(N+M) space to build the processed strings. We're materializing intermediate results that we only need for comparison.

> **Key Insight for Improvement:**
> Process both strings from RIGHT to LEFT simultaneously. When '#' is found, count how many characters to skip. Compare the next valid characters from both strings. No extra storage needed — O(1) space.

<br>

---

## Solution 2: Two Pointers from End — O(1) Space (Optimal)

**Intuition:**
Scan both strings from the end. For each string, use a skip counter: '#' increments skip, letters with skip>0 are skipped. Compare the next valid (non-skipped) characters.

**Algorithm:**
1. i = s.length-1, j = t.length-1
2. While i ≥ 0 or j ≥ 0:
   - Advance i past skipped characters (count '#', skip letters)
   - Advance j past skipped characters
   - Compare s[i] and t[j]: if different → false
   - If one is done and the other isn't → false
   - i--, j--
3. Both exhausted → true

### Time Complexity: O(N + M)
**Why?**
- Each character visited at most twice (once for counting, once for comparison)

**Detailed breakdown:**
- s=200, t=200 → at most 800 operations
- Same time as stack but O(1) space

**Example walkthrough:**
```
s = "ab#c", t = "ad#c"
i=3, j=3

getNext(s,3): s[3]='c', no skip → i=3
getNext(t,3): t[3]='c', no skip → j=3
s[3]='c' == t[3]='c' ✓, i=2, j=2

getNext(s,2): s[2]='#' → skip=1, s[1]='b' skipped → i=0
getNext(t,2): t[2]='#' → skip=1, t[1]='d' skipped → j=0
s[0]='a' == t[0]='a' ✓, i=-1, j=-1

Both exhausted → true ✓
```

### Space Complexity: O(1)
**Why?**
- Only pointer variables and skip counters

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Stack | O(N+M) | O(N+M) | Build processed strings |
| Two Pointers RTL | O(N+M) | O(1) | Process from right, skip counter |

**Recommended Solution:** Two Pointers from End (Solution 2) — O(N+M) time, O(1) space.

**Key Insights:**
1. **Right-to-left:** Backspaces affect characters to their LEFT — process from right
2. **Skip counter:** '#' increments skip, next non-'#' with skip>0 gets skipped
3. **Follow-up:** If characters can be streamed (not all in memory), this O(1) space approach is essential


<br>
<br>

---

```code```
