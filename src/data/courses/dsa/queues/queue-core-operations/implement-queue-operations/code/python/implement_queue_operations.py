class Queue:
    def __init__(self, capacity):
        self.arr = [0] * capacity
        self.front = 0
        self.rear = -1
        self.size = 0
    
    def enqueue(self, x):
        self.rear += 1
        self.arr[self.rear] = x
        self.size += 1
    
    def dequeue(self):
        self.size -= 1
        val = self.arr[self.front]
        self.front += 1
        return val
    
    def peek(self):
        return self.arr[self.front]
    
    def is_empty(self):
        return self.size == 0