class MinMaxHeap:
    def __init__(self):
        self.heap = []
    
    def parent(self, i):
        return (i - 1) // 2
    
    def left(self, i):
        return 2 * i + 1
    
    def right(self, i):
        return 2 * i + 2
    
    def bubble_up(self, i):
        while i > 0 and self.heap[i] > self.heap[self.parent(i)]:
            self.heap[i], self.heap[self.parent(i)] = self.heap[self.parent(i)], self.heap[i]
            i = self.parent(i)
    
    def bubble_down(self, i):
        max_index = i
        l = self.left(i)
        r = self.right(i)
        
        if l < len(self.heap) and self.heap[l] > self.heap[max_index]:
            max_index = l
        if r < len(self.heap) and self.heap[r] > self.heap[max_index]:
            max_index = r
        
        if i != max_index:
            self.heap[i], self.heap[max_index] = self.heap[max_index], self.heap[i]
            self.bubble_down(max_index)
    
    def insert(self, val):
        self.heap.append(val)
        self.bubble_up(len(self.heap) - 1)
    
    def extract_max(self):
        max_val = self.heap[0]
        self.heap[0] = self.heap[-1]
        self.heap.pop()
        if self.heap:
            self.bubble_down(0)
        return max_val
