Remove the outermost parentheses of every primitive valid parentheses decomposition of s.

<br>

> Input: s = "(()())(())"
> Output: "()()()"

> Explanation: Decompose into "(()())" and "(())". Remove outermost of each: "()()" and "()" → "()()()"
> 
> **Key insight:** Track nesting depth. When depth > 0 after opening, include the character. When depth > 0 before closing, include it. Depth 0→1 and 1→0 are the outermost brackets — skip them.

<br>

---

## Constraints
- `1 ≤ s.length ≤ 10⁵`
- s is a valid parentheses string

<br>

---

## All Possible Edge Cases
1. **Single primitive:** "(())" → "()"
2. **Multiple primitives:** "()()" → ""
3. **Deeply nested:** "((()))" → "(())"

<br>

---

## Solution 1: Depth Counter (Optimal)

**Intuition:** Track depth. Opening bracket at depth 0 is outermost (skip). Closing bracket that brings depth to 0 is outermost (skip). Everything else: include.

**Algorithm:**
1. depth = 0, result = ""
2. For each char c:
   - If c == '(': if depth > 0 → include. depth++
   - If c == ')': depth--. if depth > 0 → include

### Time Complexity: O(N)
**Why?** Single pass, O(1) per character.

**Detailed breakdown:** N = 100,000 → 100,000 operations

**Example walkthrough:**
```
s = "(()())(())"

'(' depth 0→1 (skip outer), '(' depth 1→2 (include), ')' depth 2→1 (include),
'(' depth 1→2 (include), ')' depth 2→1 (include), ')' depth 1→0 (skip outer)
'(' depth 0→1 (skip), '(' depth 1→2 (include), ')' depth 2→1 (include), ')' depth 1→0 (skip)

Result: "()()()" ✓
```

### Space Complexity: O(1) extra

> **Drawback:** None — this is already optimal.

> **Key Insight for Improvement:** The depth counter approach is the simplest and most efficient. A stack-based version works too but uses O(N) space unnecessarily.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Depth Counter | O(N) | O(1) | Track depth, skip at boundary |

**Key Insights:**
1. **Depth 0↔1 = outermost boundary:** Skip these transitions
2. **Depth > 0:** Always include — these are inner characters

<br><br>

---

```code```
