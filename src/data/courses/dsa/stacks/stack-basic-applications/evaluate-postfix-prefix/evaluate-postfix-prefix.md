Given a postfix or prefix expression, evaluate it and return the result.

**Postfix (Reverse Polish Notation):** Operators come after operands. Example: `"2 3 +"` means `2 + 3 = 5`

**Prefix (Polish Notation):** Operators come before operands. Example: `"+ 2 3"` means `2 + 3 = 5`

<br>

> Input:
> postfix = ["2", "3", "1", "*", "+", "9", "-"]

> Output:
> -4

> Explanation:
> The postfix expression is `"2 3 1 * + 9 -"`.
> - Push 2: Stack = [2]
> - Push 3: Stack = [2, 3]
> - Push 1: Stack = [2, 3, 1]
> - `*`: Pop 1, 3 → 3*1=3, Push 3: Stack = [2, 3]
> - `+`: Pop 3, 2 → 2+3=5, Push 5: Stack = [5]
> - Push 9: Stack = [5, 9]
> - `-`: Pop 9, 5 → 5-9=-4, Push -4: Stack = [-4]
> 
> **Result:** -4

<br>

> Input:
> prefix = ["+", "2", "3"]

> Output:
> 5

> Explanation:
> Process from right to left:
> - Push 3: Stack = [3]
> - Push 2: Stack = [3, 2]
> - `+`: Pop 2, 3 → 2+3=5, Push 5: Stack = [5]
> 
> **Result:** 5

<br>


---

## Constraints

- `Valid postfix/prefix expression`
- `Operands are single-digit or multi-digit integers`
- `Operators are +, -, *, /`

<br>

---

## All Possible Edge Cases

1. **Single operand:** '5' → 5
2. **Division by zero:** Undefined behavior — handle error
3. **Negative result:** '3 5 -' → -2
4. **Integer division:** '7 2 /' → 3 (truncate toward zero)
5. **Large numbers:** Multi-digit operands
6. **All same operator:** '2 3 4 + +' → 9

<br>

---

## Solution: Stack-Based Evaluation

**Postfix Evaluation:**
1. Use a stack
2. For each token:
   - If operand: Push to stack
   - If operator: Pop two operands, apply operator, push result
3. Final stack top is the result

**Prefix Evaluation:**
1. Process from right to left
2. For each token:
   - If operand: Push to stack
   - If operator: Pop two operands, apply operator (order matters), push result
3. Final stack top is the result

**Key insight:** Stack naturally handles operand order for expression evaluation.



<br>

### Time Complexity Analysis

**Single Pass: O(n)**
- Process each token once: n tokens
- For each token:
  - Check if operator/operand: O(1)
  - Push to stack: O(1)
  - Pop from stack: O(1)
  - Apply operation: O(1)
- Total: n × O(1) = O(n)

**Why stack is optimal?**
- LIFO property matches operand-operator relationship
- Operators always work on most recent operands
- No need to look ahead or backtrack

**Space Complexity: O(n)**
- Stack can hold up to n/2 operands in worst case
- Example: "1 2 3 4 + + +" has 4 operands before operators

**Comparison:**
- Postfix: Left to right, natural order
- Prefix: Right to left, reverse order
- Both: O(n) time, O(n) space

> **Time Complexity:** O(n) - single pass through tokens
> **Space Complexity:** O(n) - stack for operands

<br>
<br>

---

---

```code```
