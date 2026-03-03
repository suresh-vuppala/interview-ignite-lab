class QueueUsingStacks:
    def __init__(self):
        self.s1 = []
        self.s2 = []
    
    def enqueue(self, x):
        self.s1.append(x)
    
    def dequeue(self):
        if not self.s2:
            while self.s1:
                self.s2.append(self.s1.pop())
        return self.s2.pop()
    
    def peek(self):
        if not self.s2:
            while self.s1:
                self.s2.append(self.s1.pop())
        return self.s2[-1]