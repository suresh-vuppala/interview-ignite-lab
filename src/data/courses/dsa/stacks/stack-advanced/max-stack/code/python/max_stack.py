class MaxStack:
    def __init__(self):
        self.stack = []
        self.max_stack = []
    
    def push(self, x: int) -> None:
        self.stack.append(x)
        if not self.max_stack:
            self.max_stack.append(x)
        else:
            self.max_stack.append(max(x, self.max_stack[-1]))
    
    def pop(self) -> int:
        self.max_stack.pop()
        return self.stack.pop()
    
    def top(self) -> int:
        return self.stack[-1]
    
    def getMax(self) -> int:
        return self.max_stack[-1]
