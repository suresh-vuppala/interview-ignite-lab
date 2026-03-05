class InfixToPostfix:
    def infixToPostfix(self, infix: str) -> str:
        result = []
        stack = []
        
        for c in infix:
            if c.isalnum():
                result.append(c)  # Operand
            elif c == '(':
                stack.append(c)
            elif c == ')':
                while stack and stack[-1] != '(':
                    result.append(stack.pop())
                stack.pop()  # Remove '('
            else:  # Operator
                while stack and self.precedence(stack[-1]) >= self.precedence(c):
                    result.append(stack.pop())
                stack.append(c)
        
        while stack:
            result.append(stack.pop())
        
        return ''.join(result)
    
    def precedence(self, op: str) -> int:
        if op in ['+', '-']:
            return 1
        if op in ['*', '/']:
            return 2
        return 0
