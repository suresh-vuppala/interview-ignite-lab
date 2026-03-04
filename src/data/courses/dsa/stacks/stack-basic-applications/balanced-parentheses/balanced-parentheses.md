Check if a string containing parentheses is balanced. A string is balanced if every opening bracket has a corresponding closing bracket in the correct order.

<br>

> Input:
> s = "({[]})"

> Output:
> true

> Explanation:
> Stack process:
> - '(': push to stack → stack = ['(']
> - '{': push to stack → stack = ['(', '{']
> - '[': push to stack → stack = ['(', '{', '[']
> - ']': matches '[' at top, pop → stack = ['(', '{']
> - '}': matches '{' at top, pop → stack = ['(']
> - ')': matches '(' at top, pop → stack = []
> - Stack empty, all matched → balanced

<br>

> Input:
> s = "([)]"

> Output:
> false

> Explanation:
> Stack process:
> - '(': push → stack = ['(']
> - '[': push → stack = ['(', '[']
> - ')': top is '[', doesn't match ')' → unbalanced

<br>

---

## Solution: Stack-Based Matching

Use stack to track opening brackets:
1. For opening bracket: push to stack
2. For closing bracket: check if matches top of stack
3. If matches: pop from stack
4. If doesn't match or stack empty: unbalanced
5. At end: stack should be empty

**Key insight:** Last opened bracket must be first closed (LIFO - perfect for stack).

```code```

<br>

### Time Complexity Analysis

**Single Pass: O(n)**
- Traverse string once: n characters
- For each character:
  - Check if opening/closing: O(1)
  - Push to stack: O(1)
  - Pop from stack: O(1)
  - Compare brackets: O(1)
- Total: n × O(1) = O(n)

**Why stack is optimal?**
- Need to match most recent opening bracket
- LIFO property of stack perfectly matches bracket pairing
- No need to track all previous brackets, just most recent unmatched

**Space Complexity: O(n)**
- Worst case: all opening brackets, no closing
- Example: "((((" requires stack of size n
- Best case: balanced immediately, O(1) stack size
- Average case: O(n/2) = O(n)

**Why not other data structures?**
- Array: Would need to track index, less efficient
- Queue: FIFO doesn't match bracket pairing order
- HashMap: Overkill, doesn't help with ordering
- Stack: Perfect match for LIFO bracket matching

> **Time Complexity:** O(n) - single pass through string
> **Space Complexity:** O(n) - stack can hold all opening brackets in worst case

<br>
<br>

---