You are given a string `s` representing a **nested arithmetic expression**.

The expression consists of:

- Operators: `"add"`, `"sub"`, and `"mult"`
- Non-negative integers
- Parentheses `(` `)`
- Commas `,` separating arguments

<br>

## Expression Rules

1. `add(a, b)` returns `a + b`
2. `sub(a, b)` returns `a - b`
3. `mult(a, b)` returns `a * b`
4. Expressions can be **nested arbitrarily**
5. Each operator must have **exactly two operands**

<br>

## Validity Rules

An expression is considered **valid** if:

- Only supported operators (`add`, `sub`, `mult`) are used
- Each operator has exactly **2 operands**
- Parentheses are **balanced and properly nested**
- No invalid characters exist in the string

<br>

## Objective

- If the expression is **valid**, return the computed integer result
- If the expression is **invalid**, return **-1**

<br>

> Input:
> s = "add(1,2)"

> Output:
> 3

<br>

> Input:
> s = "add(sub(add(1,2),4),7)"

> Output:
> 6

> Explanation:
> - add(1,2) = 3
> - sub(3,4) = -1
> - add(-1,7) = 6

<br>

> Input:
> s = "add(1)"

> Output:
> -1

> Explanation:
> Invalid: missing operand

<br>

> Input:
> s = "mul(1,2)"

> Output:
> -1

> Explanation:
> Invalid: unsupported operator

<br>

> Input:
> s = "add(1,2))"

> Output:
> -1

> Explanation:
> Invalid: extra closing bracket

<br>

## Constraints

- `1 ≤ s.length ≤ 10^5`
- `s` consists of lowercase letters, digits, `'('`, `')'`, and `','`

<br>

## All Possible Edge Cases

1. **Valid simple expression:** `"add(1,2)"` → 3
2. **Valid nested expression:** `"add(sub(1,2),3)"` → 2
3. **Invalid operator:** `"mul(1,2)"` → -1
4. **Missing operand:** `"add(1)"` → -1
5. **Extra operands:** `"add(1,2,3)"` → -1
6. **Unbalanced parentheses:** `"add(1,2))"` → -1
7. **Missing closing parenthesis:** `"add(1,2"` → -1
8. **Empty expression:** `""` → -1
9. **Number without operator:** `"123"` → -1
10. **Invalid characters:** `"add(1,@)"` → -1

<br>

## Solution: Stack-Based Evaluation

**Intuition:**
Use a stack to track operators and their operands. Each frame on the stack represents an unfinished operation. When we encounter ')', we compute the result of the current frame and pass it to the parent frame or return it as the final result.

**Algorithm:**
1. Initialize stack of (operator, operands)
2. Parse string left to right:
   - **Operator (letters):** Push new frame with operator name
   - **Number (digits):** Add to current frame's operands
   - **Closing ')':** 
     - Validate: exactly 2 operands
     - Compute result based on operator
     - Pass result to parent or return if outermost
   - **Invalid character or rule violation:** Return -1
3. If stack not empty at end → invalid expression

**Example walkthrough:**
```
s = "add(sub(1,2),3)"

Stack: []
'add' → Stack: [("add", [])]
'(' → continue
'sub' → Stack: [("add", []), ("sub", [])]
'(' → continue
'1' → Stack: [("add", []), ("sub", [1])]
',' → continue
'2' → Stack: [("add", []), ("sub", [1,2])]
')' → compute sub(1,2)=-1 → Stack: [("add", [-1])]
',' → continue
'3' → Stack: [("add", [-1,3])]
')' → compute add(-1,3)=2 → Stack: []

Result: 2
```

**Key insight:** Stack pattern #5 (Nested Structure / Value Propagation) — inner results flow to outer layers.

### Time Complexity: O(N)
**Why?**
- Single pass through string
- Each character processed once

### Space Complexity: O(N)
**Why?**
- Stack depth proportional to nesting level
- Worst case: deeply nested expression

<br>

## Complexity Summary

| Aspect | Complexity | Reason |
|--------|-----------|---------|
| Time | O(N) | Single pass through string |
| Space | O(N) | Stack for nested frames |

**Key Insights:**
1. **Stack pattern:** Perfect for nested structures with value propagation
2. **Validation:** Check rules at each step, return -1 immediately on violation
3. **Frame-based:** Each operation is a frame with operator and operands
4. **Bottom-up evaluation:** Inner expressions compute first, results flow outward

<br>

```code```
