Convert infix expression to postfix using stack.

<br>

---

## Solution 1: Shunting Yard Algorithm (Standard)

**Algorithm:**
1. For each token:
   - Operand → output
   - '(' → push to stack
   - ')' → pop to output until '('
   - Operator → pop higher/equal precedence operators to output, then push

### Time Complexity: O(n)
### Space Complexity: O(n)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Shunting Yard | O(n) | O(n) | Operator stack with precedence rules |

<br>
<br>

---

```code```
