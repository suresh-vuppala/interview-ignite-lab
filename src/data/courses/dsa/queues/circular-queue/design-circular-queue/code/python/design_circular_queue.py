class CircularQueue:
    def __init__(self, k):
        self.arr = [0] * k
        self.capacity = k
        self.front = self.rear = -1
        self.size = 0
    
    def enqueue(self, x):
        if self.is_full():
            return False
        if self.is_empty():
            self.front = 0
        self.rear = (self.rear + 1) % self.capacity
        self.arr[self.rear] = x
        self.size += 1
        return True
    
    def dequeue(self):
        if self.is_empty():
            return False
        if self.front == self.rear:
            self.front = self.rear = -1
        else:
            self.front = (self.front + 1) % self.capacity
        self.size -= 1
        return True
    
    def is_empty(self):
        return self.size == 0
    
    def is_full(self):
        return self.size == self.capacity