class RollingHash:
    def __init__(self, s):
        n = len(s)
        self.p, self.mod = 31, 10**9+7
        self.hash = [0]*(n+1)
        self.pow = [1]*(n+1)
        for i in range(n):
            self.hash[i+1] = (self.hash[i] + (ord(s[i])-ord('a')+1)*self.pow[i]) % self.mod
            self.pow[i+1] = (self.pow[i]*self.p) % self.mod
    
    def get_hash(self, l, r):
        return (self.hash[r+1] - self.hash[l]) % self.mod