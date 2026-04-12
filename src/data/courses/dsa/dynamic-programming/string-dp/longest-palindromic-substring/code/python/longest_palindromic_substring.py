class Solution:
    def longestPalindrome(self, s) -> str:
        start,max_len=0,1
        for i in range(len(s)):
            for l,r in [(i,i),(i,i+1)]:
                while l>=0 and r<len(s) and s[l]==s[r]: l-=1; r+=1
                if r-l-1>max_len: start,max_len=l+1,r-l-1
        return s[start:start+max_len]
