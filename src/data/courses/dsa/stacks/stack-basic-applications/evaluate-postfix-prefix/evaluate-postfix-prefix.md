Evaluate a postfix (Reverse Polish Notation) expression. Tokens are integers and operators (+, -, *, /).

<br>

> Input: tokens = ["2", "1", "+", "3", "*"]
> Output: 9

> Explanation: ((2 + 1) * 3) = 9. In postfix: push 2, push 1, pop both and add (3), push 3, pop both and multiply (9).
> 
> **Key insight:** Push numbers onto stack. When operator appears, pop two operands, compute, push result. Stack naturally handles precedence and associativity.

<br>

---

## Constraints
- `1 ≤ tokens.length ≤ 10⁴`
- Tokens are valid integers or "+", "-", "*", "/"
- Division truncates toward zero

<br>

---

## All Possible Edge Cases
1. **Single number:** ["3"] → 3
2. **Negative numbers:** ["-2", "3", "+"] → 1
3. **Division truncation:** ["7", "-2", "/"] → -3 (truncate toward zero)

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
> Use Stack — Process Tokens (Optimal) for optimal performance.

<br>

---

## Solution 2: Stack — Process Tokens (Optimal)

**Intuition:** Scan left to right. Numbers: push. Operators: pop two operands (b then a), compute a op b, push result. Final stack element is the answer.

**Algorithm:**
1. For each token:
   - If number → push to stack
   - If operator → b = pop, a = pop, push(a op b)
2. Return stack.top()

### Time Complexity: O(N)
**Why?** Single pass, O(1) per token.

**Detailed breakdown:** N = 10,000 → 10,000 operations

**Example walkthrough:**
```
["2", "1", "+", "3", "*"]

"2" → push → stack=[2]
"1" → push → stack=[2, 1]
"+" → b=1, a=2, push(2+1=3) → stack=[3]
"3" → push → stack=[3, 3]
"*" → b=3, a=3, push(3*3=9) → stack=[9]

Result: 9 ✓
```

### Space Complexity: O(N)
**Why?** Stack stores at most (N+1)/2 operands.

> **Drawback:** None — this is the standard and optimal approach for RPN evaluation.

> **Key Insight for Improvement:** Already optimal. Note: order matters — a = second pop, b = first pop. a op b (not b op a).

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Stack | O(N) | O(N) | Process tokens left to right |

**Key Insights:**
1. **Pop order:** b first, a second → compute a op b
2. **Postfix eliminates precedence:** No need for parentheses or PEMDAS
3. **Prefix (Polish):** Same idea but scan right to left

<br><br>

---

```code```
