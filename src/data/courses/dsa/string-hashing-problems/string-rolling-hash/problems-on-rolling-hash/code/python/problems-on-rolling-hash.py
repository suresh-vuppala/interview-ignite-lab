class Solution:
    def longestDupSubstring(self, s: str) -> str:
        n = len(s)
        left, right = 1, n
        res = ""
        
        while left <= right:
            mid = (left + right) // 2
            dup = self.search(s, mid)
            if dup:
                res = dup
                left = mid + 1
            else:
                right = mid - 1
        return res
    
    def search(self, s, length):
        p, mod = 31, 10**9+7
        hash_val, pow_val = 0, 1
        seen = {}
        
        for i in range(length):
            hash_val = (hash_val + (ord(s[i])-ord('a')+1)*pow_val) % mod
            pow_val = (pow_val*p) % mod
        seen[hash_val] = [0]
        
        for i in range(length, len(s)):
            hash_val = (hash_val - (ord(s[i-length])-ord('a')+1)) % mod
            hash_val = (hash_val + (ord(s[i])-ord('a')+1)*pow_val) % mod
            
            if hash_val in seen:
                for idx in seen[hash_val]:
                    if s[idx:idx+length] == s[i-length+1:i+1]:
                        return s[idx:idx+length]
            seen.setdefault(hash_val, []).append(i-length+1)
        return 