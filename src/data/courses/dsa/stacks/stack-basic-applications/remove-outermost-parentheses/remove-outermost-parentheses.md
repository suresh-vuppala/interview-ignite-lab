Given a valid parentheses string `s`, remove the outermost parentheses of every primitive string in the primitive decomposition of `s`.

A primitive string is a non-empty valid parentheses string that cannot be split into two non-empty valid parentheses strings.

<br>

> Input:
> s = "(()())(())"

> Output:
> "()()()"

> Explanation:
> The input string is `"(()())(())"`.
> - First primitive: `"(()())"` → Remove outer `()` → `"()()"`
> - Second primitive: `"(())"` → Remove outer `()` → `"()"`
> - Concatenate: `"()()" + "()"` = `"()()()"`
> 
> **How it works:**
> - Use a counter to track depth
> - When counter is 0 and we see `(`, it's an opening outer parenthesis (skip it)
> - When counter becomes 0 after seeing `)`, it's a closing outer parenthesis (skip it)
> - Add all other characters to result

<br>


---

## Constraints

- `1 ≤ s.length ≤ 10⁵`
- `s is a valid parentheses string`
- `s consists of '(' and ')' only`

<br>

---

## All Possible Edge Cases

1. **Single primitive:** '()' → ''
2. **Multiple primitives:** '()()' → ''
3. **Nested:** '(())' → '()'
4. **Complex:** '(()())(())' → '()()()'
5. **Deeply nested:** '(((())))' → '((()))'

<br>

---

## Solution: Counter-Based Approach

Use a depth counter:
1. Maintain a `depth` counter starting at 0
2. For each character:
   - If `(`: Add to result only if depth > 0, then increment depth
   - If `)`: Decrement depth, then add to result only if depth > 0
3. This skips outermost parentheses of each primitive

**Key insight:** Depth 0 indicates outermost parentheses.

```code```

<br>

### Time Complexity Analysis

**Single Pass: O(n)**
- Iterate through string once: n characters
- For each character:
  - Check depth: O(1)
  - Append to result: O(1)
  - Update depth: O(1)
- Total: n × O(1) = O(n)

**Why counter approach is optimal?**
- No need for actual stack, just track depth
- Single pass through string
- Constant time per character

**Space Complexity: O(n)**
- Result string stores at most n-2 characters
- No additional data structures needed

> **Time Complexity:** O(n) - single pass through string
> **Space Complexity:** O(n) - result string

<br>
<br>

---
