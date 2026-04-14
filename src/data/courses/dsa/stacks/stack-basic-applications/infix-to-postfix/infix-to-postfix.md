Convert an infix expression (e.g., "a+b*c") to postfix notation (e.g., "abc*+") using operator precedence rules.

<br>

> Input: "a+b*c"
> Output: "abc*+"

> Explanation: * has higher precedence than +. So b*c evaluates first → postfix: bc*. Then a + (bc*) → abc*+.
> 
> **Key insight:** Use operator stack. Push operators, but first pop all operators with higher or equal precedence. '(' pushes unconditionally. ')' pops until '(' found.

<br>

---

## Constraints
- Valid infix expression with +, -, *, /, (, )
- Operands are single characters (a-z)

<br>

---

## All Possible Edge Cases
1. **No operators:** "a" → "a"
2. **Parentheses override:** "a*(b+c)" → "abc+*"
3. **Left-to-right associativity:** "a-b-c" → "ab-c-"

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
> Less efficient approach exists.

> **Key Insight for Improvement:**
> Use Operator Stack (Shunting-Yard Algorithm) for optimal performance.

<br>

---

## Solution 2: Operator Stack (Shunting-Yard Algorithm)

**Intuition:** Operands go directly to output. Operators go to stack, but first pop higher/equal precedence operators. Parentheses: '(' pushes, ')' pops until '('.

**Algorithm:**
1. For each token:
   - Operand → output
   - '(' → push to stack
   - ')' → pop to output until '(' found, discard '('
   - Operator → pop stack while top has ≥ precedence, then push
2. Pop remaining operators to output

### Time Complexity: O(N)
**Why?** Each token processed once. Each operator pushed/popped at most once.

**Detailed breakdown:** N tokens → at most 2N operations

**Example walkthrough:**
```
"a+b*c"

'a' → output="a"
'+' → stack=[+], output="a"
'b' → output="ab"
'*' → * > + precedence → push. stack=[+, *], output="ab"
'c' → output="abc"
End → pop: *, then + → output="abc*+"

Result: "abc*+" ✓
```

### Space Complexity: O(N)

> **Drawback:** None — Shunting-Yard is the standard O(N) algorithm.

> **Key Insight for Improvement:** Already optimal. The precedence comparison is the key: pop while stack top has ≥ precedence (for left-associative operators).

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Shunting-Yard | O(N) | O(N) | Operator stack with precedence |

**Key Insights:**
1. **Precedence rule:** Pop higher/equal precedence operators before pushing
2. **Parentheses:** '(' acts as a barrier — operators don't pop past it
3. **Right-associative (^):** Pop only strictly higher precedence, not equal

<br><br>

---

```code```
