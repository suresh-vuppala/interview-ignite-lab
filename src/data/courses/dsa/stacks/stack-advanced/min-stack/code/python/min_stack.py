class MinStack:
    def __init__(self):
        self.st = []
        self.min_st = []
    
    def push(self, x):
        self.st.append(x)
        if not self.min_st or x <= self.min_st[-1]:
            self.min_st.append(x)
    
    def pop(self):
        if self.st.pop() == self.min_st[-1]:
            self.min_st.pop()
    
    def top(self):
        return self.st[-1]
    
    def get_min(self):
        return self.min_st[-1]