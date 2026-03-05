class CircularQueue:
    def __init__(self, capacity: int):
        self.queue = [0] * capacity
        self.front = -1
        self.rear = -1
        self.size = capacity
    
    def enqueue(self, value: int) -> bool:
        if (self.rear + 1) % self.size == self.front:
            return False  # Full
        if self.front == -1:
            self.front = 0
        self.rear = (self.rear + 1) % self.size
        self.queue[self.rear] = value
        return True
    
    def dequeue(self) -> int:
        if self.front == -1:
            return -1  # Empty
        value = self.queue[self.front]
        if self.front == self.rear:
            self.front = self.rear = -1  # Last element
        else:
            self.front = (self.front + 1) % self.size
        return value
    
    def peek(self) -> int:
        return -1 if self.front == -1 else self.queue[self.front]
