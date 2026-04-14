Your friend is typing their name on a keyboard. Sometimes keys are long pressed — a character may be typed 1 or more times. Check if the typed string could be the result of long pressing the name.

<br>

> Input:
> name = "alex", typed = "aaleex"

> Output:
> true

> Explanation:
> 'a' long pressed once (aa), 'l' typed normally, 'e' long pressed once (ee), 'x' typed normally.
> 
> **Key insight:** Two pointers — if characters match, advance both. If typed character matches the previous typed character (long press), advance only typed pointer.

<br>



---

## Constraints

- `1 ≤ name.length, typed.length ≤ 1000`
- Lowercase English letters only

<br>

---

## All Possible Edge Cases

1. **Identical strings:** Always true
2. **typed shorter than name:** Always false
3. **Extra character not in name:** "alex" vs "aaleexa" → false ('a' at end)
4. **Long press at start:** "a" vs "aaa" → true

<br>

---

## Solution 1: Naive / Brute Force Approach

**Intuition:**
Try the most straightforward method without optimization.

**Algorithm:**
1. Apply the direct/naive approach
2. May involve extra space, multiple passes, or higher time complexity
3. Serves as baseline to understand the problem before optimizing

### Time Complexity: Higher than optimal
**Why?**
Does not exploit key structural properties of the problem.

### Space Complexity: May use extra space

> **Drawback:**
> Checking all possible long-press combinations is exponential.

> **Key Insight for Improvement:**
> Two pointers: advance both on match, advance only typed pointer on long-press repeat. Single pass O(N).

<br>

---

## Solution 2: Two Pointers (Optimal)

**Intuition:**
Pointer i for name, j for typed. If characters match → advance both. If typed[j] matches typed[j-1] (long press) → advance only j. Otherwise → false.

**Algorithm:**
1. i = 0, j = 0
2. While j < typed.length:
   - If i < name.length and name[i] == typed[j] → i++, j++ (normal match)
   - Elif j > 0 and typed[j] == typed[j-1] → j++ (long press — skip)
   - Else → return false (mismatch)
3. Return i == name.length (all name characters consumed)

### Time Complexity: O(N + M)
**Why?**
- Each iteration advances j by 1
- Total: M iterations (typed.length)
- i advances at most N times

**Detailed breakdown:**
- name=1000, typed=1000 → at most 1000 iterations

**Example walkthrough:**
```
name = "alex", typed = "aaleex"
i=0, j=0

j=0: name[0]='a' == typed[0]='a' → i=1, j=1
j=1: name[1]='l' ≠ typed[1]='a', but typed[1]=='typed[0]' → long press → j=2
j=2: name[1]='l' == typed[2]='l' → i=2, j=3
j=3: name[2]='e' == typed[3]='e' → i=3, j=4
j=4: name[3]='x' ≠ typed[4]='e', but typed[4]=='typed[3]' → long press → j=5
j=5: name[3]='x' == typed[5]='x' → i=4, j=6

i=4 == name.length=4 → true ✓
```

### Space Complexity: O(1)
**Why?**
- Only two pointer variables

> **Drawback:**
> Checking all possible long-press combinations is exponential.

> **Key Insight for Improvement:**
> Two pointers: advance both on match, advance only typed pointer on long-press repeat. Single pass O(N).


<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Two Pointers | O(N+M) | O(1) | Match or long-press check |

**Recommended Solution:** Two Pointers — O(N+M) time, O(1) space.

**Key Insights:**
1. **Long press detection:** typed[j] == typed[j-1] means this is a repeated key press
2. **Must consume all of name:** Check i == name.length at the end
3. **Order matters:** Characters must appear in the same order


<br>
<br>

---

```code```
