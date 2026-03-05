class Stack:
    def __init__(self):
        self.arr = []
    
    def push(self, val):
        self.arr.append(val)
    
    def pop(self):
        return self.arr.pop()
    
    def peek(self):
        return self.arr[-1]
    
    def is_empty(self):
        return len(self.arr) == 0
    
    def size(self):
        return len(self.arr)
