class Deque:
    def __init__(self, k):
        self.arr = [0] * k
        self.capacity = k
        self.front = self.rear = -1
        self.size = 0
    
    def insert_front(self, x):
        if self.size == self.capacity:
            return False
        if self.front == -1:
            self.front = self.rear = 0
        else:
            self.front = (self.front - 1 + self.capacity) % self.capacity
        self.arr[self.front] = x
        self.size += 1
        return True
    
    def insert_rear(self, x):
        if self.size == self.capacity:
            return False
        if self.rear == -1:
            self.front = self.rear = 0
        else:
            self.rear = (self.rear + 1) % self.capacity
        self.arr[self.rear] = x
        self.size += 1
        return True
    
    def delete_front(self):
        if self.size == 0:
            return False
        self.front = (self.front + 1) % self.capacity
        self.size -= 1
        return True
    
    def delete_rear(self):
        if self.size == 0:
            return False
        self.rear = (self.rear - 1 + self.capacity) % self.capacity
        self.size -= 1
        return True