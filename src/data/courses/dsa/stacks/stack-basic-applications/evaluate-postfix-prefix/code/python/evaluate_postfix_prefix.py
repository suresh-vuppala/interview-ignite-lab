# ============================================================
# Evaluate Reverse Polish Notation
# ============================================================

from typing import List

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        ops = {'+', '-', '*', '/'}

        for t in tokens:
            if t in ops:
                b, a = stack.pop(), stack.pop()  # b first, a second
                if t == '+': stack.append(a + b)
                elif t == '-': stack.append(a - b)
                elif t == '*': stack.append(a * b)
                else: stack.append(int(a / b))  # Truncate toward zero
            else:
                stack.append(int(t))

        return stack[0]
