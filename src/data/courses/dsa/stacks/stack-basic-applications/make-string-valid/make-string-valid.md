Given a string `s` containing only parentheses `'('` and `')'`, return the minimum number of parentheses you must add to make the string valid.

A valid parentheses string has every opening parenthesis matched with a closing parenthesis in the correct order.

<br>

> Input:
> s = "())"

> Output:
> 1

> Explanation:
> The input string is `"())"`. 
> - `(` at index 0: Valid opening, balance = 1
> - `)` at index 1: Matches opening, balance = 0
> - `)` at index 2: No matching opening, unmatched = 1
> 
> **Result:** Need to add 1 opening `(` at the beginning to make it valid: `"(())"`

<br>

> Input:
> s = "((("

> Output:
> 3

> Explanation:
> - 3 unmatched opening parentheses
> - Need to add 3 closing `)` at the end
> - Result: 3

<br>


---

## Constraints

- `1 ≤ s.length ≤ 10⁵`
- `s consists of '(' and ')' only`

<br>

---

## All Possible Edge Cases

1. **Already valid:** '()' → 0 removals
2. **All opening:** '(((' → 3 removals
3. **All closing:** ')))' → 3 removals
4. **Empty string:** 0 removals
5. **Single character:** 1 removal
6. **Alternating invalid:** ')((' → 3 removals
7. **Complex nesting:** '(()))(' → 2 removals

<br>

---

## Solution: Two Counter Approach

Use two counters:
1. `open`: Count unmatched opening parentheses
2. `close`: Count unmatched closing parentheses
3. For each character:
   - If `(`: Increment `open`
   - If `)`: If `open > 0`, decrement `open` (matched), else increment `close` (unmatched)
4. Return `open + close` (total additions needed)

**Key insight:** Track unmatched brackets separately.

```code```

<br>

### Time Complexity Analysis

**Single Pass: O(n)**
- Traverse string once: n characters
- For each character:
  - Check character type: O(1)
  - Update counters: O(1)
- Total: n × O(1) = O(n)

**Why two counters are optimal?**
- No need for actual stack
- Track unmatched opening and closing separately
- Single pass solution

**Space Complexity: O(1)**
- Only two integer counters used
- No additional data structures

**Why not stack?**
- Stack would work but uses O(n) space
- Counters achieve same result with O(1) space
- More efficient for this specific problem

> **Time Complexity:** O(n) - single pass through string
> **Space Complexity:** O(1) - only two counters

<br>
<br>

---
