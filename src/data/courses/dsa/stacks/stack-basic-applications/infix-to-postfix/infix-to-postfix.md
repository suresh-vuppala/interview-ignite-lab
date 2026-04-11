Given an infix expression, convert it to postfix notation (Reverse Polish Notation).

**Infix:** Operators between operands. Example: `A + B`
**Postfix:** Operators after operands. Example: `A B +`

<br>

> Input:
> infix = "A+B*C-D/E"

> Output:
> "ABC*+DE/-"

> Explanation:
> The infix expression is `"A+B*C-D/E"`.
> - A: Output = "A"
> - +: Push to stack, Stack = [+]
> - B: Output = "AB"
> - *: Higher precedence than +, push, Stack = [+, *]
> - C: Output = "ABC"
> - -: Pop * (higher), pop + (equal), push -, Output = "ABC*+", Stack = [-]
> - D: Output = "ABC*+D"
> - /: Same precedence as -, push, Stack = [-, /]
> - E: Output = "ABC*+DE"
> - End: Pop all, Output = "ABC*+DE/-"
> 
> **Operator Precedence:** `* / > + - > (`

<br>

> Input:
> infix = "(A+B)*C"

> Output:
> "AB+C*"

> Explanation:
> - Parentheses force A+B to be evaluated first
> - Result: AB+ then multiply by C

<br>


---

## Constraints

- `Valid infix expression`
- `Operators: +, -, *, /, ^`
- `Parentheses are balanced`
- `Operands are single characters or digits`

<br>

---

## All Possible Edge Cases

1. **No operators:** 'a' → 'a'
2. **Single operation:** 'a+b' → 'ab+'
3. **Nested parentheses:** '((a+b))' → 'ab+'
4. **Right-associative operator:** '^' is right-associative: 'a^b^c' → 'abc^^'
5. **Mixed precedence:** 'a+b*c' → 'abc*+'
6. **All same precedence:** 'a+b-c' → 'ab+c-' (left-to-right)

<br>

---

## Solution: Stack with Operator Precedence

Use a stack for operators:
1. For each character:
   - **Operand:** Add to output
   - **`(`:** Push to stack
   - **`)`:** Pop until `(`, add to output
   - **Operator:** Pop operators with higher/equal precedence, then push current
2. Pop remaining operators to output

**Key insight:** Higher precedence operators must appear first in postfix.

```code```

<br>

### Time Complexity Analysis

**Single Pass: O(n)**
- Process each character once: n characters
- For each character:
  - Check type: O(1)
  - Push to stack: O(1)
  - Pop from stack: O(1) amortized
  - Append to output: O(1)
- Total operations: 2n (each operator pushed and popped once)
- Total: O(n)

**Why stack is optimal?**
- Need to track pending operators
- Higher precedence operators must be output first
- Stack maintains operator order efficiently

**Space Complexity: O(n)**
- Stack holds at most n operators
- Output string is n characters

**Precedence handling:**
- `*` and `/` have precedence 2
- `+` and `-` have precedence 1
- `(` has precedence 0 (lowest)

> **Time Complexity:** O(n) - single pass, each operator handled twice
> **Space Complexity:** O(n) - stack and output string

<br>
<br>

---
