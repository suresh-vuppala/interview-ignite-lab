class Stack:
    def __init__(self, size):
        self.arr = [0] * size
        self.top = -1
    
    def push(self, x):
        self.top += 1
        self.arr[self.top] = x
    
    def pop(self):
        val = self.arr[self.top]
        self.top -= 1
        return val
    
    def peek(self):
        return self.arr[self.top]
    
    def is_empty(self):
        return self.top == -1