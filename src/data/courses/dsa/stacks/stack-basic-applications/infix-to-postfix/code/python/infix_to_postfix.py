# ============================================================
# Infix to Postfix (Shunting-Yard)
# ============================================================

class Solution:
    def infixToPostfix(self, s: str) -> str:
        prec = {'+': 1, '-': 1, '*': 2, '/': 2}
        ops = []
        result = []

        for c in s:
            if c.isalnum():
                result.append(c)  # Operand → output
            elif c == '(':
                ops.append(c)
            elif c == ')':
                while ops[-1] != '(':
                    result.append(ops.pop())
                ops.pop()  # Discard '('
            else:
                # Pop higher/equal precedence operators
                while ops and ops[-1] != '(' and prec.get(ops[-1], 0) >= prec.get(c, 0):
                    result.append(ops.pop())
                ops.append(c)

        while ops:
            result.append(ops.pop())

        return ''.join(result)
