class MaxStack:
    def __init__(self):
        self.st = []
        self.max_st = []
    
    def push(self, x):
        self.st.append(x)
        if not self.max_st or x >= self.max_st[-1]:
            self.max_st.append(x)
    
    def pop(self):
        if self.st.pop() == self.max_st[-1]:
            self.max_st.pop()
    
    def top(self):
        return self.st[-1]
    
    def get_max(self):
        return self.max_st[-1]