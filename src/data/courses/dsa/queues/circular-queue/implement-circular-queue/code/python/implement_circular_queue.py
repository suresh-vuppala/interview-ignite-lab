class CircularQueue:
    def __init__(self, k):
        self.arr = [0] * k
        self.capacity = k
        self.front = self.rear = -1
        self.size = 0
    
    def enqueue(self, x):
        if self.size == self.capacity:
            return False
        if self.front == -1:
            self.front = 0
        self.rear = (self.rear + 1) % self.capacity
        self.arr[self.rear] = x
        self.size += 1
        return True
    
    def dequeue(self):
        if self.size == 0:
            return False
        self.front = (self.front + 1) % self.capacity
        self.size -= 1
        return True