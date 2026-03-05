class EvaluatePostfixPrefix:
    def evalPostfix(self, tokens: list[str]) -> int:
        stack = []
        
        for token in tokens:
            if self.isOperator(token):
                b = stack.pop()
                a = stack.pop()
                stack.append(self.applyOp(a, b, token))
            else:
                stack.append(int(token))
        
        return stack.pop()
    
    def evalPrefix(self, tokens: list[str]) -> int:
        stack = []
        
        # Process from right to left
        for token in reversed(tokens):
            if self.isOperator(token):
                a = stack.pop()
                b = stack.pop()
                stack.append(self.applyOp(a, b, token))
            else:
                stack.append(int(token))
        
        return stack.pop()
    
    def isOperator(self, s: str) -> bool:
        return s in ['+', '-', '*', '/']
    
    def applyOp(self, a: int, b: int, op: str) -> int:
        if op == '+': return a + b
        if op == '-': return a - b
        if op == '*': return a * b
        if op == '/': return int(a / b)  # Truncate towards zero
        return 0
